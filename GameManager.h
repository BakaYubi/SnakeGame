#pragma once
class CGameMap;
class CSnake;
class CItem;

class CGameManager
{
	CGameMap *m_gameMap;
	CSnake *m_snake;
	CItem *m_item;
	bool m_isGameOver;

	CGameManager();
public:
	~CGameManager();
	static CGameManager *getInstance();

	void init(CGameMap *map, CSnake *snake);

	CGameMap *getGameMap() { return m_gameMap; }
	CSnake *getSnake() { return m_snake; }
	bool isGameOver() { return m_isGameOver; }

	void checkCollision();

	void updateGame();
	void draw();
};

