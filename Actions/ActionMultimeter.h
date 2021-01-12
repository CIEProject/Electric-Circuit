#pragma once
#include "Action.h"

class ActionMultimeter : public Action
{
public:
	ActionMultimeter(ApplicationManager* pApp);
	~ActionMultimeter();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
private:
	int x, y;
};