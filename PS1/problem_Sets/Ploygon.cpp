//
//  Ploygon.cpp
//  problem_Sets
//
//  Created by H M Asfaq Ahmed Shihab on 23/3/2024.

#include "Polygon.hpp"

#include <cassert>

Polygon::Polygon() noexcept : fNumberOfVertices(0) {}

void Polygon::readData(std::istream& aIStream) {
    Vector2D tempVector;
    while (aIStream >> tempVector) {
        assert(fNumberOfVertices < MAX_VERTICES);
        fVertices[fNumberOfVertices++] = tempVector;
    }
}

size_t Polygon::getNumberOfVertices() const noexcept {
    return fNumberOfVertices;
}

const Vector2D& Polygon::getVertex(size_t aIndex) const {
    assert(aIndex < fNumberOfVertices);
    return fVertices[aIndex];
}

float Polygon::getPerimeter() const noexcept {
    float perimeter = 0.0f;
    for (size_t i = 0; i < fNumberOfVertices; ++i) {
        size_t nextIndex = (i + 1) % fNumberOfVertices;
        Vector2D edge = fVertices[nextIndex] - fVertices[i];
        perimeter += edge.length();
    }
    return perimeter;
}

Polygon Polygon::scale(float aScalar) const noexcept {
    Polygon scaledPolygon;
    for (size_t i = 0; i < fNumberOfVertices; ++i) {
        scaledPolygon.fVertices[i] = fVertices[i] * aScalar;
    }
    scaledPolygon.fNumberOfVertices = fNumberOfVertices;
    return scaledPolygon;
}
