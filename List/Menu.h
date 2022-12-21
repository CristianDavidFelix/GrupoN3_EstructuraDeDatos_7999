#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "List.h"

#ifndef _MENU_H_
#define _MUNU_H_
using namespace std;

class Menu
{
public:
    int menu(string[], string, int, int, List*);
    void menu_keyboard(string[], int, int, List*);
};

#endif
