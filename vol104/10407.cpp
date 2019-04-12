#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline int GCD( int a, int b ) { return a % b? GCD( b, a % b ) : b; }

int main()
{
    int n, gcd, i;
    vector<int>num;

    while( cin >> n )
        if( n )
            num.push_back( n );
        else//
            if( num.empty() )
                break;
            else
            {
                sort( num.begin(), num.end() );
                for( i = 1; i < num.size(); ++i )
                    num[ i ] -= num.front();
                num[ i = 0 ] = 0;
                while( !num[ ++i ] );
                gcd = num[ i ];
                for( ++i; i < num.size(); ++i )
                    gcd = GCD( gcd, num[ i ] );
                cout << gcd << endl;
                num.clear();
            }

	return 0;
}