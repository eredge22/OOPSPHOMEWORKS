#include "ElectronicSafe.h"

ElectronicSafe::ElectronicSafe(const std::string& model, std::size_t maxItems, const std::string& pin, int batteryPercent)
    : Safe(model, maxItems), pin_(pin), batteryPercent_(batteryPercent) {}

bool ElectronicSafe::unlock(const std::string& credential) {
    if (batteryPercent_ <= 0) {
        return false;
    }
    batteryPercent_ = batteryPercent_ >= 5 ? batteryPercent_ - 5 : 0;
    if (credential == pin_) {
        open_ = true;
        return true;
    }
    return false;
}

std::string ElectronicSafe::getType() const {
    return "Електронний сейф";
}

int ElectronicSafe::getBatteryPercent() const {
    return batteryPercent_;
}
