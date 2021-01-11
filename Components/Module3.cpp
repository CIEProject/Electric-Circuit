#include "Module3.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Module3::Module3(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2;
	sourceVoltage = 0;
}

void Module3::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawModule3(*m_pGfxInfo, selected);
}
void Module3::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Module3");
	CircuitFile << "MOD3" << "\t" << ID << "\t" << getLabel() << "\t\t" << resistance << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Module3::Operate()
{

}
void Module3::Load(int Value, string Label)
{
	resistance = Value;
	setlabel(Label);
}
ALLCOMPS Module3::whichComponent()
{
	return 	MODULE_3;
}