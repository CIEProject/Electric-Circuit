#include "ActionSwitchSimulation.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"


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
		UI* pUI = pManager->GetUI();
		pUI->ClearToolBar();
		pUI->CreateSimulationToolBar();
	}

}

void ActionSwitchSimulation::Undo()
{}

void ActionSwitchSimulation::Redo()
{}