#include<cstdio>
#include<cstring>

int trans( int* s ) { return s[ 0 ] * 4 + s[ 1 ] * 2 + s[ 2 ]; }

bool reach( int id, int size, char state[], int prev[], int pos = 0 )
{
	if( pos == size )
		return !state[ pos-1 ] == !( id & 1 << prev[ size-2 ] * 4 + prev[ size-1 ] * 2 + prev[ 0 ] ) &&
			!*state == !( id & 1 << prev[ size-1 ] * 4 + prev[ 0 ] * 2 + prev[ 1 ] );
	else
		for( int c = 0; c <= 1; ++c )
		{
			prev[ pos ] = c;
			if( pos < 2 )
				if( reach( id, size, state, prev, pos+1 ) )
					return true;
				else;
			else if( !state[ pos-1 ] == !( id & 1 << trans( prev + pos - 2 ) ) && reach( id, size, state, prev, pos+1 ) )
				return true;
			prev[ pos ] = 0;
		}
	return false;
}

int main()
{
	int id, len, prev[ 32 ] = { 0 };
	char state[ 33 ] = { 0 };

	for( bool ok = false; scanf( "%d %d %s", &id, &len, state ) == 3; ok = false )
	{
		if( strchr( state, '1' ) && !id );
		else if( strchr( state, '0' ) && id == 255 );
		else
		{
			for( int i = 0; state[ i ]; ++i )
				state[ i ] -= '0';
			ok |= reach( id, len, state, prev );
		}
		puts( ok? "REACHABLE" : "GARDEN OF EDEN" );
	}
}
