#ifndef ACTION_DELETE_H
#define ACTION_DELETE_H

#include "Action.h"
//Class responsible for adding a new resistor action
class ActionDelete : public Action
{
public:
	ActionDelete(ApplicationManager* pApp);
	virtual ~ActionDelete(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif 