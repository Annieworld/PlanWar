#include "FoePlane.h"


CFoePlane::CFoePlane(void)
{
	m_hBmpFoePlane = 0;
	x = 0;
	y = 0;
	m_nBlood = 0;
	m_nShowID = 0;
}


CFoePlane::~CFoePlane(void)
{
	::DeleteObject(m_hBmpFoePlane);
	m_hBmpFoePlane = 0;
}
void CFoePlane::DownBlood()
{
	m_nBlood--;
}
bool CFoePlane::IsBoom()
{
	if(m_nBlood == 0)
		return true;
	else
		return false;
}