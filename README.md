# IU_ITP_Capstone_C_1

## A. Based Sum

### Problem Statement

You will be given:

1. An integer `N` representing the number of numbers to process.
2. A string `S` consisting of space-separated numbers in the following bases: binary, octal, decimal, and hexadecimal.
3. An array `A` consisting of the bases of each number in `S`, represented as `[2, 8, 10, 16]` in decimal.

Your task is to:
1. **Increase** each odd-indexed number by 10 in decimal format.
2. **Decrease** each even-indexed number by 10 in decimal format.
3. Output the **sum** of the resulting numbers in decimal.

If the input is invalid, output `"Invalid inputs"`.

---

### Input

The input will be read from `input.txt`:
- **First Line**: An integer `N` where \( 1 \leq N \leq 40 \).
- **Second Line**: A string `S` consisting of `N` space-separated positive numbers, where each number consists of at most 6 digits from `[0-9, A-F]`.
- **Third Line**: An array `A` of size `N`, where \( A[i] \in \{ 2, 8, 10, 16 \} \) for \( 0 \leq i < N \).

---

### Output

The output should be written to `output.txt`:
- A single integer representing the decimal sum of all numbers after performing the arithmetic operations.
- If the input is invalid, output `"Invalid inputs"`.

Add a newline character (`\n`) after the output.

---

### Rules for Validation

1. Ensure all numbers in `S` are valid in their respective bases as defined in `A`.
2. If any number in `S` is invalid according to its base, output `"Invalid inputs"`.

---

### Examples

#### Example 1: Invalid Input

**Input (`input.txt`)**:

**Output (`output.txt`)**:


**Explanation**: The number `8163` contains the digit `8`, which is not valid in the octal system.

---

#### Example 2: Valid Input

**Input (`input.txt`)**:

**Output (`output.txt`)**:

**Explanation**:
1. Convert the numbers in `S` to decimal:
   - Binary `100101` → Decimal `37`
   - Hexadecimal `1EF` → Decimal `495`
   - Octal `274` → Decimal `188`
   - Decimal `2024` → Decimal `2024`
2. Perform arithmetic operations:
   - Index 0: \( 37 - 10 = 27 \)
   - Index 1: \( 495 + 10 = 505 \)
   - Index 2: \( 188 - 10 = 178 \)
   - Index 3: \( 2024 + 10 = 2034 \)
3. Sum the results: \( 27 + 505 + 178 + 2034 = 2744 \).

---

### Notes

1. **Valid Digits**:
   - **Binary digits**: `[0, 1]`
   - **Octal digits**: `[0, 1, 2, 3, 4, 5, 6, 7]`
   - **Decimal digits**: `[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`
   - **Hexadecimal digits**: `[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F]`
2. Remember to handle invalid inputs gracefully.
3. Array indexing starts from 0.

---

### Implementation Guidelines

1. **Reading Input**:
   - Read `N`, `S`, and `A` from `input.txt`.
   - Validate that the inputs conform to the constraints.

2. **Conversion to Decimal**:
   - Convert each number in `S` to decimal using its respective base from `A`.

3. **Arithmetic Operations**:
   - Add 10 to the decimal representation of numbers at odd indices.
   - Subtract 10 from the decimal representation of numbers at even indices.

4. **Validation**:
   - Ensure that each number in `S` conforms to its base.
   - If any number is invalid, output `"Invalid inputs"`.

5. **Output**:
   - Write the result to `output.txt` followed by a newline.

6. **Edge Cases**:
   - Inputs where `S` contains invalid numbers for the given base.
   - Minimal values for `N` (e.g., \( N = 1 \)).
   - Inputs with mixed valid and invalid numbers.

---

### Additional Notes

- The output should strictly adhere to the format, including a newline character at the end.
- For invalid inputs, stop further processing and immediately output `"Invalid inputs\n"`.
