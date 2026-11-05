#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "Valuable.h"

class Safe {
public:
    Safe(const std::string& model, std::size_t maxItems);
    virtual ~Safe() = default;

    virtual bool unlock(const std::string& credential) = 0;
    virtual std::string getType() const = 0;

    void lock();
    bool isOpen() const;
    bool addItem(const Valuable& item);
    std::size_t itemCount() const;
    double totalValue() const;
    void printInfo() const;
    void printContents() const;

    const std::string& getModel() const;

protected:
    std::string model_;
    std::size_t maxItems_;
    bool open_;
    std::vector<Valuable> items_;
};
