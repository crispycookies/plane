//
// Created by egtob on 26.12.2022.
//

#ifndef PLANE_STM32_PWM_H
#define PLANE_STM32_PWM_H

#include "PWM.h"
#include "stm32f4xx_hal.h"
#include <map>
#include <vector>

class STM32_PWM : public PWM {
public:
    STM32_PWM(TIM_TypeDef *timer, uint32_t prescaler, uint32_t period, std::vector<uint32_t> channels);

    bool init() override;

    void enable() override;

    void disable() override;

    bool is_enabled() override;

    bool enable_channel(uint32_t channel) override;

    bool disable_channel(uint32_t channel) override;

    bool is_channel_enabled(uint32_t channel) override;

    bool set_channel_ticks(uint32_t channel, uint32_t value) override;

    std::optional<uint32_t> get_channel_ticks(uint32_t channel) override;

    double tick_length_in_us() override;
protected:
    TIM_HandleTypeDef _timer = {0};
    TIM_MasterConfigTypeDef _sMasterConfig = {0};
    TIM_OC_InitTypeDef _sConfigOC = {0};
    TIM_BreakDeadTimeConfigTypeDef _sBreakDeadTimeConfig = {0};
    std::map<uint32_t, bool> _channels;
private:
    bool configure_channels();
};


#endif //PLANE_STM32_PWM_H
