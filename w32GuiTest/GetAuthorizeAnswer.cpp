#include "stdafx.h"
#include "GetAuthorizeAnswer.h"
#include "util.h"
#include "TPConnectorDll.h"

using namespace std;
extern map<string, HWND> GlbalConfigTextBoxes;
extern map<string, HWND> GetAthAnswerTextBoxes;

BOOL CreateGetAuthorizeAnswer_TextBoxes(map<string, HWND> &TextBoxes, HWND hTab ) {
	
	// Here are the HardCodeee ....
	wstring SECU(TEXT("912EC803B2CE49E4A541068D495AB570"));
	wstring MERC(TEXT("2153"));
	wstring ANSWER_K(TEXT("dee4d38b-d228-d077-5b55-2b1a12d24a16"));
	//End Here are the HardCodeee	

	HWND eti4 =  Create_Label(FALSE, hTab, L"SECURITY", 20, 60, 130, 20);
	HWND hwnTxEd_SECURITY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 60, 400, 20,
	hTab, (HMENU) IDC_REQUEST_GAASECURITY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_SECURITY, SECU);
	TextBoxes["LSECURITY"] = eti4;
	TextBoxes[SECURITY] = hwnTxEd_SECURITY;
		
	HWND eti3 =  Create_Label(FALSE,hTab, L"MERCHANT", 20, 90, 130, 20);
	HWND hwnTxEd_MERCHANT = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 90, 400, 20,
	hTab, (HMENU) IDC_REQUEST_GAAMERCHANT, NULL, NULL);
	SetTextinTextBox(hwnTxEd_MERCHANT, MERC);
	TextBoxes["LMERCHANT"] = eti3;
	TextBoxes[MERCHANT] = hwnTxEd_MERCHANT;

	HWND eti8 =  Create_Label(FALSE,hTab, L"REQUEST_KEY", 20, 120, 130, 20);
	HWND hwnTxEd_REQUEST_KEY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 120, 400, 20,
	hTab, (HMENU) IDC_REQUEST_GAAREQUEST_KEY, NULL, NULL);
	TextBoxes["LREQUEST_KEY"] = eti8;
	TextBoxes[REQUEST_KEY] = hwnTxEd_REQUEST_KEY;
	
	HWND eti5 =  Create_Label(FALSE,hTab, L"ANSWER_KEY ", 20, 150, 130, 20);
	HWND hwnTxEd_ANSWER_KEY = CreateWindowEx(WS_EX_CLIENTEDGE, L"edit", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 150, 400, 20,
	//hTab, (HMENU) IDC_REQUEST_MERCHANT, (HINSTANCE) GetWindowLong (hTab, GWL_HINSTANCE), NULL);
	hTab, (HMENU) IDC_REQUEST_GAAANSWER_KEY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_ANSWER_KEY, ANSWER_K);
	TextBoxes["LANSWER_KEY"] = eti5;
	TextBoxes[ANSWER_KEY] = hwnTxEd_ANSWER_KEY;

	
	return TRUE;
}



BOOL GetAuthorizeAnswer(map<string, string> &Output) {
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
	
	//
	InputData[SESSION]	= L"";

	//Al dato de lo conseguimos de SendAthRTextBoxes ya que deberia estar configurado
	it = GetAthAnswerTextBoxes.find(SECURITY);
	if( it != GetAthAnswerTextBoxes.end() ) {
		cTxtLen = GetWindowTextLength(it->second);
		if( cTxtLen > 0 ) {
			GetWindowTextW(it->second, text, cTxtLen+1);
			InputData[SECURITY]=wstring(text);
		}else{
			MessageBox(NULL, TEXT("Debe ingresar 'SECURITY'"),  TEXT("SECURITY"),  MB_DEFBUTTON2);
			return FALSE;;
		}
	}
	
	it = GetAthAnswerTextBoxes.find(MERCHANT);
	if( it != GetAthAnswerTextBoxes.end() ) {
		cTxtLen = GetWindowTextLength(it->second);
		if( cTxtLen > 0 ) {
			GetWindowTextW(it->second, text, cTxtLen+1);
			InputData[MERCHANT]=wstring(text);
		}else{
			MessageBox(NULL, TEXT("Debe ingresar 'MERCHANT'"),  TEXT("MERCHANT"),  MB_DEFBUTTON2);
			return FALSE;;
		}
	}

	it = GetAthAnswerTextBoxes.find(REQUEST_KEY);
	if( it != GetAthAnswerTextBoxes.end() ) {
		cTxtLen = GetWindowTextLength(it->second);
		if( cTxtLen > 0 ) {
			GetWindowTextW(it->second, text, cTxtLen+1);
			InputData[REQUEST_KEY]=wstring(text);
		}else{
			MessageBox(NULL, TEXT("Debe ingresar 'REQUEST_KEY'"),  TEXT("REQUEST_KEY"),  MB_DEFBUTTON2);
			return FALSE;;
		}
	}

	it = GetAthAnswerTextBoxes.find(ANSWER_KEY);
	if( it != GetAthAnswerTextBoxes.end() ) {
		cTxtLen = GetWindowTextLength(it->second);
		if( cTxtLen > 0 ) {
			GetWindowTextW(it->second, text, cTxtLen+1);
			InputData[ANSWER_KEY]=wstring(text);
		}else{
			MessageBox(NULL, TEXT("Debe ingresar 'ANSWER_KEY'"),  TEXT("ANSWER_KEY"),  MB_DEFBUTTON2);
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
			pConntor->GetAuthorizeAnswer_Send(*Req, Output);
			delete Req;
			return TRUE;
		}
	}

	return FALSE;
}

