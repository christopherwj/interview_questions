/*
Write a function called my2DAlloc which allocates a two dimensional array.
Minimize the number of calls to malloc and make sure that the memory is accessible by the notation arr[i][j].
https://tianrunhe.wordpress.com/2012/04/23/allocate-a-two-dimensional-array-using-one-call-of-malloc-in-c/
*/

int** My2DAlloc(int rows, int cols) {
    int header = rows * sizeof(int*);
    int data = rows * cols * sizeof(int);
    int** rowptr = (int**)malloc(header + data);
    int* buf = (int*)(rowptr + rows);
    int k;
    for (k = 0; k < rows; ++k) {
        rowptr[k] = buf + k*cols;
    }
    return rowptr;
}
