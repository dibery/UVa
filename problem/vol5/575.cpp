#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int pow[ 31 ] = { 1 };

int main()
{
    char num[ 32 ];
    for( int i = 1; i < 31; ++i )
        pow[ i ] = pow[ i-1 ]*2 + 1;

    while( cin >> num && strcmp( num, "0" ) )
    {
        int sum = 0;
        reverse( num, num+strlen( num ) );
        for( int i = 0; num[ i ]; ++i )
            sum += ( num[ i ] - '0' ) * pow[ i ];
        cout << sum << endl;
    }

	return 0;
}