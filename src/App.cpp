#include "App.h"
using namespace std;
App::App(const string &initDetails)
{
    this->input = InputManagement();
    input.filterInitInput(initDetails);
    this->bf = new BloomFilter(input.getBitArraySize(), input.getHashFuncsVector());
    Commands *addAddress = new AddAddress(bf);
    this->commands["1"] = addAddress;
    Commands *checkAddress = new CheckAddress(bf);
    this->commands["2"] = checkAddress;
}

void App::setUserInput(const string &str)
{
    this->userInput = str;
}
// a method to run the progrem
string App::run()
{
    // try to get a line from the user
    input.inputFromUser(this->userInput);
    string choice = input.getUserChoice();
    if (input.getURL().empty() || input.getUserChoice().empty())
    {
        return nullptr;
    }
    if (commands.count(choice))
    {
       string retString = commands[choice]->execute(input.getURL());
       return retString;
    }
}
