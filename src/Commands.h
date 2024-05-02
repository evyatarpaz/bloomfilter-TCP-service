/**
 * @file Commands.h
 * @brief Definition of the Commands interface.
 */

#ifndef FOOBAR_PROJECT_COMMANDS_H
#define FOOBAR_PROJECT_COMMANDS_H
#include <string>
using namespace std;

/**
 * @class Commands
 * @brief Interface for command objects in the ICommand design pattern.
 *
 * The Commands interface declares a method for executing commands. Concrete
 * command classes should implement this interface by providing their own
 * implementation of the execute method.
 */
class Commands {
public:

     /**
     * @brief Execute the command with a specified URL.
     *
     * This pure virtual function must be implemented by concrete classes that
     * inherit from Commands. It represents the action that the command will perform
     * when executed with the provided URL.
     *
     * @param url The URL parameter needed for the command execution.
     */
    virtual string execute(const string &url) = 0;
};
#endif //FOOBAR_PROJECT_COMMANDS_H
