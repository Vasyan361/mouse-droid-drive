#define DEBUG

// Pin configuration
// #define SERVO_PIN 14
// #define ESC_PIN 12
//Mini Mouse 
#define SERVO_PIN 19
#define ESC_PIN 23
#define IN_1_PIN 12
#define IN_2_PIN 13
#define RANDOM_SEED_PIN 34

// Controller configuration
#define STICK_DEADZONE 20

// Drive motor configuration
#define MIN_ESC_MICROSECONDS 1350
#define MAX_ESC_MICROSECONDS 1650
#define CENTER_ESC_MICROSECONDS 1500
#define ESC_DRIVE
// #define MX1508_DRIVE
#define MIN_DRIVE_PWM -255
#define MAX_DRIVE_PWM 255
// #define REVERSE_DRIVE_MOTOR

// Servo configuration
#define SERVO_ANGLE_LIMIT 90
#define REVERSE_SERVO

// Sounds configuration
#define LOOP_MUSIC_MIN_TIMEOUT 5000
#define LOOP_MUSIC_MAX_TIMEOUT 15000
// #define LOOP_MUSIC