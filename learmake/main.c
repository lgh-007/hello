#include <stdio.h>
#include <stdlib.h>
#include "add.h"
#include "hello.h"
#include "sub.h"

int main(int argc, char const *argv[]) {
    int val;

    hello();
    val = sub(2,3);
    printf("%d\n", val);
    val = add(2,3);
    printf("%d\n", val);

    return 0;
}
