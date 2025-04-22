//
//  FibonacciSequenceIterator.cpp
//  problem_Set2
//
//  Created by H M Asfaq Ahmed Shihab on 18/4/2024.
#include "FibonacciSequenceIterator.hpp"

FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequenceGenerator& aSequenceObject, long long aStart) noexcept
    : fSequenceObject(aSequenceObject), fIndex(aStart - 1) {}

const long long& FibonacciSequenceIterator::operator*() const noexcept {
    return fSequenceObject.operator*();
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept {
    ++fIndex;
    fSequenceObject.next(); // Advance to the next Fibonacci number
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept {
    FibonacciSequenceIterator temp(*this);
    ++(*this);
    return temp;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept {
    return (fSequenceObject.id() == aOther.fSequenceObject.id()) && (fIndex == aOther.fIndex);
}

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const noexcept {
    return !(*this == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept {
    return FibonacciSequenceIterator(fSequenceObject, 1);
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept {
    return FibonacciSequenceIterator(fSequenceObject, 93);
}
