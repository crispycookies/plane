//
// Created by egtob on 26.12.2022.
//

#include "STM32_PWM.h"
#include <chrono>
#include <vector>
#include <algorithm>

STM32_PWM::STM32_PWM(TIM_TypeDef *timer, uint32_t prescaler, uint32_t period, std::vector<uint32_t> channels) {
    _timer.Instance = timer;
    _timer.Init.Prescaler = prescaler;
    _timer.Init.CounterMode = TIM_COUNTERMODE_UP;
    _timer.Init.Period = period;
    _timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    _timer.Init.RepetitionCounter = 0;
    _timer.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    _sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    _sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

    _sConfigOC.OCMode = TIM_OCMODE_PWM1;
    _sConfigOC.Pulse = 0;
    _sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    _sConfigOC.OCNPolarity = TIM_OCNPOLARITY_LOW;
    _sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    _sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
    _sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;

    _sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
    _sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
    _sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
    _sBreakDeadTimeConfig.DeadTime = 0;
    _sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
    _sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
    _sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;

    for (const auto &i: channels) {
        _channels[i] = 0;
    }
}

bool STM32_PWM::init() {
    enable();

    if (HAL_TIM_OC_Init(&_timer) != HAL_OK) {
        return false;
    }
    if (HAL_TIMEx_MasterConfigSynchronization(&_timer, &_sMasterConfig) != HAL_OK) {
        return false;
    }

    if (!configure_channels()) {
        return false;
    }

    if (HAL_TIMEx_ConfigBreakDeadTime(&_timer, &_sBreakDeadTimeConfig) != HAL_OK) {
        return false;
    }

    return true;
}

void STM32_PWM::enable() {
    __HAL_TIM_ENABLE(&_timer);
}

void STM32_PWM::disable() {
    __HAL_TIM_DISABLE(&_timer);
}

bool STM32_PWM::is_enabled() {
    return _timer.Instance->CR1 & ~(TIM_CR1_CEN);
}

bool STM32_PWM::enable_channel(uint32_t channel) {
    if (_channels.find(channel) == _channels.end()) {
        return false;
    }

    HAL_TIM_PWM_Start(&_timer, channel);
    return true;
}

bool STM32_PWM::disable_channel(uint32_t channel) {
    if (_channels.find(channel) == _channels.end()) {
        return false;
    }

    HAL_TIM_PWM_Stop(&_timer, channel);
    return true;
}

bool STM32_PWM::is_channel_enabled(uint32_t channel) {
    auto ticks = get_channel_ticks(channel);
    return ticks && ticks.value() != 0;
}

bool STM32_PWM::configure_channels() {
    return std::all_of(_channels.begin(), _channels.end(), [&](const auto &i) {
        return HAL_TIM_OC_ConfigChannel(&_timer, &_sConfigOC, i.first) != HAL_OK;
    });
}

bool STM32_PWM::set_channel_ticks(uint32_t channel, uint32_t value) {
    if (_channels.find(channel) == _channels.end()) {
        return false;
    }

    /* Change during runtime */
    __HAL_TIM_SET_COMPARE(&_timer, channel, value);
    return true;
}

std::optional<uint32_t> STM32_PWM::get_channel_ticks(uint32_t channel) {
    if (_channels.find(channel) == _channels.end()) {
        return std::nullopt;
    }

    /* get current period during runtime */
    return __HAL_TIM_GET_COMPARE(&_timer, channel);
}

double STM32_PWM::tick_length_in_ns() {
    constexpr double ns = std::chrono::nanoseconds(std::chrono::seconds(1)).count();

    const auto clock = SystemCoreClock;
    const auto prescaler = _timer.Init.Prescaler;

    const auto cycle = ns / clock;
    const auto time = cycle * prescaler;

    return time;
}
