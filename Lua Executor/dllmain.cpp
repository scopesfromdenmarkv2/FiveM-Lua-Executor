#include "includes.h"
#include "shell.h"

std::ofstream stream;
typedef __int64(__fastcall* t_28B30)(__int64 a1, const std::string& scriptpath, __int64 a3);
t_28B30 hook_28B30 = (t_28B30)((uintptr_t)GetModuleHandle(L"citizen-scripting-lua.dll") + 0x28B30);
__int64 __fastcall sub_28B30(__int64 a1, const std::string& scriptpath, __int64 a3) {


    if (scriptpath == "citizen:/scripting/lua/scheduler.lua")
    {
        
        return hook_28B30(a1, path.c_str(), a3);
    }
    return hook_28B30(a1, scriptpath, a3);
}
DWORD WINAPI whoops(HMODULE hModule)
{
    stream.open(path.c_str());
    string Schedcode(reinterpret_cast<char*>(scheduler), sizeof(scheduler));
    stream << Schedcode << endl;
    stream << "print('Working Executor :)')" << endl;
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(LPVOID&)hook_28B30, &sub_28B30);
    DetourTransactionCommit();
    return true;
}




BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)whoops, hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

