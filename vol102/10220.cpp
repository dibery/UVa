#include<iostream>
using namespace std;
unsigned int fact[ 1001 ][ 3000 ] = { 1 }, ans[ 1001 ] = { 0 }, n;

int main()
{
    for( int i = 1; i <= 1000; ++i )
    {
        for( int j = 0; j < 3000; ++j )
            fact[ i ][ j ] = fact[ i-1 ][ j ] * i;
        for( int j = 0; j < 3000; ++j )
            if( fact[ i ][ j ] >= 10 )
            {
                fact[ i ][ j+1 ] += fact[ i ][ j ] / 10;
                fact[ i ][ j ] %= 10;
            }
        for( int j = 0; j < 3000; ++j )
            ans[ i ] += fact[ i ][ j ];
    }

    while( cin >> n )
        cout << ans[ n ] << endl;

	return 0;
}
