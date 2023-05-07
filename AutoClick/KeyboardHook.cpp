#include "KeyboardHook.h"

void ClickLeftMouseButton() {
    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        cout << "Pressed" << endl;
        cout << lParam << endl;

        KBDLLHOOKSTRUCT* kbdStruct = (KBDLLHOOKSTRUCT*)lParam;
        DWORD vkCode = kbdStruct->vkCode;
        cout << vkCode << endl;
        if (vkCode == KeyboardHook::clickKey) {  // Der ASCII-Code für "C" ist 67
            std::cout << "Die Taste C wurde gedrückt!" << std::endl;
            /*if (mouseClick)
            {
                mouseClick = false;
            }
            else
            {
                mouseClick = true;
            }*/
            ClickLeftMouseButton();
        }
        if (vkCode == KeyboardHook::exitKey)
        {
            exit(0);
        }
        /*if (vkCode == 'D')
        {
            running = false;
        }*/

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

//char KeyboardHook::getClickKey()
//{
//    return clickKey;
//}
//
//void KeyboardHook::setClickKey(char key)
//{
//    clickKey = key;
//}
