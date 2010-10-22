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
								BigEater.h
		���ߣ�Patrick
		������������ BigEater ��������
			BigEater ��ʵ�ָ��ݴ�ʳ��������ĺڰ���AI��ҡ�

********************************************************************************
*/

#include "AbstractPlayer.h"
#include "Solver.h"

namespace Othello {
ref class BigEater : public AbstractPlayer {
private:
	CraftEngine::Solver* solver;
	System::Threading::ThreadStart^ solverThreadStart;
	System::Threading::Thread^ solverThread;
	int myColor, opColor;
	int stepDelay;
	volatile bool isDone;
	bool terminated;
	CraftEngine::SolverResult* res;

	void solverStarter();
public:
	/*
	������ʹ��ָ�����ӳ���Ӧʱ�䣬��ʼ�� BigEater ����

	������
	delay��ָ�����ӳ���Ӧʱ�䡣
	*/
	BigEater(int delay);
	virtual void init(GameContext^ gc, Chess color);
	virtual int myTurn(GameContext^ gc, Move lastMove);
	virtual void reset() { 
		terminated = true;
		if (solverThread)
			if (solverThread->IsAlive) {
				solverThread->Abort();
				solverThread->Join();
			}
	}
	virtual System::String^ getName() {
		return "��ʳ";
	}
	virtual int getStepDelay() {
		return stepDelay;
	}
	virtual void setStepDelay(int delay) {
		stepDelay = delay;
	}
	~BigEater();
	!BigEater();
};
}





