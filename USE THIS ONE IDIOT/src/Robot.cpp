#include "WPILib.h"

class Robot: public IterativeRobot
{

	RobotDrive myRobot; // robot drive system
	Joystick *stick; // only joystick
	Joystick *stick2;
	Talon talon;// the one pwm controller for the elevator
	LiveWindow *lw;
	int autoLoopCounter;

public:
	Robot() :
		myRobot(0, 1), // must be intialized in same order
		stick(1),     // ports are called here , and space if more than one port
		stick2(2),
		talon(2),
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
	{  // still work in progress
		if(autoLoopCounter < 2) //Check if we've completed the loops 100 loops= 1 second
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
	{  //works
		myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
		talon.Set(0.5);

		{
		lw->Run();
		}

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
