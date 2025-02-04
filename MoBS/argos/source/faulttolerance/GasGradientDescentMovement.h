#ifndef UNCOORDINATED_CD_ARGOS_GASGRADIENTDESCENTMOVEMENT_H
#define UNCOORDINATED_CD_ARGOS_GASGRADIENTDESCENTMOVEMENT_H

#include "SpiriController.h"
#include "FaultToleranceLoopFunctions.h"

class GasGradientDescentMovement : public virtual Movement {

public:
  GasGradientDescentMovement(Spiri_controller* controller,
          Gradient_loop_functions* loopFunctions,
          double previousValue,
          double previousAngle,
          CVector3 previousVector,
          int radius):
          controller(controller),
          loopFunctions(loopFunctions),
          previousValue(previousValue),
          previousAngle(previousAngle),
          previousVector(previousVector),
          radius(radius){}

  bool step();
private:
  int radius;
  Spiri_controller* controller;
  Gradient_loop_functions* loopFunctions;
  double previousValue;
  double previousAngle;
  CVector3 previousVector;
  int zeroCount = 0;
};


#endif //UNCOORDINATED_CD_ARGOS_GASGRADIENTDESCENTMOVEMENT_H
