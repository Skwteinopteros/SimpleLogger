#ifndef INCLUDED_LOGGER_H
#define INCLUDED_LOGGER_H

#include <mutex>
#include <string>

enum LogLevel { TRACE, DEBUG, INFO, WARN, ERROR, FATAL };

/**
 *   Singleton Logger Class.
 */

class SimpleLogger {

  private:
    static std::mutex mutex_;
    static SimpleLogger* pinstance_;

  protected:
    SimpleLogger(const LogLevel level = LogLevel::INFO) : logLevel(level) {}

    ~SimpleLogger() {}

    LogLevel logLevel;

  public:
    // Singleton Logger should not be cloneable;
    SimpleLogger(SimpleLogger& other) = delete;

    // Singleton Logger should not be assignable.
    void operator=(const SimpleLogger&) = delete;

    static SimpleLogger* GetLogger();

    LogLevel& level();

    const LogLevel& level() const;

    void log(const std::string&, const LogLevel&);

    void trace(const std::string&);

    void debug(const std::string&);

    void info(const std::string&);

    void warn(const std::string&);

    void error(const std::string&);

    void fatal(const std::string&);
};

#endif // INCLUDED_LOGGER_H
