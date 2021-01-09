#ifndef ACTION_LOAD_H
#define ACTION_LOAD_H
#include "Action.h"
#include"..\Components\Component.h"
#include <fstream>
class ActionLoad : public Action
{
private:
	ifstream file;
public:
	ActionLoad(ApplicationManager* pApp);
	virtual ~ActionLoad(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif