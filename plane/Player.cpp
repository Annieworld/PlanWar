#include "Player.h"


CPlayer::CPlayer(void)
{
	m_nGunnerType = 1;
	m_hBmpPlayer = 0;
	x = 160;
	y = 490;
}


CPlayer::~CPlayer(void)
{
	::DeleteObject(m_hBmpPlayer);
	m_hBmpPlayer = 0;
}
void CPlayer::InitFoePlane(HINSTANCE hIns)
{
	// 加载图片
	m_hBmpPlayer = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_PLAYER));
}
void CPlayer::MovePlayer(int FX)
{
	if(FX == VK_LEFT)
	{
		if(x > 0)
			x-=2;
	}
	if(FX == VK_RIGHT)
	{
		if(x < 320)
			x+=2;
	}
	if(FX == VK_UP)
	{
		if(y > 0)
			y-=2;
	}
	if(FX == VK_DOWN)
	{
		if(y < 490)
			y+=2;
	}
}
void CPlayer::ShowPlayer(HDC hdc)
{
	HDC hMemDC = ::CreateCompatibleDC(hdc);
	::SelectObject(hMemDC,m_hBmpPlayer);
	::BitBlt(hdc,x,y,60,60,hMemDC,0,0,SRCAND);
	::DeleteDC(hMemDC);
}

void CPlayer::SendGunner(HINSTANCE hIns, CGunnerBox& gunBox)
{
	//  1. 创建一个炮弹对象
	CGunner* pGunner = new CGunner;
	//  2. 初始化这个炮弹
	pGunner->InitGunner(hIns,x+27,y-9);
	//  3. 放到装炮弹的盒子理
	gunBox.m_lstGunner.push_back(pGunner);
}