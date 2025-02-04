#ifndef SPIRI_CONTROLLER_H_
#define SPIRI_CONTROLLER_H_

#include <argos3/core/control_interface/ci_controller.h>
#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/utility/math/rng.h>
#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/math/ray3.h>
#include <argos3/core/simulator/loop_functions.h>
#include <argos3/plugins/robots/generic/control_interface/ci_quadrotor_position_actuator.h>
#include <argos3/plugins/robots/generic/control_interface/ci_positioning_sensor.h>
#include <stdlib.h>
#include "MovementVector.h"
#include "MoveToPosition.h"
#include "Delay.h"
#include "SwarmManager.h"
#include "ControllerBase.h"
#include "PositionReading.h"
#include <math.h>

using namespace argos;
using namespace std;

class Spiri_controller : public CCI_Controller, public CLoopFunctions, public virtual ControllerBase {

public:
  void Init(TConfigurationNode& node);
  void ControlStep();
  bool IsFinished();
  void Reset();
  void Setup(int id, SwarmLocation *location, std::vector<Spiri_controller*>* controllers, SwarmManager* swarmManager);
  void SetupHeir();
  void fail();
  void Balance();
  Spiri_controller* RemoveLeaf();
  void Insert(Spiri_controller *child);
  void AddRecursiveWaypoint(CVector3 waypoint);
  void AddMovement(Movement *move);
  MoveToPosition* CreateOffsetMovement(CVector3 waypoint, CVector3 offsetPosition);
  int GetMinimumDepth();
  int GetMaximumDepth();
  void replace(Spiri_controller *target);
  bool failureDetected();
  void SetupParentHeir();
  bool IsFailed() {return failed;}
  std::vector<PositionReading> getReadings(int depth);
  PositionReading GetReading();
  void AddWaitForChildren(vector<Spiri_controller *> *pVector);
  int GetSwarmSize();
  int GetSwarmSize(int depth);
  Spiri_controller *getParentController();
  vector<Spiri_controller *> getChildrenControllers();

  Spiri_controller *heir = NULL;
  int id;
  bool failed = false;
  bool processedFail = false;
  SwarmLocation *location;
  SwarmManager* swarmManager;

private:

  bool finished = false;
  MovementVector* movement;
  argos::CCI_PositioningSensor* compassSensor;
  argos::CCI_QuadRotorPositionActuator* positionActuator;
  std::vector<Spiri_controller*>* controllers;
  void setupPosition();
  Spiri_controller* GetHeir();
  Spiri_controller* GetSuccessor();
  Spiri_controller* GetPredecessor();
  Spiri_controller* leftmost();
  Spiri_controller* rightmost();

};

#endif /* SPIRI_CONTROLLER_H_ */