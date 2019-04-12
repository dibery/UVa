#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<list>
using namespace std;
int fact[ 11 ] = { 1 };
inline int C( int n, int m ) { return fact[ n ] / fact[ n-m ] / fact[ m ]; }
bool cmp( char *a, char *b ) { return strcmp( a, b ) == 0; }
bool sort_cmp( char *a, char *b ) { return strcmp( a, b ) < 0; }

int main()
{
    int t, len, alter;
    char dna[ 11 ], buffer[ 11 ], type[] = { "ACGT" };
    scanf( "%d", &t );
    for( int i = 1; i <= 10; ++i )
        fact[ i ] = fact[ i-1 ] * i;

    while( t-- )
    {
        int quant = 0;
        list<char*> out;
        scanf( "%d %d %s", &len, &alter, dna );
        for( int i = 0; i <= alter; ++i )
            quant += pow( 3.0, i ) * C( len, i );
        printf( "%d\n", quant );
        if( alter == 0 )
            out.push_back( strdup( dna ) );
        else if( alter == 1 )
            for( int a = 0; a < len; ++a )
            {
                strcpy( buffer, dna );
                for( int i = 0; i < 4; ++i )
                {
                    buffer[ a ] = type[ i ];
                    out.push_back( strdup( buffer ) );
                }
            }
        else if( alter == 2 )
            for( int a = 0; a < len; ++a )
                for( int b = a+1; b < len; ++b )
                {
                    strcpy( buffer, dna );
                    for( int i = 0; i < 4; ++i )
                        for( int j = 0; j < 4; ++j )
                        {
                            buffer[ a ] = type[ i ];
                            buffer[ b ] = type[ j ];
                            out.push_back( strdup( buffer ) );
                        }
                }
        else if( alter == 3 )
            for( int a = 0; a < len; ++a )
                for( int b = a+1; b < len; ++b )
                    for( int c = b+1; c < len; ++c )
                    {
                        strcpy( buffer, dna );
                        for( int i = 0; i < 4; ++i )
                            for( int j = 0; j < 4; ++j )
                                for( int k = 0; k < 4; ++k )
                                {
                                    buffer[ a ] = type[ i ];
                                    buffer[ b ] = type[ j ];
                                    buffer[ c ] = type[ k ];
                                    out.push_back( strdup( buffer ) );
                                }
                    }
        else if( alter == 4 )
            for( int a = 0; a < len; ++a )
                for( int b = a+1; b < len; ++b )
                    for( int c = b+1; c < len; ++c )
                        for( int d = c+1; d < len; ++d )
                        {
                            strcpy( buffer, dna );
                            for( int i = 0; i < 4; ++i )
                                for( int j = 0; j < 4; ++j )
                                    for( int k = 0; k < 4; ++k )
                                        for( int l = 0; l < 4; ++l )
                                        {
                                            buffer[ a ] = type[ i ];
                                            buffer[ b ] = type[ j ];
                                            buffer[ c ] = type[ k ];
                                            buffer[ d ] = type[ l ];
                                            out.push_back( strdup( buffer ) );
                                        }
                        }
        else
            for( int a = 0; a < len; ++a )
                for( int b = a+1; b < len; ++b )
                    for( int c = b+1; c < len; ++c )
                        for( int d = c+1; d < len; ++d )
                            for( int e = d+1; e < len; ++e )
                            {
                                strcpy( buffer, dna );
                                for( int i = 0; i < 4; ++i )
                                    for( int j = 0; j < 4; ++j )
                                        for( int k = 0; k < 4; ++k )
                                            for( int l = 0; l < 4; ++l )
                                                for( int m = 0; m < 4; ++m )
                                                {
                                                    buffer[ a ] = type[ i ];
                                                    buffer[ b ] = type[ j ];
                                                    buffer[ c ] = type[ k ];
                                                    buffer[ d ] = type[ l ];
                                                    buffer[ e ] = type[ m ];
                                                    out.push_back( strdup( buffer ) );
                                                }
                            }
        out.sort( sort_cmp );
        out.unique( cmp );
        while( !out.empty() )
        {
            puts( out.front() );
            free( out.front() );
            out.pop_front();
        }
    }

    return 0;
}
