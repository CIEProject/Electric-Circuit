#include "ActionMultimeter.h"
#include "..\ApplicationManager.h"
#include "ActionOhmmeter.h"
#include "..\Components\Battery.h"
#include "..\Components\Bulb.h"
#include "..\Components\Buzzer.h"
#include "..\Components\Fuze.h"
#include "..\Components\Ground.h"
#include "..\Components\Resistor.h"
#include "..\Components\Switch.h"
#include "..\UI\UI.h"

ActionOhmmeter::ActionOhmmeter(ApplicationManager* pApp) :Action(pApp)
{
}

ActionOhmmeter::~ActionOhmmeter()
{
}

void ActionOhmmeter::Execute()
{
	UI* pUI = pManager->GetUI();
	pManager->GetUI()->PrintMsg("Select a component: ");
	pUI->GetPointClicked(x, y);
	Component* pComp = pManager->GetComponentByCordinates(x, y);
	//double
	int resistance = pComp->getResistance();
	if (pComp != nullptr)
		pUI->PrintMsg("The resistance = " + to_string(resistance));
}
void ActionOhmmeter::Undo()
{}
void ActionOhmmeter::Redo()
{}