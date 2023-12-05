# CPP-LIBRARY-TEMPLATE

<!--- TODO: remove this section after init -->
## Init template

1. Clone repo created from template

2. Enter repo directory

3. Run script:

```bash
./scripts/init_template.sh <LIBRARY_NAME>
```

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

```
