#include<cstdio>

int calc( bool& ok )
{
	int wl, dl, wr, dr;
	scanf( "%d %d %d %d", &wl, &dl, &wr, &dr );
	if( !wl )
		wl = calc( ok );
	if( !wr )
		wr = calc( ok );
	ok &= wl * dl == wr * dr;
	return wl + wr;
}

int main()
{
	int t, wl, dl, wr, dr;

	for( scanf( "%d", &t ); t--; printf( t? "\n" : "" ) )
	{
		bool ok = true;
		scanf( "%d %d %d %d", &wl, &dl, &wr, &dr );
		if( !wl )
			wl = calc( ok );
		if( !wr )
			wr = calc( ok );
		puts( ok && wl * dl == wr * dr? "YES" : "NO" );
	}
}
