//PrintScreen Plz! V1.0.0.1
//By: Keith Lim Yong Ming
//Copyright © 2015
//Contact: keithlimym@hotmail.com

#include "PSPForm.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace Gdiplus;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	PrintScreenPlz::PSPForm form;
	Application::Run(%form);
}