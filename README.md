# FooBar-Project
How to run this project:
1. Open the terminal on the project folder
-------------------------------------
![Screenshot 2024-01-24 100720](https://github.com/Eliaddr119/FooBar-Project/assets/113431442/cbf9977b-c868-4404-91a6-9b78388533d3)

2. Type cd src
--------------
![Screenshot 2024-01-24 100628](https://github.com/Eliaddr119/FooBar-Project/assets/113431442/e9ea13ec-cdbb-4bf9-8eac-71350ba105dc)

3. Type "g++ -o bloomfilter ./main.cpp ./App.cpp ./InputManagement.cpp ./BloomFilter.cpp ./HashCode.cpp ./AddAddress.cpp ./CheckAddress.cpp
   You can also run "g++ -o bloomfilter ./*.cpp" to compile all the files
--------------------------------------------------------------------------------------------------------
![Screenshot 2024-01-24 100838](https://github.com/Eliaddr119/FooBar-Project/assets/113431442/366a0df8-c3cb-4327-aa0d-0e3277d41c2f)

4. type "./bloomfilter"
-----------------------
![Screenshot 2024-01-24 100927](https://github.com/Eliaddr119/FooBar-Project/assets/113431442/4b68b9cb-fe7e-43b7-9028-da0c11b55747)
![Screenshot 2024-01-24 101126](https://github.com/Eliaddr119/FooBar-Project/assets/113431442/c0217a87-3e8e-47cb-afa5-1119ee42771c)

An explanation of our work process.
-----------------------------------
First, we opened a new project in Jira and add several tasks, then we divided the tasks between us.
We divided the tasks into 4 parts,
The first part is the tests.
The second is the implementation of the classes that resolve the tasks and the tests,
The third part is the main method and refactoring
The fourth part is the workflow of the tests on the GitHub to check the compatibility of other computer versions or different operating systems to see if our project dont have other problems that we are not aware of.

In the first part, we have a variety of tests, among them are adding addresses to a group of addresses,
A test of getters and setters for the `Bloomfilter` class, a test on `Hashcode`, and a test that checks if the input that entered by the user is correct.

In the second part, we implemented the `Bloomfilter`, `HashCode`, `App`, `InputManagement`, `CheckAddress`, and `AddAddress` classes, and of course, the 'main' to run the program.

The `Bloomfilter` class mostly holds information about the program and a few methods, geters and setters.
The `HashCode` class holds an int number and a run method, the int is for remembering the index of the Hash and the run is to run the Hash on the addresses.
The `InputManagement` manages the input that we get from the user and checks if the input is correct.
In the beginning `addAddress` and `checkAddress` were methods in the `Bloomfilter` class, but we extracted them and we turned them into classes to make the code Closed for modification and open to extensions.


The third part is the refactoring: 
1. At first we held the information about the hash member in the `Bloomfilter` class, and with the member in the `Bloomfilter` we implemented the method addToBloomFilter, after the refactor, we implemented the class HashCode that holds the implementation of the hash, With this we severed the connection of the realization of the Hash to the `Bloomfilter`.

2. we created a unique class, `Inputmanagement` class that manages the input the user enters into the program, checks if the input is valid, and moves the required parts of the input to the correct locations in the program.

3. In the project, we introduced the ICommand interface following the ICommand design pattern. This interface abstracts the execution of commands, allowing us to decouple the command objects from the classes that invoke these commands. Specifically, we applied this pattern to the `AddAddress` and `CheckAddress` classes, which were initially part of the `BloomFilter` class.

Before the refactoring, the `BloomFilter` class contained methods (`addToBloomFilter` and `checkAddress`) responsible for adding addresses to the filter and checking their presence. After the refactoring, we introduced the `AddAddress` and `CheckAddress` classes, implementing the `Commands` interface. This design allows for a more modular and maintainable codebase, where each command is encapsulated in a separate class, promoting better separation of concerns.

This refactoring enhances code readability, maintainability, and extensibility by adhering to the principles of the ICommand design pattern.

The fourth part the Docker and the workflow:
we created a DockeHub account and we created a suitable workflow according to the appropriate videos of The lecturer of the course, as well as from information on the Internet.
