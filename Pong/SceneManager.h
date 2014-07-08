#pragma once

#include "Scene.h"

#include <vector>

class SceneManager
{
	std::vector<Scene *> sceneStack;

public:
	SceneManager(void);
	~SceneManager(void);

	void pushScene(Scene * scene);
	void popScene(Scene * scene);

	//interfacing between the scenes and windows
	void update(int deltaTime);
	void paint();
	void keyPressed(char key);
	void specialKeyPressed(std::string key);
	void keyReleased(char key);
	void specialKeyReleased(std::string key);
	void menuBarMessage(std::string message);
	void recievedClick(int x, int y);
};

