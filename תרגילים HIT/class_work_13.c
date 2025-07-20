#include <stdio.h>

unsigned int rotateLeft(unsigned int num, int n);
unsigned int rotateRight(unsigned int num, int n);
void printBinary(unsigned int num);

int main() {

    unsigned int num;
    int n;

    printf("please enter an integer: \n");
    scanf("%u", &num);
    printf("Please enter the number of bits to shift: \n");
    scanf("%d", &n);

    printf("Original number in binary: ");
    printBinary(num);

    unsigned int leftResult = rotateLeft(num, n);
    printf("The left bitwise result is: %u \n", leftResult);
    printf("Left rotation result in binary: ");
    printBinary(leftResult);

    unsigned int rightResult = rotateRight(num, n);
    printf("The right bitwise result is: %u \n", rightResult);
    printf("Right rotation result in binary: ");
    printBinary(rightResult);

    return 0;
}

unsigned int rotateLeft(unsigned int num, int n) {

    // Calculate the number of bits in an unsigned int
    unsigned int bitCount = sizeof(unsigned int) * 8;
    // Perform left shift by n bits
    unsigned int left = num << n;
    // Retrieve the bits that were shifted out on the left by shifting right
    unsigned int wrapped = num >> (bitCount - n);
    // Combine the two parts to complete the circular left shift
    return left | wrapped;
}

unsigned int rotateRight(unsigned int num, int n) {

    // Calculate the number of bits in an unsigned int
    unsigned int bitCount = sizeof(unsigned int) * 8;
    // Perform right shift by n bits
    unsigned int right = num >> n;
    // Retrieve the bits that were shifted out on the left by shifting right
    unsigned int wrapped = num << (bitCount - n);
    // Combine the two parts to complete the circular left shift
    return right | wrapped;
}

// Function to print a 32-bit unsigned int in binary
void printBinary(unsigned int num) {
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // Optional spacing every byte
    }
    printf("\n");
}