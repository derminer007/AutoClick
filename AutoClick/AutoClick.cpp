// AutoClick.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
//#pragma warning(error:4003) //not enough actual parameters for macro
#include "AutoClick.h"  // winSock2 (wxWidgets) vor Windows.h einbinden
#include "KeyboardHook.h"
#include <iostream>
#include <Windows.h>
#include <thread>
#include <mutex>


using namespace std;

IMPLEMENT_APP(AutoClick)

//bool mouseClick = false;
bool running = true;

int KeyboardHook::clickKey = 186;  //Ü
int KeyboardHook::exitKey = 222;   //Ä
bool KeyboardHook::mouseClick = false;

void unlimitedClicks()
{
    
    while(true)
    {
        //lock_guard<mutex> lock(m1);
        cout << "Enter-WHILE\n";
        cout << "Schlei:  " << KeyboardHook::mouseClick << endl;
        if (KeyboardHook::mouseClick)
        {
            cout << "Unl\n";
            //sendMouseClickDLL();
            clickLeftMouseButton();
            cout << "Fertig outer\n";
        }
        //Sleep(1000);
        cout << "END-IF\n";
    }
}

//int main(int argc, char** argv) {
//
//    thread t1(unlimitedClicks);
//    KeyboardHook hook = KeyboardHook();
//    hook.handleHook();
//	  t1.join();
//    return 0;
//}

bool AutoClick::OnInit()
{
    f1 = new Fenster();
    f1->Show();

    thread t1(unlimitedClicks);
    KeyboardHook hook = KeyboardHook();
    hook.handleHook();
    t1.join();

    return true;
}
