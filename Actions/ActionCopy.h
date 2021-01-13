#ifndef ACTION_COPY_H
#define ACTION_COPY_H

#include "Action.h"
#include "..\ApplicationManager.h"

class ActionCopy : public Action
{
private:
	int Cx = 0, Cy = 0;
	bool SelectedComponents;
public:

	ActionCopy(ApplicationManager* pApp);
	~ActionCopy(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif