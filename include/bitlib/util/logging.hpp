#pragma once

#include <iostream>
#include <string>
#include <utility>

namespace bl::log {

// Unix terminal color codes.
static const std::string normal = "\x1b[0m";
static const std::string black = "\x1b[30m";
static const std::string red = "\x1b[31m";
static const std::string green = "\x1b[32m";
static const std::string yellow = "\x1b[33m";
static const std::string blue = "\x1b[34m";
static const std::string magenta = "\x1b[35m";
static const std::string cyan = "\x1b[36m";
static const std::string white = "\x1b[37m";

enum class Level { DEBUG = 10, INFO = 20, WARNING = 30, ERROR = 40, FATAL = 50 };

inline Level log_level = Level::INFO;

// https://stackoverflow.com/questions/8510071/mycout-automatic-endl
class Logger {
 public:
    Logger(std::ostream& os, std::string prefix, Level level)
        : os(os), prefix(prefix), level(level) {}

    std::ostream& os;
    std::string prefix;
    Level level;
};

class Stream {
 public:
    Stream(std::ostream& os, std::string prefix, Level level) : os(os), live(true) {
        if (log_level > level) {
            this->os.setstate(std::ios_base::badbit);
        }
        this->os << prefix;
    }
    Stream(Stream& stream) : os(stream.os), live(true) { stream.live = false; }
    Stream(Stream&& stream) : os(stream.os), live(true) { stream.live = false; }
    ~Stream() {
        if (live) {
            this->os << std::endl;
            this->os.clear();
        }
    }
    std::ostream& os;

 private:
    bool live;
};

template <class T>
Stream operator<<(Stream&& stream, const T& message) {
    stream.os << message;
    return std::move(stream);
}

template <class T>
Stream operator<<(Logger& logger, const T& message) {
    return Stream(logger.os, logger.prefix, logger.level) << message;
}

static Logger debug = Logger(std::cout, normal + "Debug: ", Level::DEBUG);
static Logger info = Logger(std::cout, normal + "Info:  ", Level::INFO);
static Logger warning = Logger(std::cout, normal + "Warn:  " + yellow, Level::WARNING);
static Logger error = Logger(std::cerr, normal + "Error: " + red, Level::ERROR);
static Logger fatal = Logger(std::cerr, normal + "Fatal: " + red, Level::FATAL);

}  // namespace bl::log
