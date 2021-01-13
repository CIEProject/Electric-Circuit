#include <iostream>
#include <sstream>
#include <cmath>
#include "ApplicationManager.h"

int main()
{
	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;
	//bool Closed = false;

	do
	{
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the drawing window
		AppManager.UpdateInterface();
	} while (ActType != EXIT3);

	return 0;
}