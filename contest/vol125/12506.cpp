#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
	int t, size;
	string all[ 1000 ];

	for( cin >> t; t; --t )
	{
		cin >> size;
		for( int i = 0; i < size; ++i )
			cin >> all[ i ];
		sort( all, all+size );
		int ans = mismatch( all[ 0 ].begin(), all[ 0 ].end(), all[ 1 ].begin() ).first - all[ 0 ].begin();
		for( int i = 1; i < size-1; ++i )
			ans += max( mismatch( all[ i ].begin(), all[ i ].end(), all[ i-1 ].begin() ).first - all[ i ].begin(), mismatch( all[ i ].begin(), all[ i ].end(), all[ i+1 ].begin() ).first - all[ i ].begin() );
		ans += mismatch( all[ size-1 ].begin(), all[ size-1 ].end(), all[ size-2 ].begin() ).first - all[ size-1 ].begin();
		cout << ans + size << endl;
	}
}
