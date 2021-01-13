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
	void DelConn(Connection* pConn);//similiar to DelComponent
	void DelAll();//Deletes all components and connections
	void reArrange();//description the in the implementation
	/// ///////////////////////////////

	Component* GetComponentByCordinates(int x, int y); //returns pointer to the component if (x,y) is in the component region
	Connection* GetConnByCordinates(int x, int y);//returns pointer to the connection if (x,y) is in the component region
	int getCompOrder(Component* comp);
	int getCompCount();
	Component** getCompList();
	//////////////////////////////////////////////////
	void UnselectAll();
	void UnselectAll(Component* pComp);//this function is not used, it was used to unselect all object except the passed object(pComp) which leaves it as it is.
	void UnselectAll(Connection* pConn);//this function is not used, it was used to unselect all object except the passed object(pConn) which leaves it as it is.

	

	// Simulation Mode Functions //
	bool ValidateCircuit();
	void ToSimulation(); // Switches to simulation mode
	double CalculateCurrent();
	double calculateNetResistance();
	double calculateNetVoltage();
	void test();
	////////////////////////////
	void Load(ifstream& file, string name);
	void SaveCircuit(ofstream& file);
	//destructor
	~ApplicationManager();
};

#endif