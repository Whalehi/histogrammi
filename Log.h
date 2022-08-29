// ----------------- Log.h ---------------

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

/// <summary>
/// Dummy logger class
/// </summary>
class Logger
{
public:
    Logger();

    /// <summary>
    /// Logging function
    /// </summary>
    /// <param name="message">Message to be printed in the console</param>
    void log(const std::string &);
};
#endif
