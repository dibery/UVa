#include<iostream>
using namespace std;
inline long long int squ( long long int a ) { return a*a; }

int main()
{
    long long int n;

    while( cin >> n )
        cout << 6 * squ( ( n+1 ) / 2 ) - 9 << endl;

	return 0;
}