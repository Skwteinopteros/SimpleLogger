#include "simple_logger.hpp"
#include <iostream>
#include <map>
#include <sstream>

std::map<LogLevel, std::string> LevelMsg{
    std::make_pair(LogLevel::TRACE, "[TRACE] "), std::make_pair(LogLevel::DEBUG, "[DEBUG] "),
    std::make_pair(LogLevel::INFO, "[INFO ] "),   std::make_pair(LogLevel::WARN, "[WARN ] "),
    std::make_pair(LogLevel::ERROR, "[ERROR] "), std::make_pair(LogLevel::FATAL, "[FATAL] "),
};

SimpleLogger* SimpleLogger::pinstance_{nullptr};
std::mutex SimpleLogger::mutex_;

LogLevel& SimpleLogger::level() { return logLevel; }

const LogLevel& SimpleLogger::level() const { return logLevel; }

/*
 * The first time we call GetInstance we will lock the storage location
 * and then we make sure again that the variable is null and then we
 * set the value. RU:
 */
SimpleLogger* SimpleLogger::GetLogger() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new SimpleLogger();
    }
    return pinstance_;
}

void SimpleLogger::log(const std::string& msg, const LogLevel& level) {

    if (level < logLevel) {
        return;
    }

    std::ostringstream message;
    message << LevelMsg[level] << msg << std::endl;

    std::cout << message.str();
}

void SimpleLogger::trace(const std::string& msg) { this->log(msg, LogLevel::TRACE); }

void SimpleLogger::debug(const std::string& msg) { this->log(msg, LogLevel::DEBUG); }

void SimpleLogger::info(const std::string& msg) { this->log(msg, LogLevel::INFO); }

void SimpleLogger::warn(const std::string& msg) { this->log(msg, LogLevel::WARN); }

void SimpleLogger::error(const std::string& msg) { this->log(msg, LogLevel::ERROR); }

void SimpleLogger::fatal(const std::string& msg) { this->log(msg, LogLevel::FATAL); }
