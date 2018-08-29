#include "Arduino.h"

#ifndef SAMPLES
#define SAMPLES

#define SAMPLE_KICK_LENGTH 6199
#define SAMPLE_SNARE_LENGTH 5222
#define SAMPLE_HIHAT_LENGTH 2131

#define SAMPLE_KICK2_LENGTH 8394
#define SAMPLE_SNARE2_LENGTH 1026
#define SAMPLE_HIHAT2_LENGTH 1243

#define SAMPLE_KICK3_LENGTH 7288
#define SAMPLE_SNARE3_LENGTH 6988
#define SAMPLE_HIHAT3_LENGTH 1128

extern const uint16_t SAMPLE_KICK[];
extern const uint16_t SAMPLE_SNARE[];
extern const uint16_t SAMPLE_HIHAT[];

extern const uint16_t SAMPLE_KICK2[];
extern const uint16_t SAMPLE_SNARE2[];
extern const uint16_t SAMPLE_HIHAT2[];

extern const uint16_t SAMPLE_KICK3[];
extern const uint16_t SAMPLE_SNARE3[];
extern const uint16_t SAMPLE_HIHAT3[];

#endif