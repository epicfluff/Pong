#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(int top, int left, RECT size, bool bounce)
{
	position.top = top;
	position.left = left;
	position.bottom = top + size.bottom;
	position.right = left + size.right;

	bouceOffGameAreaBorder = bounce;
	xSpeed = 0;
	ySpeed = 0;

}


GameObject::~GameObject(void)
{
}


void GameObject::update(int deltaTime)
{
	RectFunctions::translate(&position, xSpeed * deltaTime, ySpeed * deltaTime);
	forceIntoGameArea();
}

void GameObject::forceIntoGameArea()
{
	extern RECT gameArea;
	if(!bouceOffGameAreaBorder)
	{
		if(position.top < gameArea.top)
		{
			RectFunctions::translate(&position, 0, gameArea.top - position.top);
		}
		else if(position.bottom > gameArea.bottom)
		{
			RectFunctions::translate(&position, 0, gameArea.bottom - position.bottom);
		}
	}
	else
	{
		if(position.top < gameArea.top)
		{
			RectFunctions::translate(&position, 0, (gameArea.top - position.top)*2);
			ySpeed = -ySpeed;
		}
		else if(position.bottom > gameArea.bottom)
		{
			RectFunctions::translate(&position, 0, (gameArea.bottom - position.bottom)*2);
			ySpeed = -ySpeed;
		}
	}
}

void GameObject::checkForAndHandleCollision(GameObject * otherObject)
{
	if(!(position.left > otherObject->position.right || position.right < otherObject->position.left || position.bottom < otherObject->position.top || position.top > otherObject->position.bottom))
	{
		if(xSpeed > 0)
		{
			RectFunctions::translate(&position, otherObject->position.left - position.right, 0);
		}
		else
		{
			RectFunctions::translate(&position, otherObject->position.right - position.left, 0);
		}
		xSpeed = xSpeed - xSpeed*2; 
		ySpeed += (otherObject->ySpeed * 3)/5;
		
	}

}

RECT GameObject::getPosition()
{
	RECT newRect;
	RectFunctions::copy(&position, &newRect);
	return newRect;
}

void GameObject::setSpeed(int x, int y)
{
	xSpeed = x;
	ySpeed = y;
}
