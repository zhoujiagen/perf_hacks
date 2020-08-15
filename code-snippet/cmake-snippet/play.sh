mkdir -p tutorial-build
mkdir -p tutorial-install
rm -rf tutorial-build/*
rm -rf tutorial-install/*

# build
cd tutorial-build
cmake ../tutorial
cmake --build .

# instsall
cmake --install . --prefix ../tutorial-install

# run test
ctest -VV
