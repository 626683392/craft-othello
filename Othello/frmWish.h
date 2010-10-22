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
								frmWish.h
		���ߣ�Patrick
		������������ frmWish ��������
			frmWish ��ʵ�� ʥ���ؿ� ���塣
		
		ע������Ϊʥ���ر��ר�ã���ʽ���в����������ݡ�

********************************************************************************
*/

#include "Common.h"

#ifdef CHRISTMAS

#include "Timer.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Othello {

	public interface class WishController {
	public:
		virtual void wishShown() = 0;
		virtual void wishClosed() = 0;
	};

	/// <summary>
	/// frmWish ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public ref class frmWish : public System::Windows::Forms::Form
	{
	public:
		frmWish(WishController^ controller)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			this->controller = controller;
			controller->wishShown();
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~frmWish()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;
		WishController^ controller;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmWish::typeid));
			this->SuspendLayout();
			// 
			// frmWish
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(600, 450);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmWish";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Craft";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmWish::frmWish_FormClosed);
			this->Click += gcnew System::EventHandler(this, &frmWish::frmWish_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmWish::frmWish_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmWish_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void frmWish_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Space
					 || e->KeyCode == Keys::Escape)
					 this->Close();
			 }
	private: System::Void frmWish_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 controller->wishClosed();
			 }
	};
}

#endif
