#include "gui_CypherApp.h"
#include "cryptoModel.h"
#include "aesModel.h"
#include <memory>
/*
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include <algorithm>
*/
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;


[STAThreadAttribute]
void main()
{
    OpenSSLInitializer* opensslInitializer = new OpenSSLInitializer;
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    newCypherApp::cypherApp form;
    Application::Run(% form);
   delete opensslInitializer;    
}


bool newCypherApp::cypherApp::checkSetKey()
{
    if (System::String::IsNullOrEmpty(aesKeyLen->Text))
    {
        aesKeyLen->BackColor = System::Drawing::Color::Red;
        return false;
    }
    else
        aesKeyLen->BackColor = System::Drawing::SystemColors::Window;
    return true;
}

System::Void newCypherApp::cypherApp::aesEncrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!checkSetKey())
        return;
    
    int keyLength = 0;
    System::Int32::TryParse(aesKeyLen->Text, keyLength);

    std::unique_ptr<qto::AesCtrl> aes = std::make_unique<qto::AesCtrl>(keyLength);
    aesTextOut->Text = aes->encryptAes(AESEncryptTextBox->Text);  
    int abc = 0;
    abc = abc + 1;
}

System::Void newCypherApp::cypherApp::load_formFile_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenFileDialog^ openFileDialogSHA = gcnew OpenFileDialog;
    Stream^ myStream;

    openFileDialogSHA->InitialDirectory = "C:\\Users\\rober\\source\\repos\\cipherApp\\cipherApp";
    openFileDialogSHA->Filter = "PDF Files (*.pdf)|*.pdf|Word Files (*.docx)|*.docx|Text Files (*.txt)|*.txt|Binary Files (*.bin)|*.bin|PEM Files (*.pem)|*.pem";
    openFileDialogSHA->FilterIndex = 3;
    openFileDialogSHA->Title;
    if (openFileDialogSHA->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        if ((myStream = openFileDialogSHA->OpenFile()) == nullptr)
            return; 

        String^ textBoxName = GenerateControlName(sender);
        TextBox^ textBox = GetTextBoxByName(sender, textBoxName);
        std::string filePath = tools::systemStringToString(openFileDialogSHA->FileName);
        std::vector<unsigned char> dataFromFile = tools::load_data_from_file(filePath);
        textBox->Text = tools::convert_Bytes_To_AsciiString(dataFromFile);
        myStream->Close();              
    }
    
}

System::String^ newCypherApp::cypherApp::GenerateControlName(Object^ sender)
{
    Button^ button = safe_cast<Button^>(sender);
    TabPage^ activeTab = aesTabCtrl->SelectedTab;
    System::Windows::Forms::Control^ control = (button->Parent);
    System::Windows::Forms::Panel^ panel = safe_cast<Panel^>(button->Parent);
    System::Windows::Forms::TabPage^ tabPage = safe_cast<TabPage^>(panel->Parent);
    return activeTab->Text + tabPage->Text + "TextBox";
}

TextBox^ newCypherApp::cypherApp::GetTextBoxByName(Object^ sender, String^ name)
{
    Button^ button = safe_cast<Button^>(sender);
    System::Windows::Forms::Panel^ panel = safe_cast<Panel^>(button->Parent);
    return safe_cast<TextBox^>(panel->Controls[name]);
}

System::Void newCypherApp::cypherApp::rsaEnc_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    
}