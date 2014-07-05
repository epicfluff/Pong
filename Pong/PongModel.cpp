#include "stdafx.h"
#include "PongModel.h"

RECT gameArea = {0, 0, 50000, 25000};
RECT paddleSize = {0, 0, 1000, 10000};
RECT ballSize = {0, 0, 1000, 1000};
int paddleSpeed = 5; //units per millisecond

PongModel::PongModel(void)
{
	initPlayers();
	initBall();

}


PongModel::~PongModel(void)
{
}


void PongModel::initPlayers(void)
{
	playerOne = new GameObject(gameArea.bottom/2 - paddleSize.bottom/2, gameArea.right * 0.1, paddleSize);
	playerTwo = new GameObject(gameArea.bottom/2 - paddleSize.bottom/2, gameArea.right - gameArea.right * 0.1 - paddleSize.right, paddleSize);

	playerOneScore = 0;
	playerTwoScore = 0;

}

void PongModel::initBall(void)
{
	if(ball)
	{
		delete(ball);
	}
	ball = new GameObject(gameArea.bottom/2 - ballSize.bottom/2, gameArea.right/2 - ballSize.right/2, ballSize, true);

	SYSTEMTIME time;
	GetSystemTime(&time);

	srand(time.wMilliseconds);
	int x = rand()%2;
	int y = rand()%4;

	int ballHorizontalSpeed;
	int ballVerticalSpeed;
	if(x == 0)
		ballHorizontalSpeed = -10;
	else
		ballHorizontalSpeed = 10;
	if(y == 0)
		ballVerticalSpeed = -10;
	else if(y == 1 || y == 2)
		ballVerticalSpeed = 0;
	else
		ballVerticalSpeed = 10;

	ball->setSpeed(ballHorizontalSpeed, ballVerticalSpeed);

}

void PongModel::update(int deltaTime)
{
	playerOne->update(deltaTime);
	playerTwo->update(deltaTime);
	ball->update(deltaTime);

	ball->checkForAndHandleCollision(playerOne);
	ball->checkForAndHandleCollision(playerTwo);

	//check if ball hit goal
	if(ball->getPosition().left < gameArea.left)
	{
		playerTwoScore++;
		initBall();
	}
	else if(ball->getPosition().right > gameArea.right)
	{
		playerOneScore++;
		initBall();
	}
}


void PongModel::setPlayerDirectionUp(int player)
{
	if(player == 1)
	{
		playerOne->setSpeed(0, -paddleSpeed);
	}

	else
		playerTwo->setSpeed(0, -paddleSpeed);
}

void PongModel::setPlayerDirectionDown(int player)
{
	if(player == 1)
	{
		playerOne->setSpeed(0, paddleSpeed);
	}
	else
		playerTwo->setSpeed(0, paddleSpeed);
}

void PongModel::setPlayerDirectionNeutral(int player)
{
	if(player == 1)
	{
		playerOne->setSpeed(0, 0);
	}
	else
		playerTwo->setSpeed(0, 0);
}

void PongModel::getObjectPositions(RECT * pOne, RECT * pTwo, RECT * b, int * score1, int * score2)
{
	RectFunctions::copy(&(playerOne->getPosition()), pOne);
	RectFunctions::copy(&(playerTwo->getPosition()), pTwo);
	RectFunctions::copy(&(ball->getPosition()), b);
	*score1 = playerOneScore;
	*score2 = playerTwoScore;
}