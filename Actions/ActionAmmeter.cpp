#include "ActionAmmeter.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"

ActionAmmeter::ActionAmmeter(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAmmeter::~ActionAmmeter()
{
}

void ActionAmmeter::Execute()
{
	UI* pUI = pManager->GetUI();		//Get a Pointer to the user Interface
	pManager->GetUI()->PrintMsg("Select a component: ");		//Prints a message to user	
	pUI->GetPointClicked(x, y);		//Get the coordinates of the user click
	Component* pComp = pManager->GetComponentByCordinates(x, y);		//Gets the component which the user clicked on
	if (pComp != nullptr)		//A condition to assure that the user chose a component
		pManager->GetUI()->PrintMsg("The current = " + to_string(pManager->CalculateCurrent()));	//Prints the value of the electric current
	else
		pManager->GetUI()->ClearStatusBar();
}

void ActionAmmeter::Undo()
{}

void ActionAmmeter::Redo()
{}