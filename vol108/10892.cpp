#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
inline int GCD( int a, int b ) { return a % b? GCD( b, a % b ) : b; }

int main()
{
    int n;

    while( cin >> n && n )
    {
        int ans = 1;
        vector<int>factor;
        for( int i = sqrt( n ); i; --i )
            if( n % i == 0 )
                if( i * i != n )
                    factor.push_back( i ), factor.push_back( n / i );
                else
                    factor.push_back( i );
        for( int i = factor.size()-1; i; --i )
            for( int j = i-1; j >= 0; --j )
                if( GCD( factor[ i ], factor[ j ] ) == 1 )
                    ++ans;
        cout << n << ' ' << ans << endl;
    }

    return 0;
}