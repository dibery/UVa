#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[ 4800 ] = { 2 }, counter, size = 0, IN, hold;
char in[ 8 ], cp[ 8 ];
bool Prime, Emirp;
double bound;
bool isprime( int in )
{
    for( int i = 1; i <= size; ++i )
        if( in % prime[ i ] == 0 )
            return false;
    return true;
}

int main()
{
    for( int i = 3; i < 1000; i += 2 )
        if( isprime( i ) )
            prime[ ++size ] = i;
    prime[ ++size ] = 46341;
    while( scanf( "%s", in ) == 1 )
    {
        bound = sqrt( hold = IN = atoi( in ) );
        for( counter = 0; prime[ counter ] <= bound; counter++ )
            if( IN % prime[ counter ] == 0 )
                break;
        Prime = IN % prime[ counter ] || IN == 2;
        reverse( in, in+strlen( in ) );
        bound = sqrt( IN = atoi( in ) );
        for( counter = 0; prime[ counter ] <= bound; counter++ )
            if( IN % prime[ counter ] == 0 )
                break;
        Emirp = ( IN % prime[ counter ] || IN == 2 ) && hold != IN;
        if( Prime )
            if( Emirp )
                printf( "%d is emirp.\n", hold );
            else
                printf( "%d is prime.\n", hold );
        else
            printf( "%d is not prime.\n", hold );
    }
    return 0;
}
