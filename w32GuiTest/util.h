#ifndef UTIL_H
#define UTIL_H
/*	Developer: Mario, Leal Fuentes 
	You should Include here all util functionality
*/
#include <Windows.h>
#include <map>
#include <string>
 

std::string ws2s(const std::wstring sw);
std::map<std::string, std::string>* wsm2sm( std::map<std::string, std::wstring>& mw);

std::wstring s2ws(const std::string& s);
std::map<std::wstring, std::wstring> sm2wsm( std::map<std::string, std::string> sm);

HWND Create_Label(BOOL visible, HWND hPadre, LPCWSTR texto, int x, int y, int ancho, int alto);
HWND Create_Button(HWND hPadre, LPCWSTR texto, HMENU idc, int x, int y, int ancho, int alto);
HWND Control(const HWND hwndHija, HWND hwndPadre);

BOOL SetTextinTextBox(HWND box, std::wstring &text);
#endif //UTIL_H