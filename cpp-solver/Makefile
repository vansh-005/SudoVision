OUT_JS=sudoku_wasm.js
OUT_WASM=sudoku_wasm.wasm

all: $(OUT_JS)

$(OUT_JS): solver.cpp
	emcc solver.cpp -O3 \
	  -s WASM=1 -s MODULARIZE=1 -s EXPORT_ES6=1 \
	  -s EXPORT_NAME="initWasmModule" \
	  -s EXPORTED_FUNCTIONS="["_solve"]" \
	  -s EXPORTED_RUNTIME_METHODS="["cwrap"]" \
	  -o $(OUT_JS)

clean:
	rm -f $(OUT_JS) $(OUT_WASM)

.PHONY: all clean

