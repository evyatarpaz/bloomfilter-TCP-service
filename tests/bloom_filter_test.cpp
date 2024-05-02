#include <gtest/gtest.h> // here we include the code to be tested
#include "../src/BloomFilter.cpp"
#include "../src/HashCode.cpp"
#include "../src/InputManagement.cpp"
#include "../src/AddAddress.cpp"
#include "../src/CheckAddress.cpp"
#include <string>

TEST(BloomFilterTest, geters)
{
    // test if the bit array is in the constructed size
    set<int> hashIndex;
    hashIndex.insert(hashIndex.end(),1);
    hashIndex.insert(hashIndex.end(),2);
    BloomFilter bloomFilter = BloomFilter(8,hashIndex);
    EXPECT_EQ(bloomFilter.getBitArraySize(), 8);
}

TEST(BloomFilterTest, inputTest) {
    InputManagement im = InputManagement();
    im.filterInitInput("a");
    EXPECT_EQ(im.getBitArraySize(),0);
}

TEST(BloomFilterTest1, inputTest2) {
    InputManagement im = InputManagement();
    im.filterInitInput("8 2 1 0 a ");
    EXPECT_EQ(im.getBitArraySize(),0);
}

TEST(BloomFilterTest1, inputTest3) {
    InputManagement im = InputManagement();
    im.filterInitInput("8 2 1 0");
    EXPECT_EQ(im.getBitArraySize(),8);
}

TEST(BloomFilterTest2, inputTest4) {
    InputManagement im = InputManagement();
    im.filterInitInput("21 2 1 0 ");
    EXPECT_EQ(im.getHashFuncsVector().size(),3);
}

TEST(BloomFilterTest2, inputTest5) {
    InputManagement im = InputManagement();
    im.filterInitInput("21 2 1 0 ");
    im.inputFromUser("1 www.example.com");
    EXPECT_EQ("www.example.com" ,im.getURL());
}

TEST(BloomFilterTest2, inputTest6) {
    InputManagement im = InputManagement();
    im.filterInitInput("21 2 1 0 ");
    im.inputFromUser("1 www.example.com");
    EXPECT_EQ("1",im.getUserChoice());
}

// Test case for adding an address to the Bloom filter
TEST(BloomFilterTest3, AddAddress) {
    BloomFilter bf = BloomFilter(100, {1, 2});
    bf.addIndexToBitArray(42); // Add a specific index to the bit array
    EXPECT_TRUE(bf.getBitArray()[42]); // Verify that the bit at that index is set to true

    bf.addUrlToList("example.com");
    EXPECT_TRUE(bf.getAddressList().count("example.com") > 0); // Verify that the address is added to the list
}

// Test case for checking an address in the Bloom filter
TEST(BloomFilterTest3, CheckAddress) {
    BloomFilter bf = BloomFilter(100, {1, 2});
    // Assume some specific bit indices are set to true
    bf.addIndexToBitArray(10);
    bf.addIndexToBitArray(20);

    // Check an address that should be in the filter
    EXPECT_TRUE(bf.getBitArray()[10]);
    EXPECT_TRUE(bf.getBitArray()[20]);
    EXPECT_TRUE(bf.getAddressList().count("example.com") == 0);

    // Check an address that should not be in the filter
    EXPECT_FALSE(bf.getBitArray()[30]); // Assuming index 30 is not set
    EXPECT_FALSE(bf.getAddressList().count("example.org") > 0);
}

// Test case for checking an address that may have false positives
TEST(BloomFilterTest3, CheckFalsePositive) {
    BloomFilter bf = BloomFilter(100, {1, 2});
    // Assume some specific bit indices are set to true
    bf.addIndexToBitArray(10);
    bf.addIndexToBitArray(20);

    // Check an address that may result in a false positive
    EXPECT_TRUE(bf.getBitArray()[10]);
    EXPECT_TRUE(bf.getBitArray()[20]);
    // assuming we got false positive and checking if the url is in the list
    EXPECT_TRUE(bf.getAddressList().count("example.com") == 0);
}

// Test case for handling collisions in hash functions
TEST(BloomFilterTest3, HashFunctionCollisions) {
    BloomFilter bf = BloomFilter(100, {1, 2});
    // Assume two different addresses result in the same hash index
    bf.addIndexToBitArray(15);
    
    // Add an address that collides with the existing index
    bf.addUrlToList("example.org");

    // Verify that the address is added to the list despite the collision
    EXPECT_TRUE(bf.getAddressList().count("example.org") > 0);
}

// Test case for handling empty input in AddAddress::execute()
TEST(BloomFilterTest3, AddAddressEmptyInput) {
    BloomFilter* bf = new BloomFilter(100, {1, 2});
    // No assertions here, just testing that it doesn't crash with an empty string
    EXPECT_NO_THROW({
        AddAddress addAddress(bf);
        addAddress.execute("");
    });

    delete bf;
}

// Test case for handling empty input in CheckAddress::execute()
TEST(BloomFilterTest3, CheckAddressEmptyInput) {
    BloomFilter* bf = new BloomFilter(100, {1, 2});
    // No assertions here, just testing that it doesn't crash with an empty string
    EXPECT_NO_THROW({
        CheckAddress checkAddress(bf);
        checkAddress.execute("");
    });

    delete bf;
}

// Test case for filtering initialization input with invalid arguments
TEST(InputManagementTest3, FilterInitInputInvalidArguments) {
    InputManagement inputManager;

    // Provide an invalid input (non-integer)
    EXPECT_FALSE(inputManager.filterInitInput("abc 2"));

    // Provide an invalid input (hash function index greater than 2)
    EXPECT_FALSE(inputManager.filterInitInput("10 3"));
}

// Test case for filtering initialization input with valid arguments
TEST(InputManagementTest3, FilterInitInputValidArguments) {
    InputManagement inputManager;

    // Provide a valid input
    EXPECT_TRUE(inputManager.filterInitInput("100 1"));

    // Check the bit array size
    EXPECT_EQ(inputManager.getBitArraySize(), 100);

    // Check the hash function vector
    EXPECT_EQ(inputManager.getHashFuncsVector().size(), 1);
    EXPECT_TRUE(inputManager.getHashFuncsVector().count(1) > 0);
}
