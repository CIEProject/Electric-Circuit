#ifndef ACTION_COPY_H
#define ACTION_COPY_H

#include "Action.h"
//Class responsible for adding a new resistor action
class ActionCopy : public Action
{
public:
	ActionCopy(ApplicationManager* pApp);
	virtual ~ActionCopy(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif 