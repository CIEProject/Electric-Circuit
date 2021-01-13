#include "ActionSwitchSimulation.h"
#include "..\ApplicationManager.h"

ActionSwitchSimulation::ActionSwitchSimulation(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSwitchSimulation::~ActionSwitchSimulation(void)
{
}

void ActionSwitchSimulation::Execute()
{
	pManager->ToSimulation();
}

void ActionSwitchSimulation::Undo()
{}

void ActionSwitchSimulation::Redo()
{}