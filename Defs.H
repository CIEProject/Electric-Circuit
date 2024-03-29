#ifndef CONST_H
#define CONST_H
//This header file contains some defenitions to be used all over the application

//Terminals
enum TerminalNum { TERM1, TERM2 };
enum Status { OPEN, CLOSED };
//All possible actions
enum ActionType
{
	ADD_RESISTOR,		//Add Resistor
	ADD_BULB,			//Add Bulb
	ADD_BUZZER,
	ADD_FUZE,
	ADD_SWITCH,				//Add Switch
	ADD_BATTERY,
	ADD_GROUND,

	ADD_CONNECTION,		//Add Wire Connection
	SWITCH_IMG,
	DROP_DOWN1,
	DROP_DOWN2,
	DROP_DOWN3,

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	FLIP_SWITCH,		//Change Switch status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	EDIT,
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file
	COPY,
	CUT,
	PASTE,
	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled
	MODULE1,
	MODULE2,
	MODULE3,
	MODULE4,
	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	SELECT_SIM,
	AMMETER,
	VOLTMETER,
	MULTIMETER,
	OHMMETER,
	SIMU,
	EXIT,		//Exit the application
	EXIT3,
	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
};
enum ImageType {
	Schem,
	Real,
};
enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};
enum SHORTCUTS {
	CTRL_A=1
};
enum Dialog_Box_Button {
	YES,
	NO,
	OK,
	CANCEL
};

enum Dialog_Box_Type {
	YESNOCANCELDIALOG,
	OKCANCELDIALOG,
	OKDIALOG
};
enum ALLCOMPS
{
	RESISTOR,
	BULB,
	BUZZER,
	FUZE,
	SWITCH,
	BATTERY,
	GROUND,
	MODULE_1,
	MODULE_2,
	MODULE_3,
	MODULE_4,
};

//Maximum number of connections that can be connected to any output components
#define MAX_CONNS 20

#endif