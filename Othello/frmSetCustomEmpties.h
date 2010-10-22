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
								frmSetCustomEmpties.h
		���ߣ�Patrick
		������������ frmSetCustomEmpties ��������
			frmSetCustomEmpties ��ʵ�� �Զ���оֿո��� ���塣

********************************************************************************
*/

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Drawing;


namespace Othello {

	/// <summary>
	/// frmSetCustomEmpties ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public ref class frmSetCustomEmpties : public System::Windows::Forms::Form
	{
	public:
		frmSetCustomEmpties(int defaultEmpties)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			nudEmpties->Value = defaultEmpties;
			DialogResult = Windows::Forms::DialogResult::Cancel;
		}

		property int CustomEmpties {
			int get() {
				return (int)nudEmpties->Value;
			}
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~frmSetCustomEmpties()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Button^  btnOK;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::NumericUpDown^  nudEmpties;

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
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->nudEmpties = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudEmpties))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ʣ��ո�����";
			// 
			// btnOK
			// 
			this->btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnOK->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnOK->Location = System::Drawing::Point(11, 54);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(96, 32);
			this->btnOK->TabIndex = 1;
			this->btnOK->Text = L"ȷ��";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &frmSetCustomEmpties::btnOK_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnCancel->Location = System::Drawing::Point(113, 54);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(96, 32);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"ȡ��";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmSetCustomEmpties::btnCancel_Click);
			// 
			// nudEmpties
			// 
			this->nudEmpties->Location = System::Drawing::Point(145, 16);
			this->nudEmpties->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {18, 0, 0, 0});
			this->nudEmpties->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->nudEmpties->Name = L"nudEmpties";
			this->nudEmpties->Size = System::Drawing::Size(61, 21);
			this->nudEmpties->TabIndex = 0;
			this->nudEmpties->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nudEmpties->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// frmSetCustomEmpties
			// 
			this->AcceptButton = this->btnOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(222, 98);
			this->Controls->Add(this->nudEmpties);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmSetCustomEmpties";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"������ʣ��ո���";
			this->Load += gcnew System::EventHandler(this, &frmSetCustomEmpties::frmSetCustomEmpties_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmSetCustomEmpties::frmSetCustomEmpties_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudEmpties))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void frmSetCustomEmpties_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void frmSetCustomEmpties_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		 }
};

}
