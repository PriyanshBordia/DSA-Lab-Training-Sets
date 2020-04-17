// usedSize = 5999
// i = 79
// i*i = 5929
#include <stdio.h>

int usedSize = 5999;
int main(int argc, char const *argv[])
{
    int i = 3;
    while (usedSize > 2)
    {
        i = 3;
        while (i*i <= usedSize)
        {
            if (usedSize % i == 0)
            {
                usedSize -= 2;
                break;
            }
            i += 2;
        }

        if (i*i > usedSize)
            break;
    }
    printf("Breaked: %d\nUsed Size: %d\n", i, usedSize);
    return 0;
}
