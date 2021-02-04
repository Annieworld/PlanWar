#include "Gunner.h"


CGunner::CGunner(void)
{
	x = 0;
	y = 0;
	m_hBmpGunner = 0;
}


CGunner::~CGunner(void)
{
	::DeleteObject(m_hBmpGunner);
	m_hBmpGunner = 0;
}
void CGunner::GunnerShow(HDC hdc)
{
	HDC hMemDC = ::CreateCompatibleDC(hdc);
	::SelectObject(hMemDC,m_hBmpGunner);
	::BitBlt(hdc,x,y,6,9,hMemDC,0,0,SRCAND);
	::DeleteDC(hMemDC);
}
void CGunner::InitGunner(HINSTANCE hIns, int x1, int y1)
{
	x = x1;
	y = y1;
	m_hBmpGunner = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_GUNNER));
}
void CGunner::MoveGunner()
{
	y-=10;
}