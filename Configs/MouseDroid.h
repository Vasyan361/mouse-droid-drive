// Pin configuration
#define SERVO_PIN 14
#define ESC_PIN 12
#define RANDOM_SEED_PIN 34

// Controller configuration
#define STICK_DEADZONE 20

// Drive motor configuration
#define MIN_ESC_MICROSECONDS 1200
#define MAX_ESC_MICROSECONDS 1550
#define CENTER_ESC_MICROSECONDS 1300
#define ESC_DRIVE
// #define MX1508_DRIVE
#define MIN_DRIVE_PWM -255
#define MAX_DRIVE_PWM 255
// #define REVERSE_DRIVE_MOTOR

// Servo configuration
#define SERVO_ANGLE_LIMIT 50
#define REVERSE_SERVO

// Sounds configuration
#define LOOP_MUSIC_MIN_TIMEOUT 5000
#define LOOP_MUSIC_MAX_TIMEOUT 15000
// #define LOOP_MUSIC