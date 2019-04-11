#include<iostream>
#include<sstream>
#include<map>
using namespace std;
const string unit[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million" };
const int val[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000 };

int main()
{
	map<string,int> lookup;

	for( int i = 0; i < 31; ++i )
		lookup[ unit[ i ] ] = val[ i ];

	for( string s, token[ 32 ]; getline( cin, s ); )
	{
		int size = 0, ans = 0;
		for( stringstream ss( s ); ss >> token[ size ]; ++size );
		for( int i = *token == "negative"; i < size; ++i )
		{
			int seg = lookup[ token[ i ] ];
			while( i < size - 1 && lookup[ token[ i + 1 ] ] < 1000 )
				if( lookup[ token[ i + 1 ] ] < 100 )
					seg += lookup[ token[ ++i ] ];
				else
					seg *= 100, ++i;
			if( i < size - 1 )
				seg *= lookup[ token[ ++i ] ];
			ans += seg;
		}
		cout << ( *token == "negative"? "-" : "" ) << ans << endl;
	}
}
