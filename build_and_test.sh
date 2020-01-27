#/bin/bash
cmake . -DWITH_TESTS=ON -DCMAKE_BUILD_TYPE=Debug -DWITH_COVERAGE=ON
rm -rf ./testapp_coverage
make
make testapp_coverage

if [ $? -eq 0 ]; then
	make clean
	cmake . -DWITH_TESTS=OFF -DCMAKE_BUILD_TYPE=Release
	make
fi



