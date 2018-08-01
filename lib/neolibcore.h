#ifndef NEOLIBCORE_H
#define NEOLIBCORE_H
// HARDWARE CALIBRATION
#define Vbutton_releaseLevel  100
#define Vbutton_left          90
#define Vbutton_right         70
#define Vbutton_both          60
#define Vbutton_pressedLevel  Vbutton_left

#define Vcc                    37 // 3.7 V for LiPo
#define Vdiv 26 // measure max Voltage on Analog In

//CONSTANTS

#define BUTTON_NOTPRESSED   0
#define BUTTON_PRESSED      1
#define BUTTON_NONE         0
#define BUTTON_LEFT         1
#define BUTTON_RIGHT        2

uint8_t getButton(uint8_t pot_val)
{
  uint8_t  button = BUTTON_NONE;
  uint16_t pinVoltage;

  pinVoltage = pot_val;

  if ( pinVoltage < Vbutton_left  ) button = BUTTON_LEFT;
  if ( pinVoltage < Vbutton_right ) button = BUTTON_RIGHT;
  if ( pinVoltage < Vbutton_both  ) button = BUTTON_LEFT + BUTTON_RIGHT;

  return button;
}


uint8_t wasButtonPressed(uint8_t pot_val)
{
  static uint8_t buttonPressed    = false;
  static uint8_t buttonState      = 0;
  static uint8_t buttonValue      = BUTTON_NONE;
  static uint8_t buttonMaxValue   = 0;

  uint8_t        buttonReturnValue;
  uint16_t       pinVoltage;

  pinVoltage = pot_val;

  // hysteresis switch
  if ( pinVoltage > Vbutton_releaseLevel ) buttonPressed = false;
  if ( pinVoltage < Vbutton_pressedLevel ) buttonPressed = true;

  buttonReturnValue = BUTTON_NONE;

  switch ( buttonState )
  {
    case BUTTON_NOTPRESSED:
      {
        buttonMaxValue = 0;

        if ( buttonPressed )
        {
          buttonState = BUTTON_PRESSED;
        }
      }; break;

    case BUTTON_PRESSED:
      {
        if ( buttonPressed ) // find minimum volage level during button pressed period
        {
          buttonValue = BUTTON_NONE;

          if ( pinVoltage < Vbutton_both  ) buttonValue = BUTTON_LEFT + BUTTON_RIGHT;
          else if ( pinVoltage < Vbutton_right ) buttonValue =               BUTTON_RIGHT;
          else if ( pinVoltage < Vbutton_left  ) buttonValue = BUTTON_LEFT               ;

          if ( buttonValue > buttonMaxValue ) buttonMaxValue = buttonValue;

        } else
        {
          buttonState = BUTTON_NOTPRESSED;
          buttonReturnValue = buttonMaxValue;
        }
        ; break;

      }
  }

  return buttonReturnValue;
}

#endif // NEOLIBCORE_H
