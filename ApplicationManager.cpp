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
#include"Actions/ActionAddLabel.h"

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
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
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
	for (int i = 0; i < ConnCount; i++){
		if (ConnList[i] != nullptr)
			if (ConnList[i]->isSelected())
				DelConn(ConnList[i]);
	}
	reArrange();

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
void ApplicationManager::DelConn(Connection* pConn)
{
	for (int i = 0; i < ConnCount; i++) {
		 
		if (ConnList[i] == pConn&& pConn!=nullptr) {
			Component* comp2 = ConnList[i]->getComp(1);
			Component* comp3 = ConnList[i]->getComp(2);
			comp2->deletecon(ConnList[i]);
			comp3->deletecon(ConnList[i]);
			ConnList[i]->deleteGraphics();
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
void ApplicationManager::AddConnection(Connection* pConn) {
	ConnList[ConnCount++] = pConn;
}
void ApplicationManager::UnselectAll(Component* pComp) {
	for (int i = 0; i < CompCount; i++){
		if(CompList[i]!=pComp&&CompList[i]!=nullptr)
			CompList[i]->unSelect();
}
	for (int i = 0; i < ConnCount; i++)
		if(ConnList[i]!=nullptr)
		ConnList[i]->unSelect();
}
void ApplicationManager::UnselectAll(Connection* pConn) {
	
	for (int i = 0; i < CompCount; i++)
		if(CompList[i]!=nullptr)
			CompList[i]->unSelect();
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr&& ConnList[i] != pConn) 
			ConnList[i]->unSelect();
	
	}
}
/*reArrange function is used when a component and/or a connection is deleted, it sets the right actual number of components
and removes the ones that are nullptrs*/
void ApplicationManager::reArrange() {
	Component* tempCompList[MaxCompCount];	
	Connection* tempConnList[MaxConnCount];
	int counter = 0;
	for(int i=0;i<CompCount;i++)
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
ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction();
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
	/*case SIM_MODE:
		pAct = new Action(this);
		break;*/ //TODO
	

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
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
////////////////////////////////////////////////////////////////////
// Validates the circuit before going into simultion mode
bool ApplicationManager::ValidateCircuit() {
	return true;
}
Component* ApplicationManager::GetComponentByCordinates(int x, int y) {
	UI* pUI = GetUI();
	int  isExist = 0;
	int ydifference, xdifference;
	int compheight = pUI->getCompHeight();
	int compwidth = pUI->getCompWidth();
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr) {
			ydifference = abs(y - CompList[i]->getCompCenterY(pUI));
			xdifference = abs(x - CompList[i]->getCompCenterX(pUI));
			if ((ydifference <= compheight / 2) && (xdifference <= compwidth / 2)) {
				isExist = 1;
				return CompList[i];

				break;
			}

		}
	}
	if (isExist == 0)
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
			
			for(int j=-5;j<=5;j++) {
				/*the reason for this loop is that sometimes the click is more >x1 && >x2
								if the line the somewhat vertical*/
				if ((x + j >= x2 && x + j <= x1) || (x + j >= x1 && x + j <= x2)) {
					for (int k = -4; k <= 4; k++){
						/*while the reason for this loop is that the user 
		click is never exactly on the line equation so it checks if it is on any other near parallel line*/
						if(x1!=x2){
						right = slope*(x - (x1+k));
						left = y - (y1 + k);}
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
			/*if (x1 > x2) {
				for (int j = -5; j <= 5; j++) {
				if ((x+j) >= x2 && (x+j) <= x1) {
					for (int k = -5; k <= 5; k++) {
						if (x1 != x2) {
							right = y - (y1 + k);
							left = slope * (x - (x1 + k));
						}
						else {
							left = x - (x1 + k);
							right = 0;
						}
						if (right == left) {
							return ConnList[i];

							isExist = 1;
							break;
						
						}
					}
					}
				}
			}
			if (x2 >= x1) {
				for (int j = -5; j <= 5; j++) {
					if ((x + j) >= x1 && (x + j) <= x2) {
						for (int k = -5; k <= 5; k++) {
							if (x1 != x2) {
								right = y - (y2 + k);
								left = slope * (x - (x2 + k));
							}
							else {
								left = x - (x2 + k);
								right = 0;
							}
							if (right == left) {
								return ConnList[i];
								isExist = 1;
								break;
							}
						}
					}
				}
			}*/
			
		}
	}
	if (isExist == 0)
		return nullptr;
}
void ApplicationManager::Save(fstream& file, string name)
{
	file.open(name, ios::out);
	file << CompCount << endl;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->whichComponent() == RESISTOR)
			file << "RES" << "\t" << i + 1 << "\t" << CompList[i]->getLabel() << "\t" << CompList[i]->getResistance() << "\t" << CompList[i]->getGraphicsInfoX() << "\t" << CompList[i]->getGraphicsInfoY()
			<< endl;
		if (CompList[i]->whichComponent() == GROUND)
			file << "GND" << "\t" << i + 1 << "\t" << CompList[i]->getLabel() << "\t" << -1 << "\t" << CompList[i]->getGraphicsInfoX() << "\t" << CompList[i]->getGraphicsInfoY()
			<< endl;
		if (CompList[i]->whichComponent() == BATTERY)
			file << "BAT" << "\t" << i + 1 << "\t" << CompList[i]->getLabel() << "\t" << CompList[i]->getBatteryVoltage() << "\t" << CompList[i]->getGraphicsInfoX() << "\t" << CompList[i]->getGraphicsInfoY()
			<< endl;
		if (CompList[i]->whichComponent() == FUZE)
			file << "FUZ" << "\t" << i + 1 << "\t" << CompList[i]->getLabel() << "\t" << CompList[i]->getMaxFuze() << "\t" << CompList[i]->getGraphicsInfoX() << "\t" << CompList[i]->getGraphicsInfoY()
			<< endl;
		if (CompList[i]->whichComponent() == SWITCH)
			file << "SWT" << "\t" << i + 1 << "\t" << CompList[i]->getLabel() << "\t" << CompList[i]->getSwitchState() << "\t" << CompList[i]->getGraphicsInfoX() << "\t" << CompList[i]->getGraphicsInfoY()
			<< endl;
		if (CompList[i]->whichComponent() == BUZZER)
			file << "BZR" << "\t" << i + 1 << "\t" << CompList[i]->getLabel() << "\t" << CompList[i]->getResistance() << "\t" << CompList[i]->getGraphicsInfoX() << "\t" << CompList[i]->getGraphicsInfoY()
			<< endl;
		if (CompList[i]->whichComponent() == BULB)
			file << "BLB" << "\t" << i + 1 << "\t" << CompList[i]->getLabel() << "\t" << CompList[i]->getResistance() << "\t" << CompList[i]->getGraphicsInfoX() << "\t" << CompList[i]->getGraphicsInfoY()
			<< endl;
	}
	file << "Connection \n" << CompCount << endl;;

	for (int i = 0; i < ConnCount; i++) {
		int comp1 = getCompOrder(ConnList[i]->getComp(1)) + 1;
		int comp2 = getCompOrder(ConnList[i]->getComp(2)) + 1;
		GraphicsInfo* G = ConnList[i]->getgraphics();
		int x1 = G->PointsList[0].x;
		int x2 = G->PointsList[1].x;
		int y1 = G->PointsList[0].y;
		int y2 = G->PointsList[1].y;
		file << comp1 << "\t" << comp2 << "\t" << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << endl;
	}
	file.close();
}
int ApplicationManager::getCompOrder(Component* comp) {
	for (int i = 0; i < CompCount; i++) {
		if (comp == CompList[i])
			return i;
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
				if (CompName == "FUS")
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
			}
			else if(CompName == "Connections") { //This means that the Components are are loaded and it is time for connection to be loaded
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
void ApplicationManager::ToSimulation() {
	if (!ValidateCircuit()) {
		// TODO
	}
	else {
		this->IsSimulation = true;
		// Compute all needed voltages and current
		double current = CalculateCurrent();
		CalculateVoltages(current);
	}
}
////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	// TODO
	return 0;
}

// Calculates voltage at each component terminal
void ApplicationManager::CalculateVoltages(double current) {
	// TODO
}


////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	delete pW;
	delete pUI;
}