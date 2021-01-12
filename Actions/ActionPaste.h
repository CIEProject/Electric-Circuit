#ifndef ACTION_PASTE_H
#define ACTION_PASTE_H

#include "Action.h"
//Class responsible for adding a new resistor action
class ActionPaste : public Action
{
public:
	ActionPaste(ApplicationManager* pApp);
	virtual ~ActionPaste(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif 