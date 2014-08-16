#include "Arduino.h"
#include "ModuleLowpassFilter.h"
#include "defines.h"
#include "GlobalFilterTables.h"

// Special thanks to Gaetan Ro for adapting this filter 
// for the Equation Composer from
//
// http://www.musicdsp.org/showone.php?id=24
// (see below for a cleaned up version of this thread)

ModuleLowpassFilter::ModuleLowpassFilter()
{
  y1=0;
  y2=0;
  y3=0;
  y4=0;
  oldx=0;
  oldy1=0;
  oldy2=0;
  oldy3=0; 

  // Initialize all inputs
  this->audio_input = NULL; 
  this->cutoff_input = NULL;
  this->resonance_input = NULL;      
}


uint16_t ModuleLowpassFilter::compute()
{
  long audio = ((this->readInput(audio_input))<<1) - 4096;
  long cutoff = this->readInput(cutoff_input);
  long resonance = this->readInput(resonance_input);
  long k,p,r,x;

  // LPF_P_TABLE is computed using:
  //-------------------------------
  // cutoff = cutoff * .9;  
  // p = (cutoff*(7373-((3277*cutoff)>>12)))>>12;

  p = LPF_P_TABLE[cutoff];

  // t = ((4096-p)*5678)>>12;
  // t2 = 49152+((t*t)>>12);
  // t3 = (24576*t)>>12;
  // r = resonance * (t2+t3)/(t2-t3);

  r = (resonance * LPF_T4_TABLE[cutoff]) >> 12;


  // Inverted feed back for corner peaking
  x = audio - ((r*y4)>>12);

  // Worth trying:
  // "A much better tuning seems to be k=2*sin(cutoff * pi/2)-1;
  // k = 2 * sin_fix1212(cutoff * pi/2) - 4096;"
  k = p + p - 4095;
  
  // Four cascaded onepole filters (bilinear transform)
  y1 = ((x*p)  + (oldx*p)  - (k*y1)) >> 12;
  y2 = ((y1*p) + (oldy1*p) - (k*y2)) >> 12;
  y3 = ((y2*p) + (oldy2*p) - (k*y3)) >> 12;
  y4 = ((y3*p) + (oldy3*p) - (k*y4)) >> 12;

  // Clipper band limited sigmoid
  y4 = y4 - ((y4 * ((y4 * ((y4 * 683)>>12))>>12))>>12);    // clipping

  oldx = x;
  oldy1 = y1;
  oldy2 = y2;
  oldy3 = y3;
   
  return(((uint32_t) (y4 + 4096))>>1);
}




/* 

Original thread from: http://www.musicdsp.org/showone.php?id=24

Moog VCF
Type : 24db resonant lowpass
References : CSound source code, Stilson/Smith CCRMA paper.
Notes : Digital approximation of Moog VCF. 
Fairly easy to calculate coefficients, fairly easy to process algorithm, good sound.

Code :

  //Init
  cutoff = cutoff freq in Hz
  fs = sampling frequency //(e.g. 44100Hz)
  res = resonance [0 - 1] //(minimum - maximum)

  f = 2 * cutoff / fs; //[0 - 1]
  k = 3.6*f - 1.6*f*f -1; //(Empirical tunning)
  p = (k+1)*0.5;
  scale = e^((1-p)*1.386249;
  r = res*scale;
  y4 = output;

  y1=y2=y3=y4=oldx=oldy1=oldy2=oldy3=0;

  //Loop
  //--Inverted feed back for corner peaking
  x = input - r*y4;

  //Four cascaded onepole filters (bilinear transform)
  y1=x*p + oldx*p - k*y1;
  y2=y1*p+oldy1*p - k*y2;
  y3=y2*p+oldy2*p - k*y3;
  y4=y3*p+oldy3*p - k*y4;

  //Clipper band limited sigmoid
  y4 = y4 - (y4^3)/6;

  oldx = x;
  oldy1 = y1;
  oldy2 = y2;
  oldy3 = y3;



Comments
================================================================================

from : hagenkaiser[AT]gmx[DOT]de
comment : I guess the input is supposed to be between -1..1

from : toast[AT]nowhere[DOT]com
comment : OK. Can't guarantee this is a 100% translation to real C++, but it does 
work. Aside from possible mistakes, I mucked hard with the coefficient translation, 
so that there is a slight difference in the numbers. 

1. What kind of filter ends up with exp() in the coefficient calculation instead 
of the usual sin(), cos(), tan() transcendentals? If someone can explain where 
the e to the x comes from, I'd appreciate it. 

2. Since I didn't understand the origin of the coefficients, I saw the whole section 
as an excercise in algebra. There were some superfluous multiplications and additions. 
First I implemented the e to the x with pow(). That was stupid. I switched to exp(). 
Hated that too. Checked out the range of inputs and decided on a common approximation 
for exp(). I think it's now one of the fastest filter coefficient calcs you'll see 
for a 4 pole. Go ahead--put the cutoff on an envelope and the q on an LFO. Hell, 
FM the Q if you want! A pretty good filter. Watch the res (aka Q). Above 9, squeals 
like a pig. Not in a good way. Needs more work, i think, to stand up with the better 
LPs in the real VST world. But an awfully cool starting place. If I did something 
awful here in the translation, or if you have a question about how to use it, best 
to ask me (mistertoast) over at KvRaudio.com in the dev section. I'm toying with 
the idea of wedging this into TobyBear's filter designer as a flt file. If you manage 
first, let me know. I'm mistertoast.

from : nobody[AT]nowhere[DOT]com
comment : Still working on this one. Anyone notice it's got a few syntax problems? 
Makes me wonder if it's even been tried. Missing parenthesis. Uses ^ twice. If I 
get it to work, I'll post usable code.

from : toast[AT]nowhere[DOT]com
comment : MoogFilter.h: 

  class MoogFilter 
  { 
    public: MoogFilter(); 
    void init(); 
    void calc(); 
    float process(float x); 
    ~MoogFilter(); 
    float getCutoff(); 
    void setCutoff(float c); 
    float getRes(); 
    void setRes(float r); 
    protected: float cutoff; 
    float res; 
    float fs; 
    float y1,y2,y3,y4; 
    float oldx; 
    float oldy1,oldy2,oldy3; 
    float x; 
    float r; 
    float p; 
    float k; 
  };

from : toast[AT]nowhere[DOT]com
comment : MoogFilter.cpp: 

  #include "MoogFilter.h" MoogFilter::MoogFilter() {
      fs=44100.0;
      init();
      
  }
  
  MoogFilter::~MoogFilter() {
      
  }

  void MoogFilter::init() {
      // initialize values y1=y2=y3=y4=oldx=oldy1=oldy2=oldy3=0;
      calc();
      
  };

  void MoogFilter::calc() {
      float f = (cutoff+cutoff) / fs;
      //[0 - 1] p=f*(1.8f-0.8f*f);
      k=p+p-1.f;
      float t=(1.f-p)*1.386249f;
      float t2=12.f+t*t;
      r = res*(t2+6.f*t)/(t2-6.f*t);
  };

  float MoogFilter::process(float input) {
      // process input x = input - r*y4;
      //Four cascaded onepole filters (bilinear transform) y1= x*p + oldx*p - k*y1;
      y2=y1*p + oldy1*p - k*y2;
      y3=y2*p + oldy2*p - k*y3;
      y4=y3*p + oldy3*p - k*y4;
      //Clipper band limited sigmoid y4-=(y4*y4*y4)/6.f;
      oldx = x;
      oldy1 = y1;
      oldy2 = y2;
      oldy3 = y3;
      return y4;
      
  }
  float MoogFilter::getCutoff() {
      return cutoff;
      
  }
  void MoogFilter::setCutoff(float c) {
      cutoff=c;
      calc();
      
  }
  float MoogFilter::getRes() {
      return res;
      
  }
  void MoogFilter::setRes(float r) {
      res=r;
      calc();
      
  }


from : toast[AT]somewhereyoucantfind[DOT]com
comment : I see where the exp() comes from. It just models the resonance. I think 
it needs more work. At high frequencies it goes into self-oscillation much more 
quickly than at low frequencies.

from : dev[AT]null[DOT]com
comment : A much better tuning seems to be k=2*sin(f*pi/2)-1; (within a 0.1 cent 
up to 4kHz, at 44.1kHz sample rate)

from : bula[AT]distcore[DOT]net
comment : This filter works and sounds fine in my VST. I've re-written the code 
using templates, which makes life easier when switching between <float> and 
<double> implementation. 

#pragma once namespace DistoCore {
    template&lt;
    class T&gt;
    class MoogFilter {
        public: MoogFilter();
        ~MoogFilter() {
            
        }
        ;
        T getSampleRate() const {
            return sampleRate;
            
        }
        void setSampleRate(T fs) {
            sampleRate = fs;
            calc();
            
        }
        T getResonance() const {
            return resonance;
            
        }
        void setResonance(T filterRezo) {
            resonance = filterRezo;
            calc();
            
        }
        T getCutoff() const {
            return cutoff;
            
        }
        T getCutoffHz() const {
            return cutoff * sampleRate * 0.5;
            
        }
        void setCutoff(T filterCutoff) {
            cutoff = filterCutoff;
            calc();
            
        }
        void init();
        void calc();
        T process(T input);
        // filter an input sample using normalized params T filter(T input, T cutoff, T resonance);
        protected: // cutoff and resonance [0 - 1] T cutoff;
        T resonance;
        T sampleRate;
        T fs;
        T y1,y2,y3,y4;
        T oldx;
        T oldy1,oldy2,oldy3;
        T x;
        T r;
        T p;
        T k;
        
    }
    ;
    // Construct Moog-filter.
    template&lt;
    class T&gt;
    MoogFilter&lt;
    T&gt;
    ::MoogFilter() : sampleRate(T(44100.0)) , cutoff(T(1.0)) , resonance(T(0.0)) {
        init();
        
    }
    // Initialize filter buffers.
    template&lt;
    class T&gt;
    void MoogFilter&lt;
    T&gt;
    ::init() {
        // initialize values y1=y2=y3=y4=oldx=oldy1=oldy2=oldy3=T(0.0);
        calc();
        
    }
    // Calculate coefficients.
    class T&gt;
    void MoogFilter&lt;
    T&gt;
    ::calc() {
        // TODO: replace with your constant const double kPi = 3.1415926535897931;
        // empirical tuning p = cutoff * (T(1.8) - T(0.8) * cutoff);
        // k = p + p - T(1.0);
        // A much better tuning seems to be: k = T(2.0) * sin(cutoff * kPi * T(0.5)) - T(1.0);
        T t1 = (T(1.0) - p) * T(1.386249);
        T t2 = T(12.0) + t1 * t1;
        r = resonance * (t2 + T(6.0) * t1) / (t2 - T(6.0) * t1);
        
    }
    ;
    // template&lt;
    class T&gt;
    T MoogFilter&lt;
    T&gt;
    ::process(T input) {
        // process input x = input - r * y4;
        // four cascaded one-pole filters (bilinear transform) y1 = x * p + oldx * p - k * y1;
        y2 = y1 * p + oldy1 * p - k * y2;
        y3 = y2 * p + oldy2 * p - k * y3;
        y4 = y3 * p + oldy3 * p - k * y4;
        // clipper band limited sigmoid y4 -= (y4 * y4 * y4) / T(6.0);
        oldx = x;
        oldy1 = y1;
        oldy2 = y2;
        oldy3 = y3;
        return y4;
        
    }
    template&lt;
    class T&gt;
    T MoogFilter&lt;
    T&gt;
    ::filter(T input, T filterCutoff, T filterRezo) {
        // set params first cutoff = filterCutoff;
        resonance = filterRezo;
        calc();
        return process(input);
        
    }
    
}

from : fred[AT]topengine[DOT]net
comment : Why samplerate is missing in calc function?

*/