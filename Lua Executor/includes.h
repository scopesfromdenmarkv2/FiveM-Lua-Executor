#include <iostream>
#include "windows.h"
#include <string>
#include <vector>#define WIN32_LEAN_AND_MEAN             // Escludere gli elementi usati raramente dalle intestazioni di Windows
// File di intestazione di Windows
#include <windows.h>
#include <filesystem>
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include "detours/detours.h"
#pragma comment(lib, "detours/detours.lib")
std::string path = "C:\\sex.lua";
std::ofstream hackit;




using namespace std;