#pragma once

#include "RectFunctions.h"


class GameObject
{
private:
	RECT position;
	int xSpeed;
	int ySpeed;
	bool bouceOffGameAreaBorder;

	void forceIntoGameArea();

public:
	GameObject(int top, int left, RECT size, bool bounce = false);
	~GameObject(void);

	void update(int deltaTime);
	RECT getPosition();
	void setSpeed(int x, int y);
	void checkForAndHandleCollision(GameObject * otherObject);

};

