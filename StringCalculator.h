#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

int add(const char* numbers) {
    // Minimum code to pass the test
    return 0;
}

#endif // STRINGCALCULATOR_H
// StringCalculator.h

#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <cstring>

int add(const char* numbers) {
    // Handle empty input
    if (strcmp(numbers, "") == 0) {
        return 0;
    }
    
    // Handle single zero
    if (strcmp(numbers, "0") == 0) {
        return 0;
    }

    // Convert single number string to integer
    return atoi(numbers);
}

#endif // STRINGCALCULATOR_H
