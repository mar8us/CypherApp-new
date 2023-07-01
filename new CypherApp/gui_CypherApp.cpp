#include "gui_CypherApp.h"
#include "cryptoModel.h"
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

