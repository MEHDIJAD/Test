#include <stdio.h>
#include "ft_printf.h"
#include <stdbool.h>

void test_cases() 
{
    ft_printf("[%02.2d]\n", 42);
    printf("[%02.2d]\n", 42);

}

int main() {
    test_cases();

    
    return 0;
}

