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
								Observer.h
		���ߣ�Patrick
		�������������й۲�����Ҫʵ�ֵĽӿ�

********************************************************************************
*/

#include "Common.h"

namespace Othello {
public interface class Observer {
public:
	/*
	��������ĳһ���巽����һ����ʱ������

	������
	move�����ߵ��ǲ���
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void playerMoved(Move move, 
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	��������Ϸ��ʼʱ������

	������
	firstPlayer�����ַ�
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void gameStarted(Chess firstPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	��������Ϸ��;����ʱ������

	������
	firstPlayer�����ַ�
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void gameReseted(Chess firstPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	��������Ϸ����ʱ������

	������
	winner����ʤ����ƽ��Ϊ Chess::AVAILABLE
	nBlack���ڷ�����������
	nWhite���׷�����������
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void gameEnded(Chess winner, int nBlack, int nWhite, 
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	����������Ϸ��ͣʱ������

	������
	currentPlayer����ǰ���巽
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void gameHasBeenPaused(Chess currentPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	�������ı��ʼ����ʱ������

	������
	firstPlayer�����ַ�
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void boardChanged(Chess firstPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	��������;�л�����ʱ������

	������
	firstPlayer�����ַ�
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void playerChanged(Chess currentPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	�������ı�ʱ��ʱ������

	������
	timeLimit���µ�ʱ��
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void timeLimitChanged(int timeLimit,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	��������Ϸ��;����ʱ������

	������
	overTimer����ʱ��
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void playerOverTimed(Chess overTimer,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	������һ������ʱ������

	������
	step������Ĳ���
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void gameGoneBack(int step,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;

	/*
	������һ��ȡ������ʱ������

	������
	step��ȡ������Ĳ���
	gcBlack���ڷ������������
	gcWhite���׷������������
	*/
	virtual void gameGoneForward(int step,
		GameContext^ gcBlack, GameContext^ gcWhite) = 0;
};

} // namespace Othello

/* Observer ���ټ̳У�ֱ�Ӹ��ƣ�

public ref class <ClassName> : public Observer {
private:

public:
	<ClassName>() {}

	virtual void playerMoved(Move move, 
		GameContext^ gcBlack, GameContext^ gcWhite) {

	}

	virtual void gameStarted(Chess firstPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) {
	
	}

	virtual void gameReseted(Chess firstPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) {
	
	}

	virtual void gameEnded(Chess winner, int nBlack, int nWhite, 
		GameContext^ gcBlack, GameContext^ gcWhite) {
	
	}

	virtual void gameHasBeenPaused(Chess currentPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) {

	}

	virtual void boardChanged(Chess firstPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) {

	}

	virtual void playerChanged(Chess currentPlayer,
		GameContext^ gcBlack, GameContext^ gcWhite) {
	
	}

	virtual void timeLimitChanged(int timeLimit,
		GameContext^ gcBlack, GameContext^ gcWhite) {

	}

	virtual void playerOverTimed(Chess overTimer,
		GameContext^ gcBlack, GameContext^ gcWhite) {

	}

	virtual void gameGoneBack(int step,
		GameContext^ gcBlack, GameContext^ gcWhite) {
	
	}

	virtual void gameGoneForward(int step,
		GameContext^ gcBlack, GameContext^ gcWhite) {
	}
};

*/