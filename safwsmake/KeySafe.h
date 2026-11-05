#pragma once

#include <string>

#include "Safe.h"

class KeySafe : public Safe {
public:
    KeySafe(const std::string& model, std::size_t maxItems, const std::string& keyId);

    bool unlock(const std::string& credential) override;
    std::string getType() const override;

private:
    std::string keyId_;
};
