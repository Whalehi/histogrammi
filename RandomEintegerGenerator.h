// ----------------- RandomEintegerGenerator.h ---------------

#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H

#include "HistogramBase.h"
#include <cstdlib>

namespace Hist
{
    class RandomEintegerGenerator : RandomEintegerGeneratorBase

    {

    public:
        // Returns a pseudo-random EInteger value
        EInteger operator()();
    };

#endif
}