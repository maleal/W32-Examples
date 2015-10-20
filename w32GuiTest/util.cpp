/*	Developer: Mario, Leal Fuentes 
	You should Include here all util functionality
*/
#include "stdafx.h"
#include "util.h"
#include <CommCtrl.h>


using namespace std;

//Retorno por valor un wstring desde una referencia a string
wstring s2ws(const string& s)
{
    int len;
    int slength = (int)s.length();
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
    wstring ret(len, L'\0');
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &ret[0], len);
    return ret;
}

map<wstring, wstring> sm2wsm( map<string, string>sm) {
	map<string, string>::iterator it;
	map<wstring, wstring> ret;
	
	for(it=sm.begin(); it!=sm.end(); it++)
		ret[s2ws(it->first)] = s2ws(it->second);
	return ret;
}

//Retorno por valor un string desde una copia wstring
string ws2s(const wstring sw)
{
	if( sw.empty() ) return std::string();

    //int slength = (int)sw.length() + 1; //Si necesitas terminar el string con un caracter nulo ... descomenta!
	int slength = (int)sw.length();
    int len = WideCharToMultiByte(CP_ACP, 0, sw.c_str(), slength, 0, 0, 0, 0);

    string ret(len, '\0');
    WideCharToMultiByte(CP_ACP, 0, sw.c_str(), slength, &ret[0], len, 0, 0); 
    return ret;
}

//Retorno un puntero a map de string desde un map wstring
map<string, string> *wsm2sm( map<string, wstring>& mw)
{
	map<string, wstring>::iterator it;
	//map<string, string>ret;

	map<string, string>* pret = new map<string, string>;


	for(it=mw.begin(); it != mw.end(); it++) {
		(*pret)[it->first]=ws2s(it->second);
	}

	return pret;
/*
	for(it=mw.begin(); it != mw.end(); it++) {
		ret[it->first]= ws2s(it->second);
	}

    return ret;
	*/
}

// Crea una Create_Label o Labelbox
//==============================
HWND Create_Label(BOOL visible, HWND hPadre, LPCWSTR texto, int x, int y, int ancho, int alto)
{
  HWND hEtiqueta;
    
  hEtiqueta = CreateWindowEx(WS_EX_TRANSPARENT, L"STATIC", texto, visible?(WS_CHILD| WS_VISIBLE):(WS_CHILD),
                             x, y, ancho, alto, hPadre, NULL, NULL, NULL);

  return Control(hEtiqueta, hPadre);
}

// TEXT("&Add Entry")
HWND Create_Button(HWND hPadre, LPCWSTR texto, HMENU idc, int x, int y, int ancho, int alto) {
	// Create the 'add entry' button.
    HWND hWndChild = CreateWindowEx(0, WC_BUTTON, texto,
                    BS_PUSHBUTTON | BS_TEXT |
                    WS_CHILD | WS_TABSTOP | WS_VISIBLE,
                    x, y, ancho, alto, hPadre, idc, NULL, NULL);

    return Control(hWndChild, hPadre);
	/*if(!hWndChild) return -1;
                // Set the button controls properties.
                SendMessage(hWndChild, WM_SETFONT, (WPARAM)g_hfText, FALSE);*/
}

//

// Se encarga de informar si hubo un error al crear el control
// y cambia la fuente por la predeterminada en el Panel de Control
HWND Control(const HWND hwndHija, HWND hwndPadre)
{
  if (hwndHija == NULL)
    MessageBox(hwndPadre, L"No se puede crear el control.", L"¡Error!",
               MB_OK | MB_ICONERROR);
  else 
    SendMessage(hwndHija, WM_SETFONT, (WPARAM) GetStockObject(DEFAULT_GUI_FONT),
                MAKELPARAM(FALSE, 0));

  return hwndHija;
}

BOOL SetTextinTextBox(HWND box, wstring &text) {
	HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);

	SendMessage(box,
				WM_SETFONT,
				(WPARAM)hfDefault,
				0);

	SendMessage(box,
				WM_SETTEXT,
				NULL,
				reinterpret_cast<LPARAM>(text.c_str()));
	return TRUE;
}
