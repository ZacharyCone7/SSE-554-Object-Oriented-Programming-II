// Module 23 Exercise 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include <iostream> // For console input/output (cout)
#include <fstream>  // For file stream operations (ifstream, ofstream)
#include <string>   // For using the string class
#include <regex>    // For regular expression operations
#include <sstream>  // For reading file content into a string easily
#include <iterator> // For using distance with iterators

// Structure to hold the analysis results
struct TextAnalysisResult {
    long long total_words = 0;
    long long ing_words = 0;
    long long long_words = 0;
    bool success = false; // Flag to indicate if analysis was successful
};

// Function to analyze the text file using regex
TextAnalysisResult analyzeTextWithRegex(const std::string& filepath) {
    TextAnalysisResult result;
    std::ifstream inFile(filepath); // Open the file for reading

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filepath << "'" << std::endl;
        return result; // Return default result with success = false
    }

    // Read the entire file content into a string
    std::stringstream buffer;
    buffer << inFile.rdbuf(); // Read the whole file buffer into the stringstream
    std::string content = buffer.str();
    inFile.close(); // Close the file (though destructor would do it too)

    try {
        // 1. Total number of words: \b\w+\b
        // R"(...)" is a raw string literal, avoids escaping backslashes
        std::regex word_regex(R"(\b\w+\b)");
        auto words_begin = std::sregex_iterator(content.begin(), content.end(), word_regex);
        auto words_end = std::sregex_iterator(); // Default constructor marks the end
        result.total_words = std::distance(words_begin, words_end);

        // 2. Number of words ending with "ing" (case-insensitive): \b\w+ing\b
        // std::regex::icase makes it case-insensitive
        std::regex ing_regex(R"(\b\w+ing\b)", std::regex::icase);
        auto ing_begin = std::sregex_iterator(content.begin(), content.end(), ing_regex);
        auto ing_end = std::sregex_iterator();
        result.ing_words = std::distance(ing_begin, ing_end);

        // 3. Number of words with more than six letters (> 6 means 7 or more): \b\w{7,}\b
        std::regex long_regex(R"(\b\w{7,}\b)");
        auto long_begin = std::sregex_iterator(content.begin(), content.end(), long_regex);
        auto long_end = std::sregex_iterator();
        result.long_words = std::distance(long_begin, long_end);

        result.success = true; // Mark analysis as successful

    }
    catch (const std::regex_error& e) {
        std::cerr << "Regex error: " << e.what() << " (Code: " << e.code() << ")" << std::endl;
        // Return result with success = false
    }

    return result;
}

// Function to create a sample file if it doesn't exist
bool ensureSampleFileExists(const std::string& filepath) {
    std::ifstream checker(filepath);
    if (checker.good()) {
        checker.close();
        return true; // File already exists
    }
    checker.close(); // Close even if not good()

    std::cout << "Sample file '" << filepath << "' not found. Creating it..." << std::endl;
    std::ofstream outFile(filepath);
    if (!outFile) {
        std::cerr << "Error: Could not create sample file '" << filepath << "'" << std::endl;
        return false;
    }

    outFile << "Regular expressions are incredibly useful for string manipulation and pattern matching.\n"
        << "Programming often involves searching through text, and regex provides a powerful way for accomplishing this task efficiently.\n"
        << "Many programming languages, including Python, offer built-in support for regular expressions, making them accessible for various tasks like validating input or extracting specific information.\n"
        << "Learning regex takes practice, but it's a rewarding skill.\n"
        << "Consider searching online for more examples." << std::endl;

    if (!outFile) { // Check for errors during writing
        std::cerr << "Error: Could not write to sample file '" << filepath << "'" << std::endl;
        outFile.close();
        return false;
    }

    outFile.close();
    std::cout << "Successfully created '" << filepath << "'." << std::endl;
    return true;
}


int main() {
    std::string filename = "paragraph.txt";

    // Ensure the sample file exists or try to create it
    if (!ensureSampleFileExists(filename)) {
        return 1; // Exit if file couldn't be found or created
    }


    // Analyze the file
    TextAnalysisResult results = analyzeTextWithRegex(filename);

    // Print the results if analysis was successful
    if (results.success) {
        std::cout << "\n--- Text Analysis Results ---" << std::endl;
        std::cout << "File Analyzed: " << filename << std::endl;
        std::cout << "Total number of words: " << results.total_words << std::endl;
        std::cout << "Number of words ending with 'ing': " << results.ing_words << std::endl;
        std::cout << "Number of words with more than six letters: " << results.long_words << std::endl;
    }
    else {
        std::cerr << "Text analysis failed." << std::endl;
        return 1; // Indicate error
    }

    return 0; // Indicate success
}*/
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <iterator>

struct TextAnalysisResult {
    long long total_words = 0;
    long long ing_words = 0;
    long long long_words = 0;
    bool success = false;
};

TextAnalysisResult analyzeTextWithRegex(const std::string& filepath, std::string& contentOut) {
    TextAnalysisResult result;
    std::ifstream inFile(filepath);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filepath << "'" << std::endl;
        return result;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();
    contentOut = content;
    inFile.close();

    try {
        std::regex word_regex(R"(\b\w+\b)");
        result.total_words = std::distance(
            std::sregex_iterator(content.begin(), content.end(), word_regex),
            std::sregex_iterator()
        );

        std::regex ing_regex(R"(\b\w+ing\b)", std::regex::icase);
        result.ing_words = std::distance(
            std::sregex_iterator(content.begin(), content.end(), ing_regex),
            std::sregex_iterator()
        );

        std::regex long_regex(R"(\b\w{7,}\b)");
        result.long_words = std::distance(
            std::sregex_iterator(content.begin(), content.end(), long_regex),
            std::sregex_iterator()
        );

        result.success = true;
    }
    catch (const std::regex_error& e) {
        std::cerr << "Regex error: " << e.what() << std::endl;
    }

    return result;
}

bool ensureSampleFileExists(const std::string& filepath) {
    std::ifstream checker(filepath);
    if (checker.good()) {
        checker.close();
        return true;
    }

    checker.close();
    std::ofstream outFile(filepath);
    if (!outFile) return false;

    outFile << "Regular expressions are incredibly useful for string manipulation and pattern matching.\n"
        << "Programming often involves searching through text, and regex provides a powerful way for accomplishing this task efficiently.\n"
        << "Many programming languages, including Python, offer built-in support for regular expressions, making them accessible for various tasks like validating input or extracting specific information.\n"
        << "Learning regex takes practice, but it's a rewarding skill.\n"
        << "Consider searching online for more examples." << std::endl;

    outFile.close();
    return true;
}

void userRegexSearch(const std::string& content) {
    std::string pattern;
    std::cout << "\nEnter a regex pattern to search the paragraph: ";
    std::getline(std::cin, pattern);

    try {
        std::regex user_regex(pattern);
        auto begin = std::sregex_iterator(content.begin(), content.end(), user_regex);
        auto end = std::sregex_iterator();
        int match_count = std::distance(begin, end);

        std::cout << "Found " << match_count << " matches:\n";
        for (std::sregex_iterator it = begin; it != end; ++it) {
            std::cout << "- " << it->str() << "\n";
        }
    }
    catch (std::regex_error& e) {
        std::cerr << "Invalid regex: " << e.what() << std::endl;
    }
}

int main() {
    std::string filename = "paragraph.txt";
    std::string content;

    if (!ensureSampleFileExists(filename)) {
        std::cerr << "Could not ensure sample file exists." << std::endl;
        return 1;
    }

    TextAnalysisResult results = analyzeTextWithRegex(filename, content);
    if (results.success) {
        std::cout << "\n--- Text Analysis Results ---\n";
        std::cout << "Total words: " << results.total_words << std::endl;
        std::cout << "Words ending with 'ing': " << results.ing_words << std::endl;
        std::cout << "Words with more than six letters: " << results.long_words << std::endl;

        userRegexSearch(content); // Prompt user for custom regex search
    }
    else {
        std::cerr << "Analysis failed.\n";
        return 1;
    }

    return 0;
}


