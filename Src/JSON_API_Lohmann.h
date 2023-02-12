//
// Created by tobi on 12.02.23.
//

#ifndef PLANE_JSON_API_LOHMANN_H
#define PLANE_JSON_API_LOHMANN_H


#include "JSON_API.h"

class JSON_API_Lohmann: public JSON_API {
public:
    JSON_API_Lohmann() = default;
    ~JSON_API_Lohmann() override = default;

    bool parse(const std::string &data) override;

    double get_pitch() const override;
    double get_yaw() const override;
    double get_roll() const override;

    double get_thrust() const override;
private:
    double _roll = 0.;
    double _yaw = 0.;
    double _pitch = 0.;
    double _thrust = 0.;
};


#endif //PLANE_JSON_API_LOHMANN_H
