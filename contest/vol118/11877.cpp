#include<cstdio>
using namespace std;

int main()
{
    int bottle;

    while( scanf( "%d", &bottle ) && bottle )
        printf( "%d\n", bottle & 1? bottle / 2 * 3 + 1 - bottle : bottle / 2 * 3 - bottle );

    return 0;
}
//11877