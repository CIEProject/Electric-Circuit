#ifndef FUZE_H
#define FUZE_H
#include "Component.h"

class Fuze :public Component
{
public:
	Fuze(GraphicsInfo* r_GfxInfo);

	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Edit(UI* pUI);
	virtual void Load(int Value, string);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};
#endif
