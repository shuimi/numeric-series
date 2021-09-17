#include "NumericSeries.h"
#include "Maths.h"


int main() {

    /// LAB 1
    /// LAB 1
    /// LAB 1

    // TASK 1

    auto seriesTaskOne = NumericSeries::NumericSeries<double>([](double x, double k) {
        return pow(x, k) / Maths::fact<double>(k);
    });

    seriesTaskOne
            .setPrecision(1e-6)
            .setInitSum(1)
            .setIgnoreZeroDivision(true)
            .sum(1, 1)
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 1", "e^x Taylor's series"))
            .printout();

    auto sumSeries = seriesTaskOne + seriesTaskOne.getSum();



    // TASK 2.11

    auto seriesTaskTwo = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / (k * (k + x));
    });

    // NO OPTIMISATION
    seriesTaskTwo
            .setPrecision(0.5 * 1e-8)
            .setInitSum(0)
            .sum(0, 1)
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.11", "Without optimisation"))
            .printout();


    auto seriesTaskTwoB = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / (k * (k + 1) * (k + x));
    });

    // WITH OPTIMISATION
    seriesTaskTwoB
            .setPrecision(0.5 * 1e-8)
            .setInitSum(0)
            .sum(0, 1)
            .transform([](double sum) {
                return 1 + sum;
            })
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.11", "With optimisation"))
            .printout();



    // TASK 2.13

    auto seriesTaskThree = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / (k * k + 1);
    });

    seriesTaskThree
            .setPrecision(1e-10)
            .setInitSum(0)
            .sum(0, 1)
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.13", "Without optimisation"))
            .printout();


    auto seriesTaskThreeB = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / (pow(k, 4) * (k * k + 1));
    });

    seriesTaskThreeB
            .setPrecision(1e-10)
            .setInitSum(0)
            .sum(0, 1)
            .transform([](double sum) {
                return (pow(Maths::pi, 2) / 6) - (pow(Maths::pi, 4) / 90) + sum;
            })
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.13", "With optimisation"))
            .printout();


    /// LAB 2
    /// LAB 2
    /// LAB 2


    return 0;
}
