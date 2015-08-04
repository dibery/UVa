#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string in[ 4 ];

	while( cin >> in[ 0 ] >> in[ 1 ] >> in[ 2 ] >> in[ 3 ] )
	{
		int area = 0;
		sort( in, in+4 );
		do
			for( int abegin = 1; abegin < in[ 0 ].size() - 1; ++abegin )
				for( int aspan = 2; abegin + aspan < in[ 0 ].size() - 1; ++aspan )
					for( int bbegin = 1; bbegin + aspan < in[ 1 ].size() - 1; ++bbegin )
						for( int cbegin = 1; cbegin < in[ 2 ].size() - 1; ++cbegin )
							for( int cspan = 2; cbegin + cspan < in[ 2 ].size() - 1; ++cspan )
								for( int dbegin = 1; dbegin + cspan < in[ 3 ].size() - 1; ++dbegin )
									if( in[ 0 ][ abegin ] == in[ 2 ][ cbegin ] && 
											in[ 1 ][ bbegin ] == in[ 2 ][ cbegin+cspan ] && 
											in[ 0 ][ abegin+aspan ] == in[ 3 ][ dbegin ] && 
											in[ 1 ][ bbegin+aspan ] == in[ 3 ][ dbegin+cspan ] )
										area = max( area, ( aspan-1 ) * ( cspan-1 ) );
		while( next_permutation( in, in+4 ) );
		cout << area << endl;
	}
}
