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
								Conversions.h
		���ߣ�Patrick
		��������������ת��������������

********************************************************************************
*/

#include "Common.h"
#include "Solver.h"

namespace Othello {

namespace Conversions {
	//�� int ��ʾ���岽ת��Ϊ System::Drawing::Point �����ʾ���岽
	System::Drawing::Point intToPoint(int theInt);

	//�� int ��ʾ�����巽ת��Ϊ Chess ��ʾ�����巽
	Chess intToChess(int theInt);

	//�� System::Drawing::Point �����ʾ���岽ת��Ϊ�ַ�����ʾ���岽
	System::String^ pointToString(System::Drawing::Point thePoint);

	//�� int ��ʾ���岽ת��Ϊ�ַ�����ʾ���岽
	System::String^ intToString(int theInt);

	//��Board^��ʾ������ת��ΪCraftEngine���ܵĸ�ʽ
	void convertBoard(Board^ board, int dest[]);

} // namespace Conversions

} // namespace Othello
