#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int anag[ 22 ] = { 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991 }, n;
    while( scanf( "%d", &n ) && n )
    {
        int *pos = upper_bound( anag, anag+22, n ), num = *pos;
        if( pos == anag+22 || n >= 7 && n <= 9 || n >= 97 && n <= 99 )
            puts( "0" );
        else
            printf( "%d\n", num );
    }
}
/*bool notprime[ 10000000 ] = { true, true }, isAnag[ 10000000 ];
bool ok( int n )
{
    char verbose[ 10 ] = { 0 };
    sprintf( verbose, "%d", n );
    int len = strlen( verbose ), tmp;
    if( prev_permutation( verbose, verbose + len ) && strchr( verbose, '0' ) == NULL )
        return isAnag[ atoi( verbose ) ];
    sort( verbose, verbose + len );
    do
        if( notprime[ tmp = atoi( verbose ) ] || tmp % 2 == 0 )
            return false;
    while( next_permutation( verbose, verbose + len ) );
    return true;
}

int main()
{
    int n;
    vector<int> anag( 1, 2 );
    system("del 897.o");

    for( int i = 3; i*i < 10000000; i += 2 )
        if( !notprime[ i ] )
            for( int j = i*i; j < 10000000; j += i*2 )
                notprime[ j ] = true;

    for( int i = 3; i < 10000000; i += 2 )
        if( ok( i ) )
            isAnag[ i ] = true, anag.push_back( i );
}
*/
