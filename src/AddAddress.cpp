#include "AddAddress.h"
#include "BloomFilter.h"
using namespace std;

AddAddress::AddAddress(BloomFilter *bloomFilter) {
    this->bloomFilter= bloomFilter;
}

string AddAddress::execute(const string &url){
    size_t index;
    for (HashCode i: bloomFilter->getHashType()) {
        index = (i.run(url)) % (bloomFilter->getBitArraySize());
        bloomFilter->addIndexToBitArray(index);
    }
    bloomFilter->addUrlToList(url);
    return url;
}