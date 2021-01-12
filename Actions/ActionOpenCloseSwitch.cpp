#include "ActionOpenCloseSwitch.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionOpenCloseSwitch::ActionOpenCloseSwitch(ApplicationManager* pApp) :Action(pApp)
{
}

ActionOpenCloseSwitch::~ActionOpenCloseSwitch(void)
{
}
void ActionOpenCloseSwitch::Execute()
{
	UI* pUI = pManager->GetUI();
	int x = pUI->getXtemp();//Gets the coordinates which the user clicked on
	int y = pUI->getYtemp();
	Component* comp = pManager->GetComponentByCordinates(x, y);
	if (dynamic_cast<Switch*>(comp)) {
		comp->OpenClose();
	}



}
void ActionOpenCloseSwitch::Undo()
{}

void ActionOpenCloseSwitch::Redo()
{}