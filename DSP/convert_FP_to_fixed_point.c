


https://schaumont.dyn.wpi.edu/ece4703b20/lecture6.html

Conversion from Floating Point to Fixed Point

N-bit fixed-point numbers can be conveniently represented as N-bit integers, and in a C program we will use integer data types (int, unsigned) to store fixed-point numbers. A floating-point number is converted to a fixed-point number by proper scaling and conversion to an integer data type.

To convert a floating point number to fixed point, we first scale it by 2^k up so that the least significant fractional bit gets unit weight. 
  This conversion can lead to precision loss (at the LSB side) and overflow (at the MSB side). 
  The following program illustrates the conversion to a fix<8,6> datatype.
  
 #include <stdio.h>
  
void main() {
  float taps[5] = {0.1, 1.2, -0.3, 3.4, -1.5};

  int taps_8_6[5];    // a fix<8,6> type
  unsigned i;

  for (i=0; i<5; i++)
    taps_8_6[i] = (int) (taps[i] * (1 << 6));

  for (i=0; i<5; i++)
    printf("%+4.2f %10d\n", taps[i], taps_8_6[i]);
}


The program generates the following output:

+0.10          6
+1.20         76
-0.30        -19
+3.40        217
-1.50        -96
