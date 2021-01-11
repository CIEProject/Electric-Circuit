#include "ActionAddModule1.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionAddModule1::ActionAddModule1(ApplicationManager* pApp,int Num) :Action(pApp)
{
	ModuleNum = Num;
}

ActionAddModule1::~ActionAddModule1(void)
{
}

void ActionAddModule1::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding new module: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn

	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > UI::getToolBarHeight() + UI::getCompHeight() / 2
		&& Cy < UI::Height() - UI::getStatusBarHeight() - UI::getCompHeight() / 2
		&& Cx > UI::getCompWidth() / 2
		&& Cx < UI::getWidth() - UI::getCompWidth() / 2)) {
		pUI->GetPointClicked(Cx, Cy);

	}

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;
	switch (ModuleNum) {
	case 1: {
		Module1* pM = new Module1(pGInfo);
		string value[4];
		for (int i = 0; i < 4; i++)
		{
			value[i] = pUI->GetSrting("Enter Resistance Value for resistor " + to_string(i + 1) + " : default value is 1", "");
			if (value[i] == "")
				value[i] = "1";
		}
		double R1 = 1.0 / (stod(value[0]) + stod(value[1]));
		double R2 = 1.0 / (stod(value[2]) + stod(value[3]));
		double R = 1.0 / (R1 + R2);

		pM->setresistance(R);
		pManager->AddComponent(pM);
		break;
	}
	case 2:
	{
		Module2* pM = new Module2(pGInfo);
		string value[10];
		for (int i = 0; i < 10; i++)
		{
			value[i] = pUI->GetSrting("Enter Resistance Value for resistor " + to_string(i + 1) + " : default value is 1", "");
			if (value[i] == "")
				value[i] = "1";
		}
		double R1 = 1.0 / (stod(value[0]) + stod(value[1]) + stod(value[5]) + stod(value[6]));
		double R2 = 1.0 / (stod(value[2]) + stod(value[7]));
		double R3 = 1.0 / (stod(value[3]) + stod(value[4]) + stod(value[8]) + stod(value[9]));
		double R = 1.0 / (R1 + R2+ R3);

		pM->setresistance(R);
		pManager->AddComponent(pM);
		break;
	}
	case 3:
	{
		Module3* pM = new Module3(pGInfo);
		string value[10];
		for (int i = 0; i < 10; i++)
		{
			value[i] = pUI->GetSrting("Enter Resistance Value for resistor " + to_string(i + 1) + " : default value is 1", "");
			if (value[i] == "")
				value[i] = "1";
		}
		double R1 = 1.0 / (1/(stod(value[0])+ stod(value[1]))+1/stod(value[2])+ 1 / (stod(value[3]) + stod(value[4])));
		double R2 = 1.0 / (1 / (stod(value[5]) + stod(value[6])) + 1 / stod(value[7]) + 1 / (stod(value[8]) + stod(value[9])));
		
		double R = R1 + R2;

		pM->setresistance(R);
		pManager->AddComponent(pM);
		break;
	}
	case 4:
	{
		Module4* pM = new Module4(pGInfo);
		string value[5];
		for (int i = 0; i < 5; i++)
		{
			value[i] = pUI->GetSrting("Enter Resistance Value for resistor " + to_string(i + 1) + " : default value is 1", "");
			if (value[i] == "")
				value[i] = "1";
		}
		double R1 = 1.0 / (1 / stod(value[0]) + 1 / stod(value[1]));
		double R2 = 1.0 / stod(value[2]);
		double R3 = 1.0 / (1 / stod(value[3]) + 1 / stod(value[4]));


		double R = R1 + R2+ R3;

		pM->setresistance(R);
		pManager->AddComponent(pM);
		break;
	}
	}


	pUI->ClearStatusBar();





}

void ActionAddModule1::Undo()
{}

void ActionAddModule1::Redo()
{}

