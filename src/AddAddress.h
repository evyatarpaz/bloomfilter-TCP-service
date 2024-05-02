/**
 * @file AddAddress.h
 * @brief Definition of the AddAddress class.
 */

#ifndef FOOBAR_PROJECT_ADDADDRESS_H
#define FOOBAR_PROJECT_ADDADDRESS_H
#include "BloomFilter.h"
#include "Commands.h"
#include <string>

/**
 * @class AddAddress
 * @brief Represents a command to add an address to a Bloom Filter.
 *
 * The AddAddress class encapsulates the logic for adding a specified URL to
 * a Bloom Filter by calculating hash codes and updating the corresponding bit array.
 */
class AddAddress : public Commands{
private:
    BloomFilter *bloomFilter ; ///< Pointer to the Bloom Filter.
public:

    /**
     * @brief Constructor for the AddAddress class.
     *
     * Initializes an AddAddress object with a pointer to a Bloom Filter.
     *
     * @param bloomFilter A pointer to the Bloom Filter where the address will be added.
     */
    AddAddress(BloomFilter *bloomFilter);

     /**
     * @brief Execute the command to add an address to the Bloom Filter.
     *
     * Calculates hash codes for the given URL using the Bloom Filter's hash functions,
     * determines the corresponding bit array indices, and updates the bit array.
     * Additionally, adds the URL to the list of addresses in the Bloom Filter.
     *
     * @param url The URL to be added to the Bloom Filter.
     */
    std::string execute(const string &url);
};
#endif //FOOBAR_PROJECT_ADDADDRESS_H
