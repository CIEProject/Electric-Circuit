#include "ActionDropDown.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionDropDown::ActionDropDown(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDropDown::~ActionDropDown(void)
{
}
void ActionDropDown::Execute()
{
	UI* pUI = pManager->GetUI();
	if (pUI->dropdown1)
		pUI->dropdown1 = false;
	else
		pUI->dropdown1 = true;
}
void ActionDropDown::Undo()
{}

void ActionDropDown::Redo()
{}