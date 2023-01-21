//
// Created by egtob on 26.12.2022.
//

#ifndef PLANE_PWM_H
#define PLANE_PWM_H

#include <tuple>
#include <optional>
#include <cstdint>

class PWM {
public:
    virtual ~PWM() = default;

    virtual bool init() = 0;
    virtual double tick_length_in_us() = 0;

    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual bool is_enabled() = 0;

    virtual bool enable_channel(uint32_t channel) = 0;
    virtual bool disable_channel(uint32_t channel) = 0;
    virtual bool is_channel_enabled(uint32_t channel) = 0;
    virtual bool set_channel_ticks(uint32_t channel, uint32_t value) = 0;
    virtual std::optional<uint32_t> get_channel_ticks(uint32_t channel) = 0;
protected:
    PWM() = default;
};

#endif //PLANE_PWM_H
