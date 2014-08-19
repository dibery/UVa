#include<iostream>
#include<iomanip>
#include<map>
#include<string>
using namespace std;

int main()
{
	string name[] = { "UTC", "GMT", "BST", "IST", "WET", "WEST", "CET", "CEST", "EET", "EEST", "MSK", "MSD", "AST", "ADT", "NST", "NDT", "EST", "EDT", "CST", "CDT", "MST", "MDT", "PST", "PDT", "HST", "AKST", "AKDT", "AEST", "AEDT", "ACST", "ACDT", "AWST" };
	float zone[] = { 0, 0, 1, 1, 0, 1, 1, 2, 2, 3, 3, 4, -4, -3, -3.5, -2.5, -5, -4, -6, -5, -7, -6, -8, -7, -10, -9, -8, 10, 11, 9.5, 10.5, 8 };
	map<string,float> table;
	string time, ampm, from, to;
	int t, min;

	for( int i = 0; i < 32; ++i )
		table[ name[ i ] ] = zone[ i ];

	for( cin >> t; t; --t )
	{
		cin >> time;
		if( time == "midnight" )
			min = 0;
		else if( time == "noon" )
			min = 720;
		else
		{
			min = stoi( time.substr( 0, time.find( ':' ) ) ) * 60 + stoi( time.substr( time.find( ':' ) + 1 ) );
			if( min > 720 && min < 780 )
				min -= 720;
			cin >> ampm;
			if( ampm == "p.m." )
				min += 720;
		}
		cin >> from >> to;
		min += ( table[ to ] - table[ from ] ) * 60;
		min = ( min + 1440 ) % 1440;
		if( min == 0 )
			cout << "midnight\n";
		else if( min == 720 )
			cout << "noon\n";
		else
			cout << ( min / 60 % 12? min / 60 % 12 : 12 ) << ':' << setw(2) << setfill('0') << min % 60 << ( min > 720? " p.m." : " a.m." ) << endl;
	}
}
