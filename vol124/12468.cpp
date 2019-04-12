#include<iostream>
using namespace std;
inline int abs( int a ) { return ( a > 0 ? a : -a ); }

int main()
{
    int a, b;

    while( cin >> a >> b && a != -1 )
            cout << ( abs( a-b ) > 50? 100-abs( a-b ) : abs( a-b ) ) << endl;

	return 0;
}