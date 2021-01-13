#include "ActionMultimeter.h"
#include "..\ApplicationManager.h"

#include "..\Components\Battery.h"
#include "..\Components\Bulb.h"
#include "..\Components\Buzzer.h"
#include "..\Components\Fuze.h"
#include "..\Components\Ground.h"
#include "..\Components\Resistor.h"
#include "..\Components\Switch.h"
#include "..\UI\UI.h"

ActionMultimeter::ActionMultimeter(ApplicationManager* pApp) :Action(pApp)
{
}

ActionMultimeter::~ActionMultimeter()
{
}

void ActionMultimeter::Execute()
{
	UI* pUI = pManager->GetUI();
	pManager->GetUI()->PrintMsg("Select a component: ");
	pUI->GetPointClicked(x, y);
	Component* pComp = pManager->GetComponentByCordinates(x, y);
	string label = pComp->getlabel();
	double resistance = pComp->getResistance();
	double current = pManager->CalculateCurrent();
	double voltage = pManager->calculateNetVoltage();
	if (pComp != nullptr)
	{
		if (dynamic_cast<Battery*>(pComp)) {
			if (pComp->getlabel().length() != 0) {
				pUI->PrintMsg("The battery (" + label + ") has an EMF of " + to_string(voltage)
					+ " and has no internal resistance");
			}
			else {
				pUI->PrintMsg("This battery has an EMF of " + to_string(voltage)
					+ " and has no internal resistance");
			}
		}
		else if (dynamic_cast<Bulb*>(pComp)) {
			if (pComp->getlabel().length() != 0) {
				pUI->PrintMsg("Current passes through the bulb (" + label + ") is "
					+ to_string(current) + ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
			else {
				pUI->PrintMsg("Current passes through this bulb is " + to_string(current)
					+ ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
		}
		else if (dynamic_cast<Buzzer*>(pComp)) {
			if (pComp->getlabel().length() != 0) {
				pUI->PrintMsg("Current passes through the buzzer (" + label + ") is "
					+ to_string(current) + ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
			else {
				pUI->PrintMsg("Current passes through this buzzer is " + to_string(current)
					+ ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
		}
		else if (dynamic_cast<Fuze*>(pComp)) {
			if (pComp->getlabel().length() != 0) {
				pUI->PrintMsg("Current passes through the fuze (" + label + ") is "
					+ to_string(current) + ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
			else {
				pUI->PrintMsg("Current passes through this fuze is " + to_string(current)
					+ ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
		}
		else if (dynamic_cast<Ground*>(pComp)) {
			if (pComp->getlabel().length() != 0) {
				pUI->PrintMsg("Current passes through the gorund (" + label + ") is "
					+ to_string(current) + ", voltage across its terminals is 0.000000"
					+ ", and has a resistance of " + to_string(resistance));
			}
			else {
				pUI->PrintMsg("Current passes through the ground is " + to_string(current)
					+ ", voltage across its terminals is 0.000000"
					+ ", and has a resistance of " + to_string(resistance));
			}
		}
		else if (dynamic_cast<Resistor*>(pComp)) {
			if (pComp->getlabel().length() != 0) {
				pUI->PrintMsg("Current passes through the resistor (" + label + ") is "
					+ to_string(current) + ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
			else {
				pUI->PrintMsg("Current passes through this resistor is " + to_string(current)
					+ ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
		}
		else if (dynamic_cast<Switch*>(pComp)) {
			if (pComp->getlabel().length() != 0) {
				pUI->PrintMsg("Current passes through the switch (" + label + ") is "
					+ to_string(current) + ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
			else {
				pUI->PrintMsg("Current passes through this switch is " + to_string(current)
					+ ", voltage across its terminals is " + to_string(voltage)
					+ ", and has a resistance of " + to_string(resistance));
			}
		}
	}
}
void ActionMultimeter::Undo()
{}
void ActionMultimeter::Redo()
{}