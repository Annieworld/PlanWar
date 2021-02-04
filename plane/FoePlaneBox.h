#pragma once
#include "FoePlane.h"
class CFoePlaneBox
{
public:
	CFoePlaneBox(void);
	~CFoePlaneBox(void);
public:
	list<CFoePlane*> m_lstFoePlane;  //  装敌人飞机的链表
public:
	void AllFoePlaneMove();
	void AllFoePlaneShow(HDC hdc);
	void CreateFoePlane(HINSTANCE hIns);
};

