#ifndef COMPONENT_H
#define COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "..\Connections\Connection.h"
#include"..\ApplicationManager.h"
//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
	string m_Label;

protected:
	static int ID;
	//int MaxFuzeCurrent = 0;
	Status CompStatus;
	//Each component has two ending terminals (term1, term2)
	//double term1_volt, term2_volt;	//voltage at terminals 1&2
	double resistance, sourceVoltage; // internal resistance and voltage jump introduced by source
	//Each terminal is connected to set of connections
	Connection* term1_conns[MAX_CONNS]; //list of pointers to connections
	Connection* term2_conns[MAX_CONNS];

	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;
	bool selected;
	GraphicsInfo* m_pGfxInfo;	//The parameters required to draw a component
public:
	Component(GraphicsInfo* r_GfxInfo);
	Component();
	//////////////////////////////////////
	double term1_volt, term2_volt;
	//////////////////////////////////////
	int getTermcount(TerminalNum Term)const;
	Connection** getTermConnections(TerminalNum Term);
	void addTerm1Conn(Connection*);
	void addTerm2Conn(Connection*);
	//////////////////////////////////////
	void setSourceVoltage(int V);
	int getSourceVoltage()const;
	void setTerm1Volt(double v);		//sets the voltage at terminal1
	void setTerm2Volt(double v);		//sets the voltage at terminal2
	double getTerm1Volt()const;				//returns the voltage at terminal1
	double getTerm2Volt()const;				//returns the voltage at terminal2
	double getSourceVoltage(TerminalNum Term)const; // entering from terminal Term. Returns voltage jump/drop for battery, 0 otherwise
	double CalculateTermVoltage(TerminalNum term, double voltAtTerm, double currIntoTerm);	//Calculates the output voltage according to the inputs, sets terminal voltages
	//////////////////////////////////////
	void setlabel(string s);
	string getlabel()const;
	string getLabel()const;
	void setresistance(double R);
	int getResistance()const;
	GraphicsInfo* getGraphics();
	GraphicsInfo* get_m_pGfxInfo();
	int getCompCenterX(UI*)const; // get horizontal/vertical centers of the component
	int getCompCenterY(UI*)const;
	int getGraphicsInfoY()const;
	int getGraphicsInfoX()const;
	//////////////////////////////////////
	bool validate()const;
	void deleteGraphics();
	void deletecon(Connection* pCon);
	void reArrange();
	//////////////////////////////////////
	bool isSelected()const;
	void Selection();
	void unSelect();
	void Select();
	//////////////////////////////////////
	void Component::OpenClose(); //switches state from open to closed
	void setState(int S); //sets state
	int getCompState()const;
	//////////////////////////////////////
	bool isInRegion(int x, int y)const; // whether this point lies inside the component
	TerminalNum whichTerminal(Connection* Conn)const; // returns the terminal to which a connection is connected
	Connection* getOtherFirstTerminalConnections(Connection*);
	//////////////////////////////////////
	virtual void Operate() = 0; // activates components such as bulb and buzzer
	virtual ALLCOMPS whichComponent() = 0;
	//////////////////////////////////////
	virtual void Edit(UI* pUI )=0;
	virtual void Draw(UI*) = 0;	//for each component to Draw itself
	virtual void Load(int Value, string) = 0;
	virtual void SaveCircuit(ofstream& CircuitFile) = 0;

	static void resetID();
	//Destructor must be virtual
	virtual ~Component();
};

#endif
