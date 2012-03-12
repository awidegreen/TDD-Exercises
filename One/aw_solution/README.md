compile gtest first
-------------------

* get gtest sources -- `wget http://googletest.googlecode.com/files/gtest-1.6.0.zip`
* unzip sources -- `unzip gtest-1.6.0.zip`
* change to extracted dir and compile -- `g++ -I./include -I. -c ./src/gtest-all.cc`
* create lib -- `ar -rv libgtest.a gtest-all.o`

further info see http://lembra.wordpress.com/2011/10/17/building-google-test-framework-with-cmake/
