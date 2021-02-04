#include "PlaneApp.h"

DECLARE(CPlaneApp)
CPlaneApp::CPlaneApp(void)
{
}


CPlaneApp::~CPlaneApp(void)
{
}
void CPlaneApp::OnCreateGame()
{
	//  1.  初始化背景
	back.InitBack(m_hIns);
	//  2.  初始化玩家飞机
	plane.InitFoePlane(m_hIns);

	//  3.  启动所有的定时器
	::SetTimer(m_hMainWnd,BACK_MOVE_TIMER_ID,100,0);  //  控制背景移动
	::SetTimer(m_hMainWnd,PLAYER_MOVE_TIMER_ID,1,0);   // 控制玩家飞机移动
	::SetTimer(m_hMainWnd,SEND_GUNNER_TIMER_ID,350,0);  //  玩家飞机发射跑炮弹
	::SetTimer(m_hMainWnd,GUNNER_MOVE_TIMER_ID,10,0);   //  所有炮弹移动
	::SetTimer(m_hMainWnd,CREATE_FOEPLANE_TIMER_ID,1000,0);
	::SetTimer(m_hMainWnd,FOEPLANE_MOVE_TIMER_ID,30,0);
	::SetTimer(m_hMainWnd,CHANGE_SHOWID_TIMER_ID,150,0);
}
void CPlaneApp::OnGameDraw()
{
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hMainWnd,&ps);

	HDC hMemDC = ::CreateCompatibleDC(hdc);
	HBITMAP hBitmap = ::CreateCompatibleBitmap(hdc,380,550); // hdc 这个图片可以带颜色
	::SelectObject(hMemDC,hBitmap);

	//------------------------------------------------------
	back.ShowBack(hMemDC);//  显示背景
	plane.ShowPlayer(hMemDC);  //  显示玩家飞机
	gunBox.AllGunnerShow(hMemDC);  //  显示所有炮弹
	foeBox.AllFoePlaneShow(hMemDC);  //  显示所有敌人飞机
	blastBox.AllBlastFoePlaneShow(hMemDC);  //  显示爆炸的敌人飞机
	//------------------------------------------------------
	::BitBlt(hdc,0,0,380,550,hMemDC,0,0,SRCCOPY);

	::DeleteObject(hBitmap);
	::DeleteDC(hMemDC);
	::EndPaint(m_hMainWnd,&ps);
}
void CPlaneApp::OnGameRun(WPARAM nTimerID)
{
	if(nTimerID == CHANGE_SHOWID_TIMER_ID)
	{
		blastBox.ChangeShowID();  //  切换爆炸的效果图
	}
	if(nTimerID == CREATE_FOEPLANE_TIMER_ID)
	{
		foeBox.CreateFoePlane(m_hIns);  //  创建敌人飞机
	}
	if(nTimerID == FOEPLANE_MOVE_TIMER_ID)
	{
		foeBox.AllFoePlaneMove();  //  敌人飞机移动
	}
	if(nTimerID == SEND_GUNNER_TIMER_ID)
	{
		plane.SendGunner(m_hIns,gunBox);  //  发炮弹
	}
	if(nTimerID == GUNNER_MOVE_TIMER_ID)
	{
		gunBox.AllGunnerMove();      // 所有炮弹移动
		this->GunnetHitFoePlane();   //  炮弹打敌人飞机
	}
	if(nTimerID == BACK_MOVE_TIMER_ID)
	{
		back.MoveBack();//背景移动
	}
	if(nTimerID == PLAYER_MOVE_TIMER_ID)
	{
		if(::GetAsyncKeyState(VK_LEFT))   //  获取键盘状态
			plane.MovePlayer(VK_LEFT);  
		if(::GetAsyncKeyState(VK_RIGHT))   //  获取键盘状态
			plane.MovePlayer(VK_RIGHT);  
		if(::GetAsyncKeyState(VK_UP))   //  获取键盘状态
			plane.MovePlayer(VK_UP);  
		if(::GetAsyncKeyState(VK_DOWN))   //  获取键盘状态
			plane.MovePlayer(VK_DOWN);  
	}
	//-----------------------------------------------------------
	//  重绘
	RECT rect = {0,0,380,550};
	::InvalidateRect(m_hMainWnd,&rect,false);
}
void CPlaneApp::OnKeyDown(WPARAM nKey)
{
	////  玩家飞机移动
	//plane.MovePlayer(nKey);
	////  重绘
	//RECT rect = {0,0,380,550};
	//::InvalidateRect(m_hMainWnd,&rect,false);
}

void CPlaneApp::GunnetHitFoePlane()
{
	bool bflag = false; //  标记 炮弹是否打中敌人飞机
	//  ----------- 遍历所有的炮弹-----------------
	list<CGunner*>::iterator iteGun = gunBox.m_lstGunner.begin();
	while(iteGun != gunBox.m_lstGunner.end())
	{
		//-------------遍历所有的敌人飞机-----------
		list<CFoePlane*>::iterator iteFoe = foeBox.m_lstFoePlane.begin();
		while(iteFoe != foeBox.m_lstFoePlane.end())
		{
			//  判断 iteGun这个炮弹 是否打中iteFoe 敌人飞机
			if( (*iteFoe)->IsGunnerHitFoePlane(*iteGun) == true )
			{
				bflag = true;
				//  删除炮弹
				delete (*iteGun);
				iteGun = gunBox.m_lstGunner.erase(iteGun);
				//  敌人飞机掉血
				(*iteFoe)->DownBlood();
				//  判断敌人飞机是否爆炸
				if((*iteFoe)->IsBoom() == true)
				{
					//  把这个敌人飞机的对象放到 爆炸的链表里显示爆炸效果
					blastBox.m_lstBlastFoePlane.push_back(*iteFoe);
					//  删除节点
					foeBox.m_lstFoePlane.erase(iteFoe);
				}
				break;
			}
			++iteFoe;
		}
		//-------------遍历所有的敌人飞机-----------
		if(bflag == false)
			++iteGun;
		else
			bflag = false;
	}
}