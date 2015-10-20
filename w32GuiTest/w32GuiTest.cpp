// w32GuiTest.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
#include "w32GuiTest.h"

#include "AuthorizeRequest.h"

#include "TPConnectorDll.h"
#include <wchar.h> 
#include <commctrl.h>
#include <vector>

#include "util.h"
#pragma comment(lib, "comctl32.lib")

//Add by Marfio L.F.
//https://msdn.microsoft.com/en-us/library/windows/desktop/bb760550(v=vs.85).aspx#creating_tab_controls
//http://www.codeproject.com/Articles/14712/Win-SDK-C-Tab-Control-Made-Easy
//Viamonte 811 PB, Microcentro - CABA RRHH Natalia Reinoso* 14:00
//



using namespace std;


//const string endPointURL		= "https://developers.todopago.com.ar/services/t/1.1//services/";
//const string strAthorization	= "PRISMA f3d8b72c94ab4a06be2ef7c95490f7d3";

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

HWND hTab;
map<string, HWND> GlbalConfigTextBoxes;

map<string, HWND> SendAthRTextBoxes_Req;
map<string, HWND> SendAthRTextBoxes_PyL;

map<string, HWND> GetAthAnswerTextBoxes;
map<string, HWND> GetOpId_TextBoxes;

map<string, HWND> CyberSource_TextBoxes;
map<string, HWND> Retail_TextBoxes;
map<string, HWND> Output_TextBox;
const string OUT_TEXT = "Output_Text";




// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	TabProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



//Mario L.F. My Add functions
int  InsertTabItem(HWND hTab, LPTSTR pszText, int iid);
HWND OnCreateTabControls(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

BOOL SetTextinTextBox(HWND box, wstring &text);
BOOL CreateGlbalConfig_TextBoxes(map<string, HWND> &TextBoxes, HWND hWnd );
BOOL CreateSendAthReques_TextBoxes(map<string, HWND> &TextBoxes, map<string, HWND> &TextBoxesPyLoad, HWND hWnd );
BOOL CreateGetAuthorizeAnswer_TextBoxes(map<string, HWND> &TextBoxes, HWND hWnd);
BOOL CreateGetByOperationId_TextBoxes(map<string, HWND> &TextBoxes, HWND hWnd);
BOOL CreateCyberSource_TextBoxes(map<string, HWND> &TextBoxes, HWND hWnd);
BOOL CreateRetail_TextBoxes(map<string, HWND> &TextBoxes, HWND hWnd);

BOOL CreateOutput_TextBoxe(map<string, HWND> &output, HWND hWnd);

HWND Create_Label(BOOL visible, HWND hPadre, LPCWSTR texto, int x, int y, int ancho, int alto);
HWND Create_Button(HWND hPadre, LPCWSTR texto, HMENU idc, int x, int y, int ancho, int alto);
HWND Control(const HWND hwndHija, HWND hwndPadre);
BOOL OnNotify(HWND hwndTab, HWND hwndDisplay, LPARAM lParam);

BOOL SendAuthorizeRequest(	map<string, string>&Output);
BOOL GetAuthorizeAnswer(	map<string, string>&Output);
BOOL GetStatusByOperationId(map<string, string>&Output);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_W32GUITEST, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_W32GUITEST));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_W32GUITEST));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_W32GUITEST);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      //CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
	  CW_USEDEFAULT, CW_USEDEFAULT, 1100, 600,
	  NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK TabProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
	int wmId, wmEvent;
	map<string, string>Output;
	map<wstring, wstring>mtemp;
	map<wstring, wstring>::iterator itO;
	wstring textOup;

	map<string, string>::iterator its;

	wstring sep(L":  ");
	wstring esp(L"   ");
	//Borrar
	map<string, HWND>::iterator it;
	wchar_t text[512];
	
	
	wmId    = LOWORD(wParam);
	wmEvent = HIWORD(wParam);
	if( (message==WM_COMMAND) && (wmEvent==BN_CLICKED)  ) {
		switch (wmId)
		{
				case IDC_BTN_SENDATHR:
					
					SendAuthorizeRequest(Output);
					mtemp = sm2wsm(Output);
					for(itO = mtemp.begin(); itO != mtemp.end(); itO++) {
						textOup += itO->first + sep + itO->second + esp + L'\n';
					}
					
					it = Output_TextBox.find(OUT_TEXT);
					if( it != Output_TextBox.end() ) {
						SetTextinTextBox(it->second, textOup);
					}

					break;
				case IDC_BTN_GETATHA:
					
					Output.clear();
					GetAuthorizeAnswer(Output);
					mtemp = sm2wsm(Output);

					for(itO = mtemp.begin(); itO != mtemp.end(); itO++) {
						textOup += itO->first + sep + itO->second + esp + L'\n';
					}
					
					it = Output_TextBox.find(OUT_TEXT);
					if( it != Output_TextBox.end() ) {
						SetTextinTextBox(it->second, textOup);
					}

					break;
				case IDC_BTN_GETSTATUS:
					Output.clear();
					GetStatusByOperationId(Output);

					mtemp = sm2wsm(Output);

					for(itO = mtemp.begin(); itO != mtemp.end(); itO++) {
						textOup += itO->first + sep + itO->second + esp + L'\n';
					}
					
					it = Output_TextBox.find(OUT_TEXT);
					if( it != Output_TextBox.end() ) {
						SetTextinTextBox(it->second, textOup);
					}

					break;

				default:
					return DefSubclassProc(hWnd, message, wParam, lParam);
		}

	}
	return DefSubclassProc(hWnd, message, wParam, lParam);
}
//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//HWND hTab = 0;
	wchar_t text[256];
	map<string, HWND>::iterator it;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		hTab		=		OnCreateTabControls(hWnd, message, wParam, lParam);
		//
		CreateGlbalConfig_TextBoxes(GlbalConfigTextBoxes,			hTab);
		CreateSendAthReques_TextBoxes(SendAthRTextBoxes_Req, SendAthRTextBoxes_PyL,	hTab);
		CreateGetAuthorizeAnswer_TextBoxes(GetAthAnswerTextBoxes,	hTab);
		CreateGetByOperationId_TextBoxes(GetOpId_TextBoxes,			hTab);
		CreateCyberSource_TextBoxes(CyberSource_TextBoxes,			hTab);
		CreateRetail_TextBoxes(Retail_TextBoxes,					hTab);
		//
		CreateOutput_TextBoxe(Output_TextBox, hTab);
		
		//Create_Button(hTab, TEXT("&Add Entry"), rcBClient.top+20, rcBClient.bottom-90, 80, 40);
		Create_Button(hTab, TEXT("&SendAthRequest"),	(HMENU)IDC_BTN_SENDATHR,	20,		200, 100, 40);
		Create_Button(hTab, TEXT("&GetAthAnswer"),		(HMENU)IDC_BTN_GETATHA,		220,	200, 100, 40);
		Create_Button(hTab, TEXT("Get&ByOperation"),	(HMENU)IDC_BTN_GETSTATUS,	440,	200, 100, 40);

		break;
	
	case WM_NOTIFY:
		OnNotify(hTab, hWnd, lParam);
		break;

	case WM_SIZE:
		HWND hEdit;
        RECT rcClient;

        GetClientRect(hWnd, &rcClient);

        hEdit = GetDlgItem(hWnd, IDC_TAB);
        //SetWindowPos(hEdit, NULL, 0, 0, rcClient.right, rcClient.bottom-60, SWP_NOZORDER);
		SetWindowPos(hEdit, NULL, 0, 0, rcClient.right, rcClient.bottom, SWP_NOZORDER);
		
		GetClientRect(hTab, &rcClient);
		hEdit = GetDlgItem(hTab, IDC_BTN_SENDATHR);
		SetWindowPos(hEdit, NULL, 20, rcClient.bottom-160, 100, 40, SWP_NOZORDER);

		hEdit = GetDlgItem(hTab, IDC_BTN_GETATHA);
		SetWindowPos(hEdit, NULL, 420, rcClient.bottom-160, 100, 40, SWP_NOZORDER);

		hEdit = GetDlgItem(hTab, IDC_BTN_GETSTATUS);
		SetWindowPos(hEdit, NULL, 840, rcClient.bottom-160, 100, 40, SWP_NOZORDER);

		hEdit = GetDlgItem(hTab, IDC_OUTPUT);
		SetWindowPos(hEdit, NULL, rcClient.left+2, rcClient.bottom-100, rcClient.right-4, 100, SWP_NOZORDER);
		
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



//#pragma region TabControl



int InsertTabItem(HWND hTab, LPTSTR pszText, int iid)
{
    TCITEM ti = {0};
    ti.mask = TCIF_TEXT;
    ti.pszText = pszText;
    ti.cchTextMax = wcslen(pszText)+100;

	//TabCtrl_InsertItem(hTab, iid, &ti);

    return (int)SendMessage(hTab, TCM_INSERTITEM, iid, (LPARAM)&ti);
}


 HWND OnCreateTabControls(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	// Load and register Tab control class
    INITCOMMONCONTROLSEX iccx;
    iccx.dwSize = sizeof(INITCOMMONCONTROLSEX);
    iccx.dwICC = ICC_TAB_CLASSES;
    if (!InitCommonControlsEx(&iccx))
        return FALSE;

    // Create the Tab control 
    RECT rc;
    GetClientRect(hWnd, &rc);
    //HWND hTab = CreateWindowEx(0, WC_TABCONTROL, 0, 
	hTab = CreateWindowEx(0, WC_TABCONTROL, 0, 
        //TCS_FIXEDWIDTH | WS_CHILD | WS_VISIBLE, 
		WS_CHILD | WS_VISIBLE, 
        //rc.left + 2, rc.top + 2, rc.right - 4, rc.bottom - 60, 
		rc.left + 2, rc.top + 2, rc.right - 4, rc.bottom, 
        hWnd, (HMENU)IDC_TAB, hInst, 0);

    // Set the font of the tabs to a more typical system GUI font
    SendMessage(hTab, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), 0);

    // Store the Tab control handle as the user data associated with the 
    // parent window so that it can be retrieved for later use.
    SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)hTab);
		
	
    /////////////////////////////////////////////////////////////////////////
    // Add items to the tab common control.
    //
	InsertTabItem(hTab, L"Global Config",			0);
    InsertTabItem(hTab, L"SendAuthRequest Config",	1);
    InsertTabItem(hTab, L"GetAuthAnswer Config",	2);
	InsertTabItem(hTab, L"GetStatus Config",		3);
	InsertTabItem(hTab, L"CyberSource Config",		4);
	InsertTabItem(hTab, L"Retail Config",			5);




	//Linking the callback button function to parent windows
	//Ver:
	//http://stackoverflow.com/questions/18582749/is-it-possible-to-receive-messages-from-a-parent-window-which-is-not-the-main-wi
	SetWindowSubclass(hTab, &TabProc, 0, 0);


	return hTab;
 }


BOOL CreateOutput_TextBoxe(map<string, HWND> &output, HWND hTab) {
	// Create the Tab control 
    RECT rc;
	
    GetClientRect(hTab, &rc);
    
	HWND hwnTx = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL,  
        WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_AUTOVSCROLL,
		rc.left + 2,
		rc.bottom - 40,
		rc.right - 4,
		40,
        hTab, (HMENU)IDC_OUTPUT, hInst, 0);
	
	output[OUT_TEXT]=hwnTx;
	SetTextinTextBox(hwnTx, wstring(L"Output ..."));

	return TRUE;
}


BOOL CreateGlbalConfig_TextBoxes(map<string, HWND> &TextBoxes, HWND hTab ) {
	//wchar_t* endp = new wchar_t[512];
	//https://developers.todopago.com.ar/services/t/1.1//services/
	
	// Here are the HardCodeee ....
	wstring endp(TEXT("https://developers.todopago.com.ar/services/t/1.1//services/"));
	wstring Athor(TEXT("PRISMA f3d8b72c94ab4a06be2ef7c95490f7d3"));
	//End Here are the HardCodeee

	
	HWND eti1 =  Create_Label(TRUE, hTab, L"End Point", 20, 60, 100, 20);
	//I Add things to testing
	HWND hwnTxEd_ENDP = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	WS_VISIBLE | WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	130, 60, 400, 20,
	hTab, (HMENU) IDC_END_POINT_URL, hInst, NULL);
	
	SetTextinTextBox(hwnTxEd_ENDP, endp);

	TextBoxes["LEnd_Point"] = eti1;
	TextBoxes["End_Point"] = hwnTxEd_ENDP;

	HWND eti2 =  Create_Label(TRUE, hTab, L"Prisma Ath", 20, 90, 100, 20);
	HWND hwnTxEd_PRISA = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	WS_VISIBLE | WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	130, 90, 400, 20,
	hTab, (HMENU) IDC_PRISMA_ATHORIZ, hInst, NULL);
	
	SetTextinTextBox(hwnTxEd_PRISA, Athor);
		
	TextBoxes["LPrisma_Ath"] = eti2;
	TextBoxes["Prisma_Ath"] = hwnTxEd_PRISA;

	return true;
}

BOOL CreateGetByOperationId_TextBoxes(map<string, HWND> &TextBoxes, HWND hTab) {

	HWND eti4 =  Create_Label(FALSE, hTab, L"MERCHANT", 20, 60, 130, 20);
	HWND hwnTxEd_SECURITY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 60, 180, 20,
	hTab, (HMENU) IDC_REQUEST_GBYMERCHANT, NULL, NULL);
	TextBoxes["LMERCHANT"] = eti4;
	TextBoxes[MERCHANT] = hwnTxEd_SECURITY;

	HWND eti3 =  Create_Label(FALSE,hTab, L"GOPERATION_ID", 20, 90, 130, 20);
	HWND hwnTxEd_GOPERATION_ID = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 90, 180, 20,
	hTab, (HMENU) IDC_REQUEST_GOPERATION_ID, NULL, NULL);
	TextBoxes["LGOPERATION_ID"] = eti3;
	TextBoxes[GOPERATION_ID] = hwnTxEd_GOPERATION_ID;



	return TRUE;
}










// Handles notifications from the tab control, as follows: 
//   TCN_SELCHANGING - always returns FALSE to allow the user to select a 
//     different tab.  
//   TCN_SELCHANGE - loads a string resource and displays it in a static 
//     control on the selected tab.
// hwndTab - handle of the tab control.
// hwndDisplay - handle of the static control. 
// lParam - the lParam parameter of the WM_NOTIFY message.
//
BOOL OnNotify(HWND hwndTab, HWND hwndDisplay, LPARAM lParam)
{
    int iPage;
	map<string, HWND>::iterator it;
	//TCHAR achTemp[256]; // temporary buffer for strings

    switch (((LPNMHDR)lParam)->code)
        {
            case TCN_SELCHANGING:
                {
                    // Return FALSE to allow the selection to change.
                    return FALSE;
                }

            case TCN_SELCHANGE:
                { 
					//Debuging iPage value ..
					char * mystring = new char[100];

					iPage = TabCtrl_GetCurSel(hwndTab);
					sprintf_s(mystring, 100, "iPage Tab index= [%d]", iPage);

					string my2string(mystring);

					std::wstring ws;
					ws.append(my2string.begin(), my2string.end());
					//MessageBox(NULL, ws.c_str(),  ws.c_str(), MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);
					//End Debuging iPage value ..
					
                    // Note that g_hInst is the global instance handle.
					if(iPage == 0) {

						for(it=GlbalConfigTextBoxes.begin(); it != GlbalConfigTextBoxes.end(); it++)
							ShowWindow( it->second, SW_SHOW);
						
						//SendAthRequest
						for(it=SendAthRTextBoxes_Req.begin(); it != SendAthRTextBoxes_Req.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						for(it=SendAthRTextBoxes_PyL.begin(); it != SendAthRTextBoxes_PyL.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						//End SendAthRequest

						for(it=GetAthAnswerTextBoxes.begin(); it != GetAthAnswerTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						for(it=GetOpId_TextBoxes.begin(); it != GetOpId_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						for(it=CyberSource_TextBoxes.begin(); it != CyberSource_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						for(it=Retail_TextBoxes.begin(); it != Retail_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						
					}else if(iPage == 1) {

						for(it=GlbalConfigTextBoxes.begin(); it != GlbalConfigTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						//SendAthRequest
						for(it=SendAthRTextBoxes_Req.begin(); it != SendAthRTextBoxes_Req.end(); it++)
							ShowWindow( it->second, SW_SHOW);
						for(it=SendAthRTextBoxes_PyL.begin(); it != SendAthRTextBoxes_PyL.end(); it++)
							ShowWindow( it->second, SW_SHOW);
						//End SendAthRequest
						
						for(it=GetAthAnswerTextBoxes.begin(); it != GetAthAnswerTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						for(it=GetOpId_TextBoxes.begin(); it != GetOpId_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						for(it=CyberSource_TextBoxes.begin(); it != CyberSource_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);

						for(it=Retail_TextBoxes.begin(); it != Retail_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);

					}else if(iPage == 2) {

						for(it=GlbalConfigTextBoxes.begin(); it != GlbalConfigTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						//SendAthRequest
						for(it=SendAthRTextBoxes_Req.begin(); it != SendAthRTextBoxes_Req.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						for(it=SendAthRTextBoxes_PyL.begin(); it != SendAthRTextBoxes_PyL.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						//End SendAthRequest

						for(it=GetAthAnswerTextBoxes.begin(); it != GetAthAnswerTextBoxes.end(); it++)
							ShowWindow( it->second, SW_SHOW);
						
						for(it=GetOpId_TextBoxes.begin(); it != GetOpId_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);

						for(it=CyberSource_TextBoxes.begin(); it != CyberSource_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);

						for(it=Retail_TextBoxes.begin(); it != Retail_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
					
					}else if(iPage == 3) {

						for(it=GlbalConfigTextBoxes.begin(); it != GlbalConfigTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						//SendAthRequest
						for(it=SendAthRTextBoxes_Req.begin(); it != SendAthRTextBoxes_Req.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						for(it=SendAthRTextBoxes_PyL.begin(); it != SendAthRTextBoxes_PyL.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						//End SendAthRequest

						for(it=GetAthAnswerTextBoxes.begin(); it != GetAthAnswerTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						for(it=GetOpId_TextBoxes.begin(); it != GetOpId_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_SHOW);

						for(it=CyberSource_TextBoxes.begin(); it != CyberSource_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);

						for(it=Retail_TextBoxes.begin(); it != Retail_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
					
					}else if(iPage == 4) {

						for(it=GlbalConfigTextBoxes.begin(); it != GlbalConfigTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						//SendAthRequest
						for(it=SendAthRTextBoxes_Req.begin(); it != SendAthRTextBoxes_Req.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						for(it=SendAthRTextBoxes_PyL.begin(); it != SendAthRTextBoxes_PyL.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						//End SendAthRequest

						for(it=GetAthAnswerTextBoxes.begin(); it != GetAthAnswerTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						for(it=GetOpId_TextBoxes.begin(); it != GetOpId_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);

						for(it=CyberSource_TextBoxes.begin(); it != CyberSource_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_SHOW);

						for(it=Retail_TextBoxes.begin(); it != Retail_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
					}else if(iPage == 5) {

						for(it=GlbalConfigTextBoxes.begin(); it != GlbalConfigTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						//SendAthRequest
						for(it=SendAthRTextBoxes_Req.begin(); it != SendAthRTextBoxes_Req.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						for(it=SendAthRTextBoxes_PyL.begin(); it != SendAthRTextBoxes_PyL.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						//End SendAthRequest

						for(it=GetAthAnswerTextBoxes.begin(); it != GetAthAnswerTextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);
						
						for(it=GetOpId_TextBoxes.begin(); it != GetOpId_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);

						for(it=CyberSource_TextBoxes.begin(); it != CyberSource_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_HIDE);

						for(it=Retail_TextBoxes.begin(); it != Retail_TextBoxes.end(); it++)
							ShowWindow( it->second, SW_SHOW);
					}
					break;
                } 
        }
        return TRUE;
}




BOOL GetStatusByOperationId(map<string, string>&Output) {
	map<string, HWND>::iterator it;
	wchar_t text[512]; int cTxtLen; int ret;
	
	string strEndP; string strAth;

	map<string, wstring>InputData;

	//
	it = GlbalConfigTextBoxes.find("End_Point");
	if( it != GlbalConfigTextBoxes.end() ) {
		cTxtLen = GetWindowTextLength(it->second);
		if( cTxtLen > 0 ) {
			GetWindowTextW(it->second, text, cTxtLen+1);
			strEndP = ws2s(wstring(text));
		}else{
			MessageBox(NULL, TEXT("Debe ingresar 'End Point'"),  TEXT("End Point"),  MB_DEFBUTTON2);
			return FALSE;
		}
	}
	//				
	it = GlbalConfigTextBoxes.find("Prisma_Ath");
	if( it != GlbalConfigTextBoxes.end() ) {
		cTxtLen = GetWindowTextLength(it->second);
		if( cTxtLen > 0 ) {
			GetWindowTextW(it->second, text, cTxtLen+1);
			strAth = ws2s(wstring(text));
		}else{
			MessageBox(NULL, TEXT("Debe ingresar 'Prisma Ath'"),  TEXT("Prisma Ath"),  MB_DEFBUTTON2);
			return FALSE;;
		}
	}

	it = GetOpId_TextBoxes.find(MERCHANT);
	if( it != GetOpId_TextBoxes.end() ) {
		cTxtLen = GetWindowTextLength(it->second);
		if( cTxtLen > 0 ) {
			GetWindowTextW(it->second, text, cTxtLen+1);
			InputData[MERCHANT]=wstring(text);
		}else{
			MessageBox(NULL, TEXT("Debe ingresar 'MERCHANT'"),  TEXT("MERCHANT"),  MB_DEFBUTTON2);
			return FALSE;;
		}
	}

	it = GetOpId_TextBoxes.find(GOPERATION_ID);
	if( it != GetOpId_TextBoxes.end() ) {
		cTxtLen = GetWindowTextLength(it->second);
		if( cTxtLen > 0 ) {
			GetWindowTextW(it->second, text, cTxtLen+1);
			InputData[GOPERATION_ID]=wstring(text);
		}else{
			MessageBox(NULL, TEXT("Debe ingresar 'GOPERATION_ID'"),  TEXT("GOPERATION_ID"),  MB_DEFBUTTON2);
			return FALSE;;
		}
	}

	HINSTANCE hinstLib;
	hinstLib = LoadLibrary(TEXT("ExLinkTPConnectorDll.dll"));
	if(hinstLib == NULL) {
		MessageBox(NULL, TEXT("No encuentra ExLinkTPConnectorDll"),  TEXT("ExLinkTPConnectorDll"),  MB_DEFBUTTON2);
		return FALSE;
	}

	PF_GetDLLInterface pIntf = (PF_GetDLLInterface) GetProcAddress(hinstLib, "GetDLLInterface");
	TPCtor_Interface *pConntor = pIntf();

	if( pConntor ) {
		if(ret = pConntor->TPConnector_Init(strEndP, strAth) == 0) {
			map<string, string>*Req = wsm2sm(InputData);
			pConntor->GetByOperationId_Send(*Req, Output);
			delete Req;
			return TRUE;
		}
	}

	return FALSE;
}


//#pragma endregion
