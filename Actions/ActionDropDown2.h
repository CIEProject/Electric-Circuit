#ifndef ActionDropDown2_H
#define ActionDropDown2_H
#include "Action.h"

//Class responsible for adding a new resistor action
class ActionDropDown2 : public Action
{
public:
	ActionDropDown2(ApplicationManager* pApp);
	virtual ~ActionDropDown2(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionDropDown2::Undo();

	virtual void ActionDropDown2::Redo();
};
#endif
