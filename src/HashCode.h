/**
 * @file HashCode.h
 * @brief Definition of the HashCode class.
 */

#ifndef FOOBAR_PROJECT_HASHCODE_H
#define FOOBAR_PROJECT_HASHCODE_H
#include <string>

/**
 * @class HashCode
 * @brief Represents a simple hash code generator based on repeated hashing.
 *
 * The HashCode class provides a mechanism to generate hash codes for strings by
 * iteratively applying the standard hash function multiple times.
 */
class HashCode
{
private:
    int index; ///< The number of iterations for the hash function.
    std::hash<std::string> hash;

public:
    /**
     * @brief Constructor for the HashCode class.
     *
     * Initializes a HashCode object with a specified index.
     *
     * @param index The number of times the hash function will be applied.
     */
    explicit HashCode(int index);

    /**
     * @brief Generate a hash code for a given string.
     *
     * Applies the standard hash function to the input string iteratively
     * for the specified number of times (determined by the index).
     *
     * @param str The input string for which a hash code is to be generated.
     * @return The generated hash code.
     */
    size_t run(std::string str);
};

#endif // FOOBAR_PROJECT_HASHCODE_H
