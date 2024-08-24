#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H
#include <cstring>
#include <cstdlib>

int add(const char* numbers) {
    // Minimum code to pass the test
    return 0;
}

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
int add(const char* numbers) {
    // Handle empty input
    if (strcmp(numbers, "") == 0) {
        return 0;
    }
    
    // Handle single zero
    if (strcmp(numbers, "0") == 0) {
        return 0;
    }
    
    // Handle two numbers separated by a comma
    const char* delimiter = ",";
    char* numbersCopy = strdup(numbers);
    char* token = strtok(numbersCopy, delimiter);
    int sum = 0;
    
    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, delimiter);
    }

    free(numbersCopy);
    return sum;
}

#endif // STRINGCALCULATOR_H

