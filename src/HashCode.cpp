#include "HashCode.h"
#include <string>
#include <utility>
using namespace std;
HashCode::HashCode(int index) {
    this->index = index;
}
size_t HashCode::run(string str){
    string temp = std::move(str);
    size_t code;
    //run the hash on the string
    for (int i = 0; i < index; ++i) {
        code = hash(temp);
        temp = to_string(code);
    }
    return code;
}
