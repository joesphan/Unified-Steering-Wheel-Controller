//Safetys
#define MAX_RPM 1
#define MOT_EN_PIN 7

//encoder parameters
#define MAX_STEPS 15000                         //maximum number of steps one way
#define MAX_FULL_STEPS (MAX_STEPS * 2)        //max number of steps total

//encoder HW
#define ENCODER1_PIN 3          //must support external interrupt
#define ENCODER2_PIN 2          // ""    ""       ""       ""

//encoder RPM detect
#define ENCODER_1_REV 10000
#define RPM_DIVIDEND (60000000 / ENCODER_1_REV)

//motor control HW
#define ADC_PIN 5               //must be 5 for 12 bits

//endstop damping settings: https://www.desmos.com/calculator/rhyetd6p3d
#define ENDSTOP_FACTOR 2.5                  //dampening factor when turned past full lock
#define MAX_OVERTRAVEL 100        //how much overtravel steps is allowed before full force is applied
#define BIT_DEPTH 2048

//endstop rebound settings:
#define REBOUND_FORCE 50            //rebound force proportion to speed

//endstop spring length
#define OVERTRAVEL_SLOPE (BIT_DEPTH / MAX_OVERTRAVEL)   //internal calcs

//SPI SS pin
//#define SS_PIN 10
