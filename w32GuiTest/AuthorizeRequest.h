#ifndef AUTORIZEREQUEST_H
#define AUTORIZEREQUEST_H

#include <iostream>
#include <map>
#include <string>

#pragma once
#include "resource.h"


BOOL CreateSendAthReques_TextBoxes(std::map<std::string, HWND> &TextBoxes, std::map<std::string, HWND> &TextBoxesPyLoad, HWND hWnd );
BOOL CreateRetail_TextBoxes(std::map<std::string, HWND> &TextBoxes, HWND hWnd);
BOOL CreateCyberSource_TextBoxes(std::map<std::string, HWND> &TextBoxes, HWND hWnd);
BOOL SendAuthorizeRequest(	std::map<std::string, std::string>&Output);


#endif //AUTORIZEREQUEST_H
