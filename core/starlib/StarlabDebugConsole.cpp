#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include "StarlabDebugConsole.h"

using namespace Starlab;

DebugConsole::DebugConsole()
{
    //creat a new console to the process.
    AllocConsole();
    int hCrun;
    hCrun = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
    file  = _fdopen(hCrun, "w");
    // use default stream buffer
    setvbuf(file, NULL, _IONBF, 0);
    *stdout = *file;

    std::cout << "Ready for debugging informations!...\n" << std::endl;
}

DebugConsole* DebugConsole::m_instance = NULL;

DebugConsole::~DebugConsole()
{
    FreeConsole();
    fclose(file);
}

void DebugConsole::Destroy()
{
    if (m_instance) {
        delete m_instance;
        m_instance = NULL;
    }
    return;
}

DebugConsole* DebugConsole::Instance()
{
    if (m_instance == NULL) {
        m_instance = new DebugConsole();
    }
    return m_instance;
}
