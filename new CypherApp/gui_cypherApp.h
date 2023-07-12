#pragma once

namespace newCypherApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class cypherApp : public System::Windows::Forms::Form
	{
	public:
		cypherApp(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~cypherApp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::TabControl^ aesTabCtrl;

	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabControl^ aesEncTab;



	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::DataGridView^ gridAesEn;

	private: System::Windows::Forms::Panel^ aesPanelEn;

	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Button^ aesEncrypt;
	private: System::Windows::Forms::RadioButton^ aesCheckText;
	private: System::Windows::Forms::TextBox^ aesTextToEnc;


	private: System::Windows::Forms::ComboBox^ aesKeyLen;
	private: System::Windows::Forms::TextBox^ aesTextOut;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RadioButton^ aesLoadText;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ aesKey;
	private: System::Windows::Forms::CheckBox^ aesGenerateKey;



	protected:
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->aesTabCtrl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->aesEncTab = (gcnew System::Windows::Forms::TabControl());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->gridAesEn = (gcnew System::Windows::Forms::DataGridView());
			this->aesPanelEn = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->aesLoadText = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->aesKey = (gcnew System::Windows::Forms::TextBox());
			this->aesGenerateKey = (gcnew System::Windows::Forms::CheckBox());
			this->aesTextOut = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->aesKeyLen = (gcnew System::Windows::Forms::ComboBox());
			this->aesEncrypt = (gcnew System::Windows::Forms::Button());
			this->aesCheckText = (gcnew System::Windows::Forms::RadioButton());
			this->aesTextToEnc = (gcnew System::Windows::Forms::TextBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->aesTabCtrl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->aesEncTab->SuspendLayout();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAesEn))->BeginInit();
			this->aesPanelEn->SuspendLayout();
			this->SuspendLayout();
			// 
			// aesTabCtrl
			// 
			this->aesTabCtrl->Controls->Add(this->tabPage1);
			this->aesTabCtrl->Controls->Add(this->tabPage2);
			this->aesTabCtrl->Controls->Add(this->tabPage3);
			this->aesTabCtrl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->aesTabCtrl->Location = System::Drawing::Point(0, 0);
			this->aesTabCtrl->Name = L"aesTabCtrl";
			this->aesTabCtrl->SelectedIndex = 0;
			this->aesTabCtrl->Size = System::Drawing::Size(1000, 608);
			this->aesTabCtrl->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->aesEncTab);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(992, 579);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"AES";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// aesEncTab
			// 
			this->aesEncTab->Controls->Add(this->tabPage4);
			this->aesEncTab->Controls->Add(this->tabPage5);
			this->aesEncTab->Dock = System::Windows::Forms::DockStyle::Fill;
			this->aesEncTab->Location = System::Drawing::Point(3, 3);
			this->aesEncTab->Name = L"aesEncTab";
			this->aesEncTab->SelectedIndex = 0;
			this->aesEncTab->Size = System::Drawing::Size(986, 573);
			this->aesEncTab->TabIndex = 0;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->gridAesEn);
			this->tabPage4->Controls->Add(this->aesPanelEn);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(978, 544);
			this->tabPage4->TabIndex = 0;
			this->tabPage4->Text = L"Encrypt";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// gridAesEn
			// 
			this->gridAesEn->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAesEn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gridAesEn->Location = System::Drawing::Point(654, 3);
			this->gridAesEn->Name = L"gridAesEn";
			this->gridAesEn->RowHeadersWidth = 51;
			this->gridAesEn->RowTemplate->Height = 24;
			this->gridAesEn->Size = System::Drawing::Size(321, 538);
			this->gridAesEn->TabIndex = 1;
			// 
			// aesPanelEn
			// 
			this->aesPanelEn->Controls->Add(this->label3);
			this->aesPanelEn->Controls->Add(this->aesLoadText);
			this->aesPanelEn->Controls->Add(this->button1);
			this->aesPanelEn->Controls->Add(this->label2);
			this->aesPanelEn->Controls->Add(this->aesKey);
			this->aesPanelEn->Controls->Add(this->aesGenerateKey);
			this->aesPanelEn->Controls->Add(this->aesTextOut);
			this->aesPanelEn->Controls->Add(this->label1);
			this->aesPanelEn->Controls->Add(this->aesKeyLen);
			this->aesPanelEn->Controls->Add(this->aesEncrypt);
			this->aesPanelEn->Controls->Add(this->aesCheckText);
			this->aesPanelEn->Controls->Add(this->aesTextToEnc);
			this->aesPanelEn->Dock = System::Windows::Forms::DockStyle::Left;
			this->aesPanelEn->Location = System::Drawing::Point(3, 3);
			this->aesPanelEn->Name = L"aesPanelEn";
			this->aesPanelEn->Size = System::Drawing::Size(651, 538);
			this->aesPanelEn->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(489, 484);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Zaszyfrowany tekst";
			// 
			// aesLoadText
			// 
			this->aesLoadText->AutoSize = true;
			this->aesLoadText->Location = System::Drawing::Point(35, 59);
			this->aesLoadText->Name = L"aesLoadText";
			this->aesLoadText->Size = System::Drawing::Size(120, 21);
			this->aesLoadText->TabIndex = 10;
			this->aesLoadText->Text = L"Za³aduj z pliku";
			this->aesLoadText->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(161, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(457, 35);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Za³aduj z pliku";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 265);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Klucz";
			// 
			// aesKey
			// 
			this->aesKey->Location = System::Drawing::Point(161, 260);
			this->aesKey->Name = L"aesKey";
			this->aesKey->Size = System::Drawing::Size(457, 22);
			this->aesKey->TabIndex = 7;
			// 
			// aesGenerateKey
			// 
			this->aesGenerateKey->AutoSize = true;
			this->aesGenerateKey->Location = System::Drawing::Point(161, 288);
			this->aesGenerateKey->Name = L"aesGenerateKey";
			this->aesGenerateKey->Size = System::Drawing::Size(155, 21);
			this->aesGenerateKey->TabIndex = 6;
			this->aesGenerateKey->Text = L"generowanie klucza";
			this->aesGenerateKey->UseVisualStyleBackColor = true;
			// 
			// aesTextOut
			// 
			this->aesTextOut->Location = System::Drawing::Point(161, 393);
			this->aesTextOut->Multiline = true;
			this->aesTextOut->Name = L"aesTextOut";
			this->aesTextOut->Size = System::Drawing::Size(457, 88);
			this->aesTextOut->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 217);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"D³ugoœæ klucza";
			// 
			// aesKeyLen
			// 
			this->aesKeyLen->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->aesKeyLen->FormatString = L"N0";
			this->aesKeyLen->FormattingEnabled = true;
			this->aesKeyLen->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->aesKeyLen->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"128", L"192", L"256" });
			this->aesKeyLen->Location = System::Drawing::Point(161, 214);
			this->aesKeyLen->Name = L"aesKeyLen";
			this->aesKeyLen->Size = System::Drawing::Size(121, 24);
			this->aesKeyLen->TabIndex = 3;
			// 
			// aesEncrypt
			// 
			this->aesEncrypt->Location = System::Drawing::Point(161, 339);
			this->aesEncrypt->Name = L"aesEncrypt";
			this->aesEncrypt->Size = System::Drawing::Size(170, 48);
			this->aesEncrypt->TabIndex = 2;
			this->aesEncrypt->Text = L"Encrypt";
			this->aesEncrypt->UseVisualStyleBackColor = true;
			this->aesEncrypt->Click += gcnew System::EventHandler(this, &cypherApp::aesEncrypt_Click);
			// 
			// aesCheckText
			// 
			this->aesCheckText->AutoSize = true;
			this->aesCheckText->Checked = true;
			this->aesCheckText->Location = System::Drawing::Point(35, 141);
			this->aesCheckText->Name = L"aesCheckText";
			this->aesCheckText->Size = System::Drawing::Size(101, 21);
			this->aesCheckText->TabIndex = 1;
			this->aesCheckText->TabStop = true;
			this->aesCheckText->Text = L"Wpisz tekst";
			this->aesCheckText->UseVisualStyleBackColor = true;
			// 
			// aesTextToEnc
			// 
			this->aesTextToEnc->Location = System::Drawing::Point(161, 108);
			this->aesTextToEnc->Multiline = true;
			this->aesTextToEnc->Name = L"aesTextToEnc";
			this->aesTextToEnc->Size = System::Drawing::Size(457, 88);
			this->aesTextToEnc->TabIndex = 0;
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(978, 544);
			this->tabPage5->TabIndex = 1;
			this->tabPage5->Text = L"Decrypt";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(992, 579);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(992, 579);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"tabPage3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// cypherApp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 608);
			this->Controls->Add(this->aesTabCtrl);
			this->Name = L"cypherApp";
			this->Text = L"MyForm";
			this->aesTabCtrl->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->aesEncTab->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAesEn))->EndInit();
			this->aesPanelEn->ResumeLayout(false);
			this->aesPanelEn->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: 
		System::Void aesEncrypt_Click(System::Object^ sender, System::EventArgs^ e);
};
}
