#include "GameMap.h"
#include "util.h"

enum TileType { BLANK, WALL };

void CGameMap::initMap()
{
	TileType tile;
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			tile = (x == 0 || x == m_width - 1 || y == 0 || y == m_height - 1) ? WALL : BLANK;
			m_gameMap[y][x] = tile;
		}
	}
}

void CGameMap::draw()
{
	char *tileImg[] = { " ", "¢Ë" };
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			ScreenPrint(x*2,y,tileImg[m_gameMap[y][x]]);
		}
	}
}
