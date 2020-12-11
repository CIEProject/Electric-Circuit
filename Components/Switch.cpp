#include "Switch.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
Switch::Switch(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2;
	sourceVoltage = 0;
}

void Switch::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	if(SwitchStatus==OPEN)
		pUI->DrawOpenSwitch(*m_pGfxInfo, selected);
	else
		pUI->DrawClosedSwitch(*m_pGfxInfo, selected);




}
void Switch::Operate()
{

}
void Switch::Load(int Value, string Label) {
	SwitchStatus = Status(Value);
	setlabel(Label);
}
ALLCOMPS Switch::whichComponent() {
	return 	SWITCH;
}