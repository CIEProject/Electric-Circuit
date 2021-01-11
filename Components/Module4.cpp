#include "Module4.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Module4::Module4(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2;
	sourceVoltage = 0;
}

void Module4::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawModule4(*m_pGfxInfo, selected);
}
void Module4::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Module4");
	CircuitFile << "MOD4" << "\t" << ID << "\t" << getLabel() << "\t\t" << resistance << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Module4::Operate()
{

}
void Module4::Load(int Value, string Label)
{
	resistance = Value;
	setlabel(Label);
}
ALLCOMPS Module4::whichComponent()
{
	return 	MODULE_4;
}