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

/*
********************************************************************************
								SearchRelated.cpp
		���ߣ�Patrick
		���������� getAIPlayerName �� getAISearchOptions �����Ķ��塣

********************************************************************************
*/

#include "StdAfx.h"
#include "SearchRelated.h"

using namespace Othello;

System::String^ Players::getAIPlayerName(PlayerType type) {
	switch (type) {
	case PlayerType::RANDOM:
		return "���";
	case PlayerType::BIG_EAT:
		return "��ʳ";
	case PlayerType::EARTH:
		return "����";
	case PlayerType::CLOUDS:
		return "�ƶ�";
	case PlayerType::ORBIT:
		return "���";
	case PlayerType::MOON:
		return "����";
	case PlayerType::STAR:
		return "����";
	case PlayerType::GALAXY:
		return "��ϵ";
	case PlayerType::UNIVERSE:
		return "����";
	default:
		return "δ֪����";
	}
}

SearchOptions Players::getAISearchOptions(PlayerType type) {
	switch (type) {
	case PlayerType::EARTH:
		return SearchOptions(1, 6, 6, 6, 6, 6);
	case PlayerType::CLOUDS:
		return SearchOptions(2, 8, 8, 8, 8, 8);
	case PlayerType::ORBIT:
		return SearchOptions(4, 12, 12, 12, 12, 12);
	case PlayerType::MOON:
		return SearchOptions(8, 16, 16, 16, 16, 16);
	case PlayerType::STAR:
		return SearchOptions(12, 22, 22, 20, 20, 22);
	case PlayerType::GALAXY:
		return SearchOptions(16, 26, 24, 22, 22, 24);
	case PlayerType::UNIVERSE:
		return SearchOptions(18, 28, 26, 24, 24, 26);
	default:
		return SearchOptions(1, 6, 6, 6, 6, 6);
	}
}
