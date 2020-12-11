#include "Connection.h"
#include"..\Components\Component.h"
Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Comp1 = cmp1;
	Comp2 = cmp2;
	selected = false;
}
void Connection::Load(Component* cmp1, Component* cmp2) {
	
	Comp1 = cmp1;
	Comp2 = cmp2;
	GraphicsInfo *G1, *G2;
	G1 = Comp1->getGraphics();
	G2 = Comp2->getGraphics();
	if (pGfxInfo->PointsList[0].x < G1->PointsList[0].x)
		Comp1->addTerm1Conn(this);
	else
		Comp1->addTerm2Conn(this);
	if (pGfxInfo->PointsList[1].x < G1->PointsList[1].x)
		Comp2->addTerm1Conn(this);
	else
		Comp1->addTerm2Conn(this);
}

void Connection::Draw(UI* pUI)
{
	int xlabel = (pGfxInfo->PointsList[0].x + pGfxInfo->PointsList[1].x) / 2;
	int ylabel = ((pGfxInfo->PointsList[0].y + pGfxInfo->PointsList[1].y) / 2) + 10;
	pUI->labelMsg(c_label, xlabel, ylabel);
	
	pUI->DrawConnection(*pGfxInfo,selected);
}
void Connection::setLabel(string s) {
	c_label = s;
}
string Connection::getLabel() {
	return c_label;
	}
double Connection::lineslope() {
	double x1 = pGfxInfo->PointsList[0].x;
	double x2 = pGfxInfo->PointsList[1].x;
	double y1 = pGfxInfo->PointsList[0].y;
	double y2 = pGfxInfo->PointsList[1].y;
	
		return ((y2 - y1) / (x2 - x1));
}
Component* Connection::getComp(int n) {
	switch (n) {
	case 1:
		return Comp1;
		break;
	case 2:
		return Comp2;
		break;
	default:
		return nullptr;
	}
	
}
void Connection::setNewComp(int n, Component* comp) {
	switch (n) {
	case 1:
		Comp1 = comp;
		break;
	case 2:
		Comp2 = comp;
		break;
	}
}
void Connection::deleteGraphics() {
	delete pGfxInfo;
}
int Connection::WhichComp(Component* comp) {
	if (Comp1 == comp)
		return 1;
	else if (Comp2 == comp)
		return 2;
	else
		return 0;
}

bool Connection::isSelected() {

	return selected;
}
void Connection::Selection() {
	if (selected == false)
		selected = true;
	else
		selected = false;
}
void Connection::unSelect() {
	selected = false;
}
GraphicsInfo* Connection::getgraphics() const {
	return pGfxInfo;
}