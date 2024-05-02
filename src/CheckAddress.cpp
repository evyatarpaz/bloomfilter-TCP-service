#include "CheckAddress.h"
#include "BloomFilter.h"
using namespace std;

CheckAddress::CheckAddress(BloomFilter *bloomFilter) {
    this->bloomFilter= bloomFilter;
}

string CheckAddress::execute(const string &url){
     bool flag ;
    size_t arraySize = bloomFilter->getBitArraySize();
    for (HashCode i : bloomFilter->getHashType()) {
        flag = bloomFilter->getBitArray()[(i.run(url) % arraySize)];
    }
    if (!flag) {
        return "false" ;
    }
    else {
        auto it = bloomFilter->getAddressList().find(url); 
        if(it == bloomFilter->getAddressList().end()){
            return "true false";
            
        }
        return "true true";
    }
}