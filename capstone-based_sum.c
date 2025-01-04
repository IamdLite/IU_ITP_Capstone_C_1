#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/* Function declaration */
bool is_digit_valid(char current_char, int base, int N);  //validates input authenticity, length and base correspondance
int convert_to_integers(const char *number_str, int base, int N); //custom function to convert any base to base 10
int compute_sum(double decimal_numbers[], int N); //custom function to convert any base to base 10
void output_result(int res, bool success);  //output result to file

/* Function Definitions */
bool is_digit_valid(char current_char, int base, int N) {
    if (N >40 || N<1) return false;

    if (!(base == 2 || base == 8 || base == 10 || base == 16)) return false; //validate the base
    int value;
    if (current_char >= '0' && current_char <= '9') {
        value = current_char - '0';  // Convert '0'-'9' to corresponding integer
    } else if (current_char >= 'A' && current_char <= 'F') {
        value = current_char - 'A' + 10;  // Convert 'A'-'F' to 10-15
    } else if (current_char >= 'a' && current_char <= 'f') {
        return false;
    } else {
        return false;  // Invalid character
    }
    return value < base;  // Check if value is valid for the base
}

void output_result(int res, bool success) {
    FILE *output;
    if (!(output = fopen("output.txt", "w"))) {
        exit(EXIT_FAILURE); //handle exceptions
    }
    if (!success) {
        fprintf(output, "Invalid inputs\n"); //meaning either N, numbers oor bases had an invalid entry
    } else {
        fprintf(output, "%d\n", res); //all good, output results to output.txt
    }
    fclose(output);
}

int convert_to_integers(const char *number_str, int base, int N) {
    int result = 0;
    char count;
    char current_char;
    

    while ((current_char = *number_str++) != '\0') {
        if (!is_digit_valid(current_char, base, N)) {
            return -1;  // Invalid character in number for the given base
        }

        int digit_value;
        if (current_char >= '0' && current_char <= '9') {
            digit_value = current_char - '0'; 
        } else {
            digit_value = toupper(current_char) - 'A' + 10;  // Convert letters to digits
        }
        result = result * base + digit_value; //generalized formula to convert to base 10 (meaning code is scalable)
    }
    return result;
}

int compute_sum(double decimal_numbers[], int N) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            decimal_numbers[i] -= 10; //subtracting 10 from values in even indices
        } else {
            decimal_numbers[i] += 10; //adding 10 to values odd indices
        }
        sum += decimal_numbers[i];
    }
    return (int)sum;
}

int main() {

    bool success = true; //this variable tracks if anything would go wrong


    FILE *input;
    if (!(input = fopen("input.txt", "r"))) {
        exit(EXIT_FAILURE);
    }

    int N;
    fscanf(input, "%d", &N);  // Pass the address of N (N is number of numbers and number of bases) - see function defintions
    

    char **numbers = malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        numbers[i] = malloc(100 * sizeof(char));  // Allocate memory for each string (dynamically to avoid buffer overflows)
        fscanf(input, "%s", numbers[i]);
         if(strlen(numbers[i]) > 6 || strlen(numbers[i]) < 1){
            success = false;
            break;
        }
    }

    int *bases = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        fscanf(input, "%d", &bases[i]);  // Pass the address of bases[i]

    }

    // Ensuring the number of bases are iin the range 1 and N (inclusive)
    int count;

    for(int i= 0; i<N; i++){
        if (bases[i]!= '\0' ){
            count++;
        } else {
            break;
        }
    }
    if(count > N || count < 1) success = false; //Meaning the number of bases where out of range
     

/* Input Processing */

    double *converted_numbers = malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {   
        int converted = convert_to_integers(numbers[i], (int)bases[i], N);
        if ((converted == -1)) { //checking if the conversion was successfull (if the numbers matched their base and where in the required range)
            success = false;
            break;
        }
        converted_numbers[i] = converted; //all good! storing results in array
    }

    if (!success) {  // checking if any of the previously called funtions changed the success value to false
        output_result(0, false);
    } else {
        double sum = compute_sum(converted_numbers, N);
        output_result((int)sum, true);
    }

    for (int i = 0; i < N; i++) {
        free(numbers[i]);  // Free allocated memory for each string
    }
    free(numbers);  // Free the array of pointers to avoid memory leaks
    free(bases);
    free(converted_numbers);
    fclose(input);

    return 0;
}
