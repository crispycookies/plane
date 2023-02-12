//
// Created by tobi on 12.02.23.
//

#include "JSON_Trim_Passthrough.h"

void JSON_Trim_Passthrough::load(const std::string &data) {
    _buffer = data;
}

std::string JSON_Trim_Passthrough::get() const {
    return _buffer;
}
