#include "Logger.h"
#include <iostream>
#include <iomanip>
#include <chrono>

Logger* Logger::get() {
    static Logger instance;
    return &instance;
}

void Logger::add(LogSeverity severity, const std::string& text) {
    LogRecord rec;
    rec.timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    rec.severity = severity;
    rec.content = text;

    records.push_back(rec);

    if (records.size() > 10) {
        records.pop_front();
    }
}

void Logger::display() const {
    for (const auto& rec : records) {
        std::tm* tinfo = std::localtime(&rec.timestamp);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tinfo);

        std::cout << "[" << buffer << "] "
                  << severityToText(rec.severity) << ": "
                  << rec.content << "\n";
    }
}

std::string Logger::severityToText(LogSeverity severity) const {
    switch (severity) {
        case LogSeverity::Normal:  return "NORMAL ";
        case LogSeverity::Warning: return "WARNING";
        case LogSeverity::Error:   return "ERROR  ";
    }
    return "UNKNOWN";
}

int main() {
    Log* log = Log::Instance();

    log->message(LOG_NORMAL, "Program loaded");
    log->message(LOG_WARNING, "Low memory warning");
    log->message(LOG_ERROR, "Critical error detected!");

    log->print();

    return 0;
}