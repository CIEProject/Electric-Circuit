#ifndef ACTION_PASTE_H
#define ACTION_PASTE_H

#include "Action.h"
#include"../UI/UI.h"	
//Class responsible for adding a new resistor action
class ActionPaste : public Action
{
private:
	int Cx, Cy;
	Point P;   //stores the point to which we will paste
public:
	ActionPaste(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~ActionPaste(void);
};
#endif 