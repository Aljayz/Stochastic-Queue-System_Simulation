#ifndef RANDOM_EXPO_MEAN_H
#define RANDOM_EXPO_MEAN_H

#include <random>

class RandomExpoMean {
public:
    explicit RandomExpoMean(double mean);
    
    void setMean(double mean);
    double getValue();
    double getAverageMean() const { return totalSum / sampleCount; }

private:
    void generate();
    
    double currentValue;
    double mean;
    double totalSum = 0.0;
    int sampleCount = 0;
    
    std::random_device rd;
    std::mt19937 generator;
    std::exponential_distribution<> distribution;
};

#endif // RANDOM_EXPO_MEAN_H