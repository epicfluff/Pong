#pragma once
#ifndef PONGMODEL
#define PONGMODEL

#include "RectFunctions.h"
#include "GameObject.h"

extern RECT gameArea;
extern RECT paddelSize;
extern RECT ballSize;
extern int paddleSpeed; //units per millisecond


class PongModel
{
private:
	GameObject * playerOne;
	GameObject * playerTwo;
	GameObject * ball;

	int playerOneScore;
	int playerTwoScore;

	void initPlayers();
	void initBall();
	
	void forcePaddleIntoGameArea(RECT * player);
	void forceBallIntoGameArea();

public:
	PongModel(void);
	~PongModel(void);

	void update(int deltaTime); // in milliseconds

	void setPlayerDirectionUp(int player);
	void setPlayerDirectionDown(int player);
	void setPlayerDirectionNeutral(int player);

	void getObjectPositions(RECT * playerOne, RECT * playerTwo, RECT * ball, int * score1, int * score2);
	
};

#endif