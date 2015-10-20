#ifndef GETAUTHORIZEA_H
#define GETAUTHORIZEA_H

#include <iostream>
#include <map>
#include <string>

#pragma once
#include "resource.h"

BOOL CreateGetAuthorizeAnswer_TextBoxes(std::map<std::string, HWND> &TextBoxes, HWND hWnd);
BOOL GetAuthorizeAnswer(	std::map<std::string, std::string>&Output);

#endif //GETAUTHORIZEA_H