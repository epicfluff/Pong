#pragma once
#include "scene.h"
#include "SceneManager.h"
#include "DeviceContextManager.h"
#include "PongController.h"
#include "RectFunctions.h"


class Menu :
	public Scene
{
	SceneManager * sceneManager;
	RECT buttonArea;

	bool clickWasInVSComputerBox(int x, int y);

public:
	Menu(SceneManager * manager);
	~Menu(void);

	void update(int deltaTime);
	void paint();
	void keyPressed(char key);
	void specialKeyPressed(std::string key);
	void keyReleased(char key);
	void specialKeyReleased(std::string key);
	void menuBarMessage(std::string message) {}
	void recievedClick(int x, int y);

};

