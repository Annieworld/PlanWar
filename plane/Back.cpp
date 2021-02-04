#include "Back.h"


CBack::CBack(void)
{
	m_hBmpBackDown = 0;
	m_hBmpBackUp = 0;
	x = 0;
	y = 0;
}


CBack::~CBack(void)
{
	//  É¾³ýÍ¼Æ¬
	::DeleteObject(m_hBmpBackDown);
	::DeleteObject(m_hBmpBackUp);
	m_hBmpBackDown = 0;
	m_hBmpBackUp = 0;
}
void CBack::InitBack(HINSTANCE hIns)
{
	//  ¼ÓÔØÁ½¸öÎ»Í¼
	m_hBmpBackDown = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACK));
	m_hBmpBackUp = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACK));	
}
void CBack::MoveBack()
{
	if(y > 550)
		y = 0;
	else
		y++;
}
void CBack::ShowBack(HDC hdc)
{
	//  ÌùÍ¼
	HDC hMemDC = ::CreateCompatibleDC(hdc);

	::SelectObject(hMemDC,m_hBmpBackUp);
	::BitBlt(hdc,x,y-550,380,550,hMemDC,0,0,SRCCOPY);

	::SelectObject(hMemDC,m_hBmpBackDown);
	::BitBlt(hdc,x,y,380,550,hMemDC,0,0,SRCCOPY);

	::DeleteDC(hMemDC);
}