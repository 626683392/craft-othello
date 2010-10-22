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
								Analyze.h
		���ߣ�Patrick
		������������ַ��������Ҫ�õ����ࣺ
			AnalyzedMove �� DetailedAnalyzeResult

********************************************************************************
*/

#include "Common.h"

namespace Othello {

//�������������⼶��
public enum class QuestionLevel {
	NONE,	//û������
	NORMAL, //��һ������
	BAD		//�кܴ�����
};

//�������� AnalyzedMove ��ʾһ����ķ������
public value class AnalyzedMove {
private:
	System::String^ generalDescription;
	System::String^ sPlayedMoveEval, ^sBestMoveEval;
	int iPlayedMoveEval, iBestMoveEval;
	System::String^ sPlayedMove, ^sBestMove;
	System::Drawing::Point pPlayedMove, pBestMove;
	QuestionLevel questionLevel;
	Chess color;
public:
	//���캯������ʼ�� AnalyzedMove �����趨�������
	AnalyzedMove(System::String^ description, Chess player,
		System::String^ sPlayedEval, System::String^ sBestEval,
		int iPlayedEval, int iBestEval, System::String^ sPlayed, System::String^ sBest,
		System::Drawing::Point pPlayed, System::Drawing::Point pBest, QuestionLevel ql) {
			generalDescription = description;
			sPlayedMoveEval = sPlayedEval;
			sBestMoveEval = sBestEval;
			iPlayedMoveEval = iPlayedEval;
			iBestMoveEval = iBestEval;
			sPlayedMove = sPlayed;
			sBestMove = sBest;
			pPlayedMove = pPlayed;
			pBestMove = pBest;
			questionLevel = ql;
			color = player;
	}
	//��ȡ�ⲽ������������������
	System::String^ getGeneralDescription() {
		return generalDescription;
	}
	//��ȡ�ַ�����ʾ�������岽��ֵ
	System::String^ getSPlayedMoveEval() {
		return sPlayedMoveEval;
	}
	//��ȡ�ַ�����ʾ������岽�Ĺ�ֵ
	System::String^ getSBestMoveEval() {
		return sBestMoveEval;
	}
	//��ȡ int ��ʾ�������岽�Ĺ�ֵ
	int getIPlayedMoveEval() {
		return iBestMoveEval;
	}
	//��ȡ int ��ʾ������岽�Ĺ�ֵ
	int getIBestMoveEval() {
		return iBestMoveEval;
	}
	//��ȡ�ַ�����ʾ�������岽
	System::String^ getSPlayedMove() {
		return sPlayedMove;
	}
	//��ȡ�ַ�����ʾ������岽
	System::String^ getSBestMove() {
		return sBestMove;
	}
	//��ȡ�� System::Drawing::Point �����ʾ�������岽
	System::Drawing::Point getPPlayedMove() {
		return pPlayedMove;
	}
	//��ȡ�� System::Drawing::Point �����ʾ������岽
	System::Drawing::Point getPBestMove() {
		return pBestMove;
	}
	//��ȡ���⼶��
	QuestionLevel getQuestionLevel() {
		return questionLevel;
	}
	//��ȡ�ⲽ������巽
	Chess getPlayer() {
		return color;
	}
};

//�������� DetailedAnalyzeResult ��ʾһ����ķ������
public ref class DetailedAnalyzeResult {
	System::Collections::Generic::List<AnalyzedMove>^ moves;
public:
	//��ʼ��Ϊ�� DetailedAnalyzeResult ����
	DetailedAnalyzeResult() {
		moves = gcnew System::Collections::Generic::List<AnalyzedMove>();
		moves->Add(AnalyzedMove("", Chess::AVAILABLE, "", "", 0, 0, "", "", System::Drawing::Point(-1, -1), 
			System::Drawing::Point(-1, -1), QuestionLevel::NONE));
	}

	/*
	��������ȡĳһ���ķ������

	������
	step��Ҫ��ȡ���岽���

	����ֵ���� step ���ķ������
	*/
	AnalyzedMove getAnalyzedResult(int step) {
		return moves[step];
	}

	/*
	�������� DetailedAnalyzeResult �����м����岽�������

	������
	move��Ҫ������岽�������
	*/
	void addAnalyzedResult(AnalyzedMove move) {
		moves->Add(move);
	}

	//��ȡ�ܵ��岽��
	int getSteps() {
		return moves->Count;
	}

	//��� DetailedAnalyzeResult ����
	void clear() {
		moves->Clear();
		moves->Add(AnalyzedMove("", Chess::AVAILABLE, "", "", 0, 0, "", "", System::Drawing::Point(-1, -1), 
			System::Drawing::Point(-1, -1), QuestionLevel::NONE));
	}
};

} // namespace Othello
