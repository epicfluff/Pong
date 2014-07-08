#include "stdafx.h"
#include "SceneManager.h"


SceneManager::SceneManager(void)
{

}


SceneManager::~SceneManager(void)
{
}

void SceneManager::pushScene(Scene * scene)
{
	sceneStack.push_back(scene);
}
void SceneManager::popScene(Scene * scene)
{
	sceneStack.pop_back();  //good enough for now
}

void SceneManager::update(int deltaTime)
{
	sceneStack[sceneStack.size() - 1]->update(deltaTime);
}

void SceneManager::paint()
{
	bool rollUp = false;
	int index = sceneStack.size() - 1;

	while(index <= sceneStack.size() - 1)
	{
		if(index > 0 && !rollUp && sceneStack[index]->transparentBackground() )
		{
			index--;
		}
		else
		{
			if(sceneStack.size() > index && index >= 0)
				sceneStack[index]->paint();
			index++;
			rollUp = true;
		}
	}
}
void SceneManager::keyPressed(char key)
{
	sceneStack[sceneStack.size() - 1]->keyPressed(key);
}
void SceneManager::specialKeyPressed(std::string key)
{
	sceneStack[sceneStack.size() - 1]->specialKeyPressed(key);
}
void SceneManager::keyReleased(char key)
{
	sceneStack[sceneStack.size() - 1]->keyReleased(key);
}
void SceneManager::specialKeyReleased(std::string key)
{
	sceneStack[sceneStack.size() - 1]->specialKeyReleased(key);
}

void SceneManager::menuBarMessage(std::string message)
{
	sceneStack[sceneStack.size() - 1]->menuBarMessage(message);
}

void SceneManager::recievedClick(int x, int y)
{
	sceneStack[sceneStack.size() - 1]->recievedClick(x, y);
}