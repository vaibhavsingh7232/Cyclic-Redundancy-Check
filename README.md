CRC (Cyclic Redundancy Check) — Error Detection in C

This project implements Cyclic Redundancy Check (CRC), an error-detecting technique widely used in Computer Networks and Digital Communication.
The program accepts binary input data, a generator polynomial, computes the CRC checksum, appends it to the original data for transmission, and then verifies the received data for errors.

📌 What is CRC?

CRC is used to detect accidental changes in transmitted data.
Before transmission, a checksum (CRC bits) is calculated using a polynomial division algorithm and appended to the data.
The receiver recalculates the CRC and compares it:

Result	Meaning
CRC matches	No error in transmission
CRC mismatch	Data corrupted
🧠 Program Capabilities

✔ Accepts input data as binary string
✔ Accepts polynomial as binary string (e.g., 1101)
✔ Calculates CRC checksum using bitwise polynomial division
✔ Appends CRC to original data to form a transmittable frame
✔ Simulates receiver-side CRC verification
✔ Detects whether the transmitted data is error-free or corrupted

🧰 Technologies Used
Component	Description
Language	C
Concepts	Data Link Layer, CRC, Polynomial Division, Error Detection
🚀 How to Run the Program
🔹 Compile
gcc crc.c -o crc

🔹 Run
./crc

📌 Sample Output
Enter data (binary string): 110101101
Enter polynomial (binary string): 10011

Original Data: 110101101
Polynomial: 10011
CRC: 0101
No error detected: Data is correct

📂 Code Structure
Function	Purpose
calculate_crc()	Performs polynomial division + returns CRC
print_crc()	Displays CRC bits in binary format
main()	Handles user input, CRC generation, and CRC verification
🔎 Example Explanation
Data:      110101101
Polynomial: 10011
CRC:       0101
Transmitted Frame = Data + CRC = 1101011010101


At the receiver end:

CRC is recalculated

If the result = 0 → no transmission error

Otherwise → error detected

⭐ Learning Outcomes

By using this program, students gain clarity on:

🔹 CRC encoding and decoding
🔹 Polynomial representation in binary
🔹 Bitwise shift and XOR operations
🔹 Frame transmission and error-checking workflow in networks
