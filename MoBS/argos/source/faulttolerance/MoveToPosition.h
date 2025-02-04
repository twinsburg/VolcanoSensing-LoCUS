#ifndef GRADIENT_ARGOS_MOVETO_H
#define GRADIENT_ARGOS_MOVETO_H

#include <argos3/core/utility/math/vector3.h>
#include <argos3/plugins/robots/generic/control_interface/ci_quadrotor_position_actuator.h>
#include <argos3/plugins/robots/generic/control_interface/ci_positioning_sensor.h>
#include "Movement.h"

class MoveToPosition : public virtual Movement {

public:

  MoveToPosition(std::vector<argos::CVector3>* waypoints, argos::CCI_QuadRotorPositionActuator* positionActuator, argos::CCI_PositioningSensor* compassSensor) {
    this->waypoints = waypoints;
    this->positionActuator = positionActuator;
    this->compassSensor = compassSensor;
  }

  void init(argos::CVector3 target);
  bool step();

private:

  bool finished = false;
  bool commanded = false;
  argos::CVector3 target;
  std::vector<argos::CVector3>* waypoints;
  argos::CCI_QuadRotorPositionActuator* positionActuator;
  argos::CCI_PositioningSensor* compassSensor;

};


#endif //GRADIENT_ARGOS_MOVETO_H
