#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cstdio>
#include<stack>
using namespace std;
int bitlen( char *a )
{
    for( int i = 999; i >= 0; --i )
        if( a[ i ] == '1' )
            return i;
    return 0;
}

int main()
{
    int t;
    string str;
    char command[ 1000 ], *tmp, ins[ 1000 ];
    cin >> t;
    getline( cin, str );

    for( int i = 1; i <= t; ++i )
    {
        getline( cin, str );
        istringstream in( str );
        stack<char*> calc;

        while( memset( command, '0', sizeof( command ) ) && in >> command )
            if( isalpha( command[ 0 ] ) )
                calc.push( strdup( command ) );
            else
            {
                reverse( command, command+strlen( command ) );
                memset( ins, '0', sizeof( ins ) );
                strncpy( ins, command, strlen( command ) );
                command[ strlen( command ) ] = '0';
again:
                if( calc.empty() )
                    calc.push( strdup( ins ) );
                else//
                    if( !strcmp( calc.top(), "not" ) )
                    {
                        int i = bitlen( ins );
                        for( ; i >= 0; --i )
                            ins[ i ] = ins[ i ] == '0' ? '1' : '0';
                        free( calc.top() );
                        calc.pop();
                        if( !calc.empty() && isalpha( calc.top()[ 0 ] ) )
                            goto again;
                        calc.push( strdup( ins ) );
                    }
                    else if( !strcmp( calc.top(), "shl" ) )
                    {
                        for( int i = 999; i; --i )
                            ins[ i ] = ins[ i-1 ];
                        *ins = '0';
                        free( calc.top() );
                        calc.pop();
                        if( !calc.empty() && isalpha( calc.top()[ 0 ] ) )
                            goto again;
                        calc.push( strdup( ins ) );
                    }
                    else if( !strcmp( calc.top(), "shr" ) )
                    {
                        for( int i = 0; i < 999; ++i )
                            ins[ i ] = ins[ i+1 ];
                        ins[ 999 ] = '0';
                        free( calc.top() );
                        calc.pop();
                        if( !calc.empty() && isalpha( calc.top()[ 0 ] ) )
                            goto again;
                        calc.push( strdup( ins ) );
                    }
                    else if( !strcmp( calc.top(), "and" ) )
                    {
                        free( calc.top() );
                        calc.pop();
                        int cmp = max( bitlen( calc.top() ), bitlen( ins ) );
                        for( int i = 0; i <= cmp; ++i )
                            ins[ i ] = ( ( calc.top()[ i ] - '0' ) and ( ins[ i ] - '0' ) ) + '0';
                        free( calc.top() );
                        calc.pop();
                        if( !calc.empty() && isalpha( calc.top()[ 0 ] ) )
                            goto again;
                        calc.push( strdup( ins ) );
                    }
                    else if( !strcmp( calc.top(), "or" ) )
                    {
                        free( calc.top() );
                        calc.pop();
                        int cmp = max( bitlen( calc.top() ), bitlen( ins ) );
                        for( int i = 0; i <= cmp; ++i )
                            ins[ i ] = ( ( calc.top()[ i ] - '0' ) or ( ins[ i ] - '0' ) ) + '0';
                        free( calc.top() );
                        calc.pop();
                        if( !calc.empty() && isalpha( calc.top()[ 0 ] ) )
                            goto again;
                        calc.push( strdup( ins ) );
                    }
                    else if( !strcmp( calc.top(), "xor" ) )
                    {
                        free( calc.top() );
                        calc.pop();
                        int cmp = max( bitlen( calc.top() ), bitlen( ins ) );
                        for( int i = 0; i <= cmp; ++i )
                            ins[ i ] = ( ( calc.top()[ i ] - '0' ) xor ( ins[ i ] - '0' ) ) + '0';
                        free( calc.top() );
                        calc.pop();
                        if( !calc.empty() && isalpha( calc.top()[ 0 ] ) )
                            goto again;
                        calc.push( strdup( ins ) );
                    }
            }
        printf( "Case %d: ", i );
        tmp = calc.top();
        for( int i = bitlen( tmp ); i >= 0; --i )
            putchar( tmp[ i ] );
        puts( "" );
        free( calc.top() );
        calc.pop();
    }

	return 0;
}
