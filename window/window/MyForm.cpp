#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STATHread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	window::MyForm myForm;
	Application::Run(%myForm);


}
