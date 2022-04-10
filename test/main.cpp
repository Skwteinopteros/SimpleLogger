#include <llvm/Support/CommandLine.h>
#include <simple_logger.hpp>

int main(int argc, char** argv) {
    llvm::cl::opt<LogLevel> logLevel(
        "log-level", llvm::cl::init(LogLevel::INFO), llvm::cl::desc("Enable  messages"),
        llvm::cl::values(clEnumValN(LogLevel::TRACE, "TRACE", ""), clEnumValN(LogLevel::DEBUG, "DEBUG", ""),
                         clEnumValN(LogLevel::INFO, "INFO", ""), clEnumValN(LogLevel::WARN, "WARN", ""),
                         clEnumValN(LogLevel::ERROR, "ERROR", ""), clEnumValN(LogLevel::FATAL, "FATAL", "")));
    llvm::cl::ParseCommandLineOptions(argc, argv);

    LOGGER->level() = logLevel;

    LOGGER->trace("This is a TRACE lvl msg.");
    LOGGER->debug("This is a DEBUG lvl msg.");
    LOGGER->info("This is a INFO lvl msg.");
    LOGGER->warn("This is a WARN lvl msg.");
    LOGGER->error("This is a ERROR lvl msg.");
    LOGGER->fatal("This is a FATAL lvl msg.");

    return 0;
}
