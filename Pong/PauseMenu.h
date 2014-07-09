#pragma once
#include "Scene.h"
#include "DeviceContextManager.h"
#include "SceneManager.h"

class PauseMenu :
	public Scene
{
	SceneManager * sceneManager;

public:
	PauseMenu(SceneManager * manager);
	~PauseMenu(void);

	void update(int deltaTime);
	void paint(bool primary);
	void keyPressed(char key);
	void specialKeyPressed(std::string key);
	void keyReleased(char key);
	void specialKeyReleased(std::string key);
	void menuBarMessage(std::string message);
	void recievedClick(int x, int y);

	bool transparentBackground()
	{
		return true;
	}
};

