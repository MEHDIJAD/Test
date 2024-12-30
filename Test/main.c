#include <stdio.h>
#include "ft_printf.h"
#include <stdbool.h>

void test_cases() 
{
    ft_printf("[%4.4d]\n", 42);
    printf("[%8.3d]\n", 42);

}

int main() {
    test_cases();

    
    return 0;
}

