/**
 * @file App.h
 * @brief Definition of the App class.
 */

#ifndef FOOBAR_PROJECT_APP_H
#define FOOBAR_PROJECT_APP_H
#include "InputManagement.h"
#include "BloomFilter.h"
#include "HashCode.h"
#include "Commands.h"
#include "AddAddress.h"
#include "CheckAddress.h"
#include <map>
/**
 * @class App
 * @brief Represents the main application for managing a Bloom Filter.
 *
 * The App class is responsible for initializing the input management,
 * creating a Bloom Filter, and running the application loop to interact
 * with the user for adding and checking URLs in the Bloom Filter.
 */

class App
{
private:
    InputManagement input;
    std::string userInput;            ///< Object for managing user input.
    BloomFilter *bf;                  ///< Bloom Filter for managing URLs.
    map<string, Commands *> commands; ///< Command for managing ICommand design pattern elements

public:
    /**
     * @brief Default constructor for the App class.
     *
     * Initializes the input management and Bloom Filter, prompting the user
     * to provide necessary inputs for the application to operate.
     */
    App(const string &initDetails);

    /**
     * @brief Runs the main application loop.
     *
     * Continuously prompts the user for input, processes the choice,
     * and interacts with the Bloom Filter based on user actions.
     * The loop runs indefinitely until the application is manually terminated.
     */
    std::string run();
    void setUserInput(const std::string &str);
};
#endif // FOOBAR_PROJECT_APP_H
