# Robust C-Calculator 🧮

A comprehensive calculator application developed in C Language. This tool goes beyond standard arithmetic to handle engineering and scientific computations.

## 🚀 Features

* **Standard Arithmetic:** Basic operations (+, -, *, /) with error handling for division by zero.
* **Scientific Mode:** Trigonometry, Logarithms, Roots, and Quadratic Equation solver.
* **Matrix Operations:** Addition, Subtraction, Multiplication, Transpose, Trace, and Symmetry checks (up to 10x10).
* **Number Theory:** Prime checks, Factorials (Recursion & Loops), Fibonacci, Armstrong numbers, and LCM/HCF.
* **Complex Numbers:** Uses `struct` to handle addition, subtraction, and multiplication of complex numbers.
* **Programmer Mode:** Bitwise operations (AND, OR, XOR, NOT, Shifts) and Base conversion (Decimal ↔ Binary).

## 🛠️ Concepts Applied
* **Functions & Recursion:** Modular programming for each mode.
* **2D Arrays & Nested Loops:** Used heavily in Matrix operations.
* **Structures (structs):** Implemented for Complex number calculations.
* **Macros:** Cross-platform screen clearing for Windows/Linux.

## 🔮 Future Roadmap
* Add a **File I/O system** to save calculation history to a text file.
* Implement **Inverse** and **Determinant** functions for the Matrix mode.
* Create a simple **GUI** (Graphical User Interface) in the future.

## 💻 How to Run

### Method 1: Using an IDE (Easier)
1.  Download `RobustCalculator.c`.
2.  Open the file in any C compiler (VS Code, Code::Blocks, etc).
3.  Click the **Build and Run** button.
 
### Method 2: Command Line
If you prefer using the terminal:

1.  **Download** the `RobustCalculator.c` file.
2.  Open your terminal and **navigate** to the folder where you saved the file (e.g., `cd Downloads`).
3.  Compile the code:
    ```bash
    gcc RobustCalculator.c -o calculator
    ```
    *(Note: On Linux, add `-lm` at the end to link the math library)*
4.  Run the executable:
    * **Windows:** `.\calculator.exe`
    * **Linux/Mac:** `./calculator`
  
      
## 👤 Author
**Mantasha** - *B.Tech CSE Student*

