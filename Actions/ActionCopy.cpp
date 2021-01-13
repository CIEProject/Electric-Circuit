#include"ActionCopy.h"
#include "Action.h"
#include "..\ApplicationManager.h"

ActionCopy::ActionCopy(ApplicationManager* pApp) :Action(pApp)
{
}
ActionCopy::~ActionCopy(void)
{
}

void ActionCopy::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	int u = pManager->getCompCount();
	pManager->ClearTheClipboard(); //3a4an nl8y ay 7aga kan ma3molaha copy abl kda
	if (pManager->GetNumberOfSelectedComponents())
	{
		for (int i = 0; i < u; i++)
		{
			if (pManager->getCompList()[i]->isSelected())
				pManager->CopySelectedComponent(i); //3a4an n assign el complist[i] LL list el gdyd
		}
		pUI->PrintMsg("Components were copied successfully!");
	}
	else
	{
		pUI->PrintMsg("Select Components first and then click on the copy icon");
		//PlaySound(TEXT("Computer Error Alert.mp3"), NULL, SND_FILENAME);
	}
	pManager->UpdateInterface();
}
void ActionCopy::Undo()
{
}
void ActionCopy::Redo()
{

}