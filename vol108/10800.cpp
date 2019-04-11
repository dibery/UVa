#include<iostream>
#include<cstring>
using namespace std;
bool again( int val, int loc, int last, int *arr )
{
    for( ; loc <= last; ++loc )
        if( arr[ loc ] == val )
            return true;
    return false;
}

int main()
{
    int test, len, R='/', C='_', F='\\';
    char str[ 200 ];
    cin >> test;

    for( int k = 1; k <= test; ++k )
    {
        cin >> str+1;
        len = strlen( str+1 );
        int status[ 200 ] = { 0 }, price[ 200 ] = { 0 }, max = -1, min = 300;

        for( int i = 1; i <= len; ++i )
            if( str[ i ] == 'R' )
                status[ i ] = R;
            else if( str[ i ] == 'F' )
                status[ i ] = F;
            else
                status[ i ] = C;
        for( int i = 1; i <= len; ++i )
            if( str[ i ] == 'R' )
                price[ i ] = price[ i-1 ]+1;
            else if( str[ i ] == 'F' )
                price[ i ] = price[ i-1 ]-1;
            else
                price[ i ] = price[ i-1 ];
        for( int i = 1; i <= len; ++i )
            if( status[ i ] == C || status[ i ] == F )
                ++price[ i ];
        for( int i = 1; i <= len; ++i )
        {
            if( max < price[ i ] )
                max = price[ i ];
            if( min > price[ i ] )
                min = price[ i ];
        }

        cout << "Case #" << k << ':' << endl;
        for( int i = max; i >= min; --i )
        {
            cout << "| ";
            for( int j = 1; j <= len; ++j )
                if( price[ j ] == i )
                    cout << char( status[ j ] );
                else if( again( i, j, len, price ) )
                    cout << ' ';
            cout << endl;
        }
        cout << '+';
        for( int i = -1; i <= len; ++i )
            cout << '-';
        cout << endl << endl;
    }
    return 0;
}
