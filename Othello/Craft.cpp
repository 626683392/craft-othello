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
								Craft.cpp
		���ߣ�Patrick
		������������ Craft �Ķ��塣
			Craft ��ʵ��ʹ�� CraftEngine ����ĺڰ���AI��ҡ�

********************************************************************************
*/

#include "StdAfx.h"
#include "Craft.h"

using namespace Othello;
using namespace System::Threading;
using namespace CraftEngine;

int Othello::GetTickCount();

Craft::Craft(SearchDisplayer^ display, SearchOptions opts,
			 System::String^ name, UserInfo^ userInfo)
			 : displayer(display), options(opts)
{
	this->userInfo = userInfo;
	myName = name;
	solver = Solver::newInstance();
	solver->setBookTolerance(userInfo->BookTolerance);
	solverThreadStart = gcnew ThreadStart(this, &Craft::solverStarter);
	res = new SolverResult(0, -1);
	isDone = false;
	endSolve = false;
	//if (options.winLossStep < options.exactGameStep)
	//	options.winLossStep = options.exactGameStep;
}

Craft::!Craft() {
	delete solver;
	delete res;
	solver = NULL;
	res = NULL;
}

Craft::~Craft() {
	this->!Craft();
}

void Craft::init(GameContext^ gc, Chess color) {
	myColor = (color == Chess::BLACK) ? Solver::BLACK : Solver::WHITE;
	opColor = Solver::BLACK + Solver::WHITE - myColor;
	empties = 0;
	int board[Solver::MAXSTEP];
	for (int i = 0; i < Solver::MAXSTEP; i++)
		switch (gc->get(i / HEIGHT, i % HEIGHT)) {
		case Chess::BLACK :
			board[i] = Solver::BLACK;
			break;
		case Chess::WHITE :
			board[i] = Solver::WHITE;
			break;
		case Chess::AVAILABLE :
			board[i] = Solver::AV;
			empties++;
	}
	solver->setBoard(board);
}

void Craft::solverStarter() {
	if (empties >= options.partialExactStep50) {
		percentage = 0;
		(*res) = solver->solve(myColor, options.midGameDepth, userInfo->UseBook);
	} else if (empties >= options.partialExactStep90) {
		int percentage;
		(*res) = solver->partialSolveExact(myColor, false, 60, percentage);
		this->percentage = percentage;
	} else if (empties >= options.partialExactStep99) {
		int percentage;
		(*res) = solver->partialSolveExact(myColor, false, 95, percentage);
		this->percentage = percentage;
	} else if (empties >= options.exactGameStep) {
		int percentage;
		(*res) = solver->partialSolveExact(myColor, false, 99, percentage);
		this->percentage = percentage;
	} else {
		percentage = 100;
		(*res) = solver->solveExact(myColor, false);
	}
	isDone = true;
}

System::String^ Craft::getSpeedDescription(int speed) {
	if (!userInfo->ShowSpeed) return "";
	if (speed == 0) return "";
	return speed.ToString() + " Kn/s";
}

System::String^ Craft::getTotalNumDescription(unsigned long long totalNum) {
	if (!userInfo->ShowSpeed) return "";
	if (totalNum >= 1000000000) // Gn
		return ((double)(totalNum / 1000000) / 1000).ToString("0.000") + " Gn";
	else if (totalNum >= 100000000)
		return ((double)(totalNum / 100000) / 10).ToString("000.0") + " Mn";
	else if (totalNum >= 10000000)
		return ((double)(totalNum / 10000) / 100).ToString("00.00") + " Mn";
	else if (totalNum >= 1000000)
		return ((double)(totalNum / 1000) / 1000).ToString("0.000") + " Mn";
	else if (totalNum >= 100000)
		return ((double)(totalNum / 100) / 10).ToString("000.0") + " Kn";
	else if (totalNum >= 10000)
		return ((double)(totalNum / 10) / 100).ToString("00.00") + " Kn";
	else if (totalNum >= 1000)
		return ((double)(totalNum) / 1000).ToString("0.000") + " Kn";
	else return totalNum + " n";
}

int Craft::myTurn(GameContext^ gc, Move lastMove) {
	terminated = false;
	if (lastMove.getColor() != Chess::AVAILABLE) {
		solver->makeMove(lastMove.getX() * HEIGHT + lastMove.getY(), opColor);
		empties--;
	}
	if (gc->getAvailableCount() == 0) {
		displayer->setResult(userInfo->ShowEvaluation ? "Ƿ��" : "����");
		displayer->setSpeed("");
		displayer->setTotalNum(getTotalNumDescription(0));
		displayer->setProgress(100);
		return 0;
	}
	empties--;
	if (gc->getAvailableCount() == 1 && !endSolve) {
		System::Drawing::Point thisMove = gc->getAvailableMove(0);
		solver->makeMove(thisMove.X * HEIGHT + thisMove.Y, myColor);
		setSelectedMove(thisMove.X * HEIGHT + thisMove.Y);
		displayer->setResult(userInfo->ShowEvaluation ? "������" : "����");
		displayer->setSpeed("");
		displayer->setTotalNum(getTotalNumDescription(0));
		displayer->setProgress(100);
		return 0;
	}
	isDone = false;
	bool startThinking = true;
	displayer->searchStarted();
	solver->clearSearchStats();
	solverThread = gcnew Thread(solverThreadStart);
	solverThread->Start();
	System::DateTime timeStart = System::DateTime::UtcNow;
	double elapsedMilliseconds;
	while (!isDone) {
		elapsedMilliseconds = (System::DateTime::UtcNow - timeStart).TotalMilliseconds;
		if (elapsedMilliseconds > 100.0) {
			if (startThinking) {
				startThinking = false;
				displayer->setSearchState(true);
			}
			if (userInfo->ShowEvaluation) {
				displayer->setResult(
					getPartialResultDescription(solver->getPartialResult(), solver->getPartialDepth(),
					solver->getEpcPercentage())
				);
				setFocusedMove(solver->getFocusedMove());
				setSelectedMove(solver->getSelectedMove());
			}
			unsigned long long totalNum = solver->getEvNum();
			int speed = (int)(totalNum / (unsigned long long)elapsedMilliseconds);
			displayer->setSpeed(getSpeedDescription(speed));
			displayer->setTotalNum(getTotalNumDescription(totalNum));
			displayer->setProgress(solver->getPercent());
		}
		System::Windows::Forms::Application::DoEvents();
		if (terminated) {
			displayer->searchEnded();
			return -1;
		}
		Thread::Sleep(40);
	}
	setFocusedMove(-1);
	unsigned long long totalNum = solver->getEvNum();
	int speed = 0;
	elapsedMilliseconds = (System::DateTime::UtcNow - timeStart).TotalMilliseconds;
	if (elapsedMilliseconds > 100.0)
		speed = (int)(totalNum / (unsigned long long)elapsedMilliseconds);
	displayer->setResult(getResultDescription());
	displayer->setSpeed(getSpeedDescription(speed));
	displayer->setTotalNum(getTotalNumDescription(totalNum));
	displayer->setProgress(100);
	displayer->setSearchState(false);
	displayer->searchEnded();
	int move = res->getBestMove();
	if (move < 0) move = -move - 1;
	setSelectedMove(move);
	solver->makeMove(move, myColor);
	for (int i = 0; i < gc->getAvailableCount(); i++)
		if (gc->getAvailableMove(i).X * HEIGHT + gc->getAvailableMove(i).Y == move) {
			return i;
		}
	// It won't get here
	resetComponents();
	System::Windows::Forms::MessageBox::Show("Solver δ�ܸ����Ϸ��岽��", "������~~",
		System::Windows::Forms::MessageBoxButtons::OK,
		System::Windows::Forms::MessageBoxIcon::Error);
	return -1;
}

void Craft::resetComponents() {
	displayer->resetComponents();
}

void Craft::reset() {
	terminated = true;
	resetComponents();
	if (solverThread)
		if (solverThread->IsAlive) {
			solver->abortSearch();
			solverThread->Join();
			solver->abortSearchComplete();
		}
}

System::String^ Craft::getName() {
	return myName;
}

System::String^ Craft::getPartialResultDescription(int partialResult, int partialDepth, int percentage) {
	System::String^ result;
	if (partialDepth > 0) {
		if (partialResult > Solver::INFINITE - Solver::MAXSTEP) { // early win
			result = (partialResult == Solver::INFINITE ? "" : "��")
				+ "+" + (partialResult - Solver::INFINITE + Solver::MAXSTEP).ToString();
		} else if (partialResult < -Solver::INFINITE + Solver::MAXSTEP) { // early loss
			result = (partialResult == -Solver::INFINITE ? "" : "��")
				+ (partialResult + Solver::INFINITE - Solver::MAXSTEP).ToString();
		} else {
			result = ((partialResult > 0) ? "+" : ((partialResult == 0) ? "" : "-"))
				+ (System::Math::Abs((double)(partialResult)) / Solver::RULER).ToString("0.00");
		}
		result += " @ " + partialDepth.ToString();
	} else if (partialDepth == Solver::PARTIALDEPTH_WLD) {
		if (partialResult > 0)
			result = "ʤ";
		else if (partialResult == 0)
			result = "ƽ";
		else result = "��";
		result += percentage == 100 ? " @ ʤ��" : (" @ " + percentage + "%");
	} else if (partialDepth == Solver::PARTIALDEPTH_EXACT) {
		result = ((partialResult > 0) ? "+" : "") 
			+ partialResult.ToString();
		result += percentage == 100 ? " @ �վ�" : (" @ " + percentage + "%");
	} else {
		result = "˼����";
	}
	return result;
}

System::String^ Craft::getResultDescription() {
	if (!userInfo->ShowEvaluation) return "����";
	System::String^ result;
	int r = res->getResult();
	if (empties >= options.partialExactStep50) {
		int bm = res->getBestMove();
		if (r > Solver::INFINITE - Solver::MAXSTEP) { // early win
			result = ((bm < 0) ? "����: " : (r == Solver::INFINITE ? "" : "��")) 
				+ "+" + (r - Solver::INFINITE + Solver::MAXSTEP).ToString();
		} else if (r < -Solver::INFINITE + Solver::MAXSTEP) { // early loss
			result = ((bm < 0) ? "����: " : (r == -Solver::INFINITE ? "" : "��"))
				+ (r + Solver::INFINITE - Solver::MAXSTEP).ToString();
		} else {
			if (bm >= 0) {
				result = ((r > 0) ? "+" : ((r == 0) ? "" : "-"))
					+ (System::Math::Abs((double)r) / Solver::RULER).ToString("0.00");
			} else {
				if (System::Math::Abs(r) < 4 * Solver::RULER)
					result = "����";
				else result = "����: " + ((r > 0) ? "+" : ((r == 0) ? "" : "-"))
					+ (System::Math::Abs((double)r) / Solver::RULER).ToString("0.00");
			}
		}
	} else if (empties >= options.exactGameStep) {
		result = ((r > 0) ? "+" : "") + r.ToString();
		// +64 & -64 must be accurate evals even though in a selective search
		if (r != Solver::MAXSTEP && r != -Solver::MAXSTEP)
			result += " @ " + percentage.ToString() + "%";
	} else {
		result = ((r > 0) ? "+" : "") + r.ToString();
	}
	return result;
}

void Craft::setFocusedMove(int move) {
	if (move >= 0 && move < Solver::MAXSTEP)
		displayer->setFocusedMove(move / HEIGHT, move % HEIGHT);
	else displayer->setFocusedMove(-1, -1);
}

void Craft::setSelectedMove(int move) {
	if (move >= 0 && move < Solver::MAXSTEP)
		displayer->setSelectedMove(move / HEIGHT, move % HEIGHT);
	else displayer->setSelectedMove(-1, -1);
}

int Craft::getTip(GameContext^ gc, Move lastMove, bool endSolve) {
	solver->setBookTolerance(0);
	int pExactStep50, pExactStep90, pExactStep99, exactGameStep;
	if (endSolve) {
		this->endSolve = true;
		pExactStep50 = options.partialExactStep50;
		pExactStep90 = options.partialExactStep90;
		pExactStep99 = options.partialExactStep99;
		exactGameStep = options.exactGameStep;
		options.partialExactStep50 = options.partialExactStep90 = 
			options.partialExactStep99 = options.exactGameStep = empties;
	}
	int result = myTurn(gc, lastMove);
	if (endSolve) {
		this->endSolve = false;
		options.partialExactStep50 = pExactStep50;
		options.partialExactStep90 = pExactStep90;
		options.partialExactStep99 = pExactStep99;
		options.exactGameStep = exactGameStep;
	}
	solver->setBookTolerance(userInfo->BookTolerance);
	if (terminated) return result;
	if (gc->getAvailableCount()) solver->unMakeMove();
	if (lastMove.getColor() != Chess::AVAILABLE) solver->unMakeMove();
	return result;
}