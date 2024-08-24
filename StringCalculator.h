#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <sstream>
#include <vector>

int convertToInt(const std::string& token) {
    return std::stoi(token);
}

int sumTokens(const std::string& numbers) {
    std::istringstream stream(numbers);
    std::string token;
    int sum = 0;

    while (std::getline(stream, token, ',')) {
        int number = convertToInt(token);
        if (number <= 1000) {
            sum += number;
        }
    }

    return sum;
}

bool isEmpty(const std::string& numbers) {
    return numbers.empty();
}

bool isSingleNumber(const std::string& numbers) {
    return numbers.find(',') == std::string::npos;
}

int add(const std::string& numbers) {
    if (isEmpty(numbers)) {
        return 0;
    }
    
    if (isSingleNumber(numbers)) {
        return convertToInt(numbers);
    }

    return sumTokens(numbers);
}

#endif // STRINGCALCULATOR_H
