#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	string in, ans;

	for( cin >> t; t; --t )
	{
		cin >> in;
		ans = in;
		for( int i = in.size(); i; --i )
		{
			rotate( in.begin(), in.begin()+1, in.end() );
			ans = min( ans, in );
		}
		cout << ans << endl;
	}
}
