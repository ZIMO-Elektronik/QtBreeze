Add GitHub action once ubuntu runners [ECM](https://answers.launchpad.net/ubuntu/jammy/amd64/extra-cmake-modules) gets updated to at least 5.102.0 (currently 5.92.0).

```yml
name: build

on:
  push:
    branches: [master]

jobs:
  x86_64-linux-gnu-gcc:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - run: git fetch --unshallow --tags
      - run: sudo apt install extra-cmake-modules
      - run: sudo apt install qt6-base-dev
      - run: cmake -Bbuild
      - run: cmake --build build
```cpp