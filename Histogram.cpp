// ----------------- Histogram.cpp ---------------

#include "Histogram.h"

namespace Hist
{
    Histogram::Histogram(std::unique_ptr<Logger> logger) : HistogramBase::HistogramBase(std::move(logger))
    {
        m_log = std::move(logger);
        m_log->log("Constructor");
        m_count = std::map<EInteger, int>();
        m_minValue = INT_MAX;
        m_maxValue = INT_MIN;
    }

    Histogram::Histogram(const Histogram &hist) : HistogramBase::HistogramBase(hist)
    {
        m_log->log("Deep copy");
        m_log = std::unique_ptr<Logger>();
        m_count = hist.m_count;
        m_minValue = hist.m_minValue;
        m_maxValue = hist.m_maxValue;
    }

    Histogram::Histogram(Histogram &&hist) noexcept : HistogramBase::HistogramBase(hist)
    {
        m_log->log("Move");
        m_log = std::move(hist.m_log);
        m_count = std::move(hist.m_count);
        m_minValue = std::move(hist.m_minValue);
        m_maxValue = std::move(hist.m_maxValue);
    }

    Histogram::~Histogram()
    {
        m_log->log("Destructor");
    };

    void Histogram::add(EInteger e)
    {
        m_log->log("Adding " + std::to_string(e));
        m_minValue = m_minValue < e ? m_minValue : e;
        m_maxValue = m_maxValue > e ? m_maxValue : e;
        m_count[e]++;
    }
    EInteger Histogram::getMode() const
    {
        if (m_minValue == INT_MAX)
        {
            m_log->log("Cannot get mode of an empty list");
            throw std::exception("Cannot get mode of an empty list");
        }
        int count = INT_MIN;
        int maybeMode;
        bool wellDefined = false;
        for (auto const &x : m_count)
        {
            if (x.second > count)
            {
                count = x.second;
                maybeMode = x.first;
                wellDefined = true;
            }
            else if (x.second == count)
                wellDefined = false;
        }
        if (!wellDefined)
            throw std::exception("Mode is not well defined");
        m_log->log("Mode: " + std::to_string(maybeMode));
        return EInteger(maybeMode);
    }
    EInteger Histogram::getMinValue() const
    {
        if (m_minValue == INT_MAX)
        {
            m_log->log("Cannot get minimum value of an empty list");
            throw std::exception("Cannot get minimum value of an empty list");
        }
        m_log->log("Minimum: " + std::to_string(m_minValue));
        return EInteger(m_minValue);
    }
    EInteger Histogram::getMaxValue() const
    {
        if (m_maxValue == INT_MIN)
        {
            m_log->log("Cannot get maximum value of an empty list");
            throw std::exception("Cannot get maximum value of an empty list");
        }
        m_log->log("Maximum: " + std::to_string(m_maxValue));
        return EInteger(m_maxValue);
    }
}
