#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <cstring>
#include <cstdlib>

int convertToInt(const char* token) {
    return atoi(token);
}

int sumTokens(const char* numbers, const char* delimiters) {
    char* numbersCopy = strdup(numbers);  // Duplicate string to modify it safely
    char* token = strtok(numbersCopy, delimiters);
    int sum = 0;
    
    while (token != NULL) {
        sum += convertToInt(token);  // Use helper function to convert token
        token = strtok(NULL, delimiters);  // Get next token
    }

    free(numbersCopy);  // Free the duplicated string memory
    return sum;
}

bool isEmpty(const char* numbers) {
    return strcmp(numbers, "") == 0;
}

bool isSingleNumber(const char* numbers) {
    return strchr(numbers, ',') == nullptr && strchr(numbers, '\n') == nullptr;
}

int add(const char* numbers) {
    if (isEmpty(numbers)) {
        return 0;
    }
    
    if (isSingleNumber(numbers)) {
        return convertToInt(numbers);
    }

    const char* delimiters = ",\n";  // Handle both comma and newline
    return sumTokens(numbers, delimiters);
}

#endif // STRINGCALCULATOR_H
