#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
#include <string>

using namespace std;
struct Point
{
	int x, y;
};

struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	}
};
class ApplicationManager;

class UI
{
	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_RES,		//Resistor item in menu
		ITM_BULB,
		ITM_BUZZER,
		ITM_FUZE,
		ITM_SWITCH,
		ITM_BATTERY,
		ITM_GROUND,
		ITM_CONNECTION,
		ITM_DROP1,
		ITM_DROP2,
		ITM_DROP3,
		ITM_MOVE,
		ITM_SIMU,

		ITM_EXIT,
		ITM_DSN_CNT
		//no. of design menu items ==> This should be the last line in this enum
	};

	enum DsgnDrop1MenuItem
	{
		ITM_EDIT,
		ITM_LABEL,
		ITM_DELETE,
		ITM_SAVE,
		ITM_LOAD,
		ITM_REAL,
		ITM_DRP1_CNT
	};
	enum DsgnDrop2MenuItem
	{
		ITM_MODULE1,
		ITM_MODULE2,
		ITM_MODULE3,
		ITM_MODULE4,
		ITM_DRP2_CNT
	};
	enum DsgnDrop3MenuItem
	{
		ITM_COPY,
		ITM_CUT,
		ITM_PASTE,
		ITM_DRP3_CNT
	};
	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		ITM_CIRC_SIM,	//Circuit Simulate menu item
		ITM_AMMETER,
		ITM_VOLTMETER,
		ITM_MULTIMETER,
		ITM_OHMMETER,
		ITM_DSN,
		ITM_EXIT2,
		//TODO:Add more items names here

		ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	};

	MODE AppMode;		//Application Mode (design or simulation)
	ImageType imgType;
	static const int	width = 1200,height = 650,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 80,		//Width of each item in toolbar menu

		//Arbitrary values, you can change as you wish
		COMP_WIDTH = 50,		//Component Image width
		COMP_HEIGHT = 50,		//Component Image height
		PEN_THICKNESS = 5;
	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color

	UI* pU;

	bool IsOn; //true if the series is fully connected and all the switches are closed
	//ApplicationManager* pmanager;
	int xtemp, ytemp; //these variables store x,y and are called when the user selects a component
public:
	window* pWind;
	bool dropdown1;
	bool dropdown2;
	bool dropdown3;
	UI();
	static int getToolBarHeight();
	static int Height();
	static int getWidth();
	static int getStatusBarHeight();
	static int getCompWidth();
	static int getCompHeight();

	// Input Functions  ---------------------------
	void GetPointClicked(int&, int&);	//Get coordinate where user clicks
	string GetSrting(string msg = "Enter Value", string value = "");
	//the other "value" parameter was added so the user can edit the label without having to write it again
	//Returns a string entered by the user

	ActionType GetUserAction(ApplicationManager* pApp); //Reads the user click and maps it to an action
	int getXtemp(); //for select action
	int getYtemp();

	// Output Functions  ---------------------------
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateDropDown1Menu();
	void CreateDropDown2Menu();
	void CreateDropDown3Menu();
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearToolBarArea()const;
	void SwitchImageType();
	// Draws Components
	void DrawResistor(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawGround(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawOpenSwitch(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawClosedSwitch(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawFuze(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawBulb(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawModule1(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawModule2(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawModule3(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawModule4(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws Connection
	void DrawConnection(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	void PrintMsg(string msg) const;	//Print a message on Status bar
	void PrintMsgWithNoClear(string msg) const;	//Print a message on Status bar without clearing the old msg
	void labelMsg(string msg, int x = 25, int y = height - StatusBarHeight + 10); //for labeling components
	void set_isOn(bool); 
	bool get_isOn()const;
	~UI();
};

#endif