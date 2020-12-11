#include "Battery.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Battery::Battery(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2;
	sourceVoltage = 0;
}

void Battery::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawBattery(*m_pGfxInfo, selected);




}
void Battery::SaveCircuit(ofstream& CircuitFile)
{
	CircuitFile << "BAT" << "\t" << ID << "\t" << getLabel() << "\t" << getBatteryVoltage() << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
}

void Battery::Operate()
{

}
void Battery::Load(int Value, string Label) {
	setSourceVoltage(Value);
	setlabel(Label);
}
ALLCOMPS Battery::whichComponent() {
	return 	BATTERY;
}