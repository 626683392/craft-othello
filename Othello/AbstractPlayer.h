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
								AbstractPlayer.h
		���ߣ�Patrick
		�������������������Ҫʵ�ֵĹ�����ڡ�

********************************************************************************
*/

#include "Common.h"
#include "GameContext.h"

namespace Othello {
public interface class AbstractPlayer {
public:
	/*
	������ʹ��ָ������������ĺ����巽����ʼ����Ҷ���

	������
	gc��ָ�������������
	color��ָ�������巽
	*/
	virtual void init(GameContext^ gc, Chess color) = 0;

	/*
	�������ֵ�������壬����ָ������������ĺͶ�����һ���壬��������ߵ��塣

	������
	gc��ָ�������������
	lastMove�����ֵ���һ���壬
		������Ƿ�У�lastMove.getColor()����Chess::AVAILABLE

	����ֵ�������Ƿ�У��ɷ�������ֵ��
		���򷵻�ֵ����Ϊ[0, gc->getAvailable() - 1]�����ڵ�������
		��Ӧ���岽��gc->getAvailableMove()����������
	*/
	virtual int myTurn(GameContext^ gc, Move lastMove) = 0;

	/*
	����������ֽ�������;��ֹʱ�����á���Ҷ�����뽫��Ϸ״̬���Ϊ��ֹ��
	*/
	virtual void reset() = 0;

	/*
	��������ȡ�������

	����ֵ����ǰ��Ҷ����ʾ���������
	*/
	virtual System::String^ getName() = 0;

	/*
	��������ȡ��ҵ��ӳ���Ӧʱ��

	����ֵ����ǰ��ҵ��ӳ���Ӧʱ��
	*/
	virtual int getStepDelay();

	/*
	������������ҵ��ӳ���Ӧʱ��

	������
	delay��ϣ�����õ��ӳ���Ӧʱ��

	ע�⣺��Ҷ���һ��Ҫ��getStepDelay�з��ظ�ʱ�䡣
		�������ӿ��Կ�GUIPlayer����������������Ǽ�ʱ��Ӧ�ġ�
	*/
	virtual void setStepDelay(int delay);
};

}//namespace Othello

/* AbstractPlayer ���ټ̳У�ֱ�Ӹ��ƣ�:

public ref class <ClassName> : public AbstractPlayer {
private:

public:
	<ClassName>() {}

	virtual void init(GameContext^ gc, Chess color) {

	}
	virtual int myTurn(GameContext^ gc, Move lastMove) {

	}
	virtual void reset() {

	}
	virtual System::String^ getName() {

	}
	virtual int getStepDelay() {
		return 0;
	}
	virtual void setStepDelay(int delay) {}
};

*/
