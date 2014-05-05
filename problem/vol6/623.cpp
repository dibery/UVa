#include<iostream>
using namespace std;
unsigned int ans[ 1001 ][ 3000 ] = { 0 };

int main()
{
    ans[ 1 ][ 0 ] = 1;
    for( int i = 2; i <= 1000; ++i )
    {
        for( int j = 0; j < 3000; ++j )
            ans[ i ][ j ] = ans[ i-1 ][ j ] * i;
        for( int j = 0; j < 3000; ++j )
            if( ans[ i ][ j ] >= 10 )
            {
                ans[ i ][ j+1 ] += ans[ i ][ j ] / 10;
                ans[ i ][ j ] %= 10;
            }
    }
    int target, i = 0;

    while( cin >> target )
    {
        if( !target )
        {
            cout << "0!\n0\n";
            continue;
        }
        cout << target << '!' << endl;
        for( i = 2999; ans[ target ][ i ] == 0; --i );
        for( ; i >= 0; --i )
            cout << ans[ target ][ i ];
        cout << endl;
    }

	return 0;
}
