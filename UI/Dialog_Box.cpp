#include "Dialog_Box.h"
Dialog_Box::~Dialog_Box()
{
	delete pWind;
}
Dialog_Box::Dialog_Box(string string, Dialog_Box_Type BType)
{
	pWind = new window(450, 250, 390, 200);
	pWind->SetWaitClose(false);
	Dialog_Box_Message = string;
	DType = BType;
	Draw_Dialog_Box();
}
void Dialog_Box::Draw_Button_YES() const 
{
	pWind->SetPen(BLACK);
	pWind->DrawRectangle(25, 100, 125, 150);
	pWind->SetPen(WHITE);
	pWind->DrawString(60, 105, "YES");
}
void Dialog_Box::Draw_Button_NO() const 
{
	pWind->SetPen(BLACK);
	pWind->DrawRectangle(150, 100, 250, 150);
	pWind->SetPen(WHITE);
	pWind->DrawString(190, 105, "NO");
}
void Dialog_Box::Draw_Button_OK() const
{
	pWind->SetPen(BLACK);
	pWind->DrawRectangle(150, 100, 250, 150);

	pWind->SetPen(WHITE);
	pWind->DrawString(190, 105, "OK");
}
void Dialog_Box::Draw_Button_CANCEL() const {
	pWind->SetPen(BLACK);
	pWind->DrawRectangle(275, 100, 375, 150);
	pWind->SetPen(WHITE);
	pWind->DrawString(295, 105, "CANCEL");
}
bool Dialog_Box::Button_Clicked(int Cx, int Cy)
{
	return (Cy > 100 && Cy < 150 && 
		(Cx > 25 && Cx < 125 && DType == YESNOCANCELDIALOG || 
			(Cx > 150 && Cx < 250) || 
			(Cx > 275 && Cx < 375 && 
				DType != OKDIALOG)));
}
Dialog_Box_Button Dialog_Box::MouseClick() 
{
	int Cx, Cy, PreviousCx = 0, PreviousCy = 0;
	while (true) 
	{

		if (pWind->GetButtonState(LEFT_BUTTON, Cx, Cy) == BUTTON_UP) 
		{

			if (Button_Clicked(Cx, Cy) && !Button_Clicked(PreviousCx, PreviousCy))
			{

				if (Cx > 25 && Cx < 125) 
				{
					pWind->SetPen(WHITE);
					pWind->DrawRectangle(25, 100, 125, 150);
					pWind->DrawString(60, 105, "YES");
				}

				if (Cx > 150 && Cx < 250) 
				{
					pWind->SetPen(WHITE);
					pWind->DrawRectangle(150, 100, 250, 150);
					if (DType == YESNOCANCELDIALOG)
						pWind->DrawString(190, 105, "NO");
					else
						pWind->DrawString(190, 105, "OK");
				}

				if (Cx > 275 && Cx < 350) 
				{
					pWind->SetPen(WHITE);
					pWind->DrawRectangle(275, 100, 375, 150);
					pWind->DrawString(295, 105, "CANCEL");
				}

			}

			else if (!Button_Clicked(Cx, Cy) && Button_Clicked(PreviousCx, PreviousCy))
			{
				Draw_Dialog_Box();
			}

			PreviousCx = Cx;
			PreviousCy = Cy;

		}
		else 
		{
			if (Button_Clicked(Cx, Cy))
			{

				if (Cx > 25 && Cx < 125) 
				{
					return YES;
				}

				if (Cx > 150 && Cx < 250) 
				{
					if (DType == YESNOCANCELDIALOG)
						return NO;
					else
						return OK;
				}

				if (Cx > 275 && Cx < 350) 
				{
					return CANCEL;
				}

			}
		}
	}
}
void Dialog_Box::Draw_Dialog_Box() const
{
	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE);
	pWind->DrawRectangle(0, 0, 450, 250);
	pWind->SetPen(BLACK);

	pWind->ChangeTitle("Electric Circuit Simulator");
	pWind->SetPen(BLACK);

	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->SetBrush(BLACK);


	switch (DType)
	{
	case YESNOCANCELDIALOG:
		Draw_Button_YES();
		Draw_Button_NO();
		Draw_Button_CANCEL();
		break;

	case OKCANCELDIALOG:
		Draw_Button_OK();
		Draw_Button_CANCEL();
		break;

	case OKDIALOG:
		Draw_Button_OK();
		break;
	}
	pWind->SetPen(BLACK);
	pWind->DrawString(20, 30, Dialog_Box_Message);
}