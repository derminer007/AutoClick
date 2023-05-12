#include "KeyboardHook.h"

POINT p;

void ClickLeftMouseButton() {
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

void sendMouseClick(int x, int y) {
    INPUT input = { 0 };

    // Set up the input structure for a mouse left button down event
    input.type = INPUT_MOUSE;
    input.mi.dx = x * (65536 / GetSystemMetrics(SM_CXSCREEN)); // Convert x-coordinate to screen space
    input.mi.dy = y * (65536 / GetSystemMetrics(SM_CYSCREEN)); // Convert y-coordinate to screen space
    input.mi.mouseData = 0;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN;

    // Send the input event
    SendInput(1, &input, sizeof(INPUT));

    // Sleep
    Sleep(1);

    // Set up the input structure for a mouse left button up event
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP;

    // Send the input event
    SendInput(1, &input, sizeof(INPUT));
}

void getMousePos()
{
    //POINT p;
    GetCursorPos(&p);

    cout << "x: " << p.x << " ; y: " << p.y << endl;
}

void sendMouseClickSDL() {
    SDL_Event event;
    event.type = SDL_MOUSEBUTTONDOWN;
    event.button.button = SDL_BUTTON_LEFT;
    SDL_PushEvent(&event);

    event.type = SDL_MOUSEBUTTONUP;
    SDL_PushEvent(&event);
}

void sendMouseClickDLL()
{
    //// Mausklick simulieren
    int x = 1232; // x-Koordinate des Mauszeigers
    int y = 721; // y-Koordinate des Mauszeigers
    //mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    //mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

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

    Sleep(100);
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTUP;    // RechtsClick
    SendInput(1, &input, sizeof(INPUT));

    //int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    //int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    //// Berechne absolute Mausposition
    //int absoluteX = x * 65535 / screenWidth;
    //int absoluteY = y * 65535 / screenHeight;

    //// Klick simulieren
    //mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, absoluteX, absoluteY, 0, 0);
    //mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP, absoluteX, absoluteY, 0, 0);

}

int sendMouseClick2() {
    cout << "Enter\n";
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;

    /*POINT p;
    GetCursorPos(&p);
    cout << "Maus x: " << p.x << " y: " << p.y << endl;*/

    //// calculate absolute coordinates
    //double fScreenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
    //double fScreenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
    //double fx = p.x / fScreenWidth;
    //double fy = p.y / fScreenHeight;

    //input.mi.dx = (LONG)(fx * 65535.0);
    //input.mi.dy = (LONG)(fy * 65535.0);
    //input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    //SendInput(1, &input, sizeof(INPUT));

    // Klicke an der aktuellen Mausposition
    //input.type = INPUT_MOUSE;
    input.mi.dx = p.x * (65535 / GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy = p.y * (65535 / GetSystemMetrics(SM_CYSCREEN));
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE;
    SendInput(1, &input, sizeof(INPUT));


    //long x = p.x;
    //long y = p.y;
    //input.mi.dx = (x+1) * (65536 / GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
    //input.mi.dy = (y+1) * (65536 / GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
    //input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    //SendInput(1, &input, sizeof(INPUT));

    //
    //input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    //SendInput(1, &input, sizeof(INPUT));    // cInputs: Anzahl Elemente im input-Array, die alle ausgeführt werden
    cout << "Fertig\n";
    return 0;
}


LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
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
            //ClickLeftMouseButton();
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
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    //clickKey = 'C';
}

KeyboardHook::~KeyboardHook()
{
    UnhookWindowsHookEx(keyboardHook);
}

void KeyboardHook::handleHook()
{
    while (GetMessage(&msg, NULL, 0, 0)) {
        cout << "Reached";
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        cout << "Reached2222";
    }
}