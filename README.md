# emugb

A Game Boy Color (CGB) emulator

## Architecture

### CPU

Abstraction of the `LR35902` CPU.

Registers:

| 15 ... 8 | 7 ... 0 |
| - | - |
| A | F |
| B | C |
| D | E |
| H | L |

## Build

Build using CMake

```bash
cmake -B build
cmake --build build/
```

### Running

```bash
./build/emugb
```

### Testing

1. Using CTest
```bash
ctest --test-dir ./build/test
```

2. Using GTest
```bash
./build/test/testgb
```
