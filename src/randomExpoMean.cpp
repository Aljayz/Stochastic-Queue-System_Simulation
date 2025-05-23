// src/RandomExpoMean.cpp
#include "../include/RandomExpoMean.h"
#include <random>

RandomExpoMean::RandomExpoMean(double mean)
    : mean(mean), generator(rd()), distribution(1.0/mean), 
      currentValue(0.0), totalSum(0.0), sampleCount(0) {}

void RandomExpoMean::setMean(double mean) {
    this->mean = mean;
    distribution = std::exponential_distribution<>(1.0/mean);
}

void RandomExpoMean::generate() {
    currentValue = distribution(generator);
}

double RandomExpoMean::getValue() {
    generate();
    totalSum += currentValue;
    sampleCount++;
    return currentValue;
}