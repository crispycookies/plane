//
// Created by egtob on 26.12.2022.
//

#ifndef PLANE_SERVO_H
#define PLANE_SERVO_H

class SERVO {
public:
    virtual bool set_angle(double angle) = 0;

    virtual double get_angle() = 0;

    virtual bool disable() = 0;

    virtual bool enable() = 0;

    virtual ~SERVO() = default;

protected:
    SERVO() = default;
};

#endif //PLANE_SERVO_H
