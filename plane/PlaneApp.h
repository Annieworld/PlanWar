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
	CBack back;   //  背景
	CPlayer plane;  // 玩家飞机
	CGunnerBox gunBox;  //  装炮弹盒子
	CFoePlaneBox foeBox;  //  装敌人飞机盒子
	CBlastFoePlaneBox blastBox;  //  爆炸的敌人飞
public:
	virtual void OnCreateGame();
	virtual void OnGameDraw();
	virtual void OnGameRun(WPARAM nTimerID);
	virtual void OnKeyDown(WPARAM nKey);
public:
	void GunnetHitFoePlane();  //  炮弹打敌人飞机
};

