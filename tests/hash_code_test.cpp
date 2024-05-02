#include <gtest/gtest.h> // here we include the code to be tested
#include "../src/HashCode.cpp"
#include <string>

TEST(HashCodeTest, getters)
{
    std::string example = "www.example.com";

    std::hash<std::string> hashes;
    int outputHashes = hashes(example);

    HashCode h = HashCode(1);
    // equality between run and hash class
    EXPECT_EQ(h.run(example), outputHashes);


}