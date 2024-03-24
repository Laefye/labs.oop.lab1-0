#include "params.h"

BadParams::BadParams(const std::string& key) {
    reason = "Trying to get a bad params \"" + key + "\"";
}

const char* BadParams::what() const noexcept {
    return reason.c_str();
}
