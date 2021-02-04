#include "MidFoePlane.h"


CMidFoePlane::CMidFoePlane(void)
{
	x = rand()%(380-70);
	y = -90;
	m_nBlood = 3;
	m_nShowID = 2;
}


CMidFoePlane::~CMidFoePlane(void)
{
}
bool CMidFoePlane::IsGunnerHitFoePlane(CGunner* pGunner)
{
	//  判断  炮弹的坐标是否在 敌人飞机的矩形区域
	if(pGunner->x >= this->x && pGunner->x <= this->x + 70
		&& pGunner->y >= this->y && pGunner->y <= this->y + 90)
		return true;
	return false;
}
bool CMidFoePlane::IsHitPlayer(CPlayer& plane)
{
	//TODO:
	return false;
}
void CMidFoePlane::InitFoePlane(HINSTANCE hIns)
{
	//  加载位图
	m_hBmpFoePlane = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_MID));
}
void CMidFoePlane::MoveFoePlane()
{
	y+=4;
}
void CMidFoePlane::ShowFoePlane(HDC hdc)
{
	HDC hMemDC = ::CreateCompatibleDC(hdc);
	::SelectObject(hMemDC,m_hBmpFoePlane);
	::BitBlt(hdc,x,y,70,90,hMemDC,0,(2-m_nShowID)*90,SRCAND);
	::DeleteDC(hMemDC);
}