//
// Created by egtob on 27.12.2022.
//

#ifndef PLANE_MIXER_H
#define PLANE_MIXER_H

class MIXER {
public:
    virtual ~MIXER() = default;

    virtual bool set_yaw(double angle) = 0;
    virtual bool set_pitch(double angle) = 0;
    virtual bool set_roll(double angle) = 0;

    virtual double get_yaw() const = 0;
    virtual double get_pitch() const = 0;
    virtual double get_roll() const = 0;

    virtual bool get_has_yaw() const = 0;
    virtual bool get_has_pitch() const = 0;
    virtual bool get_has_roll() const = 0;

    virtual bool commit() = 0;
protected:
    MIXER() = default;
};

#endif //PLANE_MIXER_H
