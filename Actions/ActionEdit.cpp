#include "ActionEdit.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include<string>  
ActionEdit::ActionEdit(ApplicationManager* pApp) :Action(pApp)
{
}

ActionEdit::~ActionEdit(void)
{
}
void ActionEdit::Execute()
{
	UI* pUI = pManager->GetUI();
	pManager->UpdateInterface();
	pUI->PrintMsg("Select the component/connection you wish to Edit");
	int x, y;


	/// ///////////
	pUI->GetPointClicked(x, y);
	Component* comp1 = pManager->GetComponentByCordinates(x,y);
	Connection* conn1 = pManager->GetConnByCordinates(x, y);
	/*while (comp1 == nullptr && conn1 == nullptr) {
		pUI-> GetPointClicked(x, y);
		pUI->PrintMsg("Select the compnent/Connection you want to edit");
	}*/
	// // // // // // / //
		pUI->ClearStatusBar();
		comp1 = pManager->GetComponentByCordinates(x, y);
		conn1 = pManager->GetConnByCordinates(x, y);
		if (comp1 != nullptr) {
			comp1->Edit(pUI);
		}
		else if (conn1 != nullptr) {
		
		string value;
		int intValue;
		do {
			value = pUI->GetSrting("enter 1 to edit the label,2 to change terminals or 3 to cancel ", "");
		} while (value != "1" && value != "2" && value != "3");
		intValue = stod(value);
		switch (intValue) {
		case 1:
		{

			value = pUI->GetSrting(conn1->getLabel(), conn1->getLabel());
			conn1->setLabel(value);
			break;
		}
		case 2: {
			int x, y;
			GraphicsInfo* G = new GraphicsInfo(2);
			G = conn1->getgraphics();
			pUI->PrintMsg("Select the Terminal which you want to change");
			pUI->GetPointClicked(x, y);
			pUI->ClearStatusBar();
			Component* tempComp1 = pManager->GetComponentByCordinates(x, y);
			Component* tempComp2;
			if (tempComp1 != nullptr) {
				int compnum = conn1->WhichComp(tempComp1);
				if (compnum != 0) {
					pUI->PrintMsg("Select the new Component you want to connect to: ");
					pUI->GetPointClicked(x, y);
					pUI->ClearStatusBar();
					tempComp2 = pManager->GetComponentByCordinates(x, y);
					if (tempComp2 != nullptr) {
						tempComp1->deletecon(conn1);
						if (x > tempComp2->getCompCenterX(pUI)) {
							tempComp2->addTerm2Conn(conn1);
							G->PointsList[compnum - 1].x = tempComp2->getCompCenterX(pUI) + (pUI->getCompWidth() / 2);
							G->PointsList[compnum - 1].y = tempComp2->getCompCenterY(pUI);
						}
						else {
							tempComp2->addTerm1Conn(conn1);
							G->PointsList[compnum - 1].x = tempComp2->getCompCenterX(pUI) - (pUI->getCompWidth() / 2);
							G->PointsList[compnum - 1].y = tempComp2->getCompCenterY(pUI);

						}
						conn1->setNewComp(compnum, tempComp2);
					}
				}
			}
			break;
		}
		case 3:
			break;
		}
		}
	pUI->ClearStatusBar();
}
void ActionEdit::Undo()
{}

void ActionEdit::Redo()
{}