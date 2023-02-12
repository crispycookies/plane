//
// Created by tobi on 12.02.23.
//

#include "JSON_API_Lohmann.h"
#include "json.hpp"

bool JSON_API_Lohmann::parse(const std::string &data) {
    try {
        auto json = nlohmann::json::parse(data);

        if (json.contains("roll"))
        {
            _roll = json.at("roll");
        }
        if (json.contains("yaw"))
        {
            _yaw = json.at("yaw");
        }
        if (json.contains("pitch"))
        {
            _pitch = json.at("pitch");
        }
        if (json.contains("thrust"))
        {
            _thrust = json.at("thrust");
        }
    }
    catch (const std::exception &)
    {
        return false;
    }
    return true;
}

double JSON_API_Lohmann::get_pitch() const {
    return _pitch;
}

double JSON_API_Lohmann::get_yaw() const {
    return _yaw;
}

double JSON_API_Lohmann::get_roll() const {
    return _roll;
}

double JSON_API_Lohmann::get_thrust() const {
    return _thrust;
}
