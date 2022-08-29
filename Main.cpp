// ----------------- Main.cpp ---------------

#include "RandomEintegerGenerator.h"
#include "Histogram.h"

// Generates test data and calculates min, max and mode
int main()
{
    std::unique_ptr<Logger> logger = std::make_unique<Logger>();
    Hist::Histogram hist = Hist::Histogram(std::move(logger));
    Hist::RandomEintegerGenerator generator = Hist::RandomEintegerGenerator();
    for (int i = 0; i < 10; i++)
    {
        hist.add(generator());
    }
    hist.getMinValue();
    hist.getMaxValue();
    hist.getMode();

    Hist::Histogram hist2 = hist;
    Hist::Histogram hist3 = std::move(hist);
}
