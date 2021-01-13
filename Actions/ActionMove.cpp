#include "ActionMove.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"

ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{
}

ActionMove::~ActionMove(void)
{
}

void ActionMove::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Click on the component you want to drag.");
	keytype Button;
	char cKeyData;
	Button = pUI->pWind->GetKeyPress(cKeyData);
	int x1, y1, x2, y2;
	int u = pManager->getCompCount();
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	pUI->GetPointClicked(Cx, Cy);
	CompIndex = -1;
	while (Button != 4)
	//while (pUI->pWind->GetMouseClick(Cx, Cy) == NO_CLICK)
	{
		for (int i = 0; i < u; i++)
		{
			x1 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[0].x;
			y1 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[0].y;
			x2 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[1].x;
			y2 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[1].y;

			if (Cx > x1 && Cx < x2 && Cy > y1 && Cy < y2)
			{
				CompIndex = i;
			}
		}
		if (CompIndex == -1)
			break;
		if (pManager->getCompList()[CompIndex]->isSelected())
			pManager->getCompList()[CompIndex]->unSelect();
		
		Button = pUI->pWind->GetKeyPress(cKeyData);
		
		pManager->GetUI()->pWind->SetPen(WHITE);
		pManager->GetUI()->pWind->GetMouseCoord(Cx, Cy);
		
		if (Cx >= 30 && Cx <= 1160 && Cy >= 107 && Cy <= 574)
		{
			{
				pManager->GetUI()->pWind->DrawRectangle(pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[0].x,
					pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[0].y,
					Cx - compWidth / 2, Cy + compHeight / 2);
				pManager->GetUI()->pWind->DrawRectangle(Cx - compWidth / 2,
					pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[0].y,
					Cx + compWidth / 2, Cy - compHeight / 2);
				pManager->GetUI()->pWind->DrawRectangle(pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[0].x,
					Cy - compHeight / 2, Cx - compWidth / 2, pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[1].y);
				pManager->GetUI()->pWind->DrawRectangle(Cx - compWidth / 2, Cy + compHeight / 2, Cx + compWidth / 2,
					pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[1].y);
				pManager->GetUI()->pWind->DrawRectangle(Cx + compWidth / 2, Cy - compHeight / 2,
					pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[1].x,
					pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[1].y);
				pManager->GetUI()->pWind->DrawRectangle(Cx + compWidth / 2,
					pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[0].y,
					pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[1].x, Cy + compHeight / 2);
			}
			{
				pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[0].x = Cx - compWidth / 2;
				pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[0].y = Cy - compHeight / 2;
				pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[1].x = Cx + compWidth / 2;
				pManager->getCompList()[CompIndex]->get_m_pGfxInfo()->PointsList[1].y = Cy + compHeight / 2;
			}
		}
		
		pManager->UpdateInterfaceWithoutClrDrwArea();
		
	}
	if(CompIndex!=-1)
		pManager->getCompList()[CompIndex]->UpdateConnsGraphics(pUI);
	pUI->ClearStatusBar();
	pManager->UpdateInterface();
}











	/*UI* pUI = pManager->GetUI();
	int X, x, y, Y;
	int AllFit = 0;
	int u = pManager->getCompCount();
	int *NewCenterX = new int[pManager->getNumberOfMovingComponents()];
	int *NewCenterY = new int[pManager->getNumberOfMovingComponents()];
	int OldCenter_x, OldCenter_y;
	int NewCenter_x, NewCenter_y;
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	pManager->ClearListOfMovingComponents();
	//clicktype MouseClick;
	keytype Button;
	char cKeyData;
	Button = pUI->pWind->GetKeyPress(cKeyData);
	/*pUI->PrintMsg("Select the component(s) you want to move");
	Sleep(1000);
	pUI->PrintMsg("You have 10 seconds to select the component(s) you want to move");
	Sleep(1000);
	for (int i = 10; i > 0; i--)
	{
		pUI->PrintMsg(to_string(i));
		Sleep(1000);
	}
	pUI->PrintMsg("MOVE!!");*/

	/*for (int i = 0; i < u; i++)
	{
		int x1 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[0].x;
		int y1 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[0].y;
		int x2 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[1].x;
		int y2 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[1].y;

		if (Cx > x1 && Cx < x2 && Cy > y1 && Cy < y2)
		{
			if (pManager->getCompList()[i]->isSelected == false)
			{
				pManager->getCompList()[i]->isSelected = true;
				break;
			}
			if (pManager->getCompList()[i]->isSelected == true)
			{
				pManager->getCompList()[i]->isSelected = false;
				break;
			}
		}

	}*/
	/*if (pManager->GetNumberOfSelectedComponents())
	{
		for (int i = 0; i < u; i++)
			if (pManager->getCompList()[i]->isSelected) pManager->MoveComponents(i);
		do {
			//MouseClick = pUI->pWind->GetMouseClick(Cx, Cy);
			pUI->pWind->GetMouseCoord(Cx, Cy);
			//MouseClick = pUI->pWind->GetButtonState(LEFT_BUTTON, x, y);
			if (Cx >= 30 && Cx <= 1150 && Cy >= 110 && Cy <= 570)
			{
				pUI->PrintMsg("If you want to cancel the moving action, press on ESCAPE key");
				keytype Button;
				char cKeyData;
				Button = pUI->pWind->GetKeyPress(cKeyData);
				if (Button == ESCAPE)
					break;
				else
				{
					x = 1200, y = 650;
					//Sleep(1000);
					for (int i = 0; i < pManager->getNumberOfMovingComponents(); i++)
					{
						X = (pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].x +
							pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[1].x) / 2;
						Y = (pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].y +
							pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[1].y) / 2;
						if (X <= x && Y <= y)
						{
							x = X, y = Y;
						}
					}
					for (int i = 0; i < pManager->getNumberOfMovingComponents(); i++)
					{
						OldCenter_x = (pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].x
							+ pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[1].x) / 2;
						OldCenter_y = (pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].y
							+ pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[1].y) / 2;
						NewCenter_x = Cx + abs(x - OldCenter_x);
						NewCenter_y = Cy + abs(y - OldCenter_y);
						NewCenterX[i] = NewCenter_x;
						NewCenterY[i] = NewCenter_y;
					}
					/*for (int i = 0; i < pManager->getNumberOfMovingComponents(); i++)
					{
						/*if (pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].x >= 0
							&& pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].x <= 1200
							&& pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].y >= 0
							&& pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[1].y <= 650)*/
						/*if (NewCenterX[i] >= compWidth / 2 && NewCenterX[i] <= 1175 && NewCenterY[i] >= compHeight / 2
							&& NewCenterY[i] <= 625)
							AllFit++;
					}*/
					/*AllFit = pManager->getNumberOfMovingComponents();
					if (AllFit == pManager->getNumberOfMovingComponents())
					{
						for (int i = 0; i < pManager->getNumberOfMovingComponents(); i++)
						{
							pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].x
								= NewCenterX[i] - compWidth / 2;
							pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[1].x
								= NewCenterX[i] + compWidth / 2;
							pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[0].y
								= NewCenterY[i] - compHeight / 2;
							pManager->getListOfMovingComponents()[i]->get_m_pGfxInfo()->PointsList[1].y
								= NewCenterY[i] + compHeight / 2;
						}
					}
					else
					{
						pUI->PrintMsg("Cannot Move Components to this location! Choose another location");
						break;
					}
				}
			}
			//pManager->UpdateInterface();
		} while (Button != ESCAPE);//Button != ESCAPE);
	}
	else
	{
		pUI->PrintMsg("Select Components first and then click on the move icon");
		//PlaySound(TEXT("Computer Error Alert.mp3"), NULL, SND_FILENAME);
	}
	pManager->UpdateInterface();
}
*/




void ActionMove::Undo()
{
}
void ActionMove::Redo()
{
}
