#include "GameMap.h"
#include "GameManager.h"
#include "ObjectList.h"
#include "Snake.h"
#include "Tail.h"
#include "util.h"
#include <conio.h>
#include <time.h>

void main()
{
	CGameMap *gameMap = new CGameMap(25, 25);

	CObjectList *tailList = new CObjectList;
	CGameObject *snakeHead = new CTail(10, 10);
	tailList->pushFront(snakeHead);

	CSnake *snake = new CSnake(tailList);

	CGameManager::getInstance()->init(gameMap, snake);

	time_t curTime, oldTime = clock();
	ScreenInit();
	bool isContinue = true;

	while (isContinue) {
		CGameManager::getInstance()->updateGame();

		ScreenClear();
		CGameManager::getInstance()->draw();
		ScreenFlipping();

		if (CGameManager::getInstance()->isGameOver())
			isContinue = false;
		while (1) {
			curTime = clock();
			if (curTime - oldTime > 33) {
				curTime = oldTime;
				break;
			}
		}
	}
}