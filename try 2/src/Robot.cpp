#include "WPILib.h"

class Robot: public IterativeRobot
{

	RobotDrive myRobot; // robot drive system
	Joystick *stick; // only joystick
	Talon *rightDrive;
	Talon *leftDrive;
	LiveWindow *lw;
	int autoLoopCounter;

public:
	RobotDemo(void) :
		myRobot(1, 2),	// these must be initialized in the same order
		stick = new Joystick(1);		// as they are declared above.
		rightDrive = new Talon(1);
		leftDrive = new Talon(2)
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
		if(autoLoopCounter < 100) //Check if we've completed 100 loops (approximately 2 seconds)
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
		myRobot.ArcadeDrive(stick->GetRawAxis(Yaxis); // drive with arcade style (use right stick)
		myRobot.ArcadeDrive(stick->GetRawAxis(Xaxis);
		myRobot.ArcadeDrive(SetSpeed(Y);
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
