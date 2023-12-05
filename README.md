# base64

Simple header-only C++ library for Base64 encoding/decoding.

## Testing

Build tests:
```
# template is for header-only library by default
cmake -S . -B_build
cmake --build _build
```

Run tests:
```
cd _build && ctest
# or 
cmake --build _build --target hello_test
./_build/hello_test
```

## Usage

```cpp
#include <base64/base64.hpp>

auto encoded = base64::encode("foobar");
assert(encoded == "Zm9vYmFy");
```
