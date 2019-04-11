#include<cstdio>
inline bool isvowel( char a ) { return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'; }
inline bool same( char *a, char *b )
{
    int i;
    for( i = 0; a[ i ] && b[ i ]; ++i )
        if( isvowel( a[ i ] ) ^ isvowel( b[ i ] ) )
            return false;
        else if( !isvowel( a[ i ] ) && !isvowel( b[ i ] ) )
            if( a[ i ] != b[ i ] )
                return false;
    if( a[ i ] || b[ i ] )
        return false;
    return true;
}

int main()
{
    int t;
    char a[ 21 ], b[ 21 ];
    scanf( "%d\n", &t );

    while( t-- )
    {
        gets( a );
        gets( b );
        puts( !same( a, b )? "No" : "Yes" );
    }

	return 0;
}