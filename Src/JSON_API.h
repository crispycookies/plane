//
// Created by tobi on 12.02.23.
//

#ifndef PLANE_JSON_API_H
#define PLANE_JSON_API_H

#include <string>

class JSON_API {
public:
    virtual ~JSON_API() = default;

    virtual bool parse(const std::string &data) = 0;

    virtual double get_pitch() const = 0;
    virtual double get_yaw() const = 0;
    virtual double get_roll() const = 0;

    virtual double get_thrust() const = 0;
protected:
    JSON_API() = default;
};


#endif //PLANE_JSON_API_H
