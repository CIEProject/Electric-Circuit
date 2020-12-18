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

	if (pManager->ValidateCircuit()) {
		pManager->GetUI()->GetSrting("this is only a test for the validation technique, press enter to continue","");
	}

}

void ActionSwitchSimulation::Undo()
{}

void ActionSwitchSimulation::Redo()
{}