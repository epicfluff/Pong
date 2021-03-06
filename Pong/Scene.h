#pragma once
#include <string>

class Scene
{
public:
	virtual void update(int deltaTime)=0;
	virtual void paint(bool primary)=0;
	virtual void keyPressed(char key)=0;
	virtual void specialKeyPressed(std::string key)=0;
	virtual void keyReleased(char key)=0;
	virtual void specialKeyReleased(std::string key)=0;
	virtual void menuBarMessage(std::string message) = 0;
	virtual void recievedClick(int x, int y) {}

	virtual bool transparentBackground()
	{
		return false;
	}

};