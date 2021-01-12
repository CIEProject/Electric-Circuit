#ifndef ACTION_CUT_H
#define ACTION_CUT_H

#include "Action.h"
//Class responsible for adding a new resistor action
class ActionCut : public Action
{
public:
	ActionCut(ApplicationManager* pApp);
	virtual ~ActionCut(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif 