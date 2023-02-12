//
// Created by tobi on 12.02.23.
//

#ifndef PLANE_JSON_TRIM_H
#define PLANE_JSON_TRIM_H

#include <string>

class JSON_Trim {
public:
    virtual ~JSON_Trim() = default;

    virtual void load(const std::string &data) = 0;
    virtual std::string get() const = 0;
protected:
    JSON_Trim() = default;
};

#endif //PLANE_JSON_TRIM_H
