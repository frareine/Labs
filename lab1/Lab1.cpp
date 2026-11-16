#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>

// Checks whether x belongs to the expression's domain.
bool inDomain(double x) {
    return std::isfinite(x) && x >= -8.0 && x != -6.0
        && x != 4.0 && x != 11.0;
}

// Calculates the expression for an argument from its domain.
double f(double x) {
    return std::sin(11.0 / 52.0)
        - (17.0 * std::numbers::pi / (48.0 * std::numbers::e))
        * (13.0 / ((x + 6.0) * (x - 11.0)))
        + 7.0 * std::cos(x - 9.0)
        + (5.0 - std::sqrt(x + 8.0)) / (x - 4.0);
}

// Executes the required input, calculation, and output steps.
int main() {
    std::cout << "Executor: Vladyslav Novykov\n";
    std::cout << "Variant: 174\n";
    std::cout << "Task: calculate an expression for a real number x.\n";
    std::cout << "Enter x (x >= -8; x != -6, 4, 11): ";

    double x{};
    std::cin >> x;

    if (std::cin.fail()) {
        std::cout << "\nwrong input\n";
    }
    else {
        std::cout << "\n***** do calculations ... ";

        const bool defined = inDomain(x);
        double result{};
        if (defined) {
            result = f(x);
        }

        std::cout << "done\n";
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "for x = " << x << '\n';

        if (defined) {
            std::cout << std::setprecision(9);
            std::cout << "result = " << result << '\n';
        }
        else {
            std::cout << "result = undefined\n";
        }
    }
}
