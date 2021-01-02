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
		pManager->GetUI()->ClearStatusBar();
		pManager->GetUI()->GetSrting("Total resistance is "+to_string(pManager->calculateNetResistance()));
		pManager->GetUI()->GetSrting("Total voltage is "+to_string(pManager->calculateNetVoltage()));
		pManager->calculateTermsVoltage();
	}

}

void ActionSwitchSimulation::Undo()
{}

void ActionSwitchSimulation::Redo()
{}