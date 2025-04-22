//
//  Ploygon.hpp
//  problem_Sets
//
//  Created by H M Asfaq Ahmed Shihab on 23/3/2024.
//

#pragma once

#include "Vector2D.hpp"
#include "Matrix3x3.hpp"

constexpr size_t MAX_VERTICES = 30;

class Polygon
{
private:
    Vector2D fVertices[MAX_VERTICES];
    size_t fNumberOfVertices;
    
public:
    
    Polygon() noexcept;

    void readData( std::istream& aIStream );

    size_t getNumberOfVertices() const noexcept;
    const Vector2D& getVertex( size_t aIndex ) const;
    float getPerimeter() const noexcept;
    
    Polygon scale( float aScalar ) const noexcept;
    
    // PS1 features

    float getSignedArea() const noexcept;
    
    Polygon transform( const Matrix3x3& aMatrix ) const noexcept;
};
