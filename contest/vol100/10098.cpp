#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;

	while( cin >> s )
	{
		sort( s.begin(), s.end() );
		do
			cout << s << endl;
		while( next_permutation( s.begin(), s.end() ) );
		cout << endl;
	}
}
