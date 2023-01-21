//
// Created by egtob on 26.12.2022.
//

#ifndef PLANE_STM32_SERVO_H
#define PLANE_STM32_SERVO_H


#include <utility>

#include "SERVO.h"
#include "PWM.h"

class STM32_Servo : public SERVO {
public:
    STM32_Servo
            (PWM *const pwm, uint32_t channel, std::pair<double, double> bounds, double max_degrees, bool centered) : _pwm(pwm),
                                                                                                       _channel(channel),
                                                                                                       _angle(0.),
                                                                                                       _bounds(std::move(bounds)),
                                                                                                       _lower_offset(0.),
                                                                                                       _factor_per_degree(0.),
                                                                                                       _max_degrees(max_degrees),
                                                                                                       _centered(centered)
                                                                                                       { calculate_constants(); };

    bool disable() override;

    bool enable() override;

    bool set_angle(double angle) override;

    double get_angle() override;

protected:
    PWM *const _pwm;
    const uint32_t _channel;
    double _angle;
    std::pair<double, double> _bounds;
    double _lower_offset;
    double _factor_per_degree;
    double _max_degrees;
    double _degree_offset;
    bool _centered;
private:
    void calculate_constants();
};


#endif //PLANE_STM32_SERVO_H
