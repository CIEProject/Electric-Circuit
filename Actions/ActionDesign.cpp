#include "ActionDesign.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"


ActionDesign::ActionDesign(ApplicationManager* pApp) :Action(pApp)
{

}

ActionDesign::~ActionDesign()
{

}

void ActionDesign::Execute()
{
	UI* pUI = pManager->GetUI();		//Get a pointer to the user interface
	pUI->CreateDesignToolBar();			//Draws the design tool bar
}

void ActionDesign::Undo()
{}

void ActionDesign::Redo()
{}