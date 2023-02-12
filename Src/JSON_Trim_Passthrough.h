//
// Created by tobi on 12.02.23.
//

#ifndef PLANE_JSON_TRIM_PASSTHROUGH_H
#define PLANE_JSON_TRIM_PASSTHROUGH_H


#include "JSON_Trim.h"

class JSON_Trim_Passthrough: public JSON_Trim {
public:
    JSON_Trim_Passthrough() = default;
    ~JSON_Trim_Passthrough() override = default;

    void load(const std::string &data) override;
    std::string get() const override;
private:
    std::string _buffer;
};


#endif //PLANE_JSON_TRIM_PASSTHROUGH_H
