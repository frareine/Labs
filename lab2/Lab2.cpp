#include <cmath>
#include <format>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

const double a = -1.0;
const double b = 1.0;

// Calculates the sum using consecutive terms of the series.
double s(const double x, const double eps) {
    const double xSquared = x * x;
    double term = 1.0;
    double sum = 0.0;
    double n = 0.0;

    while (term >= eps) {
        sum += term;
        term *= xSquared / (4.0 * n + 2.0);
        ++n;
    }

    return sum + term;
}

// Reads exactly one real number from one input line.
double readNumber(const char* name, const char* hint) {
    cout << "Enter " << name << " (" << hint << "): ";

    string line;
    if (!getline(cin, line)) {
        throw invalid_argument(format("Cannot read {}.", name));
    }

    istringstream input(line);
    double value = 0.0;
    char extra = '\0';

    if (!(input >> value) || (input >> extra)) {
        throw invalid_argument(format(
            "Invalid input for {}: enter one real number only.",
            name));
    }

    return value;
}

int main() {
    cout << "Author: Vladyslav Novikov.\n";
    cout << "Variant 174: calculate a power series on [-1, 1].\n";

    try {
        const double x = readNumber("x", "from -1 to 1");

        if (!isfinite(x) || x < a || x > b) {
            throw domain_error("x must be in [-1, 1].");
        }

        const double eps = readNumber("eps", "greater than 0");

        if (!isfinite(eps) || eps <= 0.0) {
            throw domain_error("eps must be positive and finite.");
        }

        cout << "***** do calculations ... ";
        const double result = s(x, eps);
        cout << "done\n";

        cout << format("for x = {:.7E}\n", x);
        cout << format("for eps = {:.9E}\n", eps);
        cout << format("result = {:.8f}\n", result);
    }
    catch (const exception& error) {
        cout << "***** error\n";
        cout << error.what() << '\n';
    }
}
