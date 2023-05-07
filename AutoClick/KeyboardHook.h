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
	char clickKey;
public:
	KeyboardHook();
	~KeyboardHook();
	void HandleHook();
};

