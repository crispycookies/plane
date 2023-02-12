//
// Created by tobi on 12.02.23.
//

#include "Mapper_Conrad.h"

double Mapper_Conrad::get_yaw(double in) const {
    if (in < -1.) {
        in = -1.;
    } else if (in > 1.) {
        in = 1.;
    }
    return in * _to_degree;
}

double Mapper_Conrad::get_pitch(double in) const {
    if (in < -1.) {
        in = -1.;
    } else if (in > 1.) {
        in = 1.;
    }
    return in * _to_degree;
}

double Mapper_Conrad::get_roll(double in) const {
    if (in < -1.) {
        in = -1.;
    } else if (in > 1.) {
        in = 1.;
    }
    return in * _to_degree;
}

double Mapper_Conrad::get_thrust(double in) const {
    if (in < -1.) {
        in = -1.;
    } else if (in > 1.) {
        in = 1.;
    }
    return in * _to_degree;
}
