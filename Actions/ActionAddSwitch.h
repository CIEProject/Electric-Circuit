#ifndef ACTION_ADD_SWITCH_H
#define ACTION_ADD_SWITCH_H

#include "Action.h"
#include "..\Components\Switch.h"

//Class responsible for adding a new resistor action
class ActionAddSwitch : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddSwitch(ApplicationManager* pApp);
	virtual ~ActionAddSwitch(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionAddSwitch::Undo();

	virtual void ActionAddSwitch::Redo();
};
#endif