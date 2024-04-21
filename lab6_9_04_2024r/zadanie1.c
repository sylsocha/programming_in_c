#include <stdio.h>

union numbers {
    int ints;
    float floats;
    char chars;
};

int main(){
    union numbers number;

    number.ints = 26;
    printf("int: %d\n", number.ints);

    number.floats = 1.26;
    printf("float: %f\n", number.floats);

    number.chars = '2';
    printf("char: %c\n", number.chars);

    return 0;
}
