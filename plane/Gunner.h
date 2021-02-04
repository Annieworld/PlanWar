#pragma once
#include "Sys.h"

class CGunner
{
public:
	CGunner(void);
	~CGunner(void);
public:
	HBITMAP m_hBmpGunner;
	int x;
	int y;
public:
	void GunnerShow(HDC hdc);
	void InitGunner(HINSTANCE hIns, int x1, int y1);
	void MoveGunner();
};

