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
	if(CompStatus==OPEN)
		pUI->DrawOpenSwitch(*m_pGfxInfo, selected);
	else
		pUI->DrawClosedSwitch(*m_pGfxInfo, selected);




}
void Switch::Operate()
{

}
void Switch::Edit(UI* pUI) {
		//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
		string value;
		int intValue;
		do {
			value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit Switch status or 3 to cancel ", "");
		} while (value != "1" && value != "2" && value != "3");
		intValue = stod(value);
		switch (intValue) {
		case 1:
		{

			value = pUI->GetSrting(getLabel(), getLabel());
			setlabel(value);
			break;
		}
		case 2:
		{
			value = pUI->GetSrting(to_string(getCompState()), to_string(getCompState()));
			setState(stod(value));
			break;
		}
		case 3:
			break;
		}
	
	
}
void Switch::Load(int Value, string Label) {
	CompStatus = Status(Value);
	setlabel(Label);
}
void Switch::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("DefaultLabel");
	CircuitFile << "SWT" <<"\t"<<ID<< "\t" <<getLabel()<<"\t\t"<<getCompState()<<"\t"<< m_pGfxInfo->PointsList[0].x
	<< "\t" << m_pGfxInfo->PointsList[0].y<< endl;
	ID++;
	setlabel(s);
}
ALLCOMPS Switch::whichComponent() {
	return 	SWITCH;
}