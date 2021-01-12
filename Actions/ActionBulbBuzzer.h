#pragma once
#include "Action.h"
#include "..\Components\Component.h"
class ActionBulbBuzzer : public Action
{
private:
	int counter = 0, buzzeresNum = 0, switchesNum = 0, batteriesNum = 0;
public:
	ActionBulbBuzzer(ApplicationManager* pApp);
	virtual ~ActionBulbBuzzer(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};