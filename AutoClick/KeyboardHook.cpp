#include "KeyboardHook.h"

POINT p;

void clickLeftMouseButton() {
    INPUT input = { 0 };

    // Set up the input structure for a mouse left button down event
    input.type = INPUT_MOUSE;
    input.mi.mouseData = 0;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    // Send the input event
    SendInput(1, &input, sizeof(INPUT));

    // Sleep
    Sleep(1);

    // Set up the input structure for a mouse left button up event
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;

    // Send the input event
    SendInput(1, &input, sizeof(INPUT));
}

//void sendMouseClick(int x, int y) {
//    INPUT input = { 0 };
//
//    // Set up the input structure for a mouse left button down event
//    input.type = INPUT_MOUSE;
//    input.mi.dx = x * (65536 / GetSystemMetrics(SM_CXSCREEN)); // Convert x-coordinate to screen space
//    input.mi.dy = y * (65536 / GetSystemMetrics(SM_CYSCREEN)); // Convert y-coordinate to screen space
//    input.mi.mouseData = 0;
//    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN;
//
//    // Send the input event
//    SendInput(1, &input, sizeof(INPUT));
//
//    // Sleep
//    Sleep(1);
//
//    // Set up the input structure for a mouse left button up event
//    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP;
//
//    // Send the input event
//    SendInput(1, &input, sizeof(INPUT));
//}

void getMousePos()
{
    //POINT p;
    GetCursorPos(&p);

    cout << "x: " << p.x << " ; y: " << p.y << endl;
}

void sendMouseClickDLL()
{
    // Mausklick simulieren
    int x = 1232; // x-Koordinate des Mauszeigers
    int y = 721; // y-Koordinate des Mauszeigers

    // Berechnet die Koordinaten relativ zur Bildschirmgröße
    double dx = x * (65535.0f / (double)GetSystemMetrics(SM_CXSCREEN));
    double dy = y * (65535.0f / (double)GetSystemMetrics(SM_CYSCREEN));

    // Sendet den Mausklick
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = (LONG)dx;
    input.mi.dy = (LONG)dy;
    input.mi.mouseData = 0;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN;  // LinksClick
    input.mi.time = 0;
    input.mi.dwExtraInfo = 0;
    SendInput(1, &input, sizeof(INPUT));

    Sleep(1);
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTUP;    // RechtsClick
    SendInput(1, &input, sizeof(INPUT));

}

LRESULT CALLBACK KeyboardHook::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && wParam == WM_KEYUP) {
        cout << "Pressed" << endl;
        cout << lParam << endl;

        KBDLLHOOKSTRUCT* kbdStruct = (KBDLLHOOKSTRUCT*)lParam;
        DWORD vkCode = kbdStruct->vkCode;
        cout << vkCode << endl;
        if (vkCode == KeyboardHook::clickKey) {  // Der ASCII-Code für "C" ist 67
            std::cout << "Autoclick!" << std::endl;
            //lock_guard<mutex> lock(m1);
        	if (!KeyboardHook::mouseClick)
        	{
        		cout << "Erreicht\n";
        		KeyboardHook::mouseClick = true;
        		cout << KeyboardHook::mouseClick << endl;
        	}
        	else
        	{
        		KeyboardHook::mouseClick = false;
        	}
            //clickLeftMouseButton();
            //sendMouseClick2();
        }
        if (vkCode == KeyboardHook::exitKey)
        {
            exit(0);
        }
        if (vkCode == 192) // Ö
        {
            getMousePos();
        }

        // Hier wird der Code ausgeführt, wenn eine Taste gedrückt wird
        // Der Code für die Taste kann aus dem Parameter "lParam" extrahiert werden
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

KeyboardHook::KeyboardHook()
{
    //memset(&msg, 0, sizeof(msg));
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, nullptr, 0);
    //clickKey = 'C';
}

KeyboardHook::~KeyboardHook()
{
    UnhookWindowsHookEx(keyboardHook);
}

void KeyboardHook::handleHook()
{
    while (GetMessage(&msg, nullptr, 0, 0)) {
        cout << "Reached";
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        cout << "Reached2222";
    }
}