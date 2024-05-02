#ifndef FOOBAR_PROJECT_INPUTMANAGEMENT_H
#define FOOBAR_PROJECT_INPUTMANAGEMENT_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>

/**
 * @class InputManagement
 * @brief Manages user input and provides methods for initializing and retrieving data.
 *
 * The InputManagement class facilitates user input processing and manages the
 * initialization of parameters for the application. It also provides methods to
 * retrieve user choices, URLs, and related information.
 */
class InputManagement
{
private:
    int bitArraySize;              ///< Size of the bit array for Bloom Filter.
    std::string userInput;         ///< Set of hash function indexes.
    std::string url;               ///< User's choice (e.g., "www.exampl.com" or "fooexample").
    std::set<int> hashFuncsVector; ///< URL provided by the user.
    void clear();
public:
    /**
     * @brief Default constructor for the InputManagement class.
     * Initializes an InputManagement object with default values.
     */
    InputManagement();

     /**
     * @brief Get input from the user.
     *
     * Reads a line from the standard input (cin) and returns it as a string.
     *
     * @return A string representing the user input.
     */
    std::string getInput();

    /**
     * @brief Initialize input parameters from a string.
     *
     * Parses a string to extract parameters for initializing the application.
     *
     * @param str The input string containing parameters.
     * @return True if initialization is successful, false otherwise.
     */
    bool filterInitInput(const std::string& str);

    /**
     * @brief Read user input from a string.
     *
     * Parses a string to extract user choices and URLs.
     *
     * @param str The input string containing user choices and URLs.
     */
    void inputFromUser(const std::string &str);

    /**
     * @brief Get the size of the bit array specified during initialization.
     *
     * @return The size of the bit array.
     */
    int getBitArraySize();

    /**
     * @brief Get the set of hash function indexes specified during initialization.
     *
     * @return The set of hash function indexes.
     */
    std::set<int> getHashFuncsVector();

    /**
     * @brief Get the URL extracted from user input.
     *
     * @return The URL provided by the user.
     */
    std::string getURL();

    /**
     * @brief Get the user choice extracted from user input.
     *
     * @return The user's choice as a string.
     */
    std::string getUserChoice();
};
#endif //FOOBAR_PROJECT_INPUTMANAGEMENT_H
