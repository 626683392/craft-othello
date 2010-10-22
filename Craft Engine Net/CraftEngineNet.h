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

// Craft Engine Net.h

#pragma once

#include "Solver.h"
#include "Definition.h"

using namespace System;

namespace CraftEngineNet {
	
	///Craft���� .NET�汾
	public ref class Engine {
	private:
		CraftEngine::Solver* solver;

	public:
		///��ֵ���ű�����ʵ�ʹ�ֵ=(float)���ع�ֵ/RULER
		static const int RULER = CraftEngine::Solver::RULER;
		///�ڹ�ֵ�б�ʾ�����
		static const int INFINITE = CraftEngine::Solver::INFINITE;
		///����岽���൱�����̸����(8*8=64)
		static const int MAXSTEP = CraftEngine::Solver::MAXSTEP;

		///����һ���µ�����
		Engine();

		///ȡ����ǰ������
		///������
		///  searchThread: �����������߳�
		void abortSearch(System::Threading::Thread^ searchThread);
		///�����ڴ棬�ͷ���Դ
		static void cleanup();
		///��ջ�������
		static void clearCache();
		///����岽����
		void clearGame();
		///�������״̬
		void clearSearchStats();
		///�Ե�ǰ���岽���н�������ѧϰ
		void extendBook();
		
		///��������ѧϰ���ȣ��ɿ��̲߳���
		int getBookPercent();
		///���ػ���Ĵ�С(����ڵ���, ռ���ڴ�ռ�Ϊ����ֵ*64�ֽ�)
		static size_t getCacheSize();
		///��������״̬���ɿ��̲߳���
		SearchStats getSearchStats();
		///����ָ����Ϸ�����ж������������ӵ�λ������
		///������
		///  side: ��Ϸ��
		int getMobility(Chess side);

		///��ʼ��Craft Engine
		///���������Ĭ�ϲ�����ʼ��Craft Engine
		///ģ���ļ�ʹ�õ�ǰĿ¼�µ�pattern.craft�ļ�
		///�����ļ�ʹ�õ�ǰĿ¼�µ�book.craft�ļ�
		static void initialize();
		///��ʼ��Craft Engine��
		///�������ʹ��ָ���Ĳ�����ʼ��Craft Engine
		///������
		///  patternPath: ģ���ļ���·��
		///  bookPath: �����ļ���·��
		static void initialize(String^ patternPath, String^ bookPath);

		///����
		///������
		///  point: Ҫ�ߵ��岽
		///  side: ���巽
		void makeMove(Move point, Chess side);
		///����һ����(�����ڷ���������ѧϰ��)
		///������
		///  board: ��ʼ����
		///  steps: �岽����
		///Ĭ���ɺڷ�����
		void parseGame(Board board, array<Move>^ steps);
		///����һ����(�����ڷ���������ѧϰ��)
		///������
		///  board: ��ʼ����
		///  steps: �岽����
		///  firstPlayer: ���е�һ��
		void parseGame(Board board, array<Move>^ steps, Chess firstPlayer);

		///���������ļ���
		///�������ڼ��غ�δ���޸ģ��򲻻���д���ļ���
		static void saveBook();

		///���õ�ǰ����
		///������
		///  board: Ҫ���õ�����
		void setBoard(Board board);

		///������������Դ�С��Ĭ��Ϊ0
		///���ú󷵻ص������岽�Ĺ�ֵ������ֵ֮��Ĳ������Ϊtolerance
		///������
		///  tolerance: ����Դ�С
		void setBookTolerance(int tolerance);
		///���û����С(����ڵ���, ռ���ڴ�ռ�Ϊ����ֵ*64�ֽ�)
		///������
		///  newCacheSize: �����С���������1 << N��0<=N<=30
		static void setCacheSize(size_t newCacheSize);

		///�����о�����(ʹ������)�������о��������
		///������
		///  side: ���巽
		///  depth: �о����������
		SearchResult solve(Chess side, int depth);
		///�����о������������о��������
		///������
		///  side: ���巽
		///  depth: �о����������
		///  useBook: �Ƿ�ʹ������
		SearchResult solve(Chess side, int depth, bool useBook);
		///���д�ʳ����(ʹ�о����������)�����ش�ʳ�������
		///������
		///  side: ���巽
		///  depth: ��ʳ���������
		SearchResult solveBigEat(Chess side, int depth);
		///�����վ������������վ��������
		///������
		///  side: ���巽
		///  winLoss: �Ƿ����ʤ������
		///           ָ��false���о�ȷ�������
		///ʤ������ֻ�ж�ʤ������������Ĺ�ֵ�Ⱦ�ȷ�������ӽ���0
		SearchResult solveExact(Chess side, bool winLoss);

		///�����վ�ѡ���������������������
		///������
		///  side: ���巽
		///  winLoss: �Ƿ����ʤ������
		///           ָ��false���о�ȷ�����ѡ��������
		///  percentage: ����Ҫ�ﵽ�Ŀ��Ŷ�(�ٷֱ�)��ָ��100�൱����ȫ��ȷ����
		///  actualPercentage: ʵ����������Ŀ��Ŷ�(�ٷֱ�)
		///ʤ������ֻ�ж�ʤ������������Ĺ�ֵ�Ⱦ�ȷ�������ӽ���0
		SearchResult partialSolveExact(Chess side, bool winLoss, int percentage, int% actualPercentage);

		///�����ϴε��岽
		void unMakeMove();

		///��������
		~Engine();
		!Engine();
	};
}
