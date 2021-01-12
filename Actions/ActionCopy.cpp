#include "ActionCopy.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionCopy::ActionCopy(ApplicationManager* pApp) :Action(pApp)
{
}

ActionCopy::~ActionCopy(void)
{
}
void ActionCopy::Execute()
{
	pManager->GetUI()->PrintMsg("Test");

	
	
}
void ActionCopy::Undo()
{}

void ActionCopy::Redo()
{}