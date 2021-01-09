#ifndef ACTION_SWITCH_SIMU_H
#define ACTION_SWITCH_SIMU_H

#include "Action.h"

class ActionSwitchSimulation : public Action
{
public:
	ActionSwitchSimulation(ApplicationManager* pApp);
	virtual ~ActionSwitchSimulation(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif