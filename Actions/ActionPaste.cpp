#include "ActionPaste.h"
#include "..\ApplicationManager.h"
#include "../Components/Fuze.h"
#include "../Components/Bulb.h"
#include "../Components/Buzzer.h"
#include "../Components/Battery.h"
#include "../Components/Ground.h"
#include "../Components/Resistor.h"
#include "../Components/Switch.h"
#include <cmath>
using namespace std;
ActionPaste::ActionPaste(ApplicationManager* pApp) : Action(pApp)
{
}
ActionPaste::~ActionPaste(void)
{
}
void ActionPaste::Undo()
{
}
void ActionPaste::Redo()
{
}


/// The excute action has to be modified
void ActionPaste::Execute()
{
	UI* pUI = pManager->GetUI();
	int X, x, y, Y;
	int CONTINUE = 1;
	int** Positions, Rows, Columns;
	Rows = 4;
	Columns = pManager->getNumberOfCopiedComponents();
	Positions = new int* [Rows];
	for (int Row = 0; Row < Rows; Row++)
	{
		Positions[Row] = new int[Columns];
	}
	int* PositionsArr = new int[4];
	int AllFit = 0;
	if (pManager->getNumberOfCopiedComponents())
	{
		pUI->PrintMsg("Click anywhere in the drawing area to paste the components");
		while (CONTINUE)
		{
			pUI->GetPointClicked(Cx, Cy);
			if (Cx >= 20 && Cx <= 1200 && Cy >= 100 && Cy <= 650)
			{
				pUI->PrintMsg("If you want to cancel the paste action, press on ESCAPE key");
				keytype Button;
				char cKeyData;
				Button = pUI->pWind->GetKeyPress(cKeyData);
				if (Button == ESCAPE)
					break;
				else
				{
					x = 1200, y = 650; //x m4 ha ynfa3 tkon akbar men 1200, wala el y akbar men 650
					for (int i = 0; i < pManager->getNumberOfCopiedComponents(); i++)
					{
						X = pManager->getListOfCopiedComponents()[i]->getCompCenterX(pUI);
						Y = pManager->getListOfCopiedComponents()[i]->getCompCenterY(pUI);
						if (X <= x && Y <= y)
						{
							x = X, y = Y;
						}
					}
					//kda m3aya el center (x,y) bta3 awel component 3ala el 4mal
					int OldCenter_x, OldCenter_y;
					int NewCenter_x, NewCenter_y;
					int compWidth = pUI->getCompWidth();
					int compHeight = pUI->getCompHeight();
					int u = pManager->getCompCount();
					pManager->CreateACopyOfCopiedComponents();
					for (int i = 0; i < pManager->getNumberOfCopiedComponents(); i++)
					{
						OldCenter_x = pManager->getListOfCopiedComponents()[i]->getCompCenterX(pUI);
						OldCenter_y = pManager->getListOfCopiedComponents()[i]->getCompCenterY(pUI);

						NewCenter_x = Cx + abs(x - OldCenter_x);
						NewCenter_y = Cy + abs(y - OldCenter_y);


						GraphicsInfo* pCompGInfo = new GraphicsInfo(2);
						pCompGInfo->PointsList[0].x = NewCenter_x - compWidth / 2;
						pCompGInfo->PointsList[1].x = NewCenter_x + compWidth / 2;
						pCompGInfo->PointsList[0].y = NewCenter_y - compHeight / 2;
						pCompGInfo->PointsList[1].y = NewCenter_y + compHeight / 2;

						PositionsArr[0] = pCompGInfo->PointsList[0].x;
						PositionsArr[1] = pCompGInfo->PointsList[1].x;
						PositionsArr[2] = pCompGInfo->PointsList[0].y;
						PositionsArr[3] = pCompGInfo->PointsList[1].y;
			
						for (int Row = 0; Row < Rows; Row++)
						{
							Positions[Row][i] = PositionsArr[Row];
						}
					}
									
					for (int i = 0; i < pManager->getNumberOfCopiedComponents(); i++)
					{
			
						if (Positions[0][i] >= 0 && Positions[1][i] <= 1200 && Positions[2][i] >= 0 && Positions[3][i] <= 650)
							AllFit++;
					}

					if (AllFit == pManager->getNumberOfCopiedComponents())
					{
						for (int i = 0; i < pManager->getNumberOfCopiedComponents(); i++)
						{
							GraphicsInfo* pNEWGInfo = new GraphicsInfo(2);
							pNEWGInfo->PointsList[0].x = Positions[0][i];
							pNEWGInfo->PointsList[1].x = Positions[1][i];
							pNEWGInfo->PointsList[0].y = Positions[2][i];
							pNEWGInfo->PointsList[1].y = Positions[3][i];

							if (dynamic_cast<Battery*>(pManager->getListOfCopiedComponents()[i]))
							{
								Battery* pBattery = new Battery(pNEWGInfo);
								pManager->AddComponent(pBattery);
							}
							else if (dynamic_cast<Bulb*>(pManager->getListOfCopiedComponents()[i]))
							{
								Bulb* pBulb = new Bulb(pNEWGInfo);
								pManager->AddComponent(pBulb);
							}
							else if (dynamic_cast<Buzzer*>(pManager->getListOfCopiedComponents()[i]))
							{
								Buzzer* pBuzzer = new Buzzer(pNEWGInfo);
								pManager->AddComponent(pBuzzer);
							}
							else if (dynamic_cast<Fuze*>(pManager->getListOfCopiedComponents()[i]))
							{
								Fuze* pFuze = new Fuze(pNEWGInfo);
								pManager->AddComponent(pFuze);
							}
							else if (dynamic_cast<Ground*>(pManager->getListOfCopiedComponents()[i]))
							{
								Ground* pGround = new Ground(pNEWGInfo);
								pManager->AddComponent(pGround);
							}
							else if (dynamic_cast<Resistor*>(pManager->getListOfCopiedComponents()[i]))
							{
								Resistor* pResistor = new Resistor(pNEWGInfo);
								pManager->AddComponent(pResistor);
							}
							else if (dynamic_cast<Switch*>(pManager->getListOfCopiedComponents()[i]))
							{
								Switch* pSwitch = new Switch(pNEWGInfo);
								pManager->AddComponent(pSwitch);
							}
						}
					}
					else
					{
						pUI->PrintMsg("Cannot Paste Here!");
						pUI->PrintMsg("Choose another point");
						break;
					}
					CONTINUE = 0;
				}
			}
			else
			{
				pUI->PrintMsg("Cannot paste outside the drawing area");
			
			}
		}
	}
	else
	{
		//Law el condition btae3 if kan false
		pUI->PrintMsg("No copied or cutted components to paste!!");
		//PlaySound(TEXT(), NULL, SND_FILENAME);
	}
	pManager->UpdateInterface();
}