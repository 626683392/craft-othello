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
								frmEndGameInfo.h
		���ߣ�Patrick
		������������ frmEndGameInfo ��������
			frmEndGameInfo ��ʵ�֡��о���Ϣ�����塣

********************************************************************************
*/

#include "Common.h"
#include "WThorReader.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Drawing;


namespace Othello {

	public interface class EndGameInfoController {
	public:
		virtual void endGameInfoShown() = 0;
		virtual void endGameInfoClosed() = 0;
		virtual void acquireChange() = 0;
	};

	/// <summary>
	/// frmEndGameInfo ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public ref class frmEndGameInfo : public System::Windows::Forms::Form
	{
	public:
		frmEndGameInfo(EndGameInfoController^ controller) {
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			this->controller = controller;
			controller->endGameInfoShown();
		}
		frmEndGameInfo(EndGameInfoController^ controller,
			WThorGame^ game, int bestResult, int empties, Chess player)
		{
			this->frmEndGameInfo::frmEndGameInfo(controller);
			showInfo(game, bestResult, empties, player);
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~frmEndGameInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  txtDescription;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Button^  btnChangeOne;
	protected: 
	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;
		EndGameInfoController^ controller;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnChangeOne = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"���������";
			// 
			// txtDescription
			// 
			this->txtDescription->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->txtDescription->Font = (gcnew System::Drawing::Font(L"����", 10.5F));
			this->txtDescription->Location = System::Drawing::Point(12, 24);
			this->txtDescription->Multiline = true;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->ReadOnly = true;
			this->txtDescription->Size = System::Drawing::Size(317, 160);
			this->txtDescription->TabIndex = 0;
			// 
			// btnStart
			// 
			this->btnStart->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnStart->Location = System::Drawing::Point(131, 190);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(96, 32);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"��ʼ�о�";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &frmEndGameInfo::btnStart_Click);
			// 
			// btnChangeOne
			// 
			this->btnChangeOne->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnChangeOne->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnChangeOne->Location = System::Drawing::Point(233, 190);
			this->btnChangeOne->Name = L"btnChangeOne";
			this->btnChangeOne->Size = System::Drawing::Size(96, 32);
			this->btnChangeOne->TabIndex = 2;
			this->btnChangeOne->Text = L"��һ��(&A)";
			this->btnChangeOne->UseVisualStyleBackColor = true;
			this->btnChangeOne->Click += gcnew System::EventHandler(this, &frmEndGameInfo::btnChangeOne_Click);
			// 
			// frmEndGameInfo
			// 
			this->AcceptButton = this->btnStart;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnStart;
			this->ClientSize = System::Drawing::Size(342, 232);
			this->Controls->Add(this->btnChangeOne);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->txtDescription);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmEndGameInfo";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"�о���Ϣ";
			this->Load += gcnew System::EventHandler(this, &frmEndGameInfo::frmEndGameInfo_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmEndGameInfo::frmEndGameInfo_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		static String^ getResultDescription(WThorGame^ game, int bestResult, int empties, Chess player) {
			String^ result = "������ " + game->black.Name + "(��) �� "
				+ game->white.Name + "(��) ��" + game->year + "��� "
				+ game->tour.Name + " �������µ�һ���塣";
			result += "\r\n���� ";
			if (game->result > 0) {
				result += game->black.Name + " սʤ�� " + game->white.Name;
				result += "���ȷ�Ϊ " + (game->result / 2 + 32).ToString()
					+ ":" + (32 - game->result / 2).ToString();
			} else if (game->result < 0) {
				result += game->white.Name + " սʤ�� " + game->black.Name;
				result += "���ȷ�Ϊ " + (32 - game->result / 2).ToString()
					+ ":" + (game->result / 2 + 32).ToString();
			} else {
				result += game->black.Name + " �� " + game->white.Name + " �����Ժ�";
			}
			result += "��\r\n�����ڵĽ�ɫ�� "
				+ ((player == Chess::BLACK) ? (game->black.Name + "(��)") : (game->white.Name + "(��)"));
			result += "��\r\n��ֻ�ʣ�����" + empties + "����" + "��ѽ���� ";
			if (bestResult > 0) {
				result += (bestResult / 2 + 32).ToString()
					+ ":" + (32 - bestResult / 2).ToString() + " ʤ";
			} else if (bestResult < 0) {
				result += (bestResult / 2 + 32).ToString()
					+ ":" + (32 - bestResult / 2).ToString() + " ��";
			} else {
				result += "ƽ��";
			}
			result += "��\r\n׼����ӭ����ս��";
			return result;
		}
public:
		void showInfo(WThorGame^ game, int bestResult, int empties, Chess player) {
			txtDescription->Text = getResultDescription(game, bestResult, empties, player);
		}
private: System::Void frmEndGameInfo_Load(System::Object^  sender, System::EventArgs^  e) {
			 CenterToParent();
		 }
private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void frmEndGameInfo_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 controller->endGameInfoClosed();
		 }
private: System::Void btnChangeOne_Click(System::Object^  sender, System::EventArgs^  e) {
			 controller->acquireChange();
		 }
};

}
