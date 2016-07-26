#include<iostream>
using namespace std;

int main()
{
	for( int base, first, second; cin >> base >> first >> second; )
	{
		int carry = 0, len = 0, digit = first;
		do
		{
			++len;
			int tmp = ( digit * second + carry ) / base;
			digit = ( digit * second + carry ) % base;
			carry = tmp;
		}
		while( carry || digit != first );
		cout << len << endl;
	}
}
