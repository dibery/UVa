#include<iostream>
using namespace std;

int main()
{
	int t, game;
	char a, b, c;

	cin >> t;
	for( int n = 1; n <= t; ++n )
	{
		int ans = 0;
		cin >> game;
		if( game < 3 )
		{
			while( game-- )
				cin >> c;
			cout << "Case " << n << ": Yay! Mighty Rafa persists!\n";
			continue;
		}
		cin >> a >> b >> c;
		for( ans = 3; ans < game && ( a == 'W' || b == 'W' || c == 'W' ); ++ans )
			a = b, b = c, cin >> c;
		if( ans == game && ( a == 'W' || b == 'W' || c == 'W' ) )
			cout << "Case " << n << ": Yay! Mighty Rafa persists!\n";
		else
			cout << "Case " << n << ": " << ans << endl;
		while( ans++ < game )
			cin >> c;
	}
}
