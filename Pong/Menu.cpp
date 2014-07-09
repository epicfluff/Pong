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
void Menu::paint(bool primary)
{
	extern DeviceContextManager dcManager;

	SetTextColor(dcManager.back_hdc, RGB(255,255,255));
	SetBkColor(dcManager.back_hdc, RGB(0,0,0));

	RECT clientArea;
	GetClientRect(dcManager.hwnd, &clientArea);
	RECT textArea = {0, clientArea.bottom /2 - 10, clientArea.right, clientArea.bottom/2 + 10};
	RECT buttonAreaCopy = { clientArea.right/2 - 50, clientArea.bottom/2 + 27, clientArea.right/2 + 50, clientArea.bottom/2 + 50 };
	RectFunctions::copy(&buttonAreaCopy, &buttonArea); 

	TCHAR splashText[] = TEXT("Pong!");
	TCHAR buttonText[] = TEXT("VS. Computer");
	
	FillRect(dcManager.back_hdc, &clientArea, (HBRUSH) GetStockObject(BLACK_BRUSH));
	DrawText(dcManager.back_hdc, splashText, -1, &textArea, DT_CENTER | DT_VCENTER);

	drawButton(buttonArea, buttonText);

	BitBlt(dcManager.front_hdc, 0, 0, clientArea.right, clientArea.bottom, dcManager.back_hdc, 0, 0, SRCCOPY);
}

void Menu::drawButton(RECT location, TCHAR text[])
{
	extern DeviceContextManager dcManager;

	HPEN whitePen = CreatePen(PS_SOLID, 1, RGB(255,255,255));
	HPEN oldPen = (HPEN)SelectObject(dcManager.back_hdc, whitePen);

	HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(dcManager.back_hdc, blackBrush);

	Rectangle(dcManager.back_hdc, location.left, location.top, location.right, location.bottom);

	SelectObject(dcManager.back_hdc, oldPen);
	DeleteObject(whitePen);

	SelectObject(dcManager.back_hdc, oldBrush);
	DeleteObject(blackBrush);

	location.top +=3;

	DrawText(dcManager.back_hdc, text, -1, &location, DT_CENTER | DT_VCENTER);
}


void Menu::keyPressed(char key)
{
	extern PongController * pongGame;
	pongGame = new PongController(sceneManager);
	sceneManager->popScene(this);
	sceneManager->pushScene(pongGame);
	delete(this);

}
void Menu::specialKeyPressed(std::string key)
{
	extern PongController * pongGame;
	pongGame = new PongController(sceneManager);
	sceneManager->popScene(this);
	sceneManager->pushScene(pongGame);
	delete(this);
}
void Menu::keyReleased(char key){}
void Menu::specialKeyReleased(std::string key){}

void Menu::recievedClick(int x, int y)
{
	if (clickWasInVSComputerBox(x, y))
	{
		extern PongController * pongGame;
		pongGame = new PongController(sceneManager);
		sceneManager->popScene(this);
		sceneManager->pushScene(pongGame);
		delete(this);
	}
}

bool Menu::clickWasInVSComputerBox(int x, int y)
{
	if(x<buttonArea.left || x>buttonArea.right || y<buttonArea.top || y>buttonArea.bottom)
		return false;
	return true;
}