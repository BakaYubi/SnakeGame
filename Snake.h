#pragma once
class CObjectList;
typedef int DIR;

class CSnake
{
	CObjectList *m_tailList;
	DIR m_dir;
public:
	~CSnake();
	CSnake(CObjectList *list);

	DIR getDir() { return m_dir; }
	CObjectList *getTails() { return m_tailList; }

	void setDir(DIR d) { m_dir = d; }

	void update();
	void draw();
};

