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
void Fuze::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Fuse");
	CircuitFile << "FUZ" << "\t" << ID << "\t" << getlabel() << "\t\t" << getResistance() << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Fuze::Operate()
{

}
void Fuze::Edit(UI* pUI) {

	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit resistace value or 3 to cancel ");
	string value;
	int intValue;
	do {
		value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit resistace value or 3 to cancel ", "");
	} while (value != "1" && value != "2" && value != "3");
	intValue = stod(value);
	switch (intValue) {
	case 1:
	{

		value = pUI->GetSrting(getlabel(), getlabel());
		setlabel(value);
		break;
	}
	case 2:
	{
		value = pUI->GetSrting(to_string(getResistance()), to_string(getResistance()));
		setresistance(stod(value));
		break;
	}
	case 3:
		break;
	}



}
void Fuze::Load(int Value, string Label) {
	resistance = Value;
	setlabel(Label);
}
ALLCOMPS Fuze::whichComponent() {
	return 	FUZE;
}