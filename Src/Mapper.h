//
// Created by tobi on 12.02.23.
//

#ifndef PLANE_MAPPER_H
#define PLANE_MAPPER_H

class Mapper {
public:
    virtual ~Mapper() = default;

    virtual double get_yaw(double in) const = 0;
    virtual double get_pitch(double in) const = 0;
    virtual double get_roll(double in) const = 0;
    virtual double get_thrust(double in) const = 0;
protected:
    Mapper() = default;
};

#endif //PLANE_MAPPER_H
