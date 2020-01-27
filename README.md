# cmake-gtest-coverage-demo
## This example shows how to use gcovr on Linux systems to determine the degree of coverage of the code with tests

Simply run next command to compile app and running tests:
```
./build_and_test.sh
```
The following packages are required for building
```
build-essential (or similar for rpm-based OS)
cmake
libgtest-dev (or gtest for rpm-based OS)
gcovr
```

For deb-based OS need to build a gtest libs
```
cd /usr/src/gtest
sudo cmake .
sudo make

# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib
```
