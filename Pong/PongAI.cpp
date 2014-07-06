#include "stdafx.h"
#include "PongAI.h"
#include "PongController.h"


PongAI::PongAI(void)
{
}


PongAI::~PongAI(void)
{
}

void PongAI::update(RECT * paddlePos, RECT * ballPos)
{
	extern PongController * pongGame;

	if(ballPos->bottom < paddlePos->top)
		pongGame->UpPressed(1);
	else if(ballPos->top > paddlePos->bottom)
		pongGame->DownPressed(1);
	else
		pongGame->DownReleased(1);
}