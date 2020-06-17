#include "main.h"
#include "../include/scripts/test_auto.h"
using namespace okapi;

//taken from the pros website to experiment with std::make_unique syntax

std::shared_ptr<ChassisController> myChassis =
  ChassisControllerBuilder().withMotors({1, 2}, {-3, -4})
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .build();

std::shared_ptr<AsyncMotionProfileController> profileController =
  AsyncMotionProfileControllerBuilder()
    .withLimits({
      1.0, // Maximum linear velocity of the Chassis in m/s
      2.0, // Maximum linear acceleration of the Chassis in m/s/s
      10.0 // Maximum linear jerk of the Chassis in m/s/s/s
    })
    .withOutput(myChassis)
    .buildMotionProfileController();

void testAutonomous() { 
    
}