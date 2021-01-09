#ifndef ACTION_EXIT_H
#define ACTION_EXIT_H

#include "Action.h"
class ExitAction : public Action
{
public:
	ExitAction(ApplicationManager* pApp);
	virtual ~ExitAction(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif