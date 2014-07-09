#include "stdafx.h"
#include "PongController.h"


PongController::PongController(SceneManager * manager)
{
	model = new PongModel();
	view = new PongView();
	ai = new PongAI();
	sceneManager = manager;
	pauseScreen = new PauseMenu(manager);
}


PongController::~PongController(void)
{
	delete(model);
	delete(view);
}

void PongController::paint(bool primary)
{
	RECT playerOne;
	RECT playerTwo;
	RECT ball;
	int score1;
	int score2;

	model->getObjectPositions(&playerOne, &playerTwo, &ball, &score1, &score2);

	view->paint(primary, &playerOne, &playerTwo, &ball, score1, score2);
}

void PongController::update(int deltatime)
{
	model->update(deltatime);

	RECT playerOne;
	RECT playerTwo;
	RECT ball;
	int score1;
	int score2;

	model->getObjectPositions(&playerOne, &playerTwo, &ball, &score1, &score2);
	ai->update(&playerOne, &ball);
}

void PongController::UpPressed(int player)
{
	model->setPlayerDirectionUp(player);
}
void PongController::DownPressed(int player)
{
	model->setPlayerDirectionDown(player);
}
void PongController::UpReleased(int player)
{
	model->setPlayerDirectionNeutral(player);
}
void PongController::DownReleased(int player)
{
	model->setPlayerDirectionNeutral(player);
}

void PongController::newGame()
{
	if(model)
		delete(model);
	model = new PongModel();
}


void PongController::keyPressed(char key)
{
	if(key == ' ')
	{
		sceneManager->pushScene(pauseScreen);
	}
}
void PongController::specialKeyPressed(std::string key)
{
	if(key.find("up") == 0)
	{
		UpPressed(2);
	}
	if(key.find("down") == 0)
	{
		DownPressed(2);
	}
}


void PongController::keyReleased(char key)
{}
void PongController::specialKeyReleased(std::string key)
{
	if(key.find("up") == 0)
	{
		UpReleased(2);
	}
	if(key.find("down") == 0)
	{
		DownReleased(2);
	}
}

void PongController::menuBarMessage(std::string message)
{
	if( message.find("new game") == 0 )
	{
		newGame();
	}
}