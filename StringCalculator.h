#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <iostream>

int add(const std::string& numbers);

namespace {
    std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
        std::vector<std::string> tokens;
        size_t prev = 0, pos = 0;
        do {
            pos = str.find(delimiter, prev);
            if (pos == std::string::npos) pos = str.length();
            std::string token = str.substr(prev, pos - prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delimiter.length();
        } while (pos < str.length() && prev < str.length());
        return tokens;
    }

    std::vector<std::string> tokenize(const std::string& str, const std::string& delimiters) {
        std::vector<std::string> tokens;
        std::string regexPattern = "[" + delimiters + "\n]";
        std::regex re(regexPattern);
        std::sregex_token_iterator it(str.begin(), str.end(), re, -1);
        std::sregex_token_iterator end;
        while (it != end) {
            tokens.push_back(*it++);
        }
        return tokens;
    }

    std::string getDelimiter(const std::string& str) {
        if (str.substr(0, 2) == "//") {
            size_t endPos = str.find('\n');
            return str.substr(2, endPos - 2);
        }
        return ",\n";
    }
}

int add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiters = ",\n";
    std::string nums = numbers;

    if (numbers.substr(0, 2) == "//") {
        size_t newlinePos = numbers.find('\n');
        delimiters = numbers.substr(2, newlinePos - 2);
        nums = numbers.substr(newlinePos + 1);
    }

    std::vector<std::string> tokens = tokenize(nums, delimiters);
    int sum = 0;
    std::vector<int> negatives;

    for (const std::string& token : tokens) {
        if (!token.empty()) {
            int num = std::stoi(token);
            if (num < 0) {
                negatives.push_back(num);
            } else if (num <= 1000) {
                sum += num;
            }
        }
    }

    if (!negatives.empty()) {
        std::ostringstream oss;
        oss << "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            if (i > 0) oss << ", ";
            oss << negatives[i];
        }
        throw std::runtime_error(oss.str());
    }

    return sum;
}

#endif // STRING_CALCULATOR_H
