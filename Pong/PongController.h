#pragma once
#include "PongModel.h"
#include "PongView.h"
#include "PongAI.h"
#include "Scene.h"

class PongController: public Scene
{

private:
	PongModel * model;
	PongView * view;
	PongAI * ai;



public:
	PongController(void);
	~PongController(void);

	//keeping these public for the ai class, use keyPressed / Released functions below
	void UpPressed(int player);
	void DownPressed(int player);
	void UpReleased(int player);
	void DownReleased(int player);

	void newGame();

	//Scene function overrides
	void update(int deltaTime);
	void paint();
	void keyPressed(char key);
	void specialKeyPressed(std::string key);
	void keyReleased(char key);
	void specialKeyReleased(std::string key);

};

