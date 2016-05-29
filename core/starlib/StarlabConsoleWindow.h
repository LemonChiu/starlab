#pragma once
#include "Starlab.h"
#include "starlib_global.h"

namespace Starlab {

/// Console for outputting debug information
class STARLIB_EXPORT DebugConsole
{
public:
    // Output information in console
    static void Destroy();
    static DebugConsole *Instance();

public:
    virtual ~DebugConsole();

protected:
    DebugConsole();

private:
    static DebugConsole *m_instance;
    FILE *file;
};

} // Namespace
