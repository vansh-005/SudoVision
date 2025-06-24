Sudoku Solver (WebAssembly + C++ backend + TensorFlow CNN)

A browser-based Sudoku solver that uses a TensorFlow-powered CNN to recognize digits from a camera feed, and a high-performance C++ backtracking solver compiled to WebAssembly to compute the solution on the client side.

Project Overview

This project implements a fully client‑side Sudoku solver in the browser:

Digit Recognition: A TensorFlow-based convolutional neural network (CNN) identifies the digits in a photographed or live video‐streamed 9×9 Sudoku grid.

Puzzle Solving: A performant C++ backtracking solver is compiled to WebAssembly for near‑native execution speed.

Web Interface: A lightweight JavaScript/HTML front‑end orchestrates camera access, digit detection, solution rendering, and user interaction—all without any server dependency.