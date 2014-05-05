#include<cstdio>
#include<cctype>
#include<iostream>
using namespace std;
inline bool isvowel( char a ) { return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'; }

int main()
{
    char ch;

    while( scanf( "%c", &ch ) != EOF )
    {
        if( !isalpha( ch ) )
            putchar( ch );
        else if( isvowel( tolower( ch ) ) )
        {
            putchar( ch );
            while( isalpha( cin.peek() ) )
                putchar( getchar() );
            printf( "ay" );
        }
        else
        {
            while( isalpha( cin.peek() ) )
                putchar( getchar() );
            printf( "%cay", ch );
        }
    }

	return 0;
}