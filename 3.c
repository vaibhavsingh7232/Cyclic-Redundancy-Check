#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DATA_LENGTH 1024 // Maximum length for user input data

// Function to perform CRC encoding
unsigned int calculate_crc(const unsigned int *data, int data_len, unsigned int polynomial, int poly_length) {
    unsigned int crc = 0;
    int i, j;

    // Iterate over each bit of the data
    for (i = 0; i < data_len; i++) {
        crc ^= (data[i] << (poly_length - 1)); // Align the bit to the MSB
        // Perform the polynomial division
        for (j = 0; j < 8; j++) {
            if (crc & (1 << (poly_length + 7 - 1))) { // If the MSB is 1
                crc = (crc << 1) ^ polynomial; // Shift and XOR with polynomial
            } else {
                crc <<= 1; // Just shift left
            }
        }
    }

    return crc & ((1 << poly_length) - 1); // Mask the CRC to fit the polynomial length
}

// Function to print CRC in binary format
void print_crc(unsigned int crc, int poly_length) {
    for (int i = poly_length - 1; i >= 0; i--) {
        printf("%d", (crc >> i) & 1);
    }
    printf("\n");
}

int main() {
    char data[MAX_DATA_LENGTH];
    char polynomial_str[10];
    unsigned int polynomial;
    int poly_length;

    printf("Enter data (binary string): ");
    scanf("%s", data);
    int data_len = strlen(data);

    printf("Enter polynomial (binary string): ");
    scanf("%s", polynomial_str);
    poly_length = strlen(polynomial_str);

    // Convert polynomial binary string to integer
    polynomial = 0;
    for (int i = 0; i < poly_length; i++) {
        polynomial = (polynomial << 1) | (polynomial_str[i] - '0');
    }

    // Convert the binary string data to an integer array
    unsigned int data_int = 0;
    for (int i = 0; i < data_len; i++) {
        data_int = (data_int << 1) | (data[i] - '0');
    }

    unsigned int crc = calculate_crc(&data_int, data_len, polynomial, poly_length);

    // Append CRC to data for transmission
    unsigned int transmitted_data = (data_int << poly_length) | crc;

    printf("Original Data: %s\n", data);
    printf("Polynomial: %s\n", polynomial_str);
    printf("CRC: ");
    print_crc(crc, poly_length);

    // Now check for errors (in a real scenario, this would be done by the receiver)
    unsigned int received_crc = transmitted_data & ((1 << poly_length) - 1);
    unsigned int received_data = transmitted_data >> poly_length;

    unsigned int calculated_crc = calculate_crc(&received_data, data_len, polynomial, poly_length);
    if (received_crc != calculated_crc) {
        printf("Error found: CRC does not match\n");
    } else {
        printf("No error detected: Data is correct\n");
    }

    return 0;
}
