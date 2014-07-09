#pragma once
#include "PongModel.h"
#include "PongView.h"
#include "PongAI.h"
#include "Scene.h"
#include "SceneManager.h"
#include "PauseMenu.h"

class PongController: public Scene
{

private:
	PongModel * model;
	PongView * view;
	PongAI * ai;

	SceneManager * sceneManager;
	PauseMenu * pauseScreen;

public:
	PongController(SceneManager * manager);
	~PongController(void);

	//keeping these public for the ai class, use keyPressed / Released functions below
	void UpPressed(int player);
	void DownPressed(int player);
	void UpReleased(int player);
	void DownReleased(int player);

	void newGame();

	//Scene function overrides
	void update(int deltaTime);
	void paint(bool primary);
	void keyPressed(char key);
	void specialKeyPressed(std::string key);
	void keyReleased(char key);
	void specialKeyReleased(std::string key);
	void menuBarMessage(std::string message);

};

