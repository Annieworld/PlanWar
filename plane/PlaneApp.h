#pragma once
#include "gameapp.h"
#include "Back.h"
#include "Player.h"
#include "GunnerBox.h"
#include "FoePlaneBox.h"
#include "BlastFoePlaneBox.h"

class CPlaneApp :
	public CGameApp
{
public:
	CPlaneApp(void);
	~CPlaneApp(void);
public:
	CBack back;   //  ����
	CPlayer plane;  // ��ҷɻ�
	CGunnerBox gunBox;  //  װ�ڵ�����
	CFoePlaneBox foeBox;  //  װ���˷ɻ�����
	CBlastFoePlaneBox blastBox;  //  ��ը�ĵ��˷�
public:
	virtual void OnCreateGame();
	virtual void OnGameDraw();
	virtual void OnGameRun(WPARAM nTimerID);
	virtual void OnKeyDown(WPARAM nKey);
public:
	void GunnetHitFoePlane();  //  �ڵ�����˷ɻ�
};

