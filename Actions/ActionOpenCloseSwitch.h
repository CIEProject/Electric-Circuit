#ifndef ACTIONOPENCLOSESWITCH_H
#define ACTIONOPENCLOSESWITCH_H

#include "..\Components\Component.h"
#include "..\Components\Switch.h"
#include "Action.h"
//Class responsible for adding a new resistor action
class ActionOpenCloseSwitch : public Action
{
public:
	ActionOpenCloseSwitch(ApplicationManager* pApp);
	virtual ~ActionOpenCloseSwitch(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif
