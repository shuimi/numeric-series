#include "NumericSeries.h"
#include "Maths.h"
#include <iomanip>

int main() {

    /// LAB 1 - LAB 1 - LAB 1 - LAB 1 - LAB 1
    /// LAB 1 - LAB 1 - LAB 1 - LAB 1 - LAB 1
    /// LAB 1 - LAB 1 - LAB 1 - LAB 1 - LAB 1

    // TASK 1

    auto seriesTaskOne = NumericSeries::NumericSeries<double>([](double x, double k) {
        return pow(x, k) / Maths::fact<double>(k);
    });

    seriesTaskOne
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(1)
            .setIgnoreZeroDivision(true)
            .sum(1)
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 1", "e^x Taylor's series"))
            .printout();

    auto sumSeries = seriesTaskOne + seriesTaskOne.getSum();

    std::cout << "-------------\n";


    // TASK 2.11

    auto seriesTaskTwo = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / (k * (k + x));
    });

    // NO OPTIMISATION
    seriesTaskTwo
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0)
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.11", "Without optimisation"))
            .printout();


    auto seriesTaskTwoB = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / (k * (k + 1) * (k + x));
    });

    // WITH OPTIMISATION
    seriesTaskTwoB
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0)
            .transform([](double sum) {
                return 1 + sum;
            })
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.11", "With optimisation"))
            .printout();

    std::cout << "-------------\n";

    // TASK 2.13

    auto seriesTaskThree = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / (k * k + 1);
    });

    seriesTaskThree
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0)
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.13", "Without optimisation"))
            .printout();


    auto seriesTaskThreeB = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / (pow(k, 4) * (k * k + 1));
    });

    seriesTaskThreeB
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0)
            .transform([](double sum) {
                return (pow(Maths::pi, 2) / 6) - (pow(Maths::pi, 4) / 90) + sum;
            })
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.13", "With optimisation"))
            .printout();

    std::cout << "-------------\n";


    /// LAB 2 - LAB 2 - LAB 2 - LAB 2 - LAB 2
    /// LAB 2 - LAB 2 - LAB 2 - LAB 2 - LAB 2
    /// LAB 2 - LAB 2 - LAB 2 - LAB 2 - LAB 2


    // TASK 2.12


    auto seriesL = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / sqrt(pow(k, 3) + x);
    });

    auto seriesR = NumericSeries::NumericSeries<double>([](double x, double k) {
        return 1 / sqrt(pow(k, 3) - x);
    });

    double sL5, sR5, sL9, sR9;

    seriesL
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0.5)
            .transform([&sL5](double sum) {
                sL5 = sum;
                return sum;
            })
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.12", "Left series with x=0.5"))
            .printout();
    seriesR
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0.5)
            .transform([&sR5](double sum) {
                sR5 = sum;
                return sum;
            })
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.12", "Left series with x=0.5"))
            .printout();
    seriesL
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0.999999999)
            .transform([&sL9](double sum) {
                sL9 = sum;
                return sum;
            })
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.12", "Left series with x=0.999999999"))
            .printout();
    seriesR
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0.999999999)
            .transform([&sR9](double sum) {
                sR9 = sum;
                return sum;
            })
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.12", "Left series with x=0.999999999"))
            .printout();

    std::cout << "First example sum (with x=0.5): " << sL5 - sR5 << "\n";
    std::cout << "First example sum (with x=0.999999999): " << sL9 - sR9 << "\n\n";

    auto seriesLR = NumericSeries::NumericSeries<double>([](double x, double k) {
        return
                (sqrt((pow(k, 3) - x)) - sqrt((pow(k, 3) + x)))
                /
                sqrt((pow(k, 3) + x) * (pow(k, 3) - x));
    });

    seriesLR
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0.5)
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.12", "FULL series with x=0.5"))
            .printout();

    seriesLR
            .setPrecision(1e-6)
            .setLowerThreshold(1)
            .setInitSum(0)
            .sum(0.999999999)
            .report()
            .setMeta(NumericSeries::MetaInfo("Task 2.12", "FULL series with x=0.999999999"))
            .printout();

    std::cout << "-------------\n";

    /// MACHINE EPSILON
    /// MACHINE EPSILON
    /// MACHINE EPSILON

    double EPS = 1.0, i = 0.0;

    do {
        EPS = 0.5 * EPS;
        i = EPS + 1;
    } while (i > 1);

    std::cout << setiosflags(std::ios::scientific);
    std::cout << "Machine EPSILON: " << EPS << "\n";


    return 0;
}
