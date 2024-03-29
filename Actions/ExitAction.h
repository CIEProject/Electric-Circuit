#ifndef EXIT_ACTION_H
#define EXIT_ACTION_H

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