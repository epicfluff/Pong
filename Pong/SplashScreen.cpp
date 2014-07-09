#include "stdafx.h"
#include "SplashScreen.h"
#include "DeviceContextManager.h"

SplashScreen::SplashScreen(SceneManager * manager)
{
	totalEllapsedTime = 0;
	sceneManager = manager;
}


SplashScreen::~SplashScreen(void)
{
}

void SplashScreen::update(int deltaTime)
{
	totalEllapsedTime +=deltaTime;
	if(totalEllapsedTime > 2000)
	{
		sceneManager->popScene(this);
		delete(this);
	}
}

void SplashScreen::paint(bool primary)
{
	extern DeviceContextManager dcManager;

	SetTextColor(dcManager.back_hdc, RGB(255,255,255));
	SetBkColor(dcManager.back_hdc, RGB(0,0,0));

	RECT clientArea;
	GetClientRect(dcManager.hwnd, &clientArea);
	RECT textArea = {0, clientArea.bottom /2 - 10, clientArea.right, clientArea.bottom};
	TCHAR splashText[] = TEXT("Pong!");
	
	FillRect(dcManager.back_hdc, &clientArea, (HBRUSH) GetStockObject(BLACK_BRUSH));
	DrawText(dcManager.back_hdc, splashText, -1, &textArea, DT_CENTER | DT_VCENTER);
	BitBlt(dcManager.front_hdc, 0, 0, clientArea.right, clientArea.bottom, dcManager.back_hdc, 0, 0, SRCCOPY);
}
void SplashScreen::keyPressed(char key)
{
	
}
void SplashScreen::specialKeyPressed(std::string key){}
void SplashScreen::keyReleased(char key){}
void SplashScreen::specialKeyReleased(std::string key){}