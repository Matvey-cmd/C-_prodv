#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <deque>
#include <ctime>

enum class LogSeverity {
    Normal,
    Warning,
    Error
};

struct LogRecord {
    std::time_t timestamp;
    LogSeverity severity;
    std::string content;
};

class Logger {
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* get();

    void add(LogSeverity severity, const std::string& text);
    void display() const;

private:
    Logger() = default;
    ~Logger() = default;

    std::deque<LogRecord> records;

    std::string severityToText(LogSeverity severity) const;
};

#endif // LOGGER_HPP
