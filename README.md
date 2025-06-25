# Sudoku Solver

This project runs entirely in the browser. A TensorFlow model recognizes the digits from a Sudoku grid and a C++ backtracking solver, compiled to WebAssembly, computes the solution.

## Building the WebAssembly module

The solver is built with [Emscripten](https://emscripten.org/). After installing the SDK, generate the WebAssembly files with:

```bash
npm run build:solver
```


This command executes `emmake make -C cpp-solver` and creates `cpp-solver/sudoku_wasm.js` and `cpp-solver/sudoku_wasm.wasm`.

Once built, open `index.html` in a browser to try the solver.
