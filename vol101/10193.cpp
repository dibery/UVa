#include<iostream>
#include<cstdlib>
using namespace std;
int GCF( int a, int b );

int main()
{
    int a, b, data;
    char input[ 30 ];

    cin >> data;
    for( int i = 1; i <= data; i++ )
    {
        cin >> input;
        a = strtol( input, NULL, 2 );
        cin >> input;
        b = strtol( input, NULL, 2 );
        cout << "Pair #" << i << ( GCF( a, b ) == 1 ?
            ": Love is not all you need!\n" : ": All you need is love!\n" );
    }

    return 0;
}

int GCF( int a, int b )
{
    int r;

    while( a % b )
    {
        r = a % b;
        a = b;
        b = r;
    }

    return b;
}