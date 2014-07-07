#include "stdafx.h"
#include "Menu.h"


Menu::Menu(SceneManager * manager)
{
	sceneManager = manager;
}


Menu::~Menu(void)
{
}

void Menu::update(int deltaTime)
{}
void Menu::paint()
{
	extern DeviceContextManager dcManager;

	SetTextColor(dcManager.back_hdc, RGB(255,255,255));
	SetBkColor(dcManager.back_hdc, RGB(0,0,0));

	RECT clientArea;
	GetClientRect(dcManager.hwnd, &clientArea);

	TCHAR splashText[] = TEXT("Menu");
	
	FillRect(dcManager.back_hdc, &clientArea, (HBRUSH) GetStockObject(BLACK_BRUSH));
	DrawText(dcManager.back_hdc, splashText, -1, &clientArea, DT_CENTER | DT_VCENTER);
	BitBlt(dcManager.front_hdc, 0, 0, clientArea.right, clientArea.bottom, dcManager.back_hdc, 0, 0, SRCCOPY);
}
void Menu::keyPressed(char key)
{
	extern PongController * pongGame;
	pongGame = new PongController();
	sceneManager->popScene(this);
	sceneManager->pushScene(pongGame);
	delete(this);

}
void Menu::specialKeyPressed(std::string key)
{
	extern PongController * pongGame;
	pongGame = new PongController();
	sceneManager->popScene(this);
	sceneManager->pushScene(pongGame);
	delete(this);
}
void Menu::keyReleased(char key){}
void Menu::specialKeyReleased(std::string key){}