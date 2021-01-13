#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddBuzzer.h"
#include"Actions/ActionAddFuze.h"
#include"Actions/ActionAddBattery.h"
#include"Actions/ActionAddSwitch.h"
#include"Actions/ActionAddGround.h"
#include"Actions/ActionAddConnection.h"
#include"Actions/ActionDelete.h"
#include"Actions/ActionSelect.h"
#include"Actions/ActionEdit.h"
#include"Actions/ExitAction.h"
#include"Actions/ActionSave.h"
#include"Actions/ActionLoad.h"
#include"Actions/ActionSwitchSimulation.h"
#include"Actions/ActionAddLabel.h"
#include"Actions/ActionDropDown.h"
#include"Actions/ActionDropDown2.h"
#include"Actions/ActionDropDown3.h"
#include"Actions/ActionSwitchReal.h"
#include"Actions/ActionAmmeter.h"
#include"Actions/ActionAddModule1.h"
#include"Actions/ActionDesign.h"
#include"Actions/ActionBulbBuzzer.h"
#include"Actions/ActionVoltmeter.h"
#include"Actions/ActionMultimeter.h"
#include"Actions/ActionOhmmeter.h"
#include"Actions/ActionOpenCloseSwitch.h"
#include"Actions/ActionCopy.h"
#include"Actions/ActionCut.h"
#include"Actions/ActionPaste.h"
#include"Actions/ActionMove.h"
#include <iostream>
#include<cmath>

using namespace std;
//github test

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;

	IsSimulation = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxCompCount; i++)
		ConnList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(this);
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
	case ADD_RESISTOR:
		pAct = new ActionAddRes(this);
		break;
	case ADD_BULB:
		pAct = new ActionAddBulb(this);
		break;
	case ADD_BUZZER:
		pAct = new ActionAddBuzzer(this);
		break;
	case ADD_FUZE:
		pAct = new ActionAddFuze(this);
		break;
	case ADD_BATTERY:
		pAct = new ActionAddBattery(this);
		break;
	case ADD_SWITCH:
		pAct = new ActionAddSwitch(this);
		break;
	case ADD_GROUND:
		pAct = new ActionAddGround(this);
		break;
	case ADD_CONNECTION:
		pAct = new ActionAddConnection(this);
		break;
	case ADD_Label:
		pAct = new ActionAddLabel(this);
		break;
	case SELECT:
		pAct = new ActionSelect(this);
		break;
	case EDIT:
		pAct = new ActionEdit(this);
		break;
	case SAVE:
		pAct = new ActionSave(this);
		break;
	case LOAD:
		pAct = new ActionLoad(this);
		break;
	case DEL:
		pAct = new ActionDelete(this);
		break;
	case COPY:
		pAct = new ActionCopy(this);
		break;
	case CUT:
		pAct = new ActionCut(this);
		break;
	case PASTE:
		pAct = new ActionPaste(this);
		break;
	case DROP_DOWN1:
		pAct = new ActionDropDown(this);
		break;
	case DROP_DOWN2:
		pAct = new ActionDropDown2(this);
		break;
	case DROP_DOWN3:
		pAct = new ActionDropDown3(this);
		break;
	case MOVE:
		pAct = new ActionMove(this);
		break;
	case SWITCH_IMG:
		pAct = new ActionSwitchReal(this);
		break;
	case SIM_MODE:
		pAct = new ActionSwitchSimulation(this);
		break;
	case DSN_MODE:
		pAct = new ActionDesign(this);
		break;
	case AMMETER:
		pAct = new ActionAmmeter(this);
		break;
	case SIMU:
		pAct = new ActionBulbBuzzer(this);
		break;
	case SELECT_SIM:
		pAct = new ActionOpenCloseSwitch(this);
		break;
	case VOLTMETER:
		pAct = new ActionVoltmeter(this);
		break;
	case MULTIMETER:
		pAct = new ActionMultimeter(this);
		break;
	case OHMMETER:
		pAct = new ActionOhmmeter(this);
		break;
	case MODULE1:
		pAct = new ActionAddModule1(this, 1);
		break;
	case MODULE2:
		pAct = new ActionAddModule1(this, 2);
		break;
	case MODULE3:
		pAct = new ActionAddModule1(this, 3);
		break;
	case MODULE4:
		pAct = new ActionAddModule1(this, 4);
		break;
	case EXIT:
		pAct = new ExitAction(this);
		break;
	}
	if (pAct)
	{
		pAct->Execute();

		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::UpdateInterface()
{
	pUI->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr) {
			CompList[i]->Draw(pUI);
		}
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr) {
			ConnList[i]->Draw(pUI);
		}
	GetUI()->CreateDropDown1Menu();
	GetUI()->CreateDropDown2Menu();
	GetUI()->CreateDropDown3Menu();
}
//////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
void ApplicationManager::AddConnection(Connection* pConn) {
	ConnList[ConnCount++] = pConn;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::printInfo(int xi, int yi) {
	static int counter = 0;
	if (yi >= pUI->getToolBarHeight() && yi < pUI->Height() - pUI->getStatusBarHeight()) {
		Component* pcomp = GetComponentByCordinates(xi, yi);
		if (pcomp != nullptr) {
			if (counter == 0)
				pUI->ClearStatusBar();
			counter++;
			if (dynamic_cast<Battery*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Battery, Source Voltage= " + to_string(pcomp->getSourceVoltage()));
			}
			else if (dynamic_cast<Bulb*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Bulb, Resistance= " + to_string(pcomp->getResistance()));
			}
			else if (dynamic_cast<Buzzer*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Buzzer, Resistance= " + to_string(pcomp->getResistance()));
			}
			else if (dynamic_cast<Fuze*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Fuse, Resistance= " + to_string(pcomp->getResistance()));
			}
			else if (dynamic_cast<Ground*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Ground, No Resistance");
			}
			else if (dynamic_cast<Module1*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Module Number 1, Resistance= " + to_string(pcomp->getResistance()));
			}
			else if (dynamic_cast<Module2*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Module Number 2, Resistance= " + to_string(pcomp->getResistance()));
			}
			else if (dynamic_cast<Module3*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Module Number 3, Resistance= " + to_string(pcomp->getResistance()));
			}
			else if (dynamic_cast<Module4*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Module Number 4, Resistance= " + to_string(pcomp->getResistance()));
			}
			else if (dynamic_cast<Resistor*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Resistor, Resistance= " + to_string(pcomp->getResistance()));
			}
			else if (dynamic_cast<Switch*>(pcomp)) {
				pUI->PrintMsgWithNoClear("Switch, state= " + to_string(pcomp->getCompState()));
			}
		}
		else if (counter != 0)
			pUI->ClearStatusBar();
	}
	else
		counter = 0;
}
/// ///////////////////////////////////////
void ApplicationManager::DelSelected() {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr) {
			if (CompList[i]->isSelected()) {
				Connection** one = CompList[i]->getTermConnections(TERM1);
				Connection** two = CompList[i]->getTermConnections(TERM2);
				for (int j = 0; j < 20; j++) {
					DelConn(one[j]);
					DelConn(two[j]);
				}
				DelComponent(CompList[i]);
			}
		}
	}
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr)
			if (ConnList[i]->isSelected())
				DelConn(ConnList[i]);
	}

	reArrange();
	for (int i = 0; i < CompCount; i++)
		CompList[i]->reArrange();
}
void ApplicationManager::DelComponent(Component* pComp)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] == pComp) {
			CompList[i]->deleteGraphics();
			delete CompList[i];
			CompList[i] = nullptr;
		}
	}
}
void ApplicationManager::RemoveComponent(Component* pComp) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr&&CompList[i]==pComp) {
			
				Connection** one = CompList[i]->getTermConnections(TERM1);
				Connection** two = CompList[i]->getTermConnections(TERM2);
				for (int j = 0; j < 20; j++) {
					DelConn(one[j]);
					DelConn(two[j]);
				}
				CompList[i] = nullptr;
			
		}
	}
}
void ApplicationManager::DelConn(Connection* pConn)
{
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] == pConn && pConn != nullptr) {
			Component* comp2 = ConnList[i]->getComp(1);
			Component* comp3 = ConnList[i]->getComp(2);
			comp2->deletecon(ConnList[i]);
			comp3->deletecon(ConnList[i]);
			delete ConnList[i];

			ConnList[i] = nullptr;
		}
	}
}
void ApplicationManager::DelAll() {
	for (int i = 0; i < CompCount; i++) {
		DelComponent(CompList[i]);
	}

	for (int i = 0; i < ConnCount; i++) {
		DelConn(ConnList[i]);
	}
}
void ApplicationManager::reArrange() {
	/*reArrange function is used when a component and/or a connection is deleted, it sets the right actual number of components
and removes the ones that are nullptrs*/
	Component* tempCompList[MaxCompCount];
	Connection* tempConnList[MaxConnCount];
	int counter = 0;
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr) {
			tempCompList[counter] = CompList[i];
			counter++;
		}
	for (int i = 0; i < CompCount; i++) {
		CompList[i] = tempCompList[i];
		tempCompList[i] = nullptr;
	}
	CompCount = counter;
	counter = 0;
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr) {
			tempConnList[counter] = ConnList[i];
			counter++;
		}
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i] = tempConnList[i];
		tempConnList[i] = nullptr;
	}
	ConnCount = counter;
}
/// ///////////////////////////////////////////////////////////
Component* ApplicationManager::GetComponentByCordinates(int x, int y) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->isInRegion(x, y))
			return CompList[i];

	}
	return nullptr;
}

Connection* ApplicationManager::GetConnByCordinates(int x, int y) {
	//i hope there is a better way to implement this
	UI* pUI = GetUI();
	int  isExist = 0;
	int x1;
	int x2;
	int y1;
	int y2;
	double slope;
	int right, left;
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr) {
			x1 = ConnList[i]->getgraphics()->PointsList[0].x;
			x2 = ConnList[i]->getgraphics()->PointsList[1].x;
			y1 = ConnList[i]->getgraphics()->PointsList[0].y;
			y2 = ConnList[i]->getgraphics()->PointsList[1].y;
			slope = ConnList[i]->lineslope();

			for (int j = -5; j <= 5; j++) {
				/*the reason for this loop is that sometimes the click is more >x1 && >x2
								if the line the somewhat vertical*/
				if ((x + j >= x2 && x + j <= x1) || (x + j >= x1 && x + j <= x2)) {
					for (int k = -4; k <= 4; k++) {
						/*while the reason for this loop is that the user
		click is never exactly on the line equation so it checks if it is on any other near parallel line*/
						if (x1 != x2) {
							right = slope * (x - (x1 + k));
							left = y - (y1 + k);
						}
						else {
							right = x - (x1 + k);
							left = 0;
						}
						if (left == right) {
							return ConnList[i];
							isExist = 1;
							break;
						}
					}
				}
			}
		}
	}
	if (isExist == 0)
		return nullptr;
}
int ApplicationManager::getCompOrder(Component* comp) {
	for (int i = 0; i < CompCount; i++) {
		if (comp == CompList[i])
			return i;
	}
}
int ApplicationManager::getCompCount() {
	return CompCount;
}
int ApplicationManager::getConnCount() {
	return ConnCount;
}
Component** ApplicationManager::getCompList() {
	return CompList;
}
Connection** ApplicationManager::getConnList() {
	return ConnList;
}
/// ///////////////////////////////////////////////////////////
void ApplicationManager::UnselectAll() {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr)
			CompList[i]->unSelect();
	}
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr)
			ConnList[i]->unSelect();
}
void ApplicationManager::UnselectAll(Component* pComp) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != pComp && CompList[i] != nullptr)
			CompList[i]->unSelect();
	}
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr)
			ConnList[i]->unSelect();
}
void ApplicationManager::UnselectAll(Connection* pConn) {
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr)
			CompList[i]->unSelect();
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr && ConnList[i] != pConn)
			ConnList[i]->unSelect();
	}
}
/// ///////////////////////////////////////////////////////////
bool ApplicationManager::ValidateCircuit() {
	// Validates the circuit before going into simultion mode
	////////////////////////////////////////
	//makes sure that there are reasonable number of connections
	if (CompCount != ConnCount || ConnCount == 1 || ConnCount == 0) {
		pUI->PrintMsg("Not all components are connected, please make sure they are in series");
		return false;
	}
	else {
		///////////////////////////////////////////////
		for (int i = 0; i < CompCount; i++) {
			if (!(CompList[i]->validate())) {
				pUI->PrintMsg("each component must have only one connection per terminal ");
				return false;
			}
		}
		int counter = 0;
		////////////////////////////////////////////
		//makes sure there is only one ground
		for (int i = 0; i < CompCount; i++) {
			if (dynamic_cast<Ground*>(CompList[i]))
				counter++;
		}
		if (counter != 1) {
			pUI->PrintMsg("the cirucit must have one ground only");
			return false;
		}
		///////////////////////////////////////////

		for (int i = 0; i < ConnCount - 1; i++) {
			for (int j = i + 1; j < ConnCount; j++) {
				if (!(ConnList[i]->validate(ConnList[j]))) {
					pUI->PrintMsg("you cant establish a connection between two components only ");
					return false;
				}
			}
		}

		/// ////////////////////////////////////////
		//the main idea of the following part is that it makes sure
		//that there are only circuit and not two or three series connected circuits.

		Connection* conn1;
		Component* comp1;
		counter = 0;

		for (int i = 0; i < CompCount; i++) {
			comp1 = CompList[i];

			conn1 = comp1->getTermConnections(TERM1)[0];
			comp1 = conn1->getOtherComponent(comp1);
			counter = 1;
			while (comp1 != CompList[i] && counter <= CompCount) {
				conn1 = comp1->getOtherFirstTerminalConnections(conn1);
				comp1 = conn1->getOtherComponent(comp1);
				counter++;
			}

			if (counter != CompCount) {
				pUI->PrintMsg("you cannot make multiple circuits");
				return false;
			}
		}
		////////////////////////////////////////////
		return true;
	}
}
void ApplicationManager::ToSimulation()
{
	if (!ValidateCircuit())
	{
	//any useful prompt has been written inside ValidateCircuit Function
	}
	else
	{
		this->IsSimulation = true;
		UnselectAll();
		pUI->ClearStatusBar();
		pUI->dropdown1 = false;
		pUI->dropdown2 = false;
		pUI->dropdown3 = false;
		pUI->ClearToolBarArea();
		pUI->CreateSimulationToolBar();
		CalculateTermVoltages();
		// Compute all needed voltages and current
	}
}
double ApplicationManager::calculateNetResistance() {
	double NetR = 0;
	for (int i = 0; i < CompCount; i++) {
		NetR += CompList[i]->getResistance();
	}
	return NetR;
}
double ApplicationManager::calculateNetVoltage() {
	double NetV = 0;
	for (int i = 0; i < CompCount; i++) {
		NetV += CompList[i]->getSourceVoltage();
	}
	return NetV;
}
void ApplicationManager::CalculateTermVoltages() {
	double remainingVoltage = calculateNetVoltage();
	double AllVoltage = calculateNetVoltage();
	double current;
	Component* comp1 = nullptr, * ground = nullptr;
	Connection* conn1;
	int temp;
	for (int i = 0; i < CompCount; i++) {
		if (dynamic_cast<Ground*>(CompList[i])) {
			comp1 = CompList[i];
		}
	}
	ground = comp1;
	current = calculateNetVoltage() / calculateNetResistance();
	conn1 = comp1->getTermConnections(TERM1)[0];
	comp1 = conn1->getOtherComponent(comp1);
	switch (comp1->whichTerminal(conn1)) {
	case TERM1:
		comp1->setTerm1Volt(0);
		comp1->setTerm2Volt(comp1->getResistance() * current+ comp1->getSourceVoltage());
		break;
	case TERM2:
		comp1->setTerm2Volt(0);
		comp1->setTerm1Volt(comp1->getResistance() * current+ comp1->getSourceVoltage());
		break;
	}

	remainingVoltage -= comp1->getResistance() * current;
	while (comp1 != ground) {
		conn1 = comp1->getOtherFirstTerminalConnections(conn1);
		comp1 = conn1->getOtherComponent(comp1);
		switch (comp1->whichTerminal(conn1)) {
		case TERM1:
			comp1->setTerm1Volt(AllVoltage - remainingVoltage);
			comp1->setTerm2Volt(comp1->getResistance() * current + AllVoltage - remainingVoltage+ comp1->getSourceVoltage());
			break;
		case TERM2:
			comp1->setTerm2Volt(AllVoltage - remainingVoltage);
			comp1->setTerm1Volt(comp1->getResistance() * current + AllVoltage - remainingVoltage+ comp1->getSourceVoltage());
			break;
		}
		remainingVoltage -= comp1->getResistance() * current;

	}
}
//////////////////////////////////////////////////////////////////
void ApplicationManager::SaveCircuit(ofstream& CircuitFile)
{
	CircuitFile << CompCount << endl;
	for (int i = 0; i < CompCount; i++)
		CompList[i]->SaveCircuit(CircuitFile);
	Component::resetID();
	CircuitFile << "Connections \n" << ConnCount << endl;
	for (int i = 0; i < ConnCount; i++) {
		int comp1 = getCompOrder(ConnList[i]->getComp(1)) + 1;
		int comp2 = getCompOrder(ConnList[i]->getComp(2)) + 1;
		ConnList[i]->save(CircuitFile, comp1, comp2);
	}
}
void ApplicationManager::Load(ifstream& file, string name)
{
	GraphicsInfo* G = new GraphicsInfo(2);
	file.open(name);
	if (!file.fail())
	{
		string CompName;
		string Label;
		int graphicInfoX, graphicInfoY, num;
		int ID;
		int Value;
		file >> num;
		while (file >> CompName)
		{
			if (CompName != "Connections")
			{
				file >> ID;
				file >> Label;
				file >> Value;
				file >> graphicInfoX;
				file >> graphicInfoY;
				G = new GraphicsInfo(2);
				G->PointsList[0].x = graphicInfoX;
				G->PointsList[0].y = graphicInfoY;
				G->PointsList[1].x = graphicInfoX + pUI->getCompWidth();;
				G->PointsList[1].y = graphicInfoY + pUI->getCompHeight();
				if (CompName == "RES")
				{
					Resistor* comp = new Resistor(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				
				if (CompName == "SWT")
				{
					Switch* comp = new Switch(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "BAT")
				{
					Battery* comp = new Battery(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "BLB")
				{
					Bulb* comp = new Bulb(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "GND")
				{
					Ground* comp = new Ground(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "FUZ")
				{
					Fuze* comp = new Fuze(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "BZR")
				{
					Buzzer* comp = new Buzzer(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "MOD1")
				{
					Module1* comp = new Module1(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "MOD2")
				{
					Module2* comp = new Module2(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "MOD3")
				{
					Module3* comp = new Module3(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
				if (CompName == "MOD4")
				{
					Module4* comp = new Module4(G);
					comp->Load(Value, Label);
					AddComponent(comp);
				}
			}
			else if (CompName == "Connections") {
				//This means that the Components are are loaded and it is time for connection to be loaded
				int comp1;
				int comp2;
				int graphicspoint;
				file >> num;
				while (file >> comp1) {
					file >> comp2;

					file >> graphicspoint;
					G = new GraphicsInfo(2);
					G->PointsList[0].x = graphicspoint;
					file >> graphicspoint;
					G->PointsList[0].y = graphicspoint;
					file >> graphicspoint;
					G->PointsList[1].x = graphicspoint;
					file >> graphicspoint;
					G->PointsList[1].y = graphicspoint;
					Connection* C = new Connection(G);
					C->Load(CompList[comp1 - 1], CompList[comp2 - 1]);
					AddConnection(C);
				}
			}
		}
	}
	else
		pUI->PrintMsg("File open failure! ");
	file.close();
}
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	return calculateNetVoltage() / calculateNetResistance();
}

/////////////////////////////////////////
int ApplicationManager::GetNumberOfSelectedComponents()
{
	int Count = 0;
	for (int i = 0; i < getCompCount(); i++)
	{
		if (getCompList()[i]->isSelected())
			Count++;
	}
	return Count;
}

void ApplicationManager::ClearTheClipboard()
{
	for (int i = 0; i < NumberOfCopiedComponents; i++)
		ListOfCopiedComponents[i] = nullptr;
	NumberOfCopiedComponents = 0;
}

void ApplicationManager::CopySelectedComponent(int i)
{
	CompList[i]->unSelect(); // 3a4an nl8y el selection
	ListOfCopiedComponents[NumberOfCopiedComponents] = CompList[i];
	NumberOfCopiedComponents++;
}

void ApplicationManager::MoveComponents(int i)
{
	CompList[i]->unSelect();
	ListOfMovingComponents[NumberOfMovingComponents] = CompList[i];
	NumberOfMovingComponents++;
}
void ApplicationManager::ClearListOfMovingComponents()
{
	for (int i = 0; i < NumberOfMovingComponents; i++)
		ListOfMovingComponents[i] = nullptr;
	NumberOfMovingComponents = 0;
}

void ApplicationManager::CreateACopyOfCopiedComponents()
{
	for (int i = 0; i < NumberOfCopiedComponents; i++)
		CopyOfListOfCopiedComponents[i] = ListOfCopiedComponents[i];
}

void ApplicationManager::PointToTheNextComponent(int COMP)
{
	for (int i = COMP; i < CompCount; i++)
	{
		CompList[i] = CompList[i + 1]; //3a4an n point 3ala el component ely ba3deh badaloh
		UpdateInterface();
	}
	CompCount--; // hana2as 3add el components kolo 1 
}

int ApplicationManager::getNumberOfCopiedComponents() const
{
	return NumberOfCopiedComponents;
}

int ApplicationManager::getNumberOfMovingComponents() const
{
	return NumberOfMovingComponents;
}

Component** ApplicationManager::getListOfCopiedComponents()
{
	return this->ListOfCopiedComponents;
}
Component** ApplicationManager::getListOfMovingComponents()
{
	return this->ListOfMovingComponents;
}

Component** ApplicationManager::getCopyOfListOfCopiedComponents()
{
	return this->CopyOfListOfCopiedComponents;
}
void ApplicationManager::UpdateInterfaceWithoutClrDrwArea()
{
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr) {
			CompList[i]->Draw(pUI);
		}
	//CompList[i]->Draw(pUI);

	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr)
		{
			ConnList[i]->Draw(pUI);
		}
}
////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	delete pW;
	delete pUI;
}