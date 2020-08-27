# !bin/bash
rm -rf ./build
mkdir build
cd build/

cmake ..
make

echo "\n"
echo "build successful!"