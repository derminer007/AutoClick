// AutoClick.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <Windows.h>
#include "KeyboardHook.h"

using namespace std;

bool mouseClick = false;
bool running = true;




// ChatGPT kommentiert:
//void HandleKeyboardInput() {
//    if (GetAsyncKeyState('C') & 0x8000) {  // Prüfen, ob die C-Taste gedrückt wurde
//        if (!mouseClick) {  // Prüfen, ob das Klicken aktiviert ist
//            std::cout << "Mausklicks sind jetzt aktiviert!" << std::endl;
//            mouseClick = true;  // Aktivieren Sie das Klicken
//        }
//    }
//    else {
//        if (mouseClick) {  // Prüfen, ob das Klicken deaktiviert ist
//            std::cout << "Mausklicks sind jetzt deaktiviert!" << std::endl;
//            mouseClick = false;  // Deaktivieren Sie das Klicken
//        }
//    }
//}



int main() {
    KeyboardHook hook = KeyboardHook();
    hook.HandleHook();
	
    return 0;
}

// ChatGPT Lösung:

//int main() {
//    std::cout << "Das Programm wird auf die Taste C warten." << std::endl;
//    while (true) {
//        HandleKeyboardInput();  // Tastatureingabe verarbeiten
//        if (mouseClick) {  // Prüfen, ob das Klicken aktiviert ist
//            ClickLeftMouseButton();  // Mausklick ausführen
//        }
//        Sleep(50);  // Warten Sie 50 Millisekunden, um CPU-Auslastung zu vermeiden
//    }
//    return 0;
//}


// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
