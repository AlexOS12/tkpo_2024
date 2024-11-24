#pragma once

#include "Phone.h"

namespace PhoneForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->phone = new Phone;
			updatePhoneStat();

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Phone* phone = nullptr;;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ PhoneStat;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ LastOperationsMessages;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ topupAmount;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PhoneStat = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LastOperationsMessages = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->topupAmount = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(107, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Состояние телефона";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// PhoneStat
			// 
			this->PhoneStat->AutoSize = true;
			this->PhoneStat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PhoneStat->Location = System::Drawing::Point(107, 135);
			this->PhoneStat->Name = L"PhoneStat";
			this->PhoneStat->Size = System::Drawing::Size(174, 20);
			this->PhoneStat->TabIndex = 1;
			this->PhoneStat->Text = L"Состояние телефона";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(542, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Действия";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(495, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 39);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Позвонить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 254);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(220, 20);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Сообщения от операций:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// LastOperationsMessages
			// 
			this->LastOperationsMessages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LastOperationsMessages->Location = System::Drawing::Point(12, 277);
			this->LastOperationsMessages->Name = L"LastOperationsMessages";
			this->LastOperationsMessages->ReadOnly = true;
			this->LastOperationsMessages->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->LastOperationsMessages->Size = System::Drawing::Size(761, 250);
			this->LastOperationsMessages->TabIndex = 4;
			this->LastOperationsMessages->Text = L"";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(495, 77);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(186, 39);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Ответить на звонок";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(495, 122);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(186, 39);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Завершить разговор";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(495, 167);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(186, 39);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Пополнить баланс";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// topupAmount
			// 
			this->topupAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->topupAmount->Location = System::Drawing::Point(495, 232);
			this->topupAmount->Name = L"topupAmount";
			this->topupAmount->Size = System::Drawing::Size(186, 24);
			this->topupAmount->TabIndex = 5;
			this->topupAmount->Text = L"0";
			this->topupAmount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(517, 209);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(153, 20);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Сумма пополнения";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 541);
			this->Controls->Add(this->topupAmount);
			this->Controls->Add(this->LastOperationsMessages);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->PhoneStat);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(800, 580);
			this->MinimumSize = System::Drawing::Size(800, 580);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void updatePhoneStat() {
			PhoneStat->Text = gcnew String(phone->toString().c_str());
		}

		void addToLastOperationMessages(std::string message) {
			LastOperationsMessages->Text += "\n" + gcnew String(message.c_str());
		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		addToLastOperationMessages(phone->call());
		updatePhoneStat();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	addToLastOperationMessages(phone->answerCall());
	updatePhoneStat();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	addToLastOperationMessages(phone->endCall());
	updatePhoneStat();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	int amount = 0;
	try {
		amount = Convert::ToInt32(topupAmount->Text);
		addToLastOperationMessages(phone->topupBalance(amount));
		updatePhoneStat();
	}
	catch (...) {
		LastOperationsMessages->Text += "\n" + "Не удалось считать баланс пополнения";
	}
}
};
}
