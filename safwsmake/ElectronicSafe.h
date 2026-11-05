#pragma once

#include <string>

#include "Safe.h"

class ElectronicSafe : public Safe {
public:
    ElectronicSafe(const std::string& model, std::size_t maxItems, const std::string& pin, int batteryPercent);

    bool unlock(const std::string& credential) override;
    std::string getType() const override;

    int getBatteryPercent() const;

private:
    std::string pin_;
    int batteryPercent_;
};
