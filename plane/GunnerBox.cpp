#include "GunnerBox.h"


CGunnerBox::CGunnerBox(void)
{
}


CGunnerBox::~CGunnerBox(void)
{
	//  ɾ�����е��ڵ�����
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end())
	{
		// ɾ���ڵ�����
		delete (*ite);
		// ɾ���ڵ��ڵ�
		ite = m_lstGunner.erase(ite);
	}
}
void CGunnerBox::AllGunnerMove()
{
	//  ���е��ڵ��ƶ�
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end())
	{
		if( (*ite)->y < 0)
		{
			//  ɾ�������߽���ڵ�
			delete (*ite);
			ite = m_lstGunner.erase(ite);
		}
		else
		{
			//  �ڵ��ƶ�
			(*ite)->MoveGunner();
			ite++;
		}
	}
}
void CGunnerBox::AllGunnerShow(HDC hdc)
{
	//  ���е��ڵ���ʾ
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end())
	{
		//  ��ʾ�ڵ�
		(*ite)->GunnerShow(hdc);
		++ite;
	}
}