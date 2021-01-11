#pragma once
#include "Action.h"
#include "..\Components\Module1.h"
#include "..\Components\Module2.h"
#include "..\Components\Module3.h"
#include "..\Components\Module4.h"


//Class responsible for adding a new resistor action
class ActionAddModule1 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int ModuleNum;
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddModule1(ApplicationManager* pApp,int Num=1);
	virtual ~ActionAddModule1(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};