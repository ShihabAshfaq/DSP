//
//  FibonacciSequenceGenerator.cpp
//  problem_Set2
//
//  Created by H M Asfaq Ahmed Shihab on 18/4/2024.

#include "FibonacciSequenceGenerator.hpp"
#include <cassert> // For assertion

FibonacciSequenceGenerator::FibonacciSequenceGenerator(const std::string& aID) noexcept
    : fID(aID), fPrevious(0), fCurrent(1) {}

const std::string& FibonacciSequenceGenerator::id() const noexcept {
    return fID;
}

const long long& FibonacciSequenceGenerator::operator*() const noexcept {
    return fCurrent;
}

FibonacciSequenceGenerator::operator bool() const noexcept {
    return hasNext();
}

void FibonacciSequenceGenerator::reset() noexcept {
    fPrevious = 0;
    fCurrent = 1;
}

bool FibonacciSequenceGenerator::hasNext() const noexcept {
    
    return fCurrent <= LLONG_MAX - fPrevious;
}

void FibonacciSequenceGenerator::next() noexcept {
    
    if (!hasNext()) {
    
        return;
    }
    
    long long next = fPrevious + fCurrent;
    fPrevious = fCurrent;
    fCurrent = next;
}
