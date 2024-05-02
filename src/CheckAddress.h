/**
 * @file CheckAddress.h
 * @brief Definition of the CheckAddress class.
 */

#ifndef FOOBAR_PROJECT_CHECKADDRESS_H
#define FOOBAR_PROJECT_CHECKADDRESS_H
#include "BloomFilter.h"
#include "Commands.h"
#include <iostream>
using namespace std;

/**
 * @class CheckAddress
 * @brief Represents a command to check the presence of an address in a Bloom Filter.
 *
 * The CheckAddress class encapsulates the logic for checking if a specified URL
 * is likely present in a Bloom Filter by using the Bloom Filter's hash functions
 * and examining the corresponding bit array and address list.
 */
class CheckAddress : public Commands
{
private:
    BloomFilter *bloomFilter; ///< Pointer to the Bloom Filter.
public:
    /**
     * @brief Constructor for the CheckAddress class.
     *
     * Initializes a CheckAddress object with a pointer to a Bloom Filter.
     *
     * @param bloomFilter A pointer to the Bloom Filter where the address will be checked.
     */
    CheckAddress(BloomFilter *bloomFilter);

    /**
     * @brief Execute the command to check the presence of an address in the Bloom Filter.
     *
     * Uses the Bloom Filter's hash functions to calculate hash codes for the given URL.
     * Checks the corresponding bits in the bit array and verifies the address in the list.
     * Prints the result (true or false) to the standard output.
     *
     * @param url The URL to be checked in the Bloom Filter.
     */
    string execute(const string &url);
};
#endif // FOOBAR_PROJECT_CHECKADDRESS_H
