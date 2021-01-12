#ifndef CONNECTION_H
#define CONNECTION_H
#include "..\UI\UI.h"
class Component;	//forward class declaration

class Connection
{
	//connection connects between two compoenets
	Component* Comp1, * Comp2;
	GraphicsInfo* pGfxInfo;	//The parameters required to draw a connection
	string c_label;
	bool selected;
public:
	Connection(GraphicsInfo* r_GfxInfo, Component* cmp1 = nullptr, Component* cmp2 = nullptr);
	virtual void Draw(UI*);	//for connection to Draw itself
	

	bool isSelected();
	void unSelect();
	void Selection();
	//////////////////
	bool validate(Connection*);
	///////////////
	Component* getComp();
	Component* getComp(int n);
	double lineslope();
	GraphicsInfo* getgraphics() const;
	int WhichComp(Component*);
	string getLabel();
	///////////////////////

	void deleteGraphics();
	void setLabel(string s);
	void setNewComp(int n, Component*);

	////////
	void Load(Component* cmp1, Component* cmp2);
	void save(ofstream& CircuitFile, int comp1, int comp2);
	Component* getOtherComponent(Component* Cmpnt); // Get component connected to the other end of the connection
	~Connection();
};
#endif