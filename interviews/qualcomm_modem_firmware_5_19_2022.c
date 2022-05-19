#include <stdio.h>
#include <assert.h>

/*============================================================================
  
   FUNCTION: unpack
  
=============================================================================*/
/**
  This function unpacks an input array of words into an output array according
  to the specified bitwidth.

  The output is expected to be sized correctly to hold the required number of 
  entries.

  For example:

  in = { 0x12345678, 0x9abcdef0 }
  in_size = 2
  out -> an array of size at least 8
  num_bits = 8 assume power of two 

  => out = { 0x78, 0x56, 0x34, 0x12, 0xf0, 0xde, 0xbc, 0x9a }
 */
/*==========================================================================*/
void unpack(
    unsigned *in,  /** input array of words */
    int in_size,   /** input array size */
    unsigned *out, /** output array */
    int num_bits   /** output bits per entry */
    ) 
  
  // --- WRITE YOUR CODE HERE ---
  // 1 bit = 0x1, 2 = 0x03, 4 bit = 0xf, 8 bits =
  //2^n -1
   //float mask_size = num_bits / 4; 
   int mask = (1<<num_bits) - 1; 

   *out = *in&(mask);
   for(int i = 0; i < in_size; i++){
     for(int j = 0; j < 32/num_bits; j++;) 
      *out++=in[i] & mask(1<<j); 

}

int main(void) {

  // this is the input array.
  unsigned in[] = { 0x12345678, 0x9abcdef0, 0xFFFFFFFF };
  // this holds the potential output.
  unsigned out[100] = {0};
  int in_size = sizeof(in)/sizeof(unsigned);

  // unpack the input bitstream into words of 9-bits each.
  int num_bits = 9;
  unpack(in, in_size, out, num_bits);

  // these assert statements must pass for the solution to be 
  // correct.
  assert(out[0]  == 0x00000078);
  assert(out[1]  == 0x0000002b);
  assert(out[2]  == 0x0000008d);
  assert(out[3]  == 0x00000050);
  assert(out[4]  == 0x000000f7);
  assert(out[5]  == 0x000000f3);
  assert(out[6]  == 0x00000135);
  assert(out[7]  == 0x000001ff);
  assert(out[8]  == 0x000001ff);
  assert(out[9]  == 0x000001ff);
  assert(out[10] == 0x0000001f);
}
