#include "ActionDropDown3.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionDropDown3::ActionDropDown3(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDropDown3::~ActionDropDown3(void)
{
}
void ActionDropDown3::Execute()
{
	UI* pUI = pManager->GetUI();
	if (pUI->dropdown3)
		pUI->dropdown3 = false;
	else
		pUI->dropdown3 = true;
}
void ActionDropDown3::Undo()
{}

void ActionDropDown3::Redo()
{}