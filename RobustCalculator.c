#include <stdio.h>
#include <stdlib.h> // For exit() if needed
#include <math.h>   // For pow(base, exp), sqrt(), cbrt(), sin(), cos(), tan(),log10(), log(),

// MODES FUNCTION PROTOTYPES
void standardArithmeticMode(); // 1
void advancedScientificMode(); // 2
void matrixMode();             // 3
void numberTheoryMode();       // 4
void complexMode();            // 5
void ProgrammerMode();         // 6

// UTILITY FUNCTIONS
//  A. Clears the console screen
void clearScreen()
{
#ifdef _WIN32
    system("cls"); // Windows command
#else
    system("clear"); // Linux/Mac command
#endif
}

// B. Pauses the screen so user can read the result
void pauseScreen()
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ;      // Clear input buffer
    getchar(); // Wait for Enter key
}

// PROTOTYPES OF FUNCTIONS USED INSIDE MODES (HELPER FNCS)

// For mode 2---> 5th switch
void quadSolver(float a, float b, float c);

// For mode 4---> 2nd switch
void fac_loops(int n);
int fac_recur(int n);

// For mode 4---> 3rd switch
int fib_recur(int n);
void fib_loops(int n);

// For mode 4---> 8th switch
//  void printDecimal(long long n);
void printDecimal();

// For mode 5
struct Complex
{
    float real;
    float imag;
};

struct Complex add(struct Complex n1, struct Complex n2);

struct Complex sub(struct Complex n1, struct Complex n2);

struct Complex multiply(struct Complex n1, struct Complex n2);

// For mode 6---> 7th switch
void printBinary(int n);

// For mode 6---> except 4, 7, 8th switch
void showFullResult(int result);

// MAIN FUNCTION
int main()
{
    int mainChoice;

    printf("\n-----Robust C-Calculator-----\n");
    printf("Developed by Mantasha\n");
    pauseScreen(); // Let intro be seen

    do
    {
        clearScreen(); // Clear before showing menu
        printf("\n=== MAIN MENU ===\n");
        printf("1. Standard Arithmetic (+, -, *, /)\n");
        printf("2. Advanced Scientific (Trig, Roots, Logs)\n");
        printf("3. Matrix Operations\n");
        printf("4. Number Theory\n");
        printf("5. Complex Number Mode\n");
        printf("6. Programmer Mode\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice)
        {
        case 1:
            standardArithmeticMode();
            break;

        case 2:
            advancedScientificMode();
            break;

        case 3:
            matrixMode();
            break;

        case 4:
            numberTheoryMode();
            break;

        case 5:
            complexMode();
            break;

        case 6:
            ProgrammerMode();
            break;

        case 0:
            printf("Exiting... Goodbye!\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            pauseScreen(); // Pause so that the error can be seen
        }

    } while (mainChoice != 0);
    return 0;
}

// MODES FUNCTION DEFINITION

// MODE 1 :
void standardArithmeticMode()
{
    int choice;
    float n1, n2;

    do
    {
        clearScreen();
        printf("\n--- STANDARD ARITHMETIC ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division (Decimal)\n");
        printf("5. Integer Division (Quotient & Remainder)\n");
        printf("0. Back to Main Menu\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            printf("Enter two numbers: ");
            scanf("%f %f", &n1, &n2);
        }

        switch (choice)
        {
        case 1:
            printf("Result: %.2f\n", n1 + n2);
            pauseScreen();
            break;
        case 2:
            printf("Result: %.2f\n", n1 - n2);
            pauseScreen();
            break;
        case 3:
            printf("Result: %.2f\n", n1 * n2);
            pauseScreen();
            break;
        case 4:
            if (n2 == 0)
                printf("Error: Div by Zero\n");
            else
                printf("Result: %.2f\n", n1 / n2);
            pauseScreen();
            break;

        case 5:
        {
            int i1, i2;
            printf("Enter two integers: ");
            scanf("%d %d", &i1, &i2);
            if (i2 == 0)
                printf("Error: Div by Zero\n");
            else
                printf("Quotient: %d, Remainder: %d\n", i1 / i2, i1 % i2);
            pauseScreen();
        }
        break;

        case 0:
            printf("Returning to main menu...\n");
            break;

        default:
            printf("Invalid choice\n");
            pauseScreen();
        }
    } while (choice != 0);
}

// MODE 2 :
void advancedScientificMode()
{
    int choice;
    float num;

    do
    {
        clearScreen();
        printf("\n--- ADVANCED SCIENTIFIC ---\n");
        printf("1. Roots (Square, Cube)\n");
        printf("2. Power (x^y)\n");
        printf("3. Trigonometry (Sin, Cos, Tan)\n");
        printf("4. Logarithms (log, ln)\n");
        printf("5. Quadratic Equation Solver\n");
        printf("6. Scientific Notation Converter\n");
        printf("0. Back to Main Menu\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%f", &num);
            printf("Sqrt: %.2f, Cbrt: %.2f\n", sqrt(num), cbrt(num));
            pauseScreen();
            break;

        case 2:
        {
            float base, exp;
            printf("Enter base : ");
            scanf("%f", &base);
            printf("Enter exponential : ");
            scanf("%f", &exp);
            printf("%.2f raised to %.2f is %.2f\n", base, exp, pow(base, exp));
            pauseScreen();
        }
        break;

        case 3:
        {
            int trigChoice;
            printf("1. Sin  2. Cos  3. Tan\nSelect: ");
            scanf("%d", &trigChoice);
            printf("Enter angle in Radians: ");
            scanf("%f", &num);

            if (trigChoice == 1)
                printf("Sin: %.2f\n", sin(num));
            else if (trigChoice == 2)
                printf("Cos: %.2f\n", cos(num));
            else if (trigChoice == 3)
                printf("Tan: %.2f\n", tan(num));
            pauseScreen();
        }
        break;

        case 4:
            printf("Enter number: ");
            scanf("%f", &num);
            printf("Log10: %.2f, Ln: %.2f\n", log10(num), log(num));
            pauseScreen();
            break;

        case 5:
        {
            float a, b, c;
            printf("In ax^2 + bx + c = 0, input a, b, c : ");
            scanf("%f %f %f", &a, &b, &c);
            quadSolver(a, b, c);
            pauseScreen();
        }
        break;

        case 6:
        {
            float num;
            printf("Enter a number to convert: ");
            scanf("%f", &num);
            printf("Standard:   %.4f\n", num);
            printf("Scientific: %e\n", num);
            printf("Clean View: %.2e\n", num);
            pauseScreen();
        }
        break;

        case 0:
            printf("Returning...\n");
            break;

        default:
            printf("Invalid choice\n");
            pauseScreen();
        }
    } while (choice != 0);
}

// MODE 3 :
void matrixMode()
{
    int matChoice;
    do
    {
        clearScreen();
        printf("\n--- MATRIX OPERATIONS ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Check if symmetric, skew-symmetric, none?\n");
        printf("6. Trace of matrix\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &matChoice);

        switch (matChoice)
        {
        case 1:
        {

            int rows, cols;
            int a[10][10], b[10][10], sum[10][10]; // Allowed up to 10x10 matrix
            int i, j;

            printf("You selected Matrix Addition.\n");

            printf("Enter number of rows: ");
            scanf("%d", &rows);
            printf("Enter number of columns: ");
            scanf("%d", &cols);

            // Input Matrix A
            printf("\n--- Enter Matrix A ---\n");
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    // "i+1" and "j+1" is just to show user "Row 1" instead of "Row 0"
                    printf("Enter element a[%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &a[i][j]);
                }
            }

            // Input Matrix B
            printf("\n--- Enter Matrix B ---\n");
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    printf("Enter element b[%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &b[i][j]);
                }
            }

            // The Logic: Adding
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    sum[i][j] = a[i][j] + b[i][j];
                }
            }

            // The Output:
            printf("\nSum of Matrices:\n");
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    printf("%d   ", sum[i][j]); // 3 spaces for gap
                }
                printf("\n"); // New line after finishing one row
            }
            pauseScreen();
        }
        break;

        case 2:
        {
            printf("You selected Matrix Subtraction.\n");

            int rows, cols;
            int a[10][10], b[10][10], diff[10][10];
            int i, j;

            printf("Enter number of rows: ");
            scanf("%d", &rows);
            printf("Enter number of columns: ");
            scanf("%d", &cols);

            // Input Matrix A
            printf("\n--- Enter Matrix A ---\n");
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {

                    printf("Enter element a[%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &a[i][j]);
                }
            }

            // Input Matrix B
            printf("\n--- Enter Matrix B ---\n");
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    printf("Enter element b[%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &b[i][j]);
                }
            }

            // The Logic: Subtracting
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    diff[i][j] = a[i][j] - b[i][j];
                }
            }

            // The Output:
            printf("\nDifference of Matrices:\n");
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    printf("%d   ", diff[i][j]);
                }
                printf("\n");
            }

            pauseScreen();
        }
        break;
        case 3:
        {

            int m, n, p, q, i, j, k;
            int A[10][10], B[10][10], C[10][10];
            printf("You selected Matrix Multiplication.\n");
            // INPUTS OF ROWS AND COLUMNS
            printf("Enter rows in matrix A: ");
            scanf("%d", &m);
            printf("Enter columns in matrix A: ");
            scanf("%d", &n);

            printf("Enter rows in matrix B: ");
            scanf("%d", &p);
            printf("Enter columns in matrix B: ");
            scanf("%d", &q);

            // CRITICAL: If dimensions don't match, we must STOP the program.
            if (n != p)
            {
                printf("Matrix multiplication cannot be performed (Cols of A != Rows of B).\n");
                pauseScreen();
                break; // Return to matrix menu
            }

            // TAKING INPUT OF ELEMENTS OF BOTH MATRICES
            // int A[m][n]; dont make vla
            printf("\n--- Enter Matrix A ---\n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf("A[%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &A[i][j]);
                }
            }

            // int B[p][q];
            printf("\n--- Enter Matrix B ---\n");
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < q; j++)
                {
                    printf("B[%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &B[i][j]);
                }
            }

            // --- CALCULATION ---
            // The result matrix will have 'm' rows and 'q' columns

            // int C[m][q];
            for (i = 0; i < m; i++)
            { // Rows of Result
                for (j = 0; j < q; j++)
                {                // Columns of Result
                    C[i][j] = 0; // Initialize to 0 before summing
                    for (k = 0; k < n; k++)
                    { // Common dimension (Cols of A / Rows of B)
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            // PRINTING RESULT
            printf("\nResult of A * B:\n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < q; j++)
                {
                    printf("%d   ", C[i][j]);
                }
                printf("\n");
            }

            pauseScreen();
        }
        break;
        case 4:
        {

            int rows, cols;
            int a[10][10], b[10][10];
            int i, j, m, n;
            printf("You selected Transpose.\n");

            printf("Enter number of rows: ");
            scanf("%d", &rows);
            printf("Enter number of columns: ");
            scanf("%d", &cols);

            // Input Matrix
            printf("\n--- Enter Matrix ---\n");
            for (i = 0; i < rows; i++) // i < 3
            {
                for (j = 0; j < cols; j++) // j < 2
                {
                    printf("Enter element a[%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &a[i][j]);
                }
            }
            // Transpose of matrix
            printf("Transpose matrix is : \n");
            for (m = 0; m < cols; m++) // m < 2
            {
                for (n = 0; n < rows; n++) // n < 3
                {
                    b[m][n] = a[n][m];
                    printf("%d   ", b[m][n]);
                }
                printf("\n");
            }
            pauseScreen();
        }
        break;
        case 5:
        {
            int i, j, rows, cols;

            int isSymmetric = 1;
            int isSkew = 1;

            int a[10][10];

            printf("You selected \"Check if symmetric, skew-symmetric, none?\"\n");

            printf("Enter number of rows: ");
            scanf("%d", &rows);
            printf("Enter number of columns: ");
            scanf("%d", &cols);

            if (rows != cols)
                printf("Non-square matrix cannot be symmetric or skew-symmetric");

            else
            {
                // 1. I/P MATRIX
                printf("\n--- Enter Matrix A ---\n");
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < cols; j++)
                    {

                        printf("Enter element a[%d][%d]: ", i + 1, j + 1);
                        scanf("%d", &a[i][j]);
                    }
                }

                // 2. LOGIC CHECK (Needs its own loop)
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < cols; j++)
                    {
                        // Check Symmetry
                        if (a[i][j] != a[j][i])
                        {
                            isSymmetric = 0;
                        }

                        // Check Skew-Symmetry
                        // Note: This one check covers both the diagonal being 0
                        // and the mirroring (Because if x = -x, then x must be 0)
                        if (a[i][j] != -1 * a[j][i])
                        {
                            isSkew = 0;
                        }
                    }
                }

                // 3. GIVING FINAL VERDICT
                if (isSymmetric == 1)
                    printf("Matrix is symmetric");

                else if (isSkew == 1)
                    printf("Matrix is skew-symmetric");

                else
                    printf("Matrix is neither symmetric nor skew-symmetric");
            }
            pauseScreen();
        }
        break;
        case 6:
        {
            int A[10][10], sum = 0, rows, cols, i, j;
            printf("You selected Trace of Matrix.\n");

            printf("Enter number of rows: ");
            scanf("%d", &rows);
            printf("Enter number of columns: ");
            scanf("%d", &cols);

            if (rows != cols)
                printf("Trace can't be found of a non-square matrix!");

            else
            {
                // Input Matrix A
                printf("\n--- Enter Matrix A ---\n");
                for (i = 0; i < rows; i++) // i < 3
                {
                    for (j = 0; j < cols; j++) // j < 2
                    {
                        printf("Enter element a[%d][%d]: ", i + 1, j + 1);
                        scanf("%d", &A[i][j]);
                    }
                }

                // for(i = 0; i < rows; i++)
                // {
                //     for(j = 0; j < cols; j++)
                //     {
                //         if(i == j)
                //         {
                //         sum = sum + A[i][j];
                //         }
                //     }
                // }

                // Instead of checking every single number...
                // Just jump straight to the diagonal numbers
                for (i = 0; i < rows; i++)
                {
                    sum = sum + A[i][i]; // Add A[0][0], then A[1][1], then A[2][2]...
                }
                printf("Trace of matrix is %d", sum);
            }
            pauseScreen();
        }
        break;
        case 0:
            printf("Returning to Main Menu...\n");
            break;
        default:
            printf("Invalid choice.\n");
            pauseScreen();
        }
    } while (matChoice != 0);
}

// MODE 4 :
void numberTheoryMode()
{
    int num1, num2, result;
    int numth;
    do
    {
        clearScreen();
        printf("\n--- NUMBER THEORY MODE ---\n");
        printf("1. Check Primes\n");
        printf("2. Factorial\n");
        printf("3. Fibonacci Series\n");
        printf("4. Check Armstrong Number\n");
        printf("5. LCM & HCF(GCD)\n");
        printf("6. Table Printer\n");
        printf("7. Check Odd/ Even\n");
        printf("8. All divisors of a number\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &numth);

        switch (numth)
        {
        case 1:
        {
            int isPrime, i;
            printf("You selected Check Primes.\n");
            printf("Enter the number : ");
            scanf("%d", &num1);
            isPrime = 1; // set flag
            for (i = 2; i <= sqrt(num1); i++)
            {
                if (num1 % i == 0)
                {
                    isPrime = 0;
                }
            }
            if (isPrime)
                printf("%d is prime", num1);

            else
                printf("%d is not prime", num1);
            pauseScreen();
        }
        break;
        case 2:
            printf("You selected Factorial.\n");
            printf("Enter a number : ");
            scanf("%d", &num1);
            // fac_loops(num1);

            if (num1 < 0)
            {
                printf("Factorial of negative number doesn't exist.\n");
            }
            else
            {
                printf("Factorial of %d is %d\n", num1, fac_recur(num1));
            }

            pauseScreen();
            break;

        case 3:
            printf("You selected Fibonacci Series.\n");
            printf("Enter number of terms : ");
            scanf("%d", &num1);

            // series given by recursion: // For greater number of terms---> recursive method can be slow
            //  for(int i = 0 ; i < num1; i++)
            //  {
            //      printf("%d ",fib_recur(i));
            //  }

            fib_loops(num1);
            pauseScreen();
            break;
        case 4:
        {
            int temp, numDigits = 0, digit, t;
            double sum = 0;
            // since pow( , ) returns floating pt./double ; so sum after calculation can be something like 153.0001.....at last directly don't compare with temp(eg. 153)... you have to typecast sum and then compare with temp

            // temp ---> for storing original num1
            //  numDigits---> to count no. of digits in num1
            // digit---> to store digit rcvd by modular division
            //  t---> counter for no. of digits loop & digit loop
            printf("You selected Check Armstrong Number.\n");
            printf("Enter number : ");
            scanf("%d", &num1);

            temp = num1;

            // no. of digits loop
            for (t = num1; t > 0; t = t / 10)
            {
                numDigits++;
            }

            // digit loop
            for (t = num1; t > 0; t = t / 10)
            {
                digit = t % 10;
                sum = sum + pow(digit, numDigits);
            }

            if ((int)sum == temp)
                printf("%d is an Armstrong number\n", temp);

            else
                printf("%d is not an Armstrong number\n", temp);
        }
            pauseScreen();
            break;
        case 5:
        {
            printf("You selected LCM & HCF(GCD).\n");

            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);

            // 1. BACKUP the original numbers
            int og1 = num1;
            int og2 = num2;
            int gcd, lcm;

            // 2. GCD Logic (Euclidean Algorithm)
            int temp;
            while (num2 != 0)
            {
                temp = num1 % num2;
                num1 = num2;
                num2 = temp;
            }
            gcd = num1; // The HCF is stored in num1 after the loop

            // 3. LCM Formula logic
            // LCM = (Original A * Original B) / GCD
            lcm = (og1 * og2) / gcd;

            printf("HCF (GCD) = %d\n", gcd);
            printf("LCM = %d\n", lcm);
        }

            // if u need to find just the lcm without finding hcf----> ITERATIVE/ BRUTE FORCE METHOD
            //     {
            //         printf("Enter two numbers: ");
            //     scanf("%d %d", &num1, &num2);

            //     int max;

            //     // 1. Find the step size (the larger number)
            //     // If num1 is bigger, step is num1. If num2 is bigger, step is num2.
            //     int step = (num1 > num2) ? num1 : num2;

            //     // 2. Start checking from the largest number
            //     max = step;

            //     while(1)
            //     {
            //         // We only need to check if 'max' is divisible by the SMALLER number
            //         // because we already know it is divisible by the 'step' (larger number).
            //         if(max % num1 == 0 && max % num2 == 0)
            //         {
            //             printf("LCM is %d", max);
            //             break;
            //         }

            //         // IMPROVEMENT: Jump by the step size, not by 1
            //         max = max + step;
            //          }
            // }
            pauseScreen();
            break;
        case 6:
            printf("You selected Table Printer.\n");
            printf("Enter the number of which you want table of : ");
            scanf("%d", &num1);

            for (int i = 1; i <= 10; i++)
            {
                printf("%d X %d = %d \n", num1, i, num1 * i);
            }

            pauseScreen();
            break;

        case 7:
            printf("You selected Check Odd/ Even\n");
            printf("Enter the number : ");
            scanf("%d", &num1);

            if (num1 % 2 == 0)
                printf("%d is Even\n", num1);

            else
                printf("%d is odd\n", num1);
            pauseScreen();
            break;

        case 8:
            printf("You selected \"All divisors of a number\" \n");
            printf("Enter the number : ");
            scanf("%d", &num1);
            for (int i = 1; i <= num1; i++)
            {
                if (num1 % i == 0)
                {
                    printf("%d ", i);
                }
            }
            pauseScreen();
            break;

        case 0:
            printf("Returning to Main Menu...\n");
            break;
        default:
            printf("Invalid choice.\n");
            pauseScreen();
        }

    } while (numth != 0);
}

// MODE 5:
void complexMode()
{
    int compChoice;
    do
    {
        struct Complex num1, num2, result;
        clearScreen();
        printf("\n--- COMPLEX MODE ---\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &compChoice);

        if (compChoice >= 1 && compChoice <= 3)
        {
            printf("Enter num1 real part: ");
            scanf("%f", &num1.real);

            printf("Enter num1 imag part: ");
            scanf("%f", &num1.imag);

            printf("Enter num2 real part: ");
            scanf("%f", &num2.real);

            printf("Enter num2 imag part: ");
            scanf("%f", &num2.imag);
        }
        switch (compChoice)
        {
        case 1:
            printf("You selected Addition.\n");
            // ACCESS the function
            result = add(num1, num2);
            // PRINT the result
            printf("(%.1f + %.1fi) + (%.1f + %.1fi) = %.1f + %.1fi", num1.real, num1.imag, num2.real, num2.imag, result.real, result.imag);
            pauseScreen();
            break;
        case 2:
            printf("You selected Subtraction.\n");
            result = sub(num1, num2);
            printf("(%.1f + %.1fi) - (%.1f + %.1fi) = %.1f + %.1fi", num1.real, num1.imag, num2.real, num2.imag, result.real, result.imag);
            pauseScreen();
            break;
        case 3:
            printf("You selected Multiplication.\n");
            result = multiply(num1, num2);
            printf("(%.1f = %.1fi) * (%.1f = %.1fi) = %.1f + %.1fi", num1.real, num1.imag, num2.real, num2.imag, result.real, result.imag);
            pauseScreen();
            break;
        case 0:
            printf("Returning to Main Menu...\n");
            break;
        default:
            printf("Invalid choice.\n");
            pauseScreen();
        }

    } while (compChoice != 0);
}

// MODE 6:
void ProgrammerMode()
{
    int num1, num2, result;

    int progChoice;
    do
    {
        clearScreen();
        printf("\n--- PROGRAMMER MODE ---\n");
        printf("1. AND\n");
        printf("2. OR\n");
        printf("3. XOR\n");
        printf("4. NOT\n");
        printf("5. Left shift\n");
        printf("6. Right shift\n");
        printf("7. decimal ----> binary\n");
        printf("8. binary----> decimal\n");

        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &progChoice);

        switch (progChoice)
        {
        case 1:
            printf("You selected AND.\n");
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 & num2;
            showFullResult(result);
            pauseScreen();
            break;
        case 2:
            printf("You selected OR.\n");
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 | num2;
            showFullResult(result);
            pauseScreen();
            break;
        case 3:
            printf("You selected XOR.\n");
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 ^ num2;
            showFullResult(result);
            pauseScreen();
            break;
        case 4:
            printf("You selected NOT.\n");
            printf("Enter a number: ");
            scanf("%d", &num1);
            result = ~num1;
            // Note: Binary print might look weird for negative numbers
            // because of our simple printBinary function, but Decimal/Hex will be correct.
            printf("Decimal: %d\n", result);

            printf("Hex:     0x%X\n", result);
            pauseScreen();
            break;
        case 5:
            printf("You selected Left-shift.\n");
            printf("Enter number and shift amount: ");
            scanf("%d %d", &num1, &num2);
            result = num1 << num2;
            showFullResult(result);
            pauseScreen();
            break;
        case 6:
            printf("You selected Right-shift.\n");
            printf("Enter number and shift amount: ");
            scanf("%d %d", &num1, &num2);
            result = num1 >> num2;
            showFullResult(result);
            pauseScreen();
            break;
        case 7:
            printf("You selected decimal ----> binary.\n");
            printf("Enter number in decimal : ");
            scanf("%d", &num1);
            printBinary(num1);
            pauseScreen();
            break;

        case 8:
            printf("You selected binary----> decimal.\n");
            // printf("Enter number in binary : ");
            // scanf("%lld", &num1);
            // printDecimal(num1);
            printDecimal();
            pauseScreen();
            break;

        case 0:
            printf("Returning to Main Menu...\n");
            break;
        default:
            printf("Invalid choice.\n");
            pauseScreen();
        }

    } while (progChoice != 0);
}

// DEFINITION OF HELPER TO MODE FNCS

// For mode 2---> 5th switch
void quadSolver(float a, float b, float c)
{
    float discriminant, root1, root2;
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different.\n");
        printf("x1 = %.2f\n", root1);
        printf("x2 = %.2f\n", root2);
    }
    else if (discriminant == 0)
    {
        root1 = -b / (2 * a);
        printf("Roots are real and same.\n");
        printf("x1 = x2 = %.2f\n", root1);
    }
    else
    {
        float realPart = -b / (2 * a);
        float imagPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex.\n");
        printf("x1 = %.2f + %.2fi\n", realPart, imagPart);
        printf("x2 = %.2f - %.2fi\n", realPart, imagPart);
    }
}

// For mode 4---> 2nd switch
void fac_loops(int n)
{
    int mult = 1, i = 1;
    if (n < 0)
        printf("Factorial of a negetive number doesn't exits");

    else if (n == 0)
        printf("Factorial of 0 is 1");

    else
    {
        while (i <= n)
        {
            mult = mult * i;
            i++;
        }
        printf("Factorial of %d is %d", n, mult);
    }
}

int fac_recur(int n)
{

    if (n == 1 || n == 0)
        return 1;

    else
        return n * fac_recur(n - 1);
}

// For mode 4---> 3rd switch
int fib_recur(int n)
{
    if (n == 0 || n == 1)
        return n;

    else
        return fib_recur(n - 1) + fib_recur(n - 2);
}

void fib_loops(int n)
{
    int i = 0;
    int f3;
    int f1 = 0;
    int f2 = 1;

    // printf("%d ", f1);
    // printf("%d ", f2);
    printf("%d ", f1);
    if (n > 1)
    { // Only print the second number if user asked for more than 1
        printf("%d ", f2);
    }

    while (i < n - 2)
    {
        f3 = f1 + f2;
        printf("%d ", f3);

        f1 = f2;
        f2 = f3;
        i++;
    }
}

// For mode 4---> 8th switch
// bin ----> deci
// void printDecimal(long long n) // WITHOUT ARRAYS
void printDecimal()
{
    int decimal_sum = 0;
    int base = 1;

    // while (n > 0)
    // {
    //     int last_digit = n % 10;
    //     decimal_sum += last_digit * base;
    //     n = n / 10;
    //     base = base * 2;
    // }

    // printf("Decimal : %d", decimal_sum);

    // WITH ARRAYS
    int decimalNum[32];
    int n, i;

    printf("Enter the no. of digits in your binary number : ");
    scanf("%d", &n);

    // printf("Enter number in binary one by one (pressing enter key/ space-bar each time you type a digit) : ");
    printf("Enter binary digits separated by space (e.g., 1 0 1 1): ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &decimalNum[i]);
    }

    printf("\n");

    for (int j = (i - 1); j >= 0; j--)
    {
        decimal_sum += decimalNum[j] * base;
        base = base * 2;
    }

    printf("Decimal : %d", decimal_sum);
}

// For mode 5
struct Complex add(struct Complex n1, struct Complex n2)
{
    struct Complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return temp;
}

struct Complex sub(struct Complex n1, struct Complex n2)
{
    struct Complex temp;
    temp.real = n1.real - n2.real;
    temp.imag = n1.imag - n2.imag;
    return temp;
}

struct Complex multiply(struct Complex n1, struct Complex n2)
{
    struct Complex temp;
    // Formula: real = (ac - bd)
    temp.real = (n1.real * n2.real) - (n1.imag * n2.imag);
    // Formula: imag = (ad + bc)
    temp.imag = (n1.real * n2.imag) + (n1.imag * n2.real);
    return temp;
}

// For mode 6---> 7th switch
// deci----> bin
void printBinary(int n)
{
    if (n == 0)
    {
        printf("Binary : 0");
        return;
    }

    // Handle negative numbers for bitwise NOT using a simple mask (advanced but safe)
    // For now, let's assume "positive inputs" for simplicity or standard ints

    // Handle negative visualization simply for now
    if (n < 0)
    {
        printf("-");
        n = -n;
    }

    int binaryNum[32];
    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Binary : ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// For mode 6---> except 4, 7, 8th switch
// Helper to show results in all formats
void showFullResult(int result)
{
    printf("\n--- Results ---\n");

    printf("Decimal: %d\n", result);

    printf("Hex:     0x%X\n", result); // 0x is the standard prefix for Hex

    printf("Binary:  ");
    printBinary(result);

    printf("\n----------------\n");
}
