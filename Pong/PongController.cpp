#include "stdafx.h"
#include "PongController.h"


PongController::PongController(void)
{
	model = new PongModel();
	view = new PongView();

}


PongController::~PongController(void)
{
	delete(model);
	delete(view);
}

void PongController::paint()
{
	RECT playerOne;
	RECT playerTwo;
	RECT ball;
	int score1;
	int score2;

	model->getObjectPositions(&playerOne, &playerTwo, &ball, &score1, &score2);

	view->paint(&playerOne, &playerTwo, &ball, score1, score2);
}

void PongController::update(int deltatime)
{
	model->update(deltatime);
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