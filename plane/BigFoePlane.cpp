#include "BigFoePlane.h"


CBigFoePlane::CBigFoePlane(void)
{
	x = rand()%(380-108);
	y = -128;
	m_nBlood = 5;
	m_nShowID = 3;
}


CBigFoePlane::~CBigFoePlane(void)
{
}
bool CBigFoePlane::IsGunnerHitFoePlane(CGunner* pGunner)
{
	//  �ж�  �ڵ��������Ƿ��� ���˷ɻ��ľ�������
	if(pGunner->x >= this->x && pGunner->x <= this->x + 108
		&& pGunner->y >= this->y && pGunner->y <= this->y + 128)
		return true;
	return false;
}
bool CBigFoePlane::IsHitPlayer(CPlayer& plane)
{
	//TODO:
	return false;
}
void CBigFoePlane::InitFoePlane(HINSTANCE hIns)
{
	//  ����λͼ
	m_hBmpFoePlane = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BIG));
}
void CBigFoePlane::MoveFoePlane()
{
	y+=2;
}
void CBigFoePlane::ShowFoePlane(HDC hdc)
{
	HDC hMemDC = ::CreateCompatibleDC(hdc);
	::SelectObject(hMemDC,m_hBmpFoePlane);
	::BitBlt(hdc,x,y,108,128,hMemDC,0,(3-m_nShowID)*128,SRCAND);
	::DeleteDC(hMemDC);
}