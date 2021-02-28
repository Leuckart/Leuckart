//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int externvar1 = 98;
int externvar2 = 99;

void expect(int a, int b) {
    if (!(a == b)) {
        printf("Failed\n");
        printf("  %d expected, but got %d\n", a, b);
        exit(1);
    }
}


