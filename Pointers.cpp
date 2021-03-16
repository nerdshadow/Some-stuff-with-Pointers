
#include <iostream>

void increase(int* start, int* end) //increasing numbers
{
    int* currentnum = start;
    while (currentnum != end)
    {
        ++* currentnum; // increase value of current number from array
        ++ currentnum; // increase pointer 
    }
}


void writeallout(const int* start, const int* end) //trying to do something with const 
{
    const int* currentnum = start;
    while (currentnum != end)
    {
        std::cout << *currentnum << std::endl;
        ++currentnum; // increase pointer 
    }
}

void IncreasingWithVoidPointers(void* data, int size) //using void pointers because of curiosity
{
    if (size == sizeof(char))
    {
        char* PointerChar; 
        PointerChar = (char*) data; //idk why (char*) data, but google say its the correct way to do this
        ++* PointerChar;
    }
    else
    {
        if (size == sizeof(int))
        {
            int* PointerInt;
            PointerInt = (int*)data;
            ++* PointerInt;
        }
    }
}

int addfunction(int x, int y) // add function )
{
    return(x + y);
}

int ChoosedOperation(int x, int y, int (*functioncalled)(int, int)) //using pointers to call a function
{
    int answer;
    answer = (*functioncalled)(x, y);
    return answer;
}

int main()
{
    //simple actions with pointers for studying :

    int number1 = 13, number2 = 56;
    int* pointer1 = &number1, *pointer2 = &number2;
    std::cout << *pointer1 << " - " << *pointer2 << std::endl;
    *pointer2 = *pointer1;
    *pointer1 = 21;
    
    std::cout << *pointer1 << " - " << *pointer2 << std::endl;
    
    int* something = pointer1;
    std::cout << *something << std::endl << std::endl;

    // using pointers with arrays :

    int arrayofnumbers[] = { 14, 24, 34, 44, 54 };
    writeallout(arrayofnumbers, arrayofnumbers + 5);
    increase(arrayofnumbers, arrayofnumbers + 5);
    std::cout << std::endl;
    writeallout(arrayofnumbers, arrayofnumbers + 5);

    std::cout << std::endl;

    // "double pointers" :

    char oursymbol;
    char* pointertooursymbol;
    char** pointertopointer;

    oursymbol = 'A';
    pointertooursymbol = &oursymbol;
    pointertopointer = &pointertooursymbol;

    std::cout << oursymbol <<" - our symbol"<< std::endl;
    std::cout << *pointertooursymbol << " - our symbol with pointer" << std::endl;
    std::cout << **pointertopointer << " - our symbol with doublepointer" << std::endl;

    std::cout << std::endl;

    // pointers as a arguments :

    char a = 'a';
    int n = 69;
    IncreasingWithVoidPointers(&a, sizeof(a));
    IncreasingWithVoidPointers(&n, sizeof(n));
    std::cout << a << std::endl << n << std::endl;

    std::cout << std::endl;

    // pointers for functions :

    int sum;
    sum = ChoosedOperation(25, 36, addfunction);
    std::cout << sum << std::endl;
}
