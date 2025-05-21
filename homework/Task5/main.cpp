#include "Logger.h"

int main() {
    Log* log = Log::Instance();

    log->message(LOG_NORMAL, "Program loaded");
    log->message(LOG_WARNING, "Low memory warning");
    log->message(LOG_ERROR, "Critical error detected!");

    log->print();

    return 0;
}