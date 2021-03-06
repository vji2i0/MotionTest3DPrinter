#ifndef CONFIG_GCODE
#define CONFIG_GCODE

enum {SECONDS_IN_MINUTE = 60};

enum {STEPS_PER_MM_XY = 80, STEPS_PER_MM_Z = 400, STEPS_PER_MM_E = 160};

enum {F_DEFAULT = 1000};
enum {MAX_SPEED_MM_MIN_XY = 4000, MAX_SPEED_MM_MIN_Z = 500, MAX_SPEED_MM_MIN_E = 4000};
enum {MIN_SPEED_MM_MIN_XY = 50};
enum {ACCELERATION_MM_MIN_S_XY = 10000, ACCELERATION_MM_MIN_S_Z = 1000};

enum {COMMAND_BUFFER_LENGTH = 50, RESERVE_LENGTH = 10};

enum {CRITICAL_ANGLE_XY = 20};

enum {HOME_COARSE_SPEED_XY = 2000,  HOME_FINE_SPEED_XY = 500};
enum {HOME_COARSE_SPEED_Z  = 400,    HOME_FINE_SPEED_Z  = 100};
enum {HOME_FINE_DISTANCE = 5};

#define TIMER_PERIOD_S 0.000167


#endif
