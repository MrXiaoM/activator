#include <windows.h>
#include <shellapi.h>
#include <string>
#include <iostream>
using namespace std;

static void RunPowerShell(LPCWSTR command)
{
    wstring params = L"-ExecutionPolicy Unrestricted‌ -Command ";
    params += L"\"& {";
    params += command;
    params += L"}\"";

    SHELLEXECUTEINFO process = { sizeof(SHELLEXECUTEINFO) };
    process.lpFile = L"powershell.exe";
    process.lpParameters = params.c_str();
    process.hwnd = NULL;
    process.nShow = SW_SHOW;

    if (!ShellExecuteEx(&process)) {
        DWORD error = GetLastError();
        cerr << "Error running PowerShell as admin: " << error << endl;
    }
}
int main()
{
    RunPowerShell(L"irm https://get.activated.win | iex");
}
