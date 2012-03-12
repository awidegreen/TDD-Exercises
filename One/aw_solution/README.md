-compile gtest first:
wget http://googletest.googlecode.com/files/gtest-1.6.0.zip
unzip gtest-1.6.0.zip
g++ -I ${GTEST_DIR}/include -I ${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
ar -rv libgtest.a gtest-all.o

see http://lembra.wordpress.com/2011/10/17/building-google-test-framework-with-cmake/