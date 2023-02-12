//
// Created by tobi on 12.02.23.
//

#ifndef PLANE_MAPPER_CONRAD_H
#define PLANE_MAPPER_CONRAD_H


#include "Mapper.h"

class Mapper_Conrad: public Mapper {
public:
    Mapper_Conrad(double to_degree): _to_degree(to_degree) {};
    ~Mapper_Conrad() override = default;

    double get_yaw(double in) const;
    double get_pitch(double in) const;
    double get_roll(double in) const;
    double get_thrust(double in) const;
private:
    double _to_degree;
};


#endif //PLANE_MAPPER_CONRAD_H
