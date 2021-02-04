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
	//  1.  ��ʼ������
	back.InitBack(m_hIns);
	//  2.  ��ʼ����ҷɻ�
	plane.InitFoePlane(m_hIns);

	//  3.  �������еĶ�ʱ��
	::SetTimer(m_hMainWnd,BACK_MOVE_TIMER_ID,100,0);  //  ���Ʊ����ƶ�
	::SetTimer(m_hMainWnd,PLAYER_MOVE_TIMER_ID,1,0);   // ������ҷɻ��ƶ�
	::SetTimer(m_hMainWnd,SEND_GUNNER_TIMER_ID,350,0);  //  ��ҷɻ��������ڵ�
	::SetTimer(m_hMainWnd,GUNNER_MOVE_TIMER_ID,10,0);   //  �����ڵ��ƶ�
	::SetTimer(m_hMainWnd,CREATE_FOEPLANE_TIMER_ID,1000,0);
	::SetTimer(m_hMainWnd,FOEPLANE_MOVE_TIMER_ID,30,0);
	::SetTimer(m_hMainWnd,CHANGE_SHOWID_TIMER_ID,150,0);
}
void CPlaneApp::OnGameDraw()
{
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hMainWnd,&ps);

	HDC hMemDC = ::CreateCompatibleDC(hdc);
	HBITMAP hBitmap = ::CreateCompatibleBitmap(hdc,380,550); // hdc ���ͼƬ���Դ���ɫ
	::SelectObject(hMemDC,hBitmap);

	//------------------------------------------------------
	back.ShowBack(hMemDC);//  ��ʾ����
	plane.ShowPlayer(hMemDC);  //  ��ʾ��ҷɻ�
	gunBox.AllGunnerShow(hMemDC);  //  ��ʾ�����ڵ�
	foeBox.AllFoePlaneShow(hMemDC);  //  ��ʾ���е��˷ɻ�
	blastBox.AllBlastFoePlaneShow(hMemDC);  //  ��ʾ��ը�ĵ��˷ɻ�
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
		blastBox.ChangeShowID();  //  �л���ը��Ч��ͼ
	}
	if(nTimerID == CREATE_FOEPLANE_TIMER_ID)
	{
		foeBox.CreateFoePlane(m_hIns);  //  �������˷ɻ�
	}
	if(nTimerID == FOEPLANE_MOVE_TIMER_ID)
	{
		foeBox.AllFoePlaneMove();  //  ���˷ɻ��ƶ�
	}
	if(nTimerID == SEND_GUNNER_TIMER_ID)
	{
		plane.SendGunner(m_hIns,gunBox);  //  ���ڵ�
	}
	if(nTimerID == GUNNER_MOVE_TIMER_ID)
	{
		gunBox.AllGunnerMove();      // �����ڵ��ƶ�
		this->GunnetHitFoePlane();   //  �ڵ�����˷ɻ�
	}
	if(nTimerID == BACK_MOVE_TIMER_ID)
	{
		back.MoveBack();//�����ƶ�
	}
	if(nTimerID == PLAYER_MOVE_TIMER_ID)
	{
		if(::GetAsyncKeyState(VK_LEFT))   //  ��ȡ����״̬
			plane.MovePlayer(VK_LEFT);  
		if(::GetAsyncKeyState(VK_RIGHT))   //  ��ȡ����״̬
			plane.MovePlayer(VK_RIGHT);  
		if(::GetAsyncKeyState(VK_UP))   //  ��ȡ����״̬
			plane.MovePlayer(VK_UP);  
		if(::GetAsyncKeyState(VK_DOWN))   //  ��ȡ����״̬
			plane.MovePlayer(VK_DOWN);  
	}
	//-----------------------------------------------------------
	//  �ػ�
	RECT rect = {0,0,380,550};
	::InvalidateRect(m_hMainWnd,&rect,false);
}
void CPlaneApp::OnKeyDown(WPARAM nKey)
{
	////  ��ҷɻ��ƶ�
	//plane.MovePlayer(nKey);
	////  �ػ�
	//RECT rect = {0,0,380,550};
	//::InvalidateRect(m_hMainWnd,&rect,false);
}

void CPlaneApp::GunnetHitFoePlane()
{
	bool bflag = false; //  ��� �ڵ��Ƿ���е��˷ɻ�
	//  ----------- �������е��ڵ�-----------------
	list<CGunner*>::iterator iteGun = gunBox.m_lstGunner.begin();
	while(iteGun != gunBox.m_lstGunner.end())
	{
		//-------------�������еĵ��˷ɻ�-----------
		list<CFoePlane*>::iterator iteFoe = foeBox.m_lstFoePlane.begin();
		while(iteFoe != foeBox.m_lstFoePlane.end())
		{
			//  �ж� iteGun����ڵ� �Ƿ����iteFoe ���˷ɻ�
			if( (*iteFoe)->IsGunnerHitFoePlane(*iteGun) == true )
			{
				bflag = true;
				//  ɾ���ڵ�
				delete (*iteGun);
				iteGun = gunBox.m_lstGunner.erase(iteGun);
				//  ���˷ɻ���Ѫ
				(*iteFoe)->DownBlood();
				//  �жϵ��˷ɻ��Ƿ�ը
				if((*iteFoe)->IsBoom() == true)
				{
					//  ��������˷ɻ��Ķ���ŵ� ��ը����������ʾ��ըЧ��
					blastBox.m_lstBlastFoePlane.push_back(*iteFoe);
					//  ɾ���ڵ�
					foeBox.m_lstFoePlane.erase(iteFoe);
				}
				break;
			}
			++iteFoe;
		}
		//-------------�������еĵ��˷ɻ�-----------
		if(bflag == false)
			++iteGun;
		else
			bflag = false;
	}
}