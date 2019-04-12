#include<iostream>
using namespace std;
void out( long long int n, long long int *fib )
{
    bool on = false;
    for( int i = 49; i > 1; --i )
        if( n >= fib[ i ] )
        {
            cout << 1;
            n -= fib[ i ];
            on = true;
        }
        else if( on )
            cout << 0;
    cout << " (fib)\n";
}

int main()
{
    long long int fib[ 50 ] = { 0, 1 }, n, size;
    for( int i = 2; i < 50; ++i )
        fib[ i ] = fib[ i-1 ] + fib[ i-2 ];
    cin >> size;

    while( size-- )
    {
        cin >> n;
        cout << n << " = ";
        out( n, fib );
    }

    return 0;
}
