// ----------------- RandomEintegerGenerator.cpp ---------------

#include "RandomEintegerGenerator.h"

namespace Hist
{
    EInteger RandomEintegerGenerator::operator()()
    {
        return EInteger(rand() % 5);
    }
}
