//
// Created by tobi on 12.02.23.
//

#include "JSON_Trim_Passthrough.h"
#include <algorithm>

void JSON_Trim_Passthrough::load(const std::string &data) {
    if (data.size() < 2) {
        return;
    }
    auto found = std::find(std::next(data.begin()), data.end(), '{');
    if (found == data.end()) {
        _buffer = data;
    } else {
        _buffer = std::string(data.begin(), found);
    }
}

std::string JSON_Trim_Passthrough::get() const {
    return _buffer;
}
