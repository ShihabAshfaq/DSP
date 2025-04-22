//
//  main.cpp
//  problem_Sets
//
//  Created by H M Asfaq Ahmed Shihab on 21/3/2024.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <fstream>
#include "Vector3D.hpp"
#include "Matrix3x3.hpp"
#include "Polygon.hpp"

using namespace std;

#define P1
#define P2
#define P3

size_t gCount = 0;

void runP1() {
    gCount++;

    Vector3D a(1.0f, 2.0f, 3.0f);
    Vector3D b(static_cast<float>(M_PI), static_cast<float>(M_PI), static_cast<float>(M_PI));
    Vector3D c(1.23456789f, 9.876543210f, 12435.0987654321f);

    cout << "Vector a: " << a.toString() << endl;
    cout << "Vector b: " << b.toString() << endl;
    cout << "Vector c: " << c.toString() << endl;
}

void runP2() {
    gCount++;
    Matrix3x3 M(Vector3D(25.0f, -3.0f, -8.0f),
                Vector3D(6.0f, 2.0f, 15.0f),
                Vector3D(11.0f, -3.0f, 4.0f));

    cout << "Test matrix M:" << endl << M << endl;
    cout << "M * M = " << endl << M * M << endl;
    cout << "det M = " << M.det() << endl;
    cout << "Has M an inverse? " << (M.hasInverse() ? "Yes" : "No") << endl;
    cout << "transpose of M:" << endl << M.transpose() << endl;
    cout << "inverse of M:" << endl << M.inverse() << endl;
    cout << "inverse of M * 45:" << endl << M.inverse() * 45.0f << endl;
}

int runP3(int argc, char* argv[]) {
    gCount++;
    if (argc < 2) {
        cerr << "Arguments missing.\n";
        cerr << "Usage: ./problem_Sets problem_Sets Parallelogram.txt";
        return 1;
    }
    
    ifstream lInput(argv[1], ifstream::in);
    if (!lInput.good()) {
        cerr << "Cannot open input file: " << argv[1] << "\n";
        return 2;
    }
    
    Polygon lPolygon;
    lPolygon.readData(lInput);
    lInput.close();
    
    if (lPolygon.getNumberOfVertices() <= 2) {
        cerr << "Polygon must have at least three vertices to calculate the signed area.\n";
        return 3;
    }
    
    cout << "Signed area: " << lPolygon.getSignedArea() << endl;
    
    Matrix3x3 lRotate = Matrix3x3::rotate(90.0f);

    Polygon lRotatedPolygon = lPolygon.transform(lRotate);

    cout << "Signed area of rotated polygon: " << lRotatedPolygon.getSignedArea() << endl;

    for (size_t i = 0; i < lRotatedPolygon.getNumberOfVertices(); i++) {
        if ((round(lPolygon.getVertex(i).dot(lRotatedPolygon.getVertex(i) * 10.0f) / 10.0f) != 0.0f)) {
            cout << "Rotation error of vertex " << i << ": " << lPolygon.getVertex(i) << endl;
            return 3;
        }
    }

    cout << "Polygon transformation successful." << endl;

    return 0;
}

int main(int argc, char* argv[]) {
    int result = 0;

#ifdef P1
    runP1();
#endif

#ifdef P2
    runP2();
#endif

#ifdef P3
    result = runP3(argc, argv);
#endif

    if (!gCount) {
        cout << "No test enabled." << endl;
    } else {
        cout << gCount << " Test(s) completed." << endl;
    }

    return result;
}

