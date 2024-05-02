#include "InputManagement.h"

using namespace std;

InputManagement::InputManagement() = default;

string InputManagement::getInput(){
    string str;
    getline(cin,str);
    return str;
}


bool InputManagement::filterInitInput(const string &str) {
    if (str.empty()) {
        this->clear();
        return false;
    }
    stringstream ss(str);
    vector<int> vector;
    string s;
    bool firstIteration = true;
    while (getline(ss, s, ' ')) {
        if (str == s) {
            this->clear();
            return false;
        }
        try {
            int val = stoi(s);
            if (firstIteration) {
                this->bitArraySize = val;
                firstIteration = false;
            } else {
                if (val > 2) {
                    this->clear();
                    return false;
                }
                this->hashFuncsVector.insert(val);
            }

        }
        catch (invalid_argument &e) {
            this->clear();
            return false;
        }
    }
    return true;
}


void InputManagement::inputFromUser(const string &str) {
    stringstream ss(str);
    string s, s2;
    getline(ss, s, ' ');
    this->userInput = s;
    if (str == s) {
        this -> url ="";
        return;
    }
    getline(ss, s, ' ');
    getline(ss,s2,'\n');
    if (s2.empty()) {
        this -> url = s;
    }
    else {this->url = "";
    }
    
}
void InputManagement::clear() {
    this->hashFuncsVector.clear();
    this->bitArraySize = 0;
}

//Getters
int InputManagement::getBitArraySize() {
    return this->bitArraySize;
}

set<int> InputManagement::getHashFuncsVector() {
    return this->hashFuncsVector;
}

string InputManagement::getURL() {
    return this->url;
}

string InputManagement::getUserChoice() {
    return this->userInput;
}
