/*
*************************************************************************
    Craft is an othello program with relatively high AI.
    Copyright (C) 2008-2010  Patrick

    This file is part of Craft.

    Craft is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Craft is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Craft.  If not, see <http://www.gnu.org/licenses/>.

    Craft-Othello on Google Code: <http://code.google.com/p/craft-othello/>

    Patrick's E-mail: patrick880905@sina.com
    Patrick's Blog: <http://blog.sina.com.cn/patwonder>
*************************************************************************
*/

#pragma once
/*
********************************************************************************
								Common.h
		���ߣ�Patrick
		����������ͷ�ļ����������򹫹��ĳ������塢�궨���

********************************************************************************
*/

#define __MY_FUNCTION__ "In " + __FUNCTION__ + " : "
#define __APP_NAME__ System::Windows::Forms::Application::ProductName
//#define CHRISTMAS

#ifdef CHRISTMAS
#define  __APP_SPECIAL_VERSION__ " ʥ���ر��"
#else
#define __APP_SPECIAL_VERSION__ ""
#endif

#ifdef MACHINE_X64
#define __APP_SPECIAL_VERSION_2__ " (64 λ)"
#else
#define __APP_SPECIAL_VERSION_2__ ""
#endif

#ifdef _DEBUG
#define __APP_VERSION__ (System::Windows::Forms::Application::ProductVersion + " [Debug]" + __APP_SPECIAL_VERSION_2__)
#else
#define __APP_VERSION__ (System::Windows::Forms::Application::ProductVersion + __APP_SPECIAL_VERSION__ + __APP_SPECIAL_VERSION_2__)
#endif

namespace Othello {

//������ɫ
public enum class Chess {AVAILABLE, BLACK, WHITE};

//�������
public enum class PlayerType {
	GUI, RANDOM, BIG_EAT, EARTH, CLOUDS, ORBIT, MOON, STAR, GALAXY, UNIVERSE, NETWORK
};

//Do not change - may cause unexpected problems
const int WIDTH = 8;
const int HEIGHT = 8;
const int MAX_PLAYERTYPES = 11;

//�оֹ�ֵ���ʡ����������õ��Ĺ�ֵΪ+5000����ʵ�ʹ�ֵΪ(+5000/RULER)
const int RULER = 10000;

typedef array<Chess, 2> Board;

//��ʾһ����
public value class Move {
	int x, y;
	Chess color;
public:
	static const Move invalidMove = Move(0, 0, Chess::AVAILABLE);
	Move(int x, int y, Chess color) {
		this->x = x;
		this->y = y;
		this->color = color;
	}
	int getX() { return x; }
	int getY() { return y; }
	Chess getColor() { return color; }
};

}//namespace Othello
