#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int in, all[] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973 };

    while( scanf( "%d", &in ) && in )
        if( binary_search( all, all+15, in ) )
            printf( "The number %d is a Carmichael number.\n", in );
        else
            printf( "%d is normal.\n", in );
}
