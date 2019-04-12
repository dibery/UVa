#include<iostream>
#include<sstream>
#include<cctype>
using namespace std;
inline int val( char c )
{
	if( isdigit( c ) )
		return c - '0';
	return 10;
}

int main()
{
	string game;

	while( getline( cin, game ) && game != "Game Over" )
	{
		istringstream in( game );
		char roll[ 30 ] = { 0 };
		int size = 0, score = 0, round = 0;

		while( in >> roll[ size++ ] );
		for( int i = 0; i < size && round < 10; ++i )
			if( isdigit( roll[ i ] ) )
				if( roll[ i+1 ] == '/' )
					score += 10 + val( roll[ i+2 ] ), ++i, ++round;
				else
					score += val( roll[ i ] ) + val( roll[ i+1 ] ), i++, ++round;
			else//
				if( roll[ i+2 ] == '/' )
					score += 20, ++round;
				else
					score += 10 + val( roll[ i+1 ] ) + val( roll[ i+2 ] ), ++round;
		cout << score << endl;
	}
}
