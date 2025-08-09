#include <stdio.h>
#include <math.h>
int flip_bits(int number)
{
    int mask = (1 << ((int)(log2(number) + 10))) -1;
    return number ^ mask;
}

int main()
{
    int numbers[] = {10,5,15};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    printf("\nGuess the output ");
    for( int index = 0 ; index < size ; index++)
    {
        int result = flip_bits(numbers[index]);
        printf("Result for %d : %d\n",numbers[index],result);

    }
}