#pragma once
class PongAI
{
public:
	PongAI(void);
	~PongAI(void);

	void update(RECT * paddlePos, RECT * ballPos);
};

