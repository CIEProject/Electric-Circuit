#pragma once
#include "Action.h"
#include "..\Components\Switch.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"

class ActionSelect :public Action
{
private:
	UI* pUI = pManager->GetUI();

	int Cx, Cy, x1, x2, y1, y2, x_0, x_f, y_0, y_f, Old_X, Old_Y, Minimum_X = 5, Maximum_X = 1180,
		Minimum_Y = 100, Maximum_Y = 590, u = pManager->getCompCount(),u2= pManager->getConnCount();

	char cKeyData;
	
	keytype Button = pUI->pWind->GetKeyPress(cKeyData);



public:
	ActionSelect(ApplicationManager* pApp);
	virtual ~ActionSelect(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	void SwapXY(int&, int&);
};



















//#ifndef ACTION_SELECT_H
//#define ACTION_SELECT_H
//
//#include "Action.h"
//#include "..\Components\Component.h"
//
//class ActionSelect : public Action
//{
//private:
//
//	int x, y;
//
//public:
//	ActionSelect(ApplicationManager* pApp);
//	virtual ~ActionSelect(void);
//
//	//Execute action (code depends on action type)
//	virtual void Execute();
//
//	virtual void Undo();
//	virtual void Redo();
//};
//#endif