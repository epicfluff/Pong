#pragma once
#include "RectFunctions.h"

class PongView
{
private:

	void paintPlayAreaInRect(RECT * playerOne, RECT * playerTwo, RECT * ball, RECT * area);
	void paintScoreBoard(RECT * scoreBoardArea, int playerOneScore, int playerTwoScore);

public:
	PongView(void);
	~PongView(void);

	void paint(bool primary, RECT * playerOne, RECT * playerTwo, RECT * ball, int playerOneScore, int playerTwoScore);
};

