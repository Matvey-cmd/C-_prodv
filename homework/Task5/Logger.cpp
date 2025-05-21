#include "Logger.h"
#include <iostream>
#include <iomanip>
#include <chrono>

Log* Log::Instance() {
    static Log instance;
    return &instance;
}

void Log::message(LogLevel level, const std::string& text) {
    LogRecord rec;
    rec.timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    rec.level = level;
    rec.content = text;

    records.push_back(rec);

    if (records.size() > 10) {
        records.pop_front();
    }
}

void Log::print() const {
    for (const auto& rec : records) {
        std::tm* tinfo = std::localtime(&rec.timestamp);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tinfo);

        std::cout << "[" << buffer << "] "
                  << levelToText(rec.level) << ": "
                  << rec.content << "\n";
    }
}

std::string Log::levelToText(LogLevel level) const {
    switch (level) {
        case LOG_NORMAL:  return "NORMAL ";
        case LOG_WARNING: return "WARNING";
        case LOG_ERROR:  return "ERROR  ";
    }
    return "UNKNOWN";
}