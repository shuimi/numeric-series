//
// Created by Vladimir on 17.09.2021.
//

#ifndef NUMERICSERIES_NUMERICSERIES_H
#define NUMERICSERIES_NUMERICSERIES_H

#include <iostream>
#include <functional>
#include <utility>
#include <vector>

namespace NumericSeries {

    class MetaInfo {
    private:
        std::string name = "";
        std::string description = "";

        //TODO: add timestamp

    public:
        MetaInfo() {}

        MetaInfo(const std::string &name, const std::string &description) : name(name), description(description) {}

        virtual ~MetaInfo() {

        }

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            MetaInfo::name = name;
        }

        const std::string &getDescription() const {
            return description;
        }

        void setDescription(const std::string &description) {
            MetaInfo::description = description;
        }
    };

    template<typename T>
    class Report {
    private:
        MetaInfo meta;
        int iterationsAmount = 0;
        T seriesSum = 0;

    public:
        Report(int iterationsAmount, T seriesSum) : iterationsAmount(iterationsAmount), seriesSum(seriesSum) {}

        int getIterationsAmount() const {
            return iterationsAmount;
        }

        T getSeriesSum() const {
            return seriesSum;
        }

        Report setMeta(MetaInfo info) {
            this->meta = info;
            return *this;
        }

        void printout() {
            std::cout
                    << "Test name: " << this->meta.getName() << "\n"
                    << "Test description: " << this->meta.getDescription() << "\n"
                    << "Series sum: " << seriesSum << "\n"
                    << "Iterations amount: " << iterationsAmount << "\n\n";
        }

    };

    typedef std::function<double(double, double)> NumericFunction;

    template<typename T>
    class NumericSeries {
    private:

        T lowerThreshold = 0;
        T higherThreshold = 16777216;

        long long iterations = 0;
        T precision = 0;
        T sum_ = 0;

        bool ignoreZeroDivision = false;

        NumericFunction function = [](T n, T k) {
            return 0;
        };

    public:

        NumericSeries(NumericFunction function) : function(std::move(function)) {}

        NumericSeries(NumericFunction function, T precision) : precision(precision), function(std::move(function)) {}


        // LIFECYCLE METHODS

        NumericSeries setPrecision(T precision) {
            this->precision = precision;
            return *this;
        }

        NumericSeries setThresholds(T lowerThreshold, T higherThreshold) {
            this->setLowerThreshold(lowerThreshold);
            this->setHigherThreshold(higherThreshold);
            return *this;
        }

        NumericSeries setLowerThreshold(T lowerThreshold) {
            this->lowerThreshold = lowerThreshold;
            return *this;
        }

        NumericSeries setHigherThreshold(T higherThreshold) {
            this->higherThreshold = higherThreshold;
            return *this;
        }

        NumericSeries sum(T parameter) {
            if (!ignoreZeroDivision && lowerThreshold == 0) {
                throw "Zero division possibility, try ignore if you sure you have no critical division operations";
            }

            T newValue = precision;
            iterations = 0;

            for (int i = lowerThreshold; abs(newValue) >= precision; i++) {

                if (i > higherThreshold) {
                    throw "Numeric series is probably divergent";
                }

                newValue = function(parameter, i);
                sum_ += newValue;
                iterations++;
            }

            return *this;
        }

        NumericSeries transform(std::function<T(T)> transformation) {
            sum_ = transformation(sum_);
            return *this;
        }

        Report<T> report() {
            return Report<T>(iterations, sum_);
        };


        // SERVICE METHODS

        NumericSeries setInitSum(T sum) {
            sum_ = sum;
            return *this;
        }

        NumericSeries setIgnoreZeroDivision(bool ignoreZeroDivision) {
            NumericSeries::ignoreZeroDivision = ignoreZeroDivision;
            return *this;
        }

        NumericFunction getFunction() {
            return this->function;
        }

        T getSum() {
            return this->sum_;
        }


        // OPERATORS

        NumericSeries operator+(const NumericSeries &other) {
            NumericSeries series([other, this](T n, T k) {
                return other.function(n, k) + this->function(n, k);
            });
            return series;
        }

        NumericSeries operator+(const T other) {
            this->sum_ += other;
            return *this;
        }

    };

}


#endif //NUMERICSERIES_NUMERICSERIES_H
