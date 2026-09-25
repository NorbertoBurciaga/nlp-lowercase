# nlp-lowercase

A tiny C++ static library (packaged with [Conan](https://conan.io)) that lowercases text for NLP preprocessing.

```cpp
#include "nlp/lowercase.hpp"

std::string lowered = nlp::lowercase("HeLLo, WoRLD!"); // "hello, world!"

std::string s = "MiXeD";
nlp::lowercase_in_place(s); // "mixed"
```

Only ASCII `A`–`Z` are mapped to `a`–`z`; every other byte (including multi-byte UTF-8 sequences) passes through unchanged. The conversion is locale-independent, so results are stable across platforms.

## Build the Conan package

```bash
conan create .
```

## Use it in your project

`conanfile.txt`:

```ini
[requires]
nlp-lowercase/1.0.0

[generators]
CMakeDeps
CMakeToolchain
```

`CMakeLists.txt`:

```cmake
find_package(nlp_lowercase CONFIG REQUIRED)
target_link_libraries(my_app PRIVATE nlp::nlp_lowercase)
```

## Layout

- `include/nlp/lowercase.hpp` — public API
- `src/lowercase.cpp` — implementation
- `test_package/` — Conan test package (builds and runs a smoke test)

## License

MIT — see [LICENSE](LICENSE).
