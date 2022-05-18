https://stackoverflow.com/questions/52391330/create-a-precise-atof-implementation-in-c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double str_to_double(char *);
void double_to_str(double,char *);

int main(){
    int max_size;
    double x;
    char *arr;
    printf("Enter max size of string : ");
    scanf("%d",&max_size);
    arr=malloc((max_size+1)*sizeof(char));
    scanf("%s",arr);
    x=str_to_double(arr);
    printf("%f\n%f",x,atof(arr));
    return 0;
}

//string to float
double str_to_double(char *arr){
    int i,j,flag;
    double val;
    char c;
    i=0;
    j=0;
    val=0;
    flag=0;
    while ((c = *(arr+i))!='\0'){
//      if ((c<'0')||(c>'9')) return 0;
        if (c!='.'){
            val =(val*10)+(c-'0');
            if (flag == 1){
                --j;
            }
        }
        if (c=='.'){ if (flag == 1) return 0; flag=1;}
        ++i;
    }
    val = val*pow(10,j);
    return val;
}

/*
Change all your floats to doubles. When I tested it, that gave the same result as the library function atof for your test case.

atof returns double, not float. Remember that it actually is double and not float that is the "normal" floating-point type in C. A floating-point literal, such as 3.14, is of type double, and library functions such as sin, log and (the perhaps deceptively named) atof work with doubles.

It will still not be "precise", though. The closest you can get to 1236.965 as a float is (exactly) 1236.9649658203125, and as a double 1236.964999999999918145476840436458587646484375, which will be rounded to 1236.965000 by printf. No matter how many bits you have in a binary floating-point number, 1236.965 can't be exactly represented, similar to how 1/3 can't be exactly represented with a finite number of decimal digits: 0.3333333333333333...

And also, as seen in the discussion in comments, this is a hard problem, with many possible pitfalls if you want code that will always give the closest value.
*/
