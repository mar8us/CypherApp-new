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
    //OpenSSLInitializer* opensslInitializer = new OpenSSLInitializer;
    
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    newCypherApp::cypherApp form;
    Application::Run(% form);

    //delete opensslInitializer;    
}

System::Void newCypherApp::cypherApp::aesEncrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (System::String::IsNullOrEmpty(aesKeyLen->Text))
    {
        aesKeyLen->BackColor = System::Drawing::Color::Red;
        return;
    }
    else
        aesKeyLen->BackColor = System::Drawing::SystemColors::Window;
    int keyLength = 0;
    System::Int32::TryParse(aesKeyLen->Text, keyLength);

    std::unique_ptr<qto::AesCtrl> aes = std::make_unique<qto::AesCtrl>(keyLength);
    aesTextOut->Text = aes->encryptAes(aesTextToEnc->Text);
    aes->saveToFile("output/encrypted_data.bin");    
}
 