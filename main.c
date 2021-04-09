#include <stdio.h>
#include <stdlib.h>

static int amountNumbers = 10000;

/**< Bruges til at udskrive et array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
/**< Bruges til at generere X antal tilfældige nummere */
int * ManyNumbers(){
   static int mNumbers[10000];
     for(int i = 0; i<amountNumbers; i++)
        mNumbers[i] = rand();
        return mNumbers;

}
/**< 1000 tal = 0,081 | 10000 tal = 0,605 | 100000 tal = 7,971 */
int * sort(int arr[])
{
    int i, key, j;
    for (i = 1; i < amountNumbers; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}
int main()
{
    //variabler og pointervariabler
    int *numbers, *sortedNumbers;

    numbers = ManyNumbers();
    sortedNumbers = sort(numbers);
    printArray(sortedNumbers, amountNumbers);

    return 0;
}
