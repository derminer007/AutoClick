#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

void ClickLeftMouseButton();
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

class KeyboardHook
{
private:
	HHOOK keyboardHook;
	MSG msg;

	bool clickEnable;
public:
	static int clickKey;
	static int exitKey;

	KeyboardHook();
	~KeyboardHook();
	
	void handleHook();
	/*static char getClickKey();
	static void setClickKey(char key);*/
};

