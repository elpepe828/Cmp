#include <iostream>
#include <dlfcn.h>
#include <thread>
#include <chrono>
#include <cstring>
using namespace std;

bool hp_glitch = false;
bool torque_glitch = false;
bool no_tire_wear = false;
bool godmode = false;
bool superspeed = false;

void toggleHP() { hp_glitch = !hp_glitch; cout << "414 HP " << (hp_glitch ? "ON" : "OFF") << endl; }
void toggleTorque() { torque_glitch = !torque_glitch; cout << "2300nm " << (torque_glitch ? "ON" : "OFF") << endl; }
void toggleTires() { no_tire_wear = !no_tire_wear; cout << "Ruedas inf " << (no_tire_wear ? "ON" : "OFF") << endl; }
void toggleGod() { godmode = !godmode; cout << "God " << (godmode ? "ON" : "OFF") << endl; }
void toggleSpeed() { superspeed = !superspeed; cout << "Super speed " << (superspeed ? "ON" : "OFF") << endl; }

void consoleMenu() {
  while (true) {
    cout << "\n=== CMP 2.6.7 Mod Menu ===" << endl;
    cout << "1. 414 HP (" << (hp_glitch ? "ON" : "OFF") << ")" << endl;
    cout << "2. 2300nm (" << (torque_glitch ? "ON" : "OFF") << ")" << endl;
    cout << "3. Ruedas inf (" << (no_tire_wear ? "ON" : "OFF") << ")" << endl;
    cout << "4. Godmode (" << (godmode ? "ON" : "OFF") << ")" << endl;
    cout << "5. Super speed (" << (superspeed ? "ON" : "OFF") << ")" << endl;
    cout << "q. Salir" << endl;
    string choice;
    getline(cin, choice);
    if (choice == "1") toggleHP();
    else if (choice == "2") toggleTorque();
    else if (choice == "3") toggleTires();
    else if (choice == "4") toggleGod();
    else if (choice == "5") toggleSpeed();
    else if (choice == "q") break;
  }
}

__attribute__((constructor)) void init() {
  cout << "CMP Mod dylib cargada! (Demo Linux .so)" << endl;
  thread menuThread(consoleMenu);
  menuThread.detach();
}

__attribute__((destructor)) void fini() {
  cout << "CMP Mod descargada" << endl;
}

