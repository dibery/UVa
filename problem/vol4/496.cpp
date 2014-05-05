#include<cstdio>
#include<algorithm>
#include<set>
#include<cctype>
using namespace std;

int main()
{
	int tmp;
	char *input = new char[ 1000000 ], *pos = NULL;

	while( pos = gets( input ) )
	{
        set<int> a, b, both;
		while( true )
		{
			sscanf( pos, "%d", &tmp );
			a.insert( tmp );
			both.insert( tmp );
			while( *pos != ' ' && *pos )
				++pos;
            if( !*pos )
                break;
            ++pos;
		}
		pos = gets( input );
		while( *pos )
		{
			sscanf( pos, "%d", &tmp );
			b.insert( tmp );
			both.insert( tmp );
			while( *pos != ' ' && *pos )
				++pos;
            if( !*pos )
                break;
            ++pos;
		}

		bool a_is_in_b = a.size() <= b.size()? includes( b.begin(), b.end(), a.begin(), a.end() ) : false;
		bool b_is_in_a = b.size() <= a.size()? includes( a.begin(), a.end(), b.begin(), b.end() ) : false;
		bool disjoint = both.size() == a.size() + b.size();
		bool equal = a_is_in_b & b_is_in_a;

		if( equal )
            puts( "A equals B" );
        else if( a_is_in_b )
            puts( "A is a proper subset of B" );
        else if( b_is_in_a )
            puts( "B is a proper subset of A" );
        else
            puts( disjoint? "A and B are disjoint" : "I'm confused!" );
	}

	return 0;
}
