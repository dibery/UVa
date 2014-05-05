#include<cstdio>

int main()
{
    int people, round;
    scanf( "%d", &people );
    round = people + ( people % 16? 16 - people % 16 : 0 );
    char name[ people ][ 101 ], *song[ 16 ] = { "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };

    for( int i = 0; i < people; ++i )
        scanf( "%s", name+i );
    for( int i = 0; i < round; ++i )
        printf( "%s: %s\n", name[ i % people ], song[ i % 16 ] );

	return 0;
}