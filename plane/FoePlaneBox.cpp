#include "FoePlaneBox.h"
#include "BigFoePlane.h"
#include "MidFoePlane.h"
#include "SmallFoePlane.h"

CFoePlaneBox::CFoePlaneBox(void)
{
}


CFoePlaneBox::~CFoePlaneBox(void)
{
	//  删除所有的敌人飞机
	list<CFoePlane*>::iterator ite = m_lstFoePlane.begin();
	while(ite != m_lstFoePlane.end())
	{
		//  删除敌人飞机对象
		delete (*ite);
		ite = m_lstFoePlane.erase(ite);
	}
}
void CFoePlaneBox::AllFoePlaneMove()
{
	list<CFoePlane*>::iterator ite = m_lstFoePlane.begin();
	while(ite != m_lstFoePlane.end())
	{
		//  判断是超出边界
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
		//  显示敌人飞机
		(*ite)->ShowFoePlane(hdc);
		++ite;
	}
}
void CFoePlaneBox::CreateFoePlane(HINSTANCE hIns)
{
	//  1.  创建一个敌人飞机对象
	CFoePlane* pFoe = 0;
	int index = rand()%12;
	if(index >= 0 && index <= 1)
		pFoe = new CBigFoePlane;
	else if(index >= 2 && index <= 5)
		pFoe = new CMidFoePlane;
	else
		pFoe = new CSmallFoePlane;
	//  2.  初始化这个敌人飞机
	pFoe->InitFoePlane(hIns);
	//  3.  添加到链表中
	m_lstFoePlane.push_back(pFoe);
}