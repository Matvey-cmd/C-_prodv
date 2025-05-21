#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <deque>
#include <ctime>

enum LogLevel {
    LOG_NORMAL,
    LOG_WARNING,
    LOG_ERROR
};

struct LogRecord {
    std::time_t timestamp;
    LogLevel level;
    std::string content;
};

class Log {
public:
    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;

    static Log* Instance();

    void message(LogLevel level, const std::string& text);
    void print() const;

private:
    Log() = default;
    ~Log() = default;

    std::deque<LogRecord> records;

    std::string levelToText(LogLevel level) const;
};

#endif // LOGGER_HPP