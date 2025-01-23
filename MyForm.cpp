#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MyForm.h"

#include <cmath>
#using <System.dll>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]





int main()
{
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    MilitaryCommissariat::MyForm form;
    Application::Run(% form);
    return 0;
}
