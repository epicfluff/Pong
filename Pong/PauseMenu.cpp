#include "stdafx.h"
#include "PauseMenu.h"


PauseMenu::PauseMenu(SceneManager * manager)
{
	sceneManager = manager;
}


PauseMenu::~PauseMenu(void)
{
}

void PauseMenu::update(int deltaTime)
{}

void PauseMenu::paint(bool primary)
{
	extern DeviceContextManager dcManager;

	SetTextColor(dcManager.back_hdc, RGB(0,0,0));
	SetBkColor(dcManager.back_hdc, RGB(255,255,255));

	RECT clientArea;
	GetClientRect(dcManager.hwnd, &clientArea);

	RECT backgroundArea = {clientArea.right/4, clientArea.bottom*0.2, clientArea.right*3/4, clientArea.bottom - clientArea.bottom*0.01};
	RECT textArea = {0, clientArea.bottom*0.6 - 10 , clientArea.right, clientArea.bottom*0.6 + 10 };


	TCHAR splashText[] = TEXT("Pause");
	//TCHAR buttonText[] = TEXT("VS. Computer");
	
	FillRect(dcManager.back_hdc, &backgroundArea, (HBRUSH) GetStockObject(WHITE_BRUSH));
	DrawText(dcManager.back_hdc, splashText, -1, &textArea, DT_CENTER | DT_VCENTER);

	//drawButton(buttonArea, buttonText);
	if(primary)
		BitBlt(dcManager.front_hdc, 0, 0, clientArea.right, clientArea.bottom, dcManager.back_hdc, 0, 0, SRCCOPY);
}
void PauseMenu::keyPressed(char key)
{

}
void PauseMenu::specialKeyPressed(std::string key)
{
	sceneManager->popScene(this);
}
void PauseMenu::keyReleased(char key)
{}
void PauseMenu::specialKeyReleased(std::string key)
{}
void PauseMenu::menuBarMessage(std::string message)
{}
void PauseMenu::recievedClick(int x, int y)
{}