#include "Safe.h"

#include <iomanip>
#include <iostream>

Safe::Safe(const std::string& model, std::size_t maxItems)
    : model_(model), maxItems_(maxItems), open_(false) {}

void Safe::lock() {
    open_ = false;
}

bool Safe::isOpen() const {
    return open_;
}

bool Safe::addItem(const Valuable& item) {
    if (!open_ || items_.size() >= maxItems_) {
        return false;
    }
    items_.push_back(item);
    return true;
}

std::size_t Safe::itemCount() const {
    return items_.size();
}

double Safe::totalValue() const {
    double sum = 0.0;
    for (const Valuable& item : items_) {
        sum += item.getValue();
    }
    return sum;
}

void Safe::printInfo() const {
    std::cout << getType() << " \"" << model_ << "\", місткість: " << maxItems_
              << ", стан: " << (open_ ? "відчинено" : "зачинено") << std::endl;
}

void Safe::printContents() const {
    if (!open_) {
        std::cout << "Сейф зачинено, вміст недоступний." << std::endl;
        return;
    }
    std::cout << "Вміст сейфа (" << items_.size() << "/" << maxItems_ << "):" << std::endl;
    for (const Valuable& item : items_) {
        std::cout << "  - " << item.getName() << ": " << std::fixed << std::setprecision(2)
                  << item.getValue() << " грн" << std::endl;
    }
    std::cout << "  Загальна вартість: " << std::fixed << std::setprecision(2)
              << totalValue() << " грн" << std::endl;
}

const std::string& Safe::getModel() const {
    return model_;
}
