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

#include "Definition.h"

namespace CraftEngineNet {

public ref class Conversions {
public:
	//�� int ��ʾ���岽ת��Ϊ Move ��ʾ���岽
	static Move intToMove(int theInt);

	//�� Move ��ʾ���岽ת��Ϊ int ��ʾ���岽
	static int moveToInt(Move theMove);

	//�� int ��ʾ�����巽ת��Ϊ Chess ��ʾ�����巽
	static Chess intToChess(int theInt);

	//�� Chess ��ʾ�����巽ת��Ϊ int ��ʾ�����巽
	static int chessToInt(Chess theChess);

	//�� Move �����ʾ���岽ת��Ϊ�ַ�����ʾ���岽
	static System::String^ moveToString(Move theMove);

	//�� int ��ʾ���岽ת��Ϊ�ַ�����ʾ���岽
	static System::String^ intToString(int theInt);

	//��Board^��ʾ������ת��ΪCraftEngine���ܵĸ�ʽ
	static void convertBoard(Board board, int dest[]);

};

} // namespace Othello
