#pragma once
#include "Sys.h"
class CBack
{
public:
	CBack(void);
	~CBack(void);
public:
	HBITMAP m_hBmpBackDown;  //  ±³¾°Î»Í¼
	HBITMAP m_hBmpBackUp;
	int x;
	int y;
public:
	void InitBack(HINSTANCE hIns);
	void MoveBack();
	void ShowBack(HDC hdc);
};

