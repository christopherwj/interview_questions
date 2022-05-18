//Write a method to replace all spaces in a string with ‘%20’.

void replaceSpace(char* str) {
    char* ptr = str;
    int count = 0;
    int length = 0;
    while(*ptr) {
        if(*ptr == ' ')
            count++;
        length++;
        ptr++;
    }
    int newLength = length + 2 * count;
    str[newLength] = '\0';
     
    for(int i = newLength - 1; i >= 0; ) {
        if(str[i - 2 * count] == ' ') {
            str[i] = '0';
            str[i-1] = '2';
            str[i-2] = '%';
            i = i - 3;
            count--;
        } else {
            str[i] = str[i - 2 * count];
            --i;
        }
    }
}
