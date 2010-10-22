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

#include "Solver.h"

using namespace System;

namespace CraftEngineNet {
	
	///��ʾ������ɫ����Ϸ��
	public enum class Chess {
		AVAILABLE, BLACK, WHITE
	};

	///�岽���������ϵ�һ����
	public value class Move {
	private:
		int x, y;
	public:
		Move(int theX, int theY)
			: x(theX), y(theY) {}
		property int X {
			int get() {
				return x;
			}
			void set(int value) {
				x = value;
			}
		}
		property int Y {
			int get() {
				return y;
			}
			void set(int value) {
				y = value;
			}
		}
	};

	typedef array<Chess, 2>^ Board;

	///�������
	public value class SearchResult {
	private:
		Move move;
		int evaluation;
		bool bookMove;
	public:
		SearchResult(Move move, int evaluation, bool bookMove) {
			this->move = move;
			this->evaluation = evaluation;
			this->bookMove = bookMove;
		}
		///����岽
		property Move Move {
			CraftEngineNet::Move get() {
				return move;
			}
		}
		///��ֵ
		///���оֹ�ֵ���վֹ�ֵ����
		///* �վֹ�ֵ�ķ�ΧΪ-64~64
		///* �оֹ�ֵΪʵ�ʹ�ֵ*RULER(=10000)�Ľ��
		/// -���оֹ�ֵ����-INFINITE~(-INFINITE + 63)��Χ�ڣ�
		///  ��������о������м�⵽������棬��Ӧ���վֹ�ֵΪ
		///  Evaluation + INFINITE - 64
		/// -���оֹ�ֵ����(INFINITE - 63)~INFINITE��Χ�ڣ�
		///  ��������о������м�⵽��ʤ���棬��Ӧ���վֹ�ֵΪ
		///  Evaluation - INFINITE + 64
		property int Evaluation {
			int get() {
				return evaluation;
			}
		}

		///����Ƿ������ֱ�ӵõ�
		property bool BookMove {
			bool get() {
				return bookMove;
			}
		}
	};

	///����״̬
	public value class SearchStats {
	private:
		unsigned long long evaluationCount;
		Move focusedMove;
		Move selectedMove;
		int percent;
		int partialDepth;
		int partialResult;
		int epcPercentage;
	public:
		///�վ�����
		static const int PARTIALDEPTH_EXACT = CraftEngine::Solver::PARTIALDEPTH_EXACT;
		///ʤ������
		static const int PARTIALDEPTH_WLD = CraftEngine::Solver::PARTIALDEPTH_WLD;

		SearchStats(unsigned long long evnum, Move focused,
			Move selected, int percent, int pDepth, int pResult, int percentage) {
				evaluationCount = evnum;
				focusedMove = focused;
				selectedMove = selected;
				this->percent = percent;
				partialDepth = pDepth;
				partialResult = pResult;
				epcPercentage = percentage;
		}

		///������������Ѿ����й�ֵ�ľ������Ŀ
		property unsigned long long EvaluationCount {
			unsigned long long get() {
				return evaluationCount;
			}
		}
		///��ǰ�����������岽
		property Move FocusedMove {
			Move get() {
				return focusedMove;
			}
		}
		///��ǰ��Ϊ��ѵ��岽
		property Move SelectedMove {
			Move get() {
				return selectedMove;
			}
		}
		///������ɵİٷֱ�(ֻ��һ������)
		property int Percent {
			int get() {
				return percent;
			}
		}
		///���ڽ��е��������
		property int PartialDepth {
			int get() {
				return partialDepth;
			}
		}
		///��ǰ��ȵĵ�ǰ��ѹ�ֵ
		property int PartialResult {
			int get() {
				return partialResult;
			}
		}

		///�վ�ѡ���������Ŀ��Ŷ�(1%~100%)
		property int EPCPercentage {
			int get() {
				return epcPercentage;
			}
		}
	};

	public ref class InitializationException : public System::Exception {
	public:
		InitializationException() {
			
		}
		InitializationException(System::String^ message)
			: Exception(message) {
			
		}
		InitializationException(System::String^ message, System::Exception^ innerException)
			: Exception(message, innerException) {
			
		}

	};

	///һЩȫ�ֳ���
	public ref class Global abstract {
	public:
		///���̺��򳤶�
		static const int WIDTH = CraftEngine::WIDTH;
		///�������򳤶�
		static const int HEIGHT = CraftEngine::HEIGHT;
		///Infinity����
		static const int INFINITY = CraftEngine::Solver::INFINITE;
	};
} // namespace CraftEngineNet
