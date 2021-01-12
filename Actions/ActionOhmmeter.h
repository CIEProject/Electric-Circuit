#pragma once
#include "Action.h"

class ActionOhmmeter : public Action
{
public:
	ActionOhmmeter(ApplicationManager* pApp);
	~ActionOhmmeter();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
private:
	int x, y;
};