#pragma once
#include "FoePlane.h"

class CBlastFoePlaneBox
{
public:
	CBlastFoePlaneBox(void);
	~CBlastFoePlaneBox(void);
public:
	list<CFoePlane*> m_lstBlastFoePlane;  //  װ��ը�ĵ��˷ɻ�
public:
	void AllBlastFoePlaneShow(HDC hdc);
	void ChangeShowID();
};

