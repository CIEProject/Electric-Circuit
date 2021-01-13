#include "ActionSelect.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}

void ActionSelect::Execute()
{
	pUI->PrintMsg("tap to select or unselect");

	pUI->GetPointClicked(x_0, y_0);

	if (pManager->GetComponentByCordinates(x_0, y_0) == nullptr)
	{
		Cx = x_0;
		Cy = y_0;
		Old_X = Cx;
		Old_Y = Cy;

		while (123456789101112)
		{
			if (Cx < Minimum_X || Cx > Maximum_X)
			{
				Cx = Old_X;
			}
			if (Cy < Minimum_Y || Cy > Maximum_Y)
			{
				Cy = Old_Y;
			}

			{
				pUI->pWind->SetPen(WHITE);
				pUI->pWind->SetBrush(WHITE);
				pUI->pWind->DrawRectangle(Cx, y_0, Old_X, Cy, FILLED);
				pUI->pWind->DrawRectangle(x_0, Cy, Old_X, Old_Y, FILLED);
				pUI->pWind->DrawRectangle(Old_X, y_0, Cx, Cy, FILLED);
				pUI->pWind->DrawRectangle(Old_X, Cy, x_0, Old_Y, FILLED);
				pUI->pWind->DrawRectangle(Old_X, Old_Y, x_0, Cy, FILLED);
				pUI->pWind->DrawRectangle(Old_X, Cy, Cx, y_0, FILLED);
				pUI->pWind->DrawRectangle(x_0, Old_Y, Old_X, Cy, FILLED);
				pUI->pWind->DrawRectangle(Cx, Cy, Old_X, y_0, FILLED);
			}

			if (Cx != Old_X || Cy != Old_Y)
			{
				pUI->pWind->SetPen(BLACK, 2);
				pUI->pWind->DrawRectangle(x_0, y_0, Cx, Cy, FILLED);
				Old_X = Cx;
				Old_Y = Cy;
			}
			pManager->UpdateInterfaceWithoutClrDrwArea();
			if (!pUI->pWind->GetButtonState(LEFT_BUTTON, Cx, Cy) == BUTTON_DOWN)
				break;
		}

		if (Cx < Minimum_X || Cx > Maximum_X)
		{
			Cx = Old_X;
		}
		if (Cy < Minimum_Y || Cy > Maximum_Y)
		{
			Cy = Old_Y;
		}

		x_f = Cx;
		y_f = Cy;

		if (x_0 > x_f)
		{
			SwapXY(x_0, x_f);
		}
		else if (y_0 > y_f)
		{
			SwapXY(y_0, y_f);
		}
	}
	else
		for (int i = 0; i < u; i++)
		{
			x1 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[0].x;
			y1 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[0].y;
			x2 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[1].x;
			y2 = pManager->getCompList()[i]->get_m_pGfxInfo()->PointsList[1].y;

			if (x_0 > x1 && x_0 < x2 && y_0 > y1 && y_0 < y2)
			{
				x_f = x_0;
				y_f = y_0;
			}
		}

	if (x_0 == x_f && y_0 == y_f)
	{
		Component* pComp = pManager->GetComponentByCordinates(x_0, y_0);
		Connection* pConn= pManager->GetConnByCordinates(x_0, y_0);
		if (pComp != nullptr)
		{
			if (pComp->isSelected())
			{
				pComp->unSelect();
			}
			else
			{
				pComp->Select();
			}
		}
		if (pConn != nullptr)
		{
			if (pConn->isSelected())
			{
				pConn->unSelect();
			}
			else
			{
				pConn->Select();
			}
		}
	}
	else
	{
		for (int x = x_0; x <= x_f; x++)
		{
			for (int y = y_0; y <= y_f; y++)
			{
				Component* pComp = pManager->GetComponentByCordinates(x, y);
				if (pComp != nullptr)
				{
					if (!pComp->isSelected())
					{
						pComp->Select();
					}
				}
			}
		}
	}



	if (cKeyData == CTRL_A)
	{
		for (int i = 0; i < u; i++)
		{
			pManager->getCompList()[i]->Select();

		}
		for (int i = 0; i < u2; i++)
		{
			pManager->getConnList()[i]->Select();

		}
	}
	pUI->ClearStatusBar();
}

void ActionSelect::SwapXY(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void ActionSelect::Undo()
{}
void ActionSelect::Redo()
{}



























































































//#include "ActionSelect.h"
//#include "..\ApplicationManager.h"
//#include "..\UI\UI.h"
//ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
//{
//}
//
//ActionSelect::~ActionSelect(void)
//{
//}
//void ActionSelect::Execute() {
//	UI* pUI = pManager->GetUI();//Gets a pointer to the user interface
//	x = pUI->getXtemp();//Gets the coordinates which the user clicked on
//	y = pUI->getYtemp();
//	Component* comp1 = pManager->GetComponentByCordinates(x, y);
//	Connection* conn1 = pManager->GetConnByCordinates(x, y);
//	if (comp1 != nullptr){
//		
//		//pManager->UnselectAll(comp1); //this line was used to make no more than one thing to be selected
//		comp1->Selection();
//	}
//	else if (conn1 != nullptr) {
//		
//		//pManager->UnselectAll(conn1); 
//		conn1->Selection();
//	}
//
//}
//void ActionSelect::Undo()
//{}
//
//void ActionSelect::Redo()
//{}