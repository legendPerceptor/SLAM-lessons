
## Install the Eigen library

```bash
sudo apt install libeigen3-dev
```

The default path for Eigen is in "/usr/include/eigen3". But we can use the following command to locate it.
```bash
locate eigen3
```

## Use CMake to compile the targets

```bash
# Inside build
cmake ..
# CMake build files are generated
# Run a specific target
cmake --build . --target eigenMatrix -- -j 8
# Or we just make and all targets will be built
make
```