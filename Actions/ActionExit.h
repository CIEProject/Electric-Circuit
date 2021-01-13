#pragma once
#ifndef ACTION_EXIT_H
#define ACTION_EXIT_H
#include "Action.h"
#include "ActionSave.h"
#include "..\ApplicationManager.h"
#include"..\UI\UI.h"
#include "..\UI\Dialog_Box.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ActionExit : public Action
{
private:
	ofstream CircuitFile;
public:
	ActionExit(ApplicationManager* pApp);
	~ActionExit(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif