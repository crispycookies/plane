//
// Created by egtob on 26.12.2022.
//

#include "STM32_Servo.h"

bool STM32_Servo::set_angle(double angle) {
    if(!_pwm || angle < 0. || angle > _max_degrees) {
        return false;
    }
    _angle = angle;

    const auto scaled_pulse = angle * _factor_per_degree + _lower_offset;

    return _pwm->set_channel_ticks(_channel, static_cast<uint32_t>(scaled_pulse));
}

double STM32_Servo::get_angle() {
    return _angle;
}

bool STM32_Servo::disable() {
    if(!_pwm) {
        return false;
    }
    return _pwm->disable_channel(_channel);
}

bool STM32_Servo::enable() {
    if(!_pwm) {
        return false;
    }
    return _pwm->enable_channel(_channel);
}

void STM32_Servo::calculate_constants() {
    if (!_pwm) {
        return;
    }
    const auto tick_length = _pwm->tick_length_in_ns();
    const auto lower_bound = _bounds.first;
    const auto upper_bound = _bounds.second;
    const auto range = upper_bound - lower_bound;

    if (tick_length == 0 || range == 0) {
        return;
    }

    _lower_offset = lower_bound / tick_length;
    _factor_per_degree = range / _max_degrees;
}
