#pragma once
#include "Component.h"

class Module4 :public Component
{
public:
	Module4(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	
	virtual void Operate();
	virtual void Edit(UI* pUI);
	virtual void Load(int Value, string);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};