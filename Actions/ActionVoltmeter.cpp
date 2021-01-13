#include "ActionVoltmeter.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"

ActionVoltmeter::ActionVoltmeter(ApplicationManager* pApp) :Action(pApp)
{
}

ActionVoltmeter::~ActionVoltmeter()
{
}

void ActionVoltmeter::Execute()
{
	UI* pUI = pManager->GetUI();
	pManager->GetUI()->PrintMsg("Select a component: ");
	pUI->GetPointClicked(x, y);
	Component* pComp = pManager->GetComponentByCordinates(x, y);
	//double current = pManager->CalculateCurrent();
	//double voltage = pManager->calculateNetVoltage();
	if (pComp != nullptr) {
	double	v2= pComp->getTerm2Volt();
	double	v1 = pComp->getTerm1Volt();
		pUI->PrintMsg("The voltage = " + to_string(v1-v2));
	}
}
void ActionVoltmeter::Undo()
{}
void ActionVoltmeter::Redo()
{}