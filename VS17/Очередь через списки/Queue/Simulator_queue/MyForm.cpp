#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


int Main(array <String^ > ^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Simulatorqueue::MyForm form;
	Application::Run(%form);
	return 0;
}

