#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;

int main()
{
	for( int diff, rita, theo, theo_age; cin >> diff >> rita >> theo; )
	{
		double a = 2, b = 2 * diff + 2, c = diff * diff + diff - 18 - ( rita + theo ) * 2;
		theo_age = ( -b + sqrt( b * b - 4 * a * c ) + DBL_EPSILON ) / 4;
		cout << ( theo_age * theo_age + theo_age - 6 ) / 2 - theo << endl;
	}
}
