/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Arm.h"

Arm::Arm() : Subsystem("ExampleSubsystem"), armMotor(new TalonSRX(5))
 {
   armMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute);
  armMotor->SetSensorPhase(true);
  armMotor->SetSelectedSensorPosition(0);

   armMotor->Config_kP(0, 0.1);
   armMotor->Config_kI(0, 0);
   armMotor->Config_kD(0, 0);
   armMotor->Config_kF(0, 0);
    absolutePosition = armMotor->GetSelectedSensorPosition(0) & 0xFFF;
    armMotor->SetSelectedSensorPosition(absolutePosition);
 }

void Arm::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Arm::moveArm(double set) {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  
  armMotor->Set(ControlMode::Position, set);

}

TalonSRX* Arm::getArmMotor() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  return armMotor;
}

double Arm::getArmPosition() {
  armMotor->GetSelectedSensorPosition();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
