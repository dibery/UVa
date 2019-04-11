#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
unsigned long long int take( unsigned long long int n, unsigned long long int m )
{
    unsigned long long int back = 1;
    for( unsigned long long int i = 1; i <= m; ++i )
        back = back * ( n - i + 1 ) / i;
    return back;
}

int main()
{
    char n[ 10000 ], m[ 10000 ];
    unsigned long long int N, M;
    cout.precision( 50 );

    while( cin >> n >> m )
    {
        N = strtoll( n, NULL, 10 );
        M = strtoll( m, NULL, 10 );
        if( N-M < M )
            M = N-M;
        if( !N && !M )
            break;
        if( !M || N == 1 || !strcmp( n, m ) )
            cout << 1 << endl;
        else
            cout << take( N, M ) << endl;
    }
    return 0;
}
