// StringCalculator.h

#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <cstring>
#include <cstdlib>

int add(const char* numbers) {
    // Handle empty input
    if (strcmp(numbers, "") == 0) {
        return 0;
    }
    
    // Handle single zero
    if (strcmp(numbers, "0") == 0) {
        return 0;
    }
    
    // Handle single number (non-zero)
    if (strchr(numbers, ',') == NULL) {
        return atoi(numbers);
    }

    // Handle two or more numbers separated by a comma
    const char* delimiter = ",";
    char* numbersCopy = strdup(numbers);  // Duplicate the input to avoid modifying the original string
    char* token = strtok(numbersCopy, delimiter);
    int sum = 0;
    
    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, delimiter);
    }

    free(numbersCopy);  // Free the allocated memory
    return sum;
}

#endif // STRINGCALCULATOR_H
