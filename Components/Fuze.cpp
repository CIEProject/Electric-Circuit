#include "Fuze.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Fuze::Fuze(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2;
	sourceVoltage = 0;
}

void Fuze::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawFuze(*m_pGfxInfo, selected);




}
void Fuze::Operate()
{

}
void Fuze::Load(int Value, string Label) {
	MaxFuzeCurrent = Value;
	setlabel(Label);
}
ALLCOMPS Fuze::whichComponent() {
	return 	FUZE;
}