//
// Created by tobi on 24.01.23.
//

#include "VTAIL_Mixer.h"

bool VTAIL_Mixer::set_yaw(double angle) {
    return false;
}

bool VTAIL_Mixer::set_pitch(double angle) {
    if (std::abs(angle) > _degree_limit){
       return false;
    }

    _pitch = angle;

    return true;
}

bool VTAIL_Mixer::set_roll(double angle) {
    if (std::abs(angle) > _degree_limit){
        return false;
    }

    _roll = angle;

    return true;
}

double VTAIL_Mixer::get_yaw() const {
    return 0.;
}

double VTAIL_Mixer::get_pitch() const {
    return _pitch;
}

double VTAIL_Mixer::get_roll() const {
    return _roll;
}

bool VTAIL_Mixer::get_has_yaw() const {
    return false;
}

bool VTAIL_Mixer::get_has_pitch() const {
    return true;
}

bool VTAIL_Mixer::get_has_roll() const {
    return true;
}

bool VTAIL_Mixer::commit() {
    auto roll_angle_left = _roll;
    auto roll_angle_right = _roll;

    auto pitch_angle_left = _pitch;
    auto pitch_angle_right = - _pitch;

    auto comb_left = roll_angle_left + pitch_angle_left;
    auto comb_right = roll_angle_right + pitch_angle_right;

    _right->set_angle(comb_right);
    _left->set_angle(comb_left);

    return true;
}
