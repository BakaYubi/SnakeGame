#include "GameManager.h"
#include "Tail.h"
#include "Snake.h"
#include "Item.h"
#include "GameMap.h"
#include "ObjectList.h"
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "util.h"

CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
}

CGameManager * CGameManager::getInstance()
{
	static CGameManager instance;
	return & instance;
}

void CGameManager::init(CGameMap * map, CSnake * snake)
{
	m_gameMap = map;
	m_snake = snake;
	int width = m_gameMap->getWidth();
	int height = m_gameMap->getHeight();

	int x = 1 + rand() % (width - 2);
	int y = 1 + rand() % (height - 2);
	m_item = new CItem(x, y);

	m_isGameOver = false;
}

void CGameManager::checkCollision()
{
}

void CGameManager::updateGame()
{
	time_t curTime, oldTime = clock();
	while (1) {
		if (_kbhit()) {
			int nKey = _getch();
			DIR dir = m_snake->getDir();
			if (nKey == LEFT || nKey == RIGHT || nKey == UP || nKey == DOWN)
				dir = nKey;
			m_snake->setDir(dir);
		}
		curTime = clock();
		if (curTime - oldTime > 33 * 4) {
			oldTime = curTime;
			break;
		}
	}
	m_snake->update();
	checkCollision();
}

void CGameManager::draw()
{
	m_gameMap->draw();

	int tNum = m_snake->getTails()->getCount();
	for (int i = 0; i < tNum; i++)
		m_snake->getTails()->getObject(i)->draw();

	m_item->draw();

	if (m_isGameOver) {
		int x = m_gameMap->getWidth() / 2;
		int y = m_gameMap->getHeight() / 2;
		ScreenPrint(x, y, "Game Over...!!!");
	}
}
