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
								WThorReader.h
		���ߣ�Patrick
		������������ WThorReader ��������
			WThorReader ���װ�˶� WThor �Ծֿ�ķ��ʣ�����ʵ�ֲо�ģʽ��

********************************************************************************
*/

#include "Common.h"

//�ļ�ͷ�ṹ��
//1�ֽ�  �ļ�������ݵİ�λ���֣���20��ʾ20**��
//1�ֽ�  �ļ�������ݵĵ�2λ
//1�ֽ�  �ļ��������·�
//1�ֽ�  �ļ�����������
//4�ֽ�  N1���ļ������ļ�¼��������ǶԾֿ��õģ�
//2�ֽ�  N2���ļ������ļ�¼������������ֿ�ͱ������õģ�
//2�ֽ�  �Ծ����
//1�ֽ�  P1�����̴�С��0��8��ʾ8*8
//1�ֽ�  P2����Ϸ���ͣ�1��ʾsolitaires��Ϸ��0��ʾ�����������ڰ��壩
//1�ֽ�  P3������վּ����������ȣ�һ��Ϊ22
//1�ֽ�  ����
//
//�Ծֿ��¼�ṹ������8*8�ڰ��壬ÿ����¼68�ֽ�
//2�ֽ�  �������ƣ�����ֻ�Ǹ���ţ���������Ҫ��������е���Ӧ��¼
//2�ֽ�  �ڷ��������֣�����ֻ�Ǹ���ţ���������Ҫ�����ֿ�
//2�ֽ�  �׷���������
//1�ֽ�  �Ծֽ���ʱ�ڷ���������������ո��ʤ����
//1�ֽ�  �ڷ�������ѵ��ӣ�����ʣ��P3���ո�ʱ����������վּ��㣬�ڷ��ĵ�����
//60�ֽ� �岽���У�ÿ����һ���ֽڣ���Ϊ�к�*10+�кţ���A1=11��A2=21��Ƿ�еĲ�������¼��ֻ�ǽ��������ֽ���0
//
//���ֿ��¼�ṹ
//ÿ����¼20�ֽڣ��ַ������ͣ��Խ�β������¼�������֡����ڳ���һ�������ż�ע�������ߣ���
//
//Thor(quin/becquet)
//
//�������¼�ṹ
//ÿ����¼26�ֽڣ��ַ������ͣ���¼�������ơ�

namespace Othello {

public value class WThorHeader {
public:
	int year, month, day;
	int recordNum;
	int tourYear;
	int boardSize;
	bool isSolitaires;
	int theoricalScoreDepth;
};

public value class WThorPlayer {
private:
	System::String^ name;
public:
	WThorPlayer(System::String^ name) {
		this->name = name;
	}
	property System::String^ Name {
		System::String^ get() {
			return name;
		}
	}
};

public value class WThorTour {
private:
	System::String^ name;
public:
	WThorTour(System::String^ name) {
		this->name = name;
	}
	property System::String^ Name {
		System::String^ get() {
			return name;
		}
	}
};

public value class WThorGame {
public:
	WThorTour tour;
	WThorPlayer black, white;
	int year;
	int result;
	array<System::Drawing::Point>^ moveSequence;
};

public ref class WThorReader {
	System::Collections::Generic::List<WThorPlayer>^ players;
	System::Collections::Generic::List<WThorTour>^ tours;
	WThorHeader header;
	System::IO::BinaryReader^ br;
	System::IO::FileStream^ fs;
	System::String^ currentFileName;

	static const int JOU_RECORD_LENGTH = 20;
	static const int TRN_RECORD_LENGTH = 26;
	static const int WTHOR_HEADER_LENGTH = 16;
	static const int GAME_RECORD_LENGTH = 68;
public:
	WThorReader();
	bool loadPlayers(System::String^ jouFileName);
	bool loadTours(System::String^ trnFileName);
	bool loadGameFile(System::String^ wtbFileName);
	void unloadGameFile();
	int getGameCount();
	int getTourYear();
	bool readGame(int index, WThorGame^ game);
	~WThorReader();
};

} // namespace Othello
