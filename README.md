# emugb

A Game Boy Color (CGB) emulator

## Architecture

### CPU

Abstraction of the `LR35902` CPU.

|Register| 15 ... 8 | 7 ... 0 |
| -- | - | - |
| AF | A | F |
| BC | B | C |
| DE | D | E |
| HL | H | L |
| SP | - | - |
| PC | - | - |

|Flag Register|||||||||
| - | - | - | - | - | - | - | - | - |
| F | z | n | h | c | x | x | x | x |


## Build

Build using CMake

```bash
cmake -B build
cd build
make
```

### Running

```bash
./bin/emugb
```

### Testing

1. Using CTest
```bash
ctest
```

2. Using GTest
```bash
./bin/testgb
```
