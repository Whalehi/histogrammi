// ----------------- HistogramBase.h ---------------

#ifndef HISTOGRAMBASE_H

#define HISTOGRAMBASE_H

#include "Log.h"

#include <memory>

namespace Hist
{

  enum EInteger : int

  {

    Zero = 0,

    One = 1,

    Two = 2,

    Three = 3,

    Four = 4

  };

  class RandomEintegerGeneratorBase

  {

  public:
    // Returns a pseudo-random EInteger value

    virtual EInteger operator()() = 0;
  };

  class HistogramBase

  {

  public:
    HistogramBase() = delete;

    HistogramBase(std::unique_ptr<Logger>){};

    HistogramBase(const HistogramBase &){};

    HistogramBase(HistogramBase &&) noexcept {};

    virtual ~HistogramBase(){};

    virtual void add(EInteger) = 0;

    virtual EInteger getMode() const = 0;

    virtual EInteger getMinValue() const = 0;

    virtual EInteger getMaxValue() const = 0;

  private:
    std::unique_ptr<Logger> m_log;
  };

}
#endif
