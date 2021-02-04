#include "BlastFoePlaneBox.h"


CBlastFoePlaneBox::CBlastFoePlaneBox(void)
{
}


CBlastFoePlaneBox::~CBlastFoePlaneBox(void)
{
	list<CFoePlane*>::iterator ite = m_lstBlastFoePlane.begin();
	while(ite != m_lstBlastFoePlane.end())
	{
		delete (*ite);
		ite = m_lstBlastFoePlane.erase(ite);
	}
}
void CBlastFoePlaneBox::AllBlastFoePlaneShow(HDC hdc)
{
	list<CFoePlane*>::iterator ite = m_lstBlastFoePlane.begin();
	while(ite != m_lstBlastFoePlane.end())
	{
		(*ite)->ShowFoePlane(hdc);
		++ite;
	}
}
void CBlastFoePlaneBox::ChangeShowID()
{
	list<CFoePlane*>::iterator ite = m_lstBlastFoePlane.begin();
	while(ite != m_lstBlastFoePlane.end())
	{
		//  �жϱ�ը��Ч��ͼ�Ƿ���ʾ��
		if((*ite)->m_nShowID == 0)
		{
			delete(*ite);
			ite = m_lstBlastFoePlane.erase(ite);
		}
		else
		{
			(*ite)->m_nShowID--;
			++ite;
		}
	}
}