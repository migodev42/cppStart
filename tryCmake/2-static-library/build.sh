# !bin/bash
rm -rf ./build
# cd build/
# cmake..

cmake -B ./build

cd build/
make

echo ""
echo "build successful!"