#pragma once
#include "UI.h"
#include <string>
class Dialog_Box
{
	//friend class UI;
public:
	Dialog_Box(string string, Dialog_Box_Type pType);
	~Dialog_Box();
	void Draw_Button_YES() const;
	void Draw_Button_NO() const;
	void Draw_Button_OK() const;
	void Draw_Button_CANCEL() const;
	bool Button_Clicked(int x, int y);
	Dialog_Box_Button MouseClick();
	void Draw_Dialog_Box() const;
private:
	Dialog_Box_Type DType;
	window* pWind;
	string Dialog_Box_Message;
};