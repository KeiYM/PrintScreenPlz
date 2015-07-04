//PrintScreen Plz! V1.0.0.1
//By: Keith Lim Yong Ming
//Copyright © 2015
//Contact: keithlimym@hotmail.com

#pragma once
#include <afxwin.h>
#include <atlimage.h>
#include <fstream>
#include <string>
#include <msclr/marshal.h>
#include <sstream>
#include "AboutForm.h"

namespace PrintScreenPlz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace msclr::interop;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for PSPForm
	/// </summary>
	public ref class PSPForm : public System::Windows::Forms::Form
	{
	public:
		PSPForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SetDefaults();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PSPForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  bmpRB;
	private: System::Windows::Forms::RadioButton^  pngRB;
	private: System::Windows::Forms::RadioButton^  jpegRB;

	private: System::Windows::Forms::Button^  setSavePath;
	private: System::Windows::Forms::Button^  setPSButt;
	private: System::Windows::Forms::Button^  startPS;
	private: System::Windows::Forms::Button^  stopPS;


	private: System::Windows::Forms::TextBox^  savePath;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  currScreenLabel;

	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	//Own Variables
	private: String^ folderName;
	private: System::Windows::Forms::Label^  printScrLabel;

	//Name of PrintScreen stroke
	private: String^ printScrKey;

	private: HWND hWnd;

	//UNIT of Key-stroke (For PrintScreen)
	private: UINT vK;

	private: System::Windows::Forms::Button^  terminatePS;
	private: System::Windows::Forms::Button^  aboutMe;
	private: System::Windows::Forms::CheckBox^  addShift;
	private: System::Windows::Forms::CheckBox^  addCtrl;
	private: System::Windows::Forms::CheckBox^  addAlt;
	private: System::Windows::Forms::CheckBox^  addWin;
	private: System::Windows::Forms::Label^  additionalKeyStroke;

	//HotKey ID
	private: int id;

	//Additional KeyStrokes (Ctrl, Alt, Windows, Shift)
	private: int ADD_KEYS;

	//About Form:
	private: System::Windows::Forms::Form ^ aboutForm;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PSPForm::typeid));
			this->bmpRB = (gcnew System::Windows::Forms::RadioButton());
			this->pngRB = (gcnew System::Windows::Forms::RadioButton());
			this->setSavePath = (gcnew System::Windows::Forms::Button());
			this->jpegRB = (gcnew System::Windows::Forms::RadioButton());
			this->setPSButt = (gcnew System::Windows::Forms::Button());
			this->startPS = (gcnew System::Windows::Forms::Button());
			this->stopPS = (gcnew System::Windows::Forms::Button());
			this->savePath = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->currScreenLabel = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->printScrLabel = (gcnew System::Windows::Forms::Label());
			this->terminatePS = (gcnew System::Windows::Forms::Button());
			this->aboutMe = (gcnew System::Windows::Forms::Button());
			this->addShift = (gcnew System::Windows::Forms::CheckBox());
			this->addCtrl = (gcnew System::Windows::Forms::CheckBox());
			this->addAlt = (gcnew System::Windows::Forms::CheckBox());
			this->addWin = (gcnew System::Windows::Forms::CheckBox());
			this->additionalKeyStroke = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bmpRB
			// 
			this->bmpRB->AutoSize = true;
			this->bmpRB->Location = System::Drawing::Point(95, 41);
			this->bmpRB->Name = L"bmpRB";
			this->bmpRB->Size = System::Drawing::Size(48, 17);
			this->bmpRB->TabIndex = 0;
			this->bmpRB->TabStop = true;
			this->bmpRB->Text = L"BMP";
			this->bmpRB->UseVisualStyleBackColor = true;
			// 
			// pngRB
			// 
			this->pngRB->AutoSize = true;
			this->pngRB->Location = System::Drawing::Point(149, 41);
			this->pngRB->Name = L"pngRB";
			this->pngRB->Size = System::Drawing::Size(48, 17);
			this->pngRB->TabIndex = 1;
			this->pngRB->TabStop = true;
			this->pngRB->Text = L"PNG";
			this->pngRB->UseVisualStyleBackColor = true;
			// 
			// setSavePath
			// 
			this->setSavePath->Location = System::Drawing::Point(12, 12);
			this->setSavePath->Name = L"setSavePath";
			this->setSavePath->Size = System::Drawing::Size(85, 23);
			this->setSavePath->TabIndex = 2;
			this->setSavePath->Text = L"Set Save Path";
			this->setSavePath->UseVisualStyleBackColor = true;
			this->setSavePath->Click += gcnew System::EventHandler(this, &PSPForm::button1_Click);
			// 
			// jpegRB
			// 
			this->jpegRB->AutoSize = true;
			this->jpegRB->Location = System::Drawing::Point(203, 41);
			this->jpegRB->Name = L"jpegRB";
			this->jpegRB->Size = System::Drawing::Size(52, 17);
			this->jpegRB->TabIndex = 3;
			this->jpegRB->TabStop = true;
			this->jpegRB->Text = L"JPEG";
			this->jpegRB->UseVisualStyleBackColor = true;
			// 
			// setPSButt
			// 
			this->setPSButt->Location = System::Drawing::Point(12, 64);
			this->setPSButt->Name = L"setPSButt";
			this->setPSButt->Size = System::Drawing::Size(131, 23);
			this->setPSButt->TabIndex = 4;
			this->setPSButt->Text = L"Set PrintScr Button";
			this->setPSButt->UseVisualStyleBackColor = true;
			this->setPSButt->Click += gcnew System::EventHandler(this, &PSPForm::setPSButt_Click);
			// 
			// startPS
			// 
			this->startPS->Location = System::Drawing::Point(93, 140);
			this->startPS->Name = L"startPS";
			this->startPS->Size = System::Drawing::Size(75, 23);
			this->startPS->TabIndex = 5;
			this->startPS->Text = L"Start";
			this->startPS->UseVisualStyleBackColor = true;
			this->startPS->Click += gcnew System::EventHandler(this, &PSPForm::startPS_Click);
			// 
			// stopPS
			// 
			this->stopPS->Location = System::Drawing::Point(174, 141);
			this->stopPS->Name = L"stopPS";
			this->stopPS->Size = System::Drawing::Size(75, 23);
			this->stopPS->TabIndex = 6;
			this->stopPS->Text = L"Stop";
			this->stopPS->UseVisualStyleBackColor = true;
			this->stopPS->Click += gcnew System::EventHandler(this, &PSPForm::stopPS_Click);
			// 
			// savePath
			// 
			this->savePath->Location = System::Drawing::Point(104, 13);
			this->savePath->Name = L"savePath";
			this->savePath->ReadOnly = true;
			this->savePath->Size = System::Drawing::Size(231, 20);
			this->savePath->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Save Image As";
			// 
			// currScreenLabel
			// 
			this->currScreenLabel->AutoSize = true;
			this->currScreenLabel->Location = System::Drawing::Point(155, 69);
			this->currScreenLabel->Name = L"currScreenLabel";
			this->currScreenLabel->Size = System::Drawing::Size(132, 13);
			this->currScreenLabel->TabIndex = 10;
			this->currScreenLabel->Text = L"Current PrintScr Button Is: ";
			// 
			// printScrLabel
			// 
			this->printScrLabel->AutoSize = true;
			this->printScrLabel->Location = System::Drawing::Point(283, 69);
			this->printScrLabel->Name = L"printScrLabel";
			this->printScrLabel->Size = System::Drawing::Size(35, 13);
			this->printScrLabel->TabIndex = 11;
			this->printScrLabel->Text = L"label3";
			// 
			// terminatePS
			// 
			this->terminatePS->Location = System::Drawing::Point(255, 141);
			this->terminatePS->Name = L"terminatePS";
			this->terminatePS->Size = System::Drawing::Size(75, 23);
			this->terminatePS->TabIndex = 13;
			this->terminatePS->Text = L"Close";
			this->terminatePS->UseVisualStyleBackColor = true;
			this->terminatePS->Click += gcnew System::EventHandler(this, &PSPForm::terminatePS_Click);
			// 
			// aboutMe
			// 
			this->aboutMe->Location = System::Drawing::Point(12, 140);
			this->aboutMe->Name = L"aboutMe";
			this->aboutMe->Size = System::Drawing::Size(75, 23);
			this->aboutMe->TabIndex = 14;
			this->aboutMe->Text = L"About";
			this->aboutMe->UseVisualStyleBackColor = true;
			this->aboutMe->Click += gcnew System::EventHandler(this, &PSPForm::aboutMe_Click);
			// 
			// addShift
			// 
			this->addShift->AutoSize = true;
			this->addShift->Location = System::Drawing::Point(158, 94);
			this->addShift->Name = L"addShift";
			this->addShift->Size = System::Drawing::Size(56, 17);
			this->addShift->TabIndex = 15;
			this->addShift->Text = L"+ Shift";
			this->addShift->UseVisualStyleBackColor = true;
			// 
			// addCtrl
			// 
			this->addCtrl->AutoSize = true;
			this->addCtrl->Location = System::Drawing::Point(221, 94);
			this->addCtrl->Name = L"addCtrl";
			this->addCtrl->Size = System::Drawing::Size(50, 17);
			this->addCtrl->TabIndex = 16;
			this->addCtrl->Text = L"+ Ctrl";
			this->addCtrl->UseVisualStyleBackColor = true;
			// 
			// addAlt
			// 
			this->addAlt->AutoSize = true;
			this->addAlt->Location = System::Drawing::Point(158, 114);
			this->addAlt->Name = L"addAlt";
			this->addAlt->Size = System::Drawing::Size(47, 17);
			this->addAlt->TabIndex = 17;
			this->addAlt->Text = L"+ Alt";
			this->addAlt->UseVisualStyleBackColor = true;
			// 
			// addWin
			// 
			this->addWin->AutoSize = true;
			this->addWin->Location = System::Drawing::Point(221, 114);
			this->addWin->Name = L"addWin";
			this->addWin->Size = System::Drawing::Size(79, 17);
			this->addWin->TabIndex = 18;
			this->addWin->Text = L"+ Windows";
			this->addWin->UseVisualStyleBackColor = true;
			// 
			// additionalKeyStroke
			// 
			this->additionalKeyStroke->AutoSize = true;
			this->additionalKeyStroke->Location = System::Drawing::Point(12, 94);
			this->additionalKeyStroke->Name = L"additionalKeyStroke";
			this->additionalKeyStroke->Size = System::Drawing::Size(117, 13);
			this->additionalKeyStroke->TabIndex = 19;
			this->additionalKeyStroke->Text = L"Add Additional Strokes:";
			// 
			// PSPForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(347, 174);
			this->Controls->Add(this->additionalKeyStroke);
			this->Controls->Add(this->addWin);
			this->Controls->Add(this->addAlt);
			this->Controls->Add(this->addCtrl);
			this->Controls->Add(this->addShift);
			this->Controls->Add(this->aboutMe);
			this->Controls->Add(this->terminatePS);
			this->Controls->Add(this->printScrLabel);
			this->Controls->Add(this->currScreenLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->savePath);
			this->Controls->Add(this->stopPS);
			this->Controls->Add(this->startPS);
			this->Controls->Add(this->setPSButt);
			this->Controls->Add(this->jpegRB);
			this->Controls->Add(this->setSavePath);
			this->Controls->Add(this->pngRB);
			this->Controls->Add(this->bmpRB);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"PSPForm";
			this->Text = L"PrintScreen Plz! V1.0.0.1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void SetDefaults() {
			this->KeyPreview = true;

			//Turn off "Stop" Button
			stopPS->Enabled = false;

			//TODO: Look for txt file containing Saving Details
			//Set as default folder (My Pictures):
			CHAR userMyPicture[MAX_PATH];
			HRESULT pictureResult = SHGetFolderPathA(NULL, CSIDL_MYPICTURES, NULL, SHGFP_TYPE_CURRENT, userMyPicture);
			String^ pictureFP;
			pictureFP = gcnew String(userMyPicture);
			folderName = pictureFP;
			savePath->Text = folderName;
			//Set RadioBox to selected Type
			jpegRB->Checked = true;
			//Set Print Screen Key to selected Key
			printScrKey = "Delete";
			printScrLabel->Text = printScrKey;

			//Virtual Key value for Delete
			vK = 0x2E;

			//ID of HotKey
			id = 0;
			
			//Set to No Mods
			ADD_KEYS = 0x00;

		}
#pragma endregion

	//Open the Folder Dialog
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Show the FolderBrowserDialog.
				 System::Windows::Forms::DialogResult result = folderBrowserDialog->ShowDialog();

				 if ( result == System::Windows::Forms::DialogResult::OK )
				 {
					 folderName = folderBrowserDialog->SelectedPath;
					 savePath->Text = folderName;
				 }
			 }

	//Close App
	private: System::Void terminatePS_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Close Program.
				 //TODO: Remove all Listeners (If any)
				 UnregisterHotKey(hWnd,id);
				 Application::Exit();
			 }
			 
	//Setting Key
	private: System::Void setPSButt_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Set Displays
				 currScreenLabel->Text = "PRESS ANY KEY";
				 printScrLabel->Text = "";
				 setPSButt->Enabled = false;
				 setSavePath->Enabled = false;
				 savePath->Enabled = false;
				 jpegRB->Enabled = false;
				 bmpRB->Enabled = false;
				 pngRB->Enabled = false;
				 startPS->Enabled = false;
				 stopPS->Enabled = false;
				 terminatePS->Enabled = false;
				 aboutMe->Enabled = false;
				 addWin->Enabled = false;
				 addCtrl->Enabled = false;
				 addAlt->Enabled = false;
				 addShift->Enabled = false;
				 
				 //Add Listener
				 this->KeyDown += gcnew KeyEventHandler(this, &PSPForm::PSPForm_SetKey);
			 }

	//Listener for Setting Key
	private: System::Void PSPForm_SetKey(Object^ sender, KeyEventArgs^ e) {
				 //Set Displays. Update new PrintScreen key
				 currScreenLabel->Text = "Current PrintScr Button Is: ";
				 printScrLabel->Text = e->KeyCode.ToString();
				 printScrKey = e->KeyCode.ToString();

				 vK = e->KeyValue;

				 setPSButt->Enabled = true;
				 setSavePath->Enabled = true;
				 savePath->Enabled = true;
				 jpegRB->Enabled = true;
				 bmpRB->Enabled = true;
				 pngRB->Enabled = true;
				 startPS->Enabled = true;
				 stopPS->Enabled = false;
				 terminatePS->Enabled = true;
				 aboutMe->Enabled = true;

				 //If HotKey matches special Keys (Ctrl,Alt,Shift,Win), disable their Checkboxes
				 switch(vK){
						case VK_CONTROL  :
							addWin->Enabled = true;
							addCtrl->Checked = false;
							addAlt->Enabled = true;
							addShift->Enabled = true;
							break;
						case VK_MENU  :
							addWin->Enabled = true;
							addCtrl->Enabled = true;
							addAlt->Checked = false;
							addShift->Enabled = true;
							break;
 						case VK_SHIFT  :
							addWin->Enabled = true;
							addCtrl->Enabled = true;
							addAlt->Enabled = true;
							addShift->Checked = false;
							break;
						case VK_LWIN  :
						case VK_RWIN  :
							addWin->Checked = false;
							addCtrl->Enabled = true;
							addAlt->Enabled = true;
							addShift->Enabled = true;
							break;
						default : 
							addWin->Enabled = true;
							addCtrl->Enabled = true;
							addAlt->Enabled = true;
							addShift->Enabled = true;
							break;
				}

				 //Remove Listener
				 this->KeyDown -=  gcnew KeyEventHandler(this, &PSPForm::PSPForm_SetKey);
			 }

	//Set the HotKey for PrintScreen
	private: System::Void startPS_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Set Displays
				 setPSButt->Enabled = false;
				 setSavePath->Enabled = false;
				 savePath->Enabled = false;
				 jpegRB->Enabled = false;
				 bmpRB->Enabled = false;
				 pngRB->Enabled = false;
				 startPS->Enabled = false;
				 terminatePS->Enabled = false;
				 stopPS->Enabled = true;
				 aboutMe->Enabled = false;
				 addWin->Enabled = false;
				 addCtrl->Enabled = false;
				 addAlt->Enabled = false;
				 addShift->Enabled = false;


				 //Global Hotkey
				 HWND hWnd = static_cast<HWND>(Handle.ToPointer());

				 //Reset Additional Key Value
				 ADD_KEYS = 0x00;

				 //Special Cases (Ctrl, Alt, Shift & Windows)
				 switch(vK){
						case VK_CONTROL  :
							ADD_KEYS |= MOD_CONTROL;
							break;
						case VK_MENU  :
							ADD_KEYS |= MOD_ALT;
							break;
 						case VK_SHIFT  :
							ADD_KEYS |= MOD_SHIFT;
							break;
						case VK_LWIN  :
						case VK_RWIN  :
							ADD_KEYS |= MOD_WIN;
							break;
						default : break;
				}

				//Append Additional Keys
				if(addCtrl->Checked) {
					ADD_KEYS |= MOD_CONTROL;
				}
				if(addAlt->Checked) {
					ADD_KEYS |= MOD_ALT;
				}
				if(addShift->Checked) {
					ADD_KEYS |= MOD_SHIFT;
				}
				if(addWin->Checked) {
					ADD_KEYS |= MOD_WIN;
				}

				if (RegisterHotKey(hWnd, id, ADD_KEYS, vK))  //0x2E is DEL
				{
					 _tprintf(_T("REGISTERED"));
				}
			}

	//HotKey Activated
	protected:  virtual void WndProc(System::Windows::Forms::Message% m) override {
					HWND hWnd = static_cast<HWND>(Handle.ToPointer());
					if (m.Msg == WM_HOTKEY){

						//Clunky temp solution: Disable the HotKey and resend the Key input to System
						//This allows the user to continue using the key button as per normal in Apps
						UnregisterHotKey(hWnd,id);

						//Resend Keystroke to whatever App
						INPUT input;
						input.type = INPUT_KEYBOARD;
						input.ki.wScan = MapVirtualKey(vK, MAPVK_VK_TO_VSC);
						input.ki.time = 0;
						input.ki.dwExtraInfo = 0;
						input.ki.wVk = vK;
						input.ki.dwFlags = 0;	//No Key-down
						SendInput(1, &input, sizeof(INPUT));

						input.ki.dwFlags = KEYEVENTF_KEYUP;
						SendInput(1, &input, sizeof(INPUT));

						_tprintf(_T("WM_HOTKEY received\n"));

						//Print the Screen:
						//Initialize Params to get Dimensions of Screen
						int x1, y1, x2, y2, w, h;
						//Get Screen Dimensions
						x1  = GetSystemMetrics(SM_XVIRTUALSCREEN);
						y1  = GetSystemMetrics(SM_YVIRTUALSCREEN);
						x2  = GetSystemMetrics(SM_CXVIRTUALSCREEN);
						y2  = GetSystemMetrics(SM_CYVIRTUALSCREEN);
						w   = x2 - x1;
						h   = y2 - y1;

						//Copy the Screen to a BitMap
						//hScreen is entire Screen of user
						HDC     hScreen = GetDC(NULL);
						HDC     hDC     = CreateCompatibleDC(hScreen);
						HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
						HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
						BOOL    bRet    = BitBlt(hDC, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);

						//Saving BitMap to the Clipboard
						OpenClipboard(NULL);

						//Clear previous entry
						EmptyClipboard();
						SetClipboardData(CF_BITMAP, hBitmap);
						CloseClipboard();

						//Clean up Information
						SelectObject(hDC, old_obj);
						DeleteDC(hDC);
						ReleaseDC(NULL, hScreen);
						DeleteObject(hBitmap);

						//Grab from Clipboard and Save to File
						if (!IsClipboardFormatAvailable(CF_DIB))
							return;

						marshal_context ^ context = gcnew marshal_context();

						TCHAR* path = (TCHAR*)Marshal::StringToHGlobalUni(savePath->Text).ToPointer();

						HBITMAP hBitmap2 = (HBITMAP)GetClipboardData(CF_BITMAP);
						TCHAR szName[MAX_PATH] = { 0 };
						SYSTEMTIME st = { 0 };
						::GetLocalTime(&st);



						//Prepare to Save
						CImage image; 
						image.Attach(hBitmap); 

						if(bmpRB->Checked) {					
							_stprintf(szName, _T("%s\\%02d-%02d-%02d-%03d.bmp"), path, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
							image.Save(szName, Gdiplus::ImageFormatBMP);
						}else if(jpegRB->Checked) {
							_stprintf(szName, _T("%s\\%02d-%02d-%02d-%03d.jpg"), path, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
							image.Save(szName, Gdiplus::ImageFormatJPEG); 
						}else if(pngRB->Checked) {
							_stprintf(szName, _T("%s\\%02d-%02d-%02d-%03d.png"), path, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
							image.Save(szName, Gdiplus::ImageFormatPNG);
						} 
						CloseClipboard();

						//Re-register HotKey
						RegisterHotKey(hWnd, id, ADD_KEYS, vK);
					}
					Form::WndProc(m);
				}

	//Stop tracking PrintScreen
	private: System::Void stopPS_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Set Display. Stop Tracking
				 setPSButt->Enabled = true;
				 setSavePath->Enabled = true;
				 savePath->Enabled = true;
				 jpegRB->Enabled = true;
				 bmpRB->Enabled = true;
				 pngRB->Enabled = true;
				 startPS->Enabled = true;
				 stopPS->Enabled = false;
				 terminatePS->Enabled = true;
				 aboutMe->Enabled = true;
				 addWin->Enabled = true;
				 addCtrl->Enabled = true;
				 addAlt->Enabled = true;
				 addShift->Enabled = true;


				 //Remove Hotkey
				 UnregisterHotKey(hWnd,id);
			 }

	//Load the About Form
	private: System::Void aboutMe_Click(System::Object^  sender, System::EventArgs^  e) {
				 AboutForm ^aForm = gcnew AboutForm();
				 aForm->StartPosition = FormStartPosition::Manual;
				 aForm->Location = this->Location;
                 aForm->ShowDialog();
			 }
};

}