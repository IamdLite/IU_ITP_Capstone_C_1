# IU_ITP_Capstone_C_1

# A. based sum

time limit per test1 second
memory limit per test256 megabytes
inputinput.txt
outputoutput.txt

You will be given an integer N
 representing the amount of numbers you will need to process. A string S
 consisting of space-separated numbers of the following bases: binary, octal, decimal and, hexadecimal. An array A
 consisting of the bases of each number in S
 which will be represented in the input in the following decimal values [2, 8, 10, 16].

Your task is to perform the following arithmetic operations on the numbers in S
:

Increase each odd-indexed number by 10 in decimal format.
Decrease each even-indexed number by 10 in decimal format.
Finally, output the sum of the resulting numbers in decimal.

For example, given the following input:

N
 = 4
S
 = 100101 1EF 274 2024
A
 = 2 16 8 10
The decimal representation of the numbers will be the following:

binary(100101) →
 decimal(37)
hexadecimal(1EF) →
 decimal(495)
octal(274) →
 decimal(188)
decimal(2024) →
 decimal(2024)
To do the arithmetic operations we will need to add 10 to odd-indexed elements and subtract 10 from even-indexed elements:

index(0) = 37 →
 37 - 10 = 27
index(1) = 495 →
 495 + 10 = 505
index(2) = 188 →
 188 - 10 = 178
index(3) = 2024 →
 2024 + 10 = 2034
After that, we calculate the sum of the results and output it: 27 + 505 + 178 + 2034 = 2744

Furthermore, you have to verify that the input is correct, and if not you have to output "Invalid inputs".

You should expect testcases that do not conform to the input restriction explained below in the input format section, and you have to handle these testcases by verifying that the input is correct, and if not you have to output "Invalid inputs".

An example of invalid inputs:

N
 = 2
S
 = 2059 8163
A
 = 16 8
because the first digit in "8163" does not exist in the octal system (octal digits: [0, 1, 2, 3, 4, 5, 6, 7]).
Input
input.txt:

First line: an integer N
 (1 ≤ N
 ≤ 40).
Second line: a string S
 consisting of N
 space-separated positive numbers where each number consists of at most 6 digits from the following set of digits [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F].
Third line: an array A
 consisting of N
 elements where (A[i]
 ∈
 [2, 8, 10, 16]; 0 ≤ i
 < N
).
Output
The output should be written to output.txt and should contain the following:

First line: an integer representing the decimal form of the sum of all numbers after performing the mentioned arithmetic operations or "Invalid inputs".
Examples
InputCopy
2
2059 8163
16 8
OutputCopy
Invalid inputs
InputCopy
4
100101 1EF 274 2024
2 16 8 10
OutputCopy
2744
Note
Remember that array indexing starts from 0
You need to print a newline character "\n" after your output. E.g: if the solution is "Invalid inputs" then you should print "Invalid inputs\n".
You will be reading and writing from files, not standard input/output.
binary digits: [0, 1]
octal digits: [0, 1, 2, 3, 4, 5, 6, 7]
decimal digits: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
hexadecimal digits: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F]

