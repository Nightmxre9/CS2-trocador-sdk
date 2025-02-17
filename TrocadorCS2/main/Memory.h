#ifndef MEMORY_H
#define MEMORY_H

#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <iostream>

class Memory {
public:
    Memory(const std::string& processName) {
        processID = GetProcessID(processName);
        if (processID == 0) {
            std::cerr << "[ERRO] Processo não encontrado!" << std::endl;
            return;
        }
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
        if (!hProcess) {
            std::cerr << "[ERRO] Falha ao abrir o processo." << std::endl;
        }
    }

    ~Memory() {
        if (hProcess) {
            CloseHandle(hProcess);
        }
    }

    template <typename T>
    T Read(uintptr_t address) {
        T value{};
        ReadProcessMemory(hProcess, (LPCVOID)address, &value, sizeof(T), nullptr);
        return value;
    }

    template <typename T>
    void Write(uintptr_t address, T value) {
        WriteProcessMemory(hProcess, (LPVOID)address, &value, sizeof(T), nullptr);
    }

    uintptr_t GetModuleAddress(const std::string& moduleName) {
        MODULEENTRY32 moduleEntry;
        moduleEntry.dwSize = sizeof(MODULEENTRY32);
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processID);
    
        if (hSnapshot == INVALID_HANDLE_VALUE) return 0;
    
        if (Module32First(hSnapshot, &moduleEntry)) {
            do {
#ifdef UNICODE
                std::wstring moduleW(moduleName.begin(), moduleName.end());  
                if (_wcsicmp(moduleEntry.szModule, moduleW.c_str()) == 0) { 
#else
                if (_stricmp(moduleEntry.szModule, moduleName.c_str()) == 0) {  
#endif
                    CloseHandle(hSnapshot);
                    return (uintptr_t)moduleEntry.modBaseAddr;
                }
            } while (Module32Next(hSnapshot, &moduleEntry));
        }
    
        CloseHandle(hSnapshot);
        return 0;
    }

private:
    HANDLE hProcess = nullptr;
    DWORD processID = 0;

    DWORD GetProcessID(const std::string& processName) {
        PROCESSENTRY32 processEntry;
        processEntry.dwSize = sizeof(PROCESSENTRY32);
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        if (hSnapshot == INVALID_HANDLE_VALUE) return 0;

        if (Process32First(hSnapshot, &processEntry)) {
            do {
#ifdef UNICODE
                std::wstring processNameW(processName.begin(), processName.end());
                if (!_wcsicmp(processEntry.szExeFile, processNameW.c_str())) {
#else
                if (!_stricmp(processEntry.szExeFile, processName.c_str())) {
#endif
                    CloseHandle(hSnapshot);
                    return processEntry.th32ProcessID;
                }
            } while (Process32Next(hSnapshot, &processEntry));
        }

        CloseHandle(hSnapshot);
        return 0;
    }
};

#endif  // MEMORY_