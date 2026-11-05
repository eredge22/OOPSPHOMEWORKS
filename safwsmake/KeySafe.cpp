#include "KeySafe.h"

KeySafe::KeySafe(const std::string& model, std::size_t maxItems, const std::string& keyId)
    : Safe(model, maxItems), keyId_(keyId) {}

bool KeySafe::unlock(const std::string& credential) {
    if (credential == keyId_) {
        open_ = true;
        return true;
    }
    return false;
}

std::string KeySafe::getType() const {
    return "Ключовий сейф";
}
