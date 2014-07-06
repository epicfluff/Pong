#pragma once
#include "PongModel.h"
#include "PongView.h"
#include "PongAI.h"

class PongController
{

private:
	PongModel * model;
	PongView * view;
	PongAI * ai;


public:
	PongController(void);
	~PongController(void);

	void UpPressed(int player);
	void DownPressed(int player);
	void UpReleased(int player);
	void DownReleased(int player);

	void paint();
	void update(int deltatime);
	void newGame();


};

