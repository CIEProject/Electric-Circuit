#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include<fstream>
#include<iosfwd >
#include "Defs.h"
//#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum {
		MaxCompCount = 200,
		MaxConnCount = 1000
	};	//Max no of components and connectors

private:

	bool IsSimulation; // true when in simulation mode
	bool IsSeries;
	int CompCount;		//Actual number of Components
	int ConnCount;		//Actual number of Connections
	int drawningpenwidth;
	int NumberOfCopiedComponents;
	int NumberOfMovingComponents;
	Component* ListOfCopiedComponents[200];
	Component* CopyOfListOfCopiedComponents[200];
	Component* ListOfMovingComponents[200];
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount];	//List of all Connections (Array of pointers)
	window* pW;
	UI* pUI; //pointer to the UI

public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	
	UI* GetUI(); //Gets a pointer to UI Object
	void AddComponent(Component* pComp); //Adds a new component to the list of components
	void AddConnection(Connection* pConn);//Adds a new connection to the list of connection
	void printInfo(int xi, int yi); //prints information about the components on which the mouse is standing


	/// /////////////////////////////////

	void DelSelected();//deletes all components/connections that are selected by the user, can be more than one at once
	void DelComponent(Component* pComp);//deletes pComp from the CompList
	void RemoveComponent(Component* pComp);//removes pComp from the CompList
	void DelConn(Connection* pConn);//similiar to DelComponent
	void DelAll();//Deletes all components and connections
	void reArrange();//description the in the implementation
	/// ///////////////////////////////

	Component* GetComponentByCordinates(int x, int y); //returns pointer to the component if (x,y) is in the component region
	Connection* GetConnByCordinates(int x, int y);//returns pointer to the connection if (x,y) is in the component region
	int getCompOrder(Component* comp)const;
	int getCompCount()const;
	int getConnCount()const;
	Component** getCompList();
	Connection** getConnList();
	//////////////////////////////////////////////////
	void UnselectAll();
	void UnselectAll(Component* pComp);//this function is not used, it was used to unselect all object except the passed object(pComp) which leaves it as it is.
	void UnselectAll(Connection* pConn);//this function is not used, it was used to unselect all object except the passed object(pConn) which leaves it as it is.

	

	// Simulation Mode Functions //
	bool ValidateCircuit()const;
	void ToSimulation(); 
	double CalculateCurrent();
	double calculateNetResistance();
	double calculateNetVoltage();
	void CalculateTermVoltages();
	////////////////////////////
	void ErasePointers();
	int GetNumberOfSelectedComponents()const;
	void ApplicationManager::ClearTheClipboard();
	void ApplicationManager::CopySelectedComponent(int i);
	void PointToTheNextComponent(int COMP);
	int getNumberOfCopiedComponents() const;
	Component** getListOfCopiedComponents();
	void CreateACopyOfCopiedComponents();
	Component** getCopyOfListOfCopiedComponents();
	void MoveComponents(int i);
	void ClearListOfMovingComponents();
	Component** getListOfMovingComponents();
	int getNumberOfMovingComponents() const;
	void UpdateInterfaceWithoutClrDrwArea();


	/////////////////////////
	void Load(ifstream& file, string name);
	void SaveCircuit(ofstream& file);
	//destructor
	~ApplicationManager();
};

#endif