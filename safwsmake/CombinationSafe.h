#pragma once

#include <string>

#include "Safe.h"

class CombinationSafe : public Safe {
public:
    CombinationSafe(const std::string& model, std::size_t maxItems, const std::string& combination);

    bool unlock(const std::string& credential) override;
    std::string getType() const override;

    bool isBlocked() const;

private:
    std::string combination_;
    int failedAttempts_;
    static const int kMaxAttempts = 3;
};
