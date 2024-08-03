#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the input string starts with a custom delimiter
bool has_custom_delimiter(const char* str) {
    return str[0] == '/' && str[1] == '/';
}

// Function to extract the custom delimiter from the input string
void extract_custom_delimiter(const char* str, char* delimiter) {
    const char* start = str + 2; // Skip over "//"
    size_t length = strcspn(start, "\n"); // Find the position of the newline character
    strncpy(delimiter, start, length); // Copy the delimiter
    delimiter[length] = '\0'; // Null-terminate the delimiter
}

// Function to split the input string using the given delimiters and store the numbers in an array
void split_and_convert_to_numbers(const char* str, const char* delimiters, int* numbers, int* count) {
    char* copy = strdup(str);
    char* token = strtok(copy, delimiters);
    while (token) {
        numbers[(*count)++] = atoi(token);
        token = strtok(NULL, delimiters);
    }
    free(copy);
}

// Function to check for negative numbers in the array and generate an error message
bool check_for_negatives(int* numbers, int count, char* error_message) {
    bool has_negatives = false;
    strcpy(error_message, "negatives not allowed: ");
    for (int i = 0; i < count; i++) {
        if (numbers[i] < 0) {
            has_negatives = true;
            char number_str[12];
            snprintf(number_str, sizeof(number_str), "%d ", numbers[i]);
            strcat(error_message, number_str);
        }
    }
    return has_negatives;
}

// Function to sum the numbers in the array, ignoring those greater than 1000
int calculate_sum(int* numbers, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] <= 1000) {
            total += numbers[i];
        }
    }
    return total;
}

// Function to process the input string and return the sum of numbers
int process_input_and_sum(const char* str, const char* delimiters) {
    int numbers[1000];
    int count = 0;
    split_and_convert_to_numbers(str, delimiters, numbers, &count);

    char error_message[256];
    if (check_for_negatives(numbers, count, error_message)) {
        printf("%s\n", error_message); // Print the error message for negative numbers
        return -1; // Indicate an error
    }

    return calculate_sum(numbers, count);
}

// Main function to handle the input string and calculate the sum
int add_numbers(const char* str) {
    if (*str == '\0') {
        return 0;
    }

    char delimiter[10] = ",\n";
    if (has_custom_delimiter(str)) {
        extract_custom_delimiter(str, delimiter);
        str = strchr(str, '\n') + 1; // Move past the custom delimiter line
    }

    return process_input_and_sum(str, delimiter);
}

// Example usage
int main() {
    const char* input = "//;\n1;2\n3,4";
    int result = add_numbers(input);
    if (result != -1) {
        printf("Sum: %d\n", result);
    }
    return 0;
}
