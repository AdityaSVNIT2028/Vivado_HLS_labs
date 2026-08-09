void divide(unsigned char N, unsigned char D, unsigned char *Q, unsigned char *R){
    // Input is N (Dividend) and D (Divisor)
    // Q (Quotient) and R (Remainder) are the outputs

    // Check if D is not zero to prevent division by zero
    if (D != 0) {

        // Initialize Q and R outputs
        *Q = 0;
        *R = 0;

        // Loop 8 times, counting down from MSB (7) to LSB (0)
        for (int i = 7; i >= 0; i--) {
            // Shift remainder left by 1 to make room for the next bit
            *R = *R << 1;

            // Isolate the i-th bit of N and place it in the LSB position (0 or 1)
            unsigned char iBitN = (N >> i) & 1;

            // Insert the extracted bit into the LSB of the remainder
            *R = *R | iBitN;

            // If the current remainder is greater than or equal to the divisor
            if (*R >= D) {
                *R = *R - D;         // Subtract the divisor from the remainder
                *Q |= (1 << i);      // Set the i-th bit of the quotient to 1
            }
        }
    }
}
