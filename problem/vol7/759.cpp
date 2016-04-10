#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string one[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		   ten[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		   hun[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		   tho[] = { "", "M", "MM", "MMM" }, roman[ 4000 ];

	for( int i = 1; i < 4000; ++i )
	  roman[ i ] = tho[ i / 1000 ] + hun[ i / 100 % 10 ] + ten[ i / 10 % 10 ] + one[ i % 10 ];

	for( string s; getline( cin, s ); )
	  if( find( roman, roman + 4000, s ) == roman + 4000 )
		cout << "This is not a valid number\n";
	  else
		cout << find( roman, roman + 4000, s ) - roman << endl;
}
