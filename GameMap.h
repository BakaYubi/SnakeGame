#pragma once
class CGameMap
{
	int m_width;
	int m_height;
	int **m_gameMap;
public:
	~CGameMap(){}
	CGameMap(int w,int h):m_width(w),m_height(h){
		m_gameMap = new int *[h];
		for (int i = 0; i < h; i++)
			m_gameMap[i] = new int[w];
		initMap();
	}
	void initMap();

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	void draw();
};

