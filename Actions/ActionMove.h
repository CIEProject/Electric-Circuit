#pragma once
#include "Action.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

//#include "\Components\Switch.h"

class ActionMove :public Action
{
private:
	int Cx, Cy, CompIndex = 0;
public:
	ActionMove(ApplicationManager* pApp);
	~ActionMove(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};