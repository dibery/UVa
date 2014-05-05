#include<iostream>
using namespace std;

int main()
{
    int base, exp, mod, cal[ 32 ], ans;

    while( cin >> base >> exp >> mod )
    {
        if( base == 0 || mod == 1 )
            cout << 0 << endl;
        else if( base == 1 || exp == 0 )
            cout << 1 << endl;
        else if( exp == 1 )
            cout << base % mod << endl;
        else
        {
            *cal = ans = 1;
            cal[ 1 ] = base % mod;
            for( int i = 2; i < 32; ++i )
                cal[ i ] = ( cal[ i-1 ] * cal[ i-1 ] ) % mod;
            for( int i = 0; i < 31; ++i )
                if( 1 << i & exp )
                    ans = ( ans * cal[ i+1 ] ) % mod;
            cout << ans << endl;
        }
    }

	return 0;
}