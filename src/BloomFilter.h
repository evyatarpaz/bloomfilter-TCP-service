/**
 * @file BloomFilter.h
 * @brief Definition of the BloomFilter class.
 */

#ifndef FOOBAR_PROJECT_BLOOMFILTER_H
#define FOOBAR_PROJECT_BLOOMFILTER_H
#include <string>
#include <list>
#include "HashCode.h"
#include <vector>
#include <set>
using namespace std;

/**
 * @class BloomFilter
 * @brief Represents a Bloom Filter data structure for managing URLs.
 *
 * The BloomFilter class provides functionality for managing a Bloom Filter,
 * including initializing, retrieving information, and adding addresses.
 */
class BloomFilter
{
private:
    std::vector<bool> bitArrayVector;  ///< Bit array representing the Bloom Filter.
    std::set<std::string> addressList; ///< List of addresses stored in the Bloom Filter.
    std::vector<HashCode> hashType;    ///< Set of hash function indexes.

public:
    /**
     * @brief Parameterized constructor for the BloomFilter class.
     *
     * Initializes the Bloom Filter with a specified size and a set of hash indexes.
     *
     * @param size The size of the bit array in the Bloom Filter.
     * @param hashIndex Set of hash indexes to determine the hash functions used.
     */
    BloomFilter(int size, const std::set<int> &hashIndex);

    /**
     * @brief Default constructor for the BloomFilter class.
     * Initializes an empty Bloom Filter.
     */
    BloomFilter();

    void addAddressToBloomfilter(std::string url);
    void checkAddress(std::string url);

    /**
     * @brief Get the size of the bit array in the Bloom Filter.
     *
     * @return The size of the bit array.
     */
    size_t getBitArraySize();

    /**
     * @brief Get the current bit array.
     *
     * @return A vector representing the current state of the bit array.
     */
    std::vector<bool> getBitArray();

    /**
     * @brief Get the list of addresses stored in the Bloom Filter.
     *
     * @return A set containing the addresses present in the Bloom Filter.
     */
    std::set<std::string> getAddressList();

    /**
     * @brief Get the vector of hash codes used by the Bloom Filter.
     *
     * @return A vector of HashCode objects representing the hash functions.
     */
    std::vector<HashCode> getHashType();

    /**
     * @brief Add an index to the bit array in the Bloom Filter.
     *
     * @param index The index to be set to true in the bit array.
     */

    void addIndexToBitArray(size_t index);

    /**
     * @brief Add an address to the list of addresses in the Bloom Filter.
     *
     * @param url The address to be added.
     */
    void addUrlToList(const string &url);
};

#endif // FOOBAR_PROJECT_BLOOMFILTER_H
