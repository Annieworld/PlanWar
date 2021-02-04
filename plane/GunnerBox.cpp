#include "GunnerBox.h"


CGunnerBox::CGunnerBox(void)
{
}


CGunnerBox::~CGunnerBox(void)
{
	//  删除所有的炮弹对象
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end())
	{
		// 删除炮弹对象
		delete (*ite);
		// 删除炮弹节点
		ite = m_lstGunner.erase(ite);
	}
}
void CGunnerBox::AllGunnerMove()
{
	//  所有的炮弹移动
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end())
	{
		if( (*ite)->y < 0)
		{
			//  删除超出边界的炮弹
			delete (*ite);
			ite = m_lstGunner.erase(ite);
		}
		else
		{
			//  炮弹移动
			(*ite)->MoveGunner();
			ite++;
		}
	}
}
void CGunnerBox::AllGunnerShow(HDC hdc)
{
	//  所有的炮弹显示
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end())
	{
		//  显示炮弹
		(*ite)->GunnerShow(hdc);
		++ite;
	}
}