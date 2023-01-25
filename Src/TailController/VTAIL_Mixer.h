//
// Created by tobi on 24.01.23.
//

#ifndef PLANE_VTAIL_MIXER_H
#define PLANE_VTAIL_MIXER_H

#include "MIXER.h"
#include "../LLServoStuff/SERVO.h"
#include <cmath>

class VTAIL_Mixer : public MIXER {
public:
    VTAIL_Mixer(SERVO *const left, SERVO *const right, double degree_limit): _left(left), _right(right), _degree_limit(std::abs(degree_limit)) {};

    bool set_yaw(double angle) override;
    bool set_pitch(double angle) override;
    bool set_roll(double angle) override;

    double get_yaw() const override;
    double get_pitch() const override;
    double get_roll() const override;

    bool get_has_yaw() const override;
    bool get_has_pitch() const override;
    bool get_has_roll() const override;

    bool commit() override;
protected:
private:
    SERVO *const _left;
    SERVO *const _right;
    const double _degree_limit;

    double _pitch = 0.;
    double _roll = 0.;
};


#endif //PLANE_VTAIL_MIXER_H
