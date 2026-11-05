#include "Valuable.h"

Valuable::Valuable(const std::string& name, double value)
    : name_(name), value_(value) {}

const std::string& Valuable::getName() const {
    return name_;
}

double Valuable::getValue() const {
    return value_;
}
