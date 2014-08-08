#include<cstdio>
#include<cstring>

void perm( char* str, char* ans, int index, int now )
{
	if( !now )
		return;
	int blank = 0, pos = ( index % now? index % now : now ) - 1;	//pos : 0 ~ N-1
	for( int ins = 0; ; blank += ans[ ins ] == '\0', ++ins )
		if( blank == pos && !ans[ ins ] )
		{
			ans[ ins ] = str[ now-1 ];
			break;
		}
	perm( str, ans, (index + now-1) / now, now-1 );
}

int main()
{
	int t, seq;
	char str[ 30 ] = { 0 };

	for( scanf( "%d", &t ); t; --t )
	{
		char ans[ 30 ] = { 0 };
		scanf( "%s %d", str, &seq );
		perm( str, ans, seq, strlen( str ) );
		puts( ans );
	}
}
