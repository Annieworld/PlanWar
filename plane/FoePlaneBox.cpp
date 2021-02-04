#include "FoePlaneBox.h"
#include "BigFoePlane.h"
#include "MidFoePlane.h"
#include "SmallFoePlane.h"

CFoePlaneBox::CFoePlaneBox(void)
{
}


CFoePlaneBox::~CFoePlaneBox(void)
{
	//  ɾ�����еĵ��˷ɻ�
	list<CFoePlane*>::iterator ite = m_lstFoePlane.begin();
	while(ite != m_lstFoePlane.end())
	{
		//  ɾ�����˷ɻ�����
		delete (*ite);
		ite = m_lstFoePlane.erase(ite);
	}
}
void CFoePlaneBox::AllFoePlaneMove()
{
	list<CFoePlane*>::iterator ite = m_lstFoePlane.begin();
	while(ite != m_lstFoePlane.end())
	{
		//  �ж��ǳ����߽�
		if( (*ite)->y > 550 )
		{
			delete (*ite);
			ite = m_lstFoePlane.erase(ite);
		}
		else
		{
			(*ite)->MoveFoePlane();
			++ite;
		}
	}
}
void CFoePlaneBox::AllFoePlaneShow(HDC hdc)
{
	list<CFoePlane*>::iterator ite = m_lstFoePlane.begin();
	while(ite != m_lstFoePlane.end())
	{
		//  ��ʾ���˷ɻ�
		(*ite)->ShowFoePlane(hdc);
		++ite;
	}
}
void CFoePlaneBox::CreateFoePlane(HINSTANCE hIns)
{
	//  1.  ����һ�����˷ɻ�����
	CFoePlane* pFoe = 0;
	int index = rand()%12;
	if(index >= 0 && index <= 1)
		pFoe = new CBigFoePlane;
	else if(index >= 2 && index <= 5)
		pFoe = new CMidFoePlane;
	else
		pFoe = new CSmallFoePlane;
	//  2.  ��ʼ��������˷ɻ�
	pFoe->InitFoePlane(hIns);
	//  3.  ��ӵ�������
	m_lstFoePlane.push_back(pFoe);
}