#include<iostream>
#include<cctype>
using namespace std;

int main()
{
	int size;
	char X = 'X', Y = 'Y', Z = 'Z', x = 'x', y = 'y', z = 'z';
	string cmd;

	while( cin >> size && size )
	{
		char stat = X;

		for( int i = 1; i < size; ++i )
		{
			cin >> cmd;
			if( cmd == "No" )
				continue;
			else if( cmd == "+y" )
				if( stat == X )
					stat = Y;
				else if( stat == x )
					stat = y;
				else if( stat == Y )
					stat = x;
				else if( stat == y )
					stat = X;
				else;
			else if( cmd == "-y" )
				if( stat == X )
					stat = y;
				else if( stat == x )
					stat = Y;
				else if( stat == Y )
					stat = X;
				else if( stat == y )
					stat = x;
				else;
			else if( cmd == "+z" )
				if( stat == X )
					stat = Z;
				else if( stat == x )
					stat = z;
				else if( stat == Z )
					stat = x;
				else if( stat == z )
					stat = X;
				else;
			else if( cmd == "-z" )
				if( stat == X )
					stat = z;
				else if( stat == x )
					stat = Z;
				else if( stat == Z )
					stat = X;
				else if( stat == z )
					stat = x;
		}
		cout << ( isupper( stat )? '+' : '-' ) << char( tolower( stat ) ) << endl;
	}
}
