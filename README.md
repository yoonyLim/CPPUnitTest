## File Structure

```
CPPUnitTest
|   CMakeLists.txt
|
|___build
|   |___src
|   |
|   |___test
|   |   ...
|
|___lib
|   |___googlemock
|   |
|   |___googletest
|   |   CMakeLists.txt
|   |   ...
|
|___src
|   |   CMakeLists.txt
|   |   main.cpp
|   |   UnsortedList.cpp
|   |   UnsortedList.h
|
|___test
    |   CMakeLists.txt
    |   main.cpp
    |   UnsrotedType-test.cpp
```

## Getting Started

***Prerequisite: CMake should have been installed***

1. From the root of the project, make a `build` directory and move to it with the following command:

```bash
mkdir build && cd build
```

2. Compile every directory with the following command:

```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" 
```

3. Build the project with the following command:

```bash
make all
```

4. Run compiled tests that is in the `test` directory of the `build` directory:

```bash
./test/[PROJECT_NAME]_test
```

To log the test output to a file

```bash
./test/[PROJECT_NAME]_test > [OUTPUT_FILE_NAME]
```
