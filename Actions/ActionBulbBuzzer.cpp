#include "ActionBulbBuzzer.h"
#include <windows.h>
#include <mmsystem.h>
#include "..\CMUgraphicsLib\auxil.h"
#include "..\ApplicationManager.h"
#include "..\Components\Switch.h"
#include <chrono>
#include <thread>	
#include "..\Components\Buzzer.h"
#include "..\Components\Battery.h"
#include "..\UI\UI.h"

ActionBulbBuzzer::ActionBulbBuzzer(ApplicationManager* pApp) :Action(pApp)
{

}

ActionBulbBuzzer::~ActionBulbBuzzer()
{

}

void ActionBulbBuzzer::Execute()
{
	int x, y;
	UI* pUI = pManager->GetUI();
	for (int i = 0; i < pManager->getCompCount(); i++)
	{
		if (dynamic_cast<Switch*>(pManager->getCompList()[i]))
		{
			switchesNum++;
			if (pManager->getCompList()[i]->getCompState() == CLOSED) counter++;
		}
		if (dynamic_cast<Battery*>(pManager->getCompList()[i])) batteriesNum++;
	}

	if (switchesNum == counter && batteriesNum > 0)
	{
		pUI->set_isOn(true);
	
	pManager->UpdateInterface();
	for (int i = 0; i < pManager->getCompCount(); i++)
		if (dynamic_cast<Buzzer*>(pManager->getCompList()[i]))
			buzzeresNum++;
	if ((buzzeresNum > 0 && batteriesNum > 0) && (switchesNum == 0 || switchesNum == counter))
		for (int i = 0; i < 5; i++) {

			
			PlaySound(TEXT("Sounds\\Buzzer_sound2.wav"), NULL, SND_FILENAME);
		}
	else {
		chrono::seconds dura(5);
		this_thread::sleep_for(dura);
	}
	}
	else
	{
		pUI->PrintMsg("There is at least one open switch");

	}
	pUI->set_isOn(false);
	pManager->UpdateInterface();
}
void ActionBulbBuzzer::Undo()
{}

void ActionBulbBuzzer::Redo()
{}