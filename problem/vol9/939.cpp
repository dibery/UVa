#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define B family.begin()
using namespace std;

const int NEXT[3][3] = { { 0, 2, 0 }, { 2, 1, 1 }, { 0, 1, 2 } };
const	string type[] = { "non-existent", "dominant", "recessive" };
class man
{
	public:
		man( int t = -1 ) { type = t; }
		man( const string& p ) { p1 = p; type = -1; }
		void set( man& a, man& b ) { type = NEXT[ a.type ][ b.type ]; }
		void operator+= ( const string& p ) { p2 = p; }
		string p1, p2; //parent
		int type; //0-2, N-D-R
};

int main()
{
	int n, i;
	string first, second;
	map<string,man> family, proc;

	while( cin >> n )
	{
		for( i = 0; i < n; ++i )
		{
			cin >> first >> second;
			if( find( type, type+3, second ) != type+3 )
				family[ first ] = man( find( type, type+3, second ) - type );
			else if( proc.find( second ) == proc.end() )
				proc[ second ] = man( first );
			else
				proc[ second ] += first;
		}
		n = family.size() + proc.size();
		while( family.size() != n )
			for( map<string,man>::iterator i = proc.begin(); i != proc.end(); ++i )
				if( family.find( i->second.p1 ) != family.end() && family.find( i->second.p2 ) != family.end() )
				{
					i->second.set( family[ i->second.p1 ], family[ i->second.p2 ] );
					family[ i->first ] = i->second;
					map<string,man>::iterator j = i;
					if( proc.size() > 1 )
						--i, proc.erase( j );
				}
		proc.clear();
		while( !family.empty() )
			cout << B->first << ' ' << type[ B->second.type ] << endl, family.erase( B );
	}
}
