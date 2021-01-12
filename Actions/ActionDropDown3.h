#ifndef ActionDropDown3_H
#define ActionDropDown3_H
#include "Action.h"

//Class responsible for adding a new resistor action
class ActionDropDown3 : public Action
{
public:
	ActionDropDown3(ApplicationManager* pApp);
	virtual ~ActionDropDown3(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionDropDown3::Undo();

	virtual void ActionDropDown3::Redo();
};
#endif
