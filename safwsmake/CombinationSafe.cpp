#include "CombinationSafe.h"

CombinationSafe::CombinationSafe(const std::string& model, std::size_t maxItems, const std::string& combination)
    : Safe(model, maxItems), combination_(combination), failedAttempts_(0) {}

bool CombinationSafe::unlock(const std::string& credential) {
    if (isBlocked()) {
        return false;
    }
    if (credential == combination_) {
        failedAttempts_ = 0;
        open_ = true;
        return true;
    }
    ++failedAttempts_;
    return false;
}

std::string CombinationSafe::getType() const {
    return "Кодовий сейф";
}

bool CombinationSafe::isBlocked() const {
    return failedAttempts_ >= kMaxAttempts;
}
