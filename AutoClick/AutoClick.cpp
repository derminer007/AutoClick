// AutoClick.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <Windows.h>
#include "KeyboardHook.h"

using namespace std;

bool mouseClick = false;
bool running = true;

int KeyboardHook::clickKey = 186;  //Ü
int KeyboardHook::exitKey = 222;   //Ä
int main() {
    
    KeyboardHook hook = KeyboardHook();
    hook.handleHook();
	
    return 0;
}