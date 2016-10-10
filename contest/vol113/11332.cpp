#include<iostream>
using namespace std;

int f( int n )
{
	int sum = 0;
	for( ; n > 0; n /= 10 )
		sum += n % 10;
	return sum;
}

int g( int n )
{
	return n < 10? n : g( f( n ) );
}

int main()
{
	for( int n; cin >> n && n; )
		cout << g( n ) << endl;
}
