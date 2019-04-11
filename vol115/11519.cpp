#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double get_angle( double dx, double dy )
{
	if( dx == 0 )
		if( dy > 0 )
			return M_PI / 2;
		else if( dy < 0 )
			return 1.5 * M_PI;
		else
			return 0;
	else if( dx > 0 )
		return fmod( atan( dy / dx ) + 2 * M_PI, 2 * M_PI );
	else
		return fmod( atan( dy / dx ) + M_PI, 2 * M_PI );
}

double deg_diff( double from, double to )
{
	from = from / M_PI * 180;
	to = to / M_PI * 180;
	return fmod( to - from + 360, 360 );
}

int main()
{
	int t, cmd;

	cout << fixed << setprecision( 0 );
	for( cin >> t; t-- && cin >> cmd; )
	{
		double x = 0, y = 0, tx, ty;
		int deg = 0;
		string missing;

		for( string act, size; cmd-- && cin >> act >> size; )
			if( size != "?" )
				if( act == "fd" )
					x += stoi( size ) * cos( deg * M_PI / 180 ), y += stoi( size ) * sin( deg * M_PI / 180 );
				else if( act == "bk" )
					x -= stoi( size ) * cos( deg * M_PI / 180 ), y -= stoi( size ) * sin( deg * M_PI / 180 );
				else if( act == "lt" )
					deg = ( deg + stoi( size ) ) % 360;
				else
					deg = ( deg - stoi( size ) + 360 ) % 360;
			else
			{
				missing = act;
				tx = x;
				ty = y;
			}

		if( missing == "bk" || missing == "fd" )
			cout << hypot( x, y ) << endl;
		else if( missing == "rt" )
			cout << deg_diff( get_angle( -tx, -ty ), get_angle( x - tx, y - ty ) ) << endl;
		else
			cout << deg_diff( get_angle( x - tx, y - ty ), get_angle( -tx, -ty ) ) << endl;
	}
}
