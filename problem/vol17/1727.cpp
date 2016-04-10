#include<bits/stdc++.h>
using namespace std;

int main()
{
	string month[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" }, week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" }, M, W;
	int day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, t;

	for( cin >> t; t--; )
	{
		cin >> M >> W;
		int holiday = 0, days = day[ find( month, month + 12, M ) - month ], start = find( week, week + 7, W ) - week;
		for( int i = 0; i < days; ++i, start %= 7 )
			holiday += start++ > 4;
		cout << holiday << endl;
	}
}
