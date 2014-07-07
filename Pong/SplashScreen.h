#pragma once
#include "scene.h"
#include "SceneManager.h"


class SplashScreen :
	public Scene
{
	int totalEllapsedTime;
	SceneManager * sceneManager;

public:
	SplashScreen(SceneManager * manager);
	~SplashScreen(void);

	void update(int deltaTime);
	void paint();
	void keyPressed(char key);
	void specialKeyPressed(std::string key);
	void keyReleased(char key);
	void specialKeyReleased(std::string key);
};

