/*
     MotorController: controls the servo drive
*/
#define ENDSTOP_DAMPENING 100                 //dampening factor when turned past full lock
#define FFB_MULTIPLIER 0.35                   //required multiplier to get it into 2 * 255 domain
#define OVERTRAVEL_RAMP_TO_FULL_FORCE 50      //how much overtravel is allowed before full force is applied
                                              //like spring length
/*
   servoDrive: communicates with the servo drive, input as a force direction
*/
void servoDrive(int force) {

}
/*
    Drives the endstop, over travel as input, - as left + as right
*/
void endStopDrive(int overTravel) {
  servoDrive();
}
