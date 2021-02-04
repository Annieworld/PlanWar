#include "SmallFoePlane.h"




CSmallFoePlane::CSmallFoePlane(void)
{
	x = rand()%(380-34);
	y = -28;
	m_nBlood = 1;
	m_nShowID = 1;
}


CSmallFoePlane::~CSmallFoePlane(void)
{
}
bool CSmallFoePlane::IsGunnerHitFoePlane(CGunner* pGunner)
{
	//  �ж�  �ڵ��������Ƿ��� ���˷ɻ��ľ�������
	if(pGunner->x >= this->x && pGunner->x <= this->x + 34
		&& pGunner->y >= this->y && pGunner->y <= this->y + 28)
		return true;
	return false;
}
bool CSmallFoePlane::IsHitPlayer(CPlayer& plane)
{
	//TODO:
	return false;
}
void CSmallFoePlane::InitFoePlane(HINSTANCE hIns)
{
	//  ����λͼ
	m_hBmpFoePlane = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_SMALL));
}
void CSmallFoePlane::MoveFoePlane()
{
	y+=6;
}
void CSmallFoePlane::ShowFoePlane(HDC hdc)
{
	HDC hMemDC = ::CreateCompatibleDC(hdc);
	::SelectObject(hMemDC,m_hBmpFoePlane);
	::BitBlt(hdc,x,y,34,28,hMemDC,0,(1-m_nShowID)*28,SRCAND);
	::DeleteDC(hMemDC);
}