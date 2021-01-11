#pragma once
#include "Component.h"

class Module2 :public Component
{
public:
	Module2(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	
	virtual void Operate();
	virtual void Load(int Value, string);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};