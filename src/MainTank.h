#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"

class MainTank : public Tank
{
public:
	MainTank()
	{
		m_x = 300;
		m_y = 300;
		m_color = WHITE;
		m_dir = Dir::UP;
		m_step = 2;
	}

	~MainTank(){}

	// 设置行驶方向
	void SetDir(Dir dir);
	void Display();
	void Move();

protected:
	// 绘制坦克主体
	void DrawTankBody(int style);
};
void MainTank::SetDir(Dir dir)
{
	m_dir = dir;
}

void MainTank::DrawTankBody(int style)
{
	fillrectangle(m_x - 4, m_y - 4, m_x + 4, m_y + 4);

	if (style == 1)
	{
		fillrectangle(m_x - 8, m_y - 6, m_x - 6, m_y + 6);
		fillrectangle(m_x + 6, m_y - 6, m_x + 8, m_y + 6);
	}
	else
	{
		fillrectangle(m_x - 6, m_y - 8, m_x + 6, m_y - 6);
		fillrectangle(m_x - 6, m_y + 6, m_x + 6, m_y + 8);
	}
	
}

void MainTank::Display()
{
	COLORREF color_save = getfillcolor();

	setfillcolor(m_color);

	switch (m_dir)
	{
	case UP:
		DrawTankBody(1);
		line(m_x, m_y, m_x, m_y - 10);
		break;
	case DOWN:
		DrawTankBody(1);
		line(m_x, m_y, m_x, m_y + 10);
		break;
	case LEFT:
		DrawTankBody(0);
		line(m_x, m_y, m_x - 10, m_y);
		break;
	case RIGHT:
		DrawTankBody(0);
		line(m_x, m_y, m_x + 10, m_y);
		break;
	default:
		break;
	}

	setfillcolor(color_save);
}

void MainTank::Move()
{
	switch (m_dir)
	{
	case UP:
		m_y -= m_step;
		if (m_y < 0)
			m_y = Graphic::GetScreenHeight() - 1;
		break;
	case DOWN:
		m_y += m_step;
		if (m_y > Graphic::GetScreenHeight())
			m_y = 1;
		break;
	case LEFT:
		m_x -= m_step;
		if (m_x < 0)
			m_x = Graphic::GetScreenWidth() - 1;
		break;
	case RIGHT:
		m_x += m_step;
		if (m_x > Graphic::GetScreenWidth())
			m_x = 1;
		break;
	default:
		break;
	}
}

#endif