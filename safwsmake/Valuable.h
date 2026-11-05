#pragma once

#include <string>

class Valuable {
public:
    Valuable(const std::string& name, double value);

    const std::string& getName() const;
    double getValue() const;

private:
    std::string name_;
    double value_;
};
