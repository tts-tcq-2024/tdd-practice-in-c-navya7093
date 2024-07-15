#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <regex>

namespace {

    std::vector<std::string> splitHelper(const std::string& str, const std::string& delimiter, size_t& prev, size_t& pos) {
        std::vector<std::string> tokens;
        do {
            pos = str.find(delimiter, prev);
            if (pos == std::string::npos) pos = str.length();
            std::string token = str.substr(prev, pos - prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delimiter.length();
        } while (pos < str.length() && prev < str.length());
        return tokens;
    }

    std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
        size_t prev = 0, pos = 0;
        return splitHelper(str, delimiter, prev, pos);
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

    void throwNegativesException(const std::vector<int>& negatives) {
        std::ostringstream oss;
        oss << "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            if (i > 0) oss << ", ";
            oss << negatives[i];
        }
        throw std::runtime_error(oss.str());
    }

    void checkNegatives(const std::vector<int>& numbers) {
        std::vector<int> negatives;
        for (int num : numbers) {
            if (num < 0) {
                negatives.push_back(num);
            }
        }
        if (!negatives.empty()) {
            throwNegativesException(negatives);
        }
    }

    int sumNumbers(const std::vector<int>& numbers) {
        int sum = 0;
        for (int num : numbers) {
            if (num <= 1000) {
                sum += num;
            }
        }
        return sum;
    }

    std::vector<int> parseNumbers(const std::vector<std::string>& tokens) {
        std::vector<int> numbers;
        for (const std::string& token : tokens) {
            if (!token.empty()) {
                numbers.push_back(std::stoi(token));
            }
        }
        return numbers;
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
    std::vector<int> parsedNumbers = parseNumbers(tokens);
    checkNegatives(parsedNumbers);
    return sumNumbers(parsedNumbers);
}

#endif // STRING_CALCULATOR_H
