#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;

int main()
{
    int t = 0;
    char in[ 10 ];
    vector<char*>all;

    while( scanf( "%s", in ) != EOF )
    {
        if( strcmp( in, "9" ) )
            all.push_back( strdup( in ) );
        else
        {
            bool imme = true;
            for( int i = 0; i < all.size() && imme; ++i )
                for( int j = 0; j < all.size() && imme; ++j )
                    if( i != j && !strncmp( all[ i ], all[ j ], strlen( all[ i ] ) ) )
                        imme = false;
            for( int i = 0; i < all.size(); ++i )
                free( all[ i ] );
            all.clear();
            printf( "Set %d is %simmediately decodable\n", ++t, imme? "" : "not " );
        }
    }

	return 0;
}