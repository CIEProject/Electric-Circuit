#include "Battery.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Battery::Battery(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 0;
	sourceVoltage = 10;
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
	string s = getlabel();
	if (s == "")
		setlabel("Battery");
	CircuitFile << "BAT" << "\t" << ID << "\t" << getLabel() << "\t\t" << getSourceVoltage() << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	setlabel(s);
	ID++;
}

void Battery::Operate()
{

}
void Battery::Edit(UI* pUI) {
		//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
		string value;
		int intValue;
		do {
			value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit Battery voltage or 3 to cancel ", "");
		} while (value != "1" && value != "2" && value != "3");
		intValue = stod(value);
		switch (intValue) {
		case 1:
		{

			value = pUI->GetSrting(getLabel(),getLabel());
			setlabel(value);
			break;
		}
		case 2:
		{
			value = pUI->GetSrting(to_string(getSourceVoltage()), to_string(getSourceVoltage()));
			setSourceVoltage(stod(value));
			break;
		}
		case 3:
			break;
		}
		
	
}
void Battery::Load(int Value, string Label) {
	setSourceVoltage(Value);
	setlabel(Label);
}
ALLCOMPS Battery::whichComponent() {
	return 	BATTERY;
}