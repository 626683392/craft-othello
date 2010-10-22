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
								frmThanks.h
		���ߣ�Patrick
		������������ frmThanks ��������
			frmThanks ��ʵ�֡���л�����塣

********************************************************************************
*/

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Othello {

	/// <summary>
	/// frmThanks ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public ref class frmThanks : public System::Windows::Forms::Form
	{
	public:
		frmThanks(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~frmThanks()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  lstHelpers;

	private: System::Windows::Forms::Button^  btnOK;
	protected: 

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lstHelpers = (gcnew System::Windows::Forms::ListBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"΢���ź�", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(205, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"��л������Ա�� Craft ���������и����֧�ֺͰ�����";
			// 
			// lstHelpers
			// 
			this->lstHelpers->Font = (gcnew System::Drawing::Font(L"΢���ź�", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lstHelpers->FormattingEnabled = true;
			this->lstHelpers->ItemHeight = 17;
			this->lstHelpers->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Maxi", L"Zach"});
			this->lstHelpers->Location = System::Drawing::Point(12, 51);
			this->lstHelpers->Name = L"lstHelpers";
			this->lstHelpers->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->lstHelpers->Size = System::Drawing::Size(205, 106);
			this->lstHelpers->Sorted = true;
			this->lstHelpers->TabIndex = 1;
			// 
			// btnOK
			// 
			this->btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnOK->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnOK->Font = (gcnew System::Drawing::Font(L"΢���ź�", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btnOK->Location = System::Drawing::Point(139, 163);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(78, 29);
			this->btnOK->TabIndex = 0;
			this->btnOK->Text = L"�ر�";
			this->btnOK->UseVisualStyleBackColor = true;
			// 
			// frmThanks
			// 
			this->AcceptButton = this->btnOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnOK;
			this->ClientSize = System::Drawing::Size(229, 201);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->lstHelpers);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmThanks";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"��л";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
