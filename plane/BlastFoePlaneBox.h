#pragma once
#include "FoePlane.h"

class CBlastFoePlaneBox
{
public:
	CBlastFoePlaneBox(void);
	~CBlastFoePlaneBox(void);
public:
	list<CFoePlane*> m_lstBlastFoePlane;  //  装爆炸的敌人飞机
public:
	void AllBlastFoePlaneShow(HDC hdc);
	void ChangeShowID();
};

