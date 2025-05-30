//
//  Matrix3x3.hpp
//  problem_Sets
//
//  Created by H M Asfaq Ahmed Shihab on 23/3/2024.

#pragma once

#include <ostream>
#include "Vector3D.hpp"

class Matrix3x3 {
private:
    Vector3D fRows[3];

public:
    Matrix3x3() noexcept;
    Matrix3x3(const Vector3D& aRow1, const Vector3D& aRow2, const Vector3D& aRow3) noexcept;
    Matrix3x3 operator*(const float aScalar) const noexcept;
    Matrix3x3 operator+(const Matrix3x3& aOther) const noexcept;
    Vector3D operator*(const Vector3D& aVector) const noexcept;

    static Matrix3x3 scale(const float aX = 1.0f, const float aY = 1.0f);
    static Matrix3x3 translate(const float aX = 0.0f, const float aY = 0.0f);
    static Matrix3x3 rotate(const float aAngleInDegree = 0.0f);

    const Vector3D row(size_t aRowIndex) const;
    const Vector3D column(size_t aColumnIndex) const;

    // Problem Set 1 features
    Matrix3x3 operator*(const Matrix3x3& aOther) const noexcept;
    float det() const noexcept;
    Matrix3x3 transpose() const noexcept;
    bool hasInverse() const noexcept;
    Matrix3x3 inverse() const noexcept;

    friend std::ostream& operator<<(std::ostream& aOStream, const Matrix3x3& aMatrix);
};
