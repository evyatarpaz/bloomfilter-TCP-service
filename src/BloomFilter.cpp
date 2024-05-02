#include "BloomFilter.h"
#include "HashCode.h"
#include <iostream>
using namespace std;

BloomFilter::BloomFilter()= default;

BloomFilter::BloomFilter(int size,const set<int>& hashIndex) {
    this->bitArrayVector.assign(size, false);
    for (int i: hashIndex) {
        this->hashType.insert(hashType.end(),HashCode(i));

    }
}

void addAddressToBloomfilter(string url){
    
}
size_t BloomFilter::getBitArraySize() {
    return this->bitArrayVector.size();
}

vector<bool>BloomFilter::getBitArray() {
    return this->bitArrayVector;
}

set<string> BloomFilter::getAddressList() {
    return this->addressList;
}

vector<HashCode> BloomFilter::getHashType() {
    return this->hashType;
}

void BloomFilter:: addIndexToBitArray(size_t index) {
    bitArrayVector[index] =true;
}

void BloomFilter::addUrlToList(const string &url) {
    addressList.insert(url);
}

