//
//  Polygon.hpp
//  problem_Sets
//
//  Created by H M Asfaq Ahmed Shihab on 24/3/2024.
//

#pragma once
#include "Vector2D.hpp"
#include "Matrix3x3.hpp"
#include <istream>

constexpr size_t MAX_VERTICES = 30;

class Polygon {
private:
    Vector2D fVertices[MAX_VERTICES];
    size_t fNumberOfVertices = 0; // Initialized to ensure starting count is 0

public:
    Polygon() noexcept;
    void readData(std::istream& aIStream);
    size_t getNumberOfVertices() const noexcept;
    const Vector2D& getVertex(size_t aIndex) const;
    float getPerimeter() const noexcept;
    Polygon scale(float aScalar) const noexcept;

    // Problem Set 3 extensions
    float getSignedArea() const noexcept;
    Polygon transform(const Matrix3x3& aMatrix) const noexcept;
};
