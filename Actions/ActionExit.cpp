#include "ActionExit.h"
#include "ExitAction.h"
ActionExit::ActionExit(ApplicationManager* pApp) : Action(pApp)
{
}

ActionExit::~ActionExit()
{
	CircuitFile.close();
}

void ActionExit::Execute()
{
	UI* pUI = pManager->GetUI();
	bool isOpen = false;
	bool isSaved = false;
	CircuitFile.open("AutoSavedCircuit.cir");
	CircuitFile.clear();
	pManager->SaveCircuit(CircuitFile);
	CircuitFile << "END_OF_FILE\n";
	CircuitFile.close();

	ifstream SavedCircuit, UnSavedCircuit;

	SavedCircuit.open("Circuit.cir");
	UnSavedCircuit.open("AutoSavedCircuit.cir");

	if (!SavedCircuit.is_open() || !UnSavedCircuit.is_open())
	{
		isOpen = true;
	}

	string StringInSavedCircuit, StringInUnSavedCircuit;

	while (!SavedCircuit.eof() && !UnSavedCircuit.eof())
	{
		getline(SavedCircuit, StringInSavedCircuit);
		getline(UnSavedCircuit, StringInUnSavedCircuit);

		if (StringInSavedCircuit != StringInUnSavedCircuit)
		{
			isSaved = true;
			SavedCircuit.close();
			UnSavedCircuit.close();
			break;
		}

	}

	SavedCircuit.close();
	UnSavedCircuit.close();

	if (isSaved)
	{
		Dialog_Box dialog("Do you want to save changes to Circuit?", YESNOCANCELDIALOG);

		Dialog_Box_Button DType = dialog.MouseClick();

		if (DType == Dialog_Box_Button::YES)
		{
			Action* pAct1 = new ActionSave(this->pManager);
			pAct1->Execute();
			delete pAct1;
			system("Circuit.cir");
			pManager->Closed = true;

		}
		else if (DType == Dialog_Box_Button::NO)
		{
			pManager->Closed = true;
		}
	}
}

void ActionExit::Undo()
{
}
void ActionExit::Redo()
{
}
