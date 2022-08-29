// ----------------- Histogram.h ---------------

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "HistogramBase.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <map>

namespace Hist
{
  class Histogram : HistogramBase
  {
  public:
    /// <summary>
    ///  Constructor for Histogram
    /// </summary>
    /// <param name="logger">Unique pointer to a logger</param>
    Histogram(std::unique_ptr<Logger> logger);

    Histogram(const Histogram &);

    Histogram(Histogram &&hist) noexcept;

    ~Histogram();

    /// <summary>
    /// Adds an EInteger to the Histogram
    /// </summary>
    /// <returns></returns>
    void add(EInteger);

    /// <summary>
    /// Returns the mode of the Histogram.
    /// Throws an exception if the Histogram is empty or mode is not well defined
    /// </summary>
    EInteger getMode() const;

    /// <summary>
    /// Returns the minimum value in Histogram.
    /// Throws an exception if the Histogram is empty
    /// </summary>
    EInteger getMinValue() const;

    /// <summary>
    /// Returns the maximum value in Histogram.
    /// Throws an exception if the Histogram is empty
    /// </summary>
    EInteger getMaxValue() const;

  private:
    // Pointer to the logger
    std::unique_ptr<Logger> m_log;
    // Map storing the number of occurences of each EInteger in the Histogram
    std::map<EInteger, int> m_count;
    // Minimum value in the Histogram
    int m_minValue;
    // Maximum value in the Histogram
    int m_maxValue;
  };
}
#endif
