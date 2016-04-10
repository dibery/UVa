#include<iostream>
using namespace std;

int main()
{
	int N, L, C, len[ 1000 ];
	string s;

	while( cin >> N >> L >> C )
	{
		int lines = 0;

		for( int i = 0; i < N; ++i )
			cin >> s, len[ i ] = s.size();
		for( int i = 0; i < N; ++lines )
			for( int sum = 0; sum + len[ i ] <= C; ++i )
				sum += len[ i ] + 1;

		cout << ( lines + L - 1 ) / L << endl;
	}
}
