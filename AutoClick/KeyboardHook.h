#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <mutex>
#include <thread>
#include <atomic>

using namespace std;

void clickLeftMouseButton();
//LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
//int sendMouseClick2();
//void sendMouseClickSDL();
void sendMouseClickDLL();
//static bool mouseClick = false;
//extern atomic<bool> mouseClick = false;
//static mutex m1;

class KeyboardHook
{
private:
	HHOOK keyboardHook;
	MSG msg;

	bool clickEnable;
public:
	static int clickKey;
	static int exitKey;
	static bool mouseClick;

	KeyboardHook();
	~KeyboardHook();
	
	void handleHook();
	static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
	/*static char getClickKey();
	static void setClickKey(char key);*/
};

