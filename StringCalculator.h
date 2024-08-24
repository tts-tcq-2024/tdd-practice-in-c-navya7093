#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <cstring>
#include <cstdlib>

int add(const char* numbers) {
    // Handle empty input
    if (strcmp(numbers, "") == 0) {
        return 0;
    }
    
    // Handle single number or zero
    if (strchr(numbers, ',') == nullptr) {
        return atoi(numbers);
    }

    // Handle two numbers separated by a comma
    const char* delimiter = ",";
    char* numbersCopy = strdup(numbers);  // Duplicate string to modify it safely
    char* token = strtok(numbersCopy, delimiter);
    int sum = 0;
    
    while (token != NULL) {
        sum += atoi(token);  // Convert token to integer and add to sum
        token = strtok(NULL, delimiter);  // Get next token
    }

    free(numbersCopy);  // Free the duplicated string memory
    return sum;
}

#endif // STRINGCALCULATOR_H
