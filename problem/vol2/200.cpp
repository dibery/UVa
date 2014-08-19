#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	string in;

	while( cin >> in )
	{
		bool used[ 26 ] = { false };
		vector<string> dic;
		set<char> dep[ 26 ];
		pair<string::iterator,string::iterator> diff;

		do
		{
			dic.push_back( in );
			for( int i = 0; i < in.size(); ++i )
				used[ in[ i ] - 'A' ] = true;
		}
		while( cin >> in && in != "#" );

		for( int i = 0; i < dic.size(); ++i )
			for( int j = i+1; j < dic.size(); ++j )
			{
				diff = mismatch( dic[ i ].begin(), dic[ i ].end(), dic[ j ].begin() );
				if( *diff.first != *diff.second && diff.first != dic[ i ].end() )
					dep[ *diff.second - 'A' ].insert( *diff.first );
			}

		while( count( used, used+26, false ) != 26 )
		{
			for( int i = 0; i < 26; ++i )
				if( used[ i ] && dep[ i ].empty() )
				{
					char c = i+'A';
					cout << c;
					for( int j = 0; j < 26; ++j )
						dep[ j ].erase( c );
					used[ i ] = false;
				}
		}
		cout << endl;
	}
}
