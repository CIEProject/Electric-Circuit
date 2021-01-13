#include "ActionDropDown2.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionDropDown2::ActionDropDown2(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDropDown2::~ActionDropDown2(void)
{
}
void ActionDropDown2::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->dropdown1 = false;
	pUI->dropdown3 = false;
	if (pUI->dropdown2)
		pUI->dropdown2 = false;
	else
		pUI->dropdown2 = true;
}
void ActionDropDown2::Undo()
{}

void ActionDropDown2::Redo()
{}