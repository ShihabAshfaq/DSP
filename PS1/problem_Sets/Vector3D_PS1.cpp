//  Vector3D_PS1.cpp
//  problem_Sets
//  Created by H M Asfaq Ahmed Shihab on 23/3/2024.

#define _USE_MATH_DEFINES
#include "Vector3D.hpp"
#include <sstream>
#include <iomanip>

std::string Vector3D::toString() const noexcept {
    std::stringstream ss;
    ss << "[";

    if (std::floor(x()) == x()) {
        ss << std::fixed << std::setprecision(0) << x();
    } else {
        ss << std::fixed << std::setprecision(4) << x();
    }
    ss << ", ";

    if (std::floor(y()) == y()) {
        ss << std::fixed << std::setprecision(0) << y();
    } else {
        ss << std::fixed << std::setprecision(4) << y();
    }
    ss << ", ";

    if (std::floor(w()) == w()) {
        ss << std::fixed << std::setprecision(0) << w();
    } else {
        ss << std::fixed << std::setprecision(4) << w();
    }
    

    ss << "]";
    return ss.str();
}
