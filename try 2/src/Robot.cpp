#include "WPILib.h"

class Robot: public IterativeRobot
{

	RobotDrive myRobot = new Talon(0, 1); // robot drive system
	Joystick stick = new Joystick(1); // only joystick
	Talon Elevator = new Talon(2);
	LiveWindow *lw;
	int autoLoopCounter;

public:
	Robot() :
		myRobot(0, 1), // must be intialized in same order
		stick(1),
		Elevator(2),
		lw(NULL),
		autoLoopCounter(0)
	{
		myRobot.SetExpiration(0.1);
	}

private:
	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
	}

	void AutonomousInit()
	{
		autoLoopCounter = 0;
	}

	void AutonomousPeriodic()
	{
		if(autoLoopCounter < 2) //Check if we've completed 100 loops (approximately 2 seconds)
		{
			myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
			autoLoopCounter++;
			} else {
			myRobot.Drive(0.0, 0.0); 	// stop robot
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic(void)
	{
		myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
		if (stick.GetTrigger == 1) //raise the elevator
		{
				Elevator.Set(-0.7);
		}
		else if (stick.GetTrigger == 0)
		{
				Elevator.Set(0.0);
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
