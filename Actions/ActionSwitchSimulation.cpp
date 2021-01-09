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
	if (pManager->ValidateCircuit())
	{
		pManager->UnselectAll();
		UI* pUI = pManager->GetUI();
		pUI->dropdown = false;
		pUI->ClearToolBarArea();
		pUI->CreateSimulationToolBar();
	}
}

void ActionSwitchSimulation::Undo()
{}

void ActionSwitchSimulation::Redo()
{}