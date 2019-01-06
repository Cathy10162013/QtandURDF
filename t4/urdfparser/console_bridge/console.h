/* Author: Ryan Luna, Ioan Sucan */
/* Author: CR 2018.12 */

#ifndef CONSOLE_BRIDGE_CONSOLE_
#define CONSOLE_BRIDGE_CONSOLE_

#include <string>

/** \file console.h
    \defgroup logging Logging Macros
    \{

    \def CONSOLE_BRIDGE_logError(fmt, ...)
    \brief Log a formatted error string.
    \remarks This macro takes the same arguments as <a href="http://www.cplusplus.com/reference/clibrary/cstdio/printf">printf</a>.

    \def CONSOLE_BRIDGE_logWarn(fmt, ...)
    \brief Log a formatted warning string.
    \remarks This macro takes the same arguments as <a href="http://www.cplusplus.com/reference/clibrary/cstdio/printf">printf</a>.

    \def CONSOLE_BRIDGE_logInform(fmt, ...)
    \brief Log a formatted information string.
    \remarks This macro takes the same arguments as <a href="http://www.cplusplus.com/reference/clibrary/cstdio/printf">printf</a>.

    \def CONSOLE_BRIDGE_logDebug(fmt, ...)
    \brief Log a formatted debugging string.
    \remarks This macro takes the same arguments as <a href="http://www.cplusplus.com/reference/clibrary/cstdio/printf">printf</a>.

    \}
*/
#define CONSOLE_BRIDGE_logError(fmt, ...)  \
  console_bridge::log(__FILE__, __LINE__, console_bridge::CONSOLE_BRIDGE_LOG_ERROR, fmt, ##__VA_ARGS__)

#define CONSOLE_BRIDGE_logWarn(fmt, ...)   \
  console_bridge::log(__FILE__, __LINE__, console_bridge::CONSOLE_BRIDGE_LOG_WARN,  fmt, ##__VA_ARGS__)

#define CONSOLE_BRIDGE_logInform(fmt, ...) \
  console_bridge::log(__FILE__, __LINE__, console_bridge::CONSOLE_BRIDGE_LOG_INFO,  fmt, ##__VA_ARGS__)

#define CONSOLE_BRIDGE_logDebug(fmt, ...)  \
  console_bridge::log(__FILE__, __LINE__, console_bridge::CONSOLE_BRIDGE_LOG_DEBUG, fmt, ##__VA_ARGS__)


/** \brief Message namespace. This contains classes needed to
    output error messages (or logging) from within the library.
    Message logging can be performed with \ref logging "logging macros" */
namespace console_bridge
{
/** \brief The set of priorities for message logging */
enum LogLevel
  {
    CONSOLE_BRIDGE_LOG_DEBUG = 0,
    CONSOLE_BRIDGE_LOG_INFO,
    CONSOLE_BRIDGE_LOG_WARN,
    CONSOLE_BRIDGE_LOG_ERROR,
    CONSOLE_BRIDGE_LOG_NONE
  };

void log(const char *file, int line, LogLevel level, const char* m, ...);

}


#endif
