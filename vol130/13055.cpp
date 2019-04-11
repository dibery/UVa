#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	string cmd, name;
	stack<string> dream;

	cin >> n;
	for( int i = 0; i < n; ++i )
	{
		cin >> cmd;

		if( cmd == "Sleep" )
			cin >> name, dream.push( name );
		else if( cmd == "Kick" && !dream.empty() )
			dream.pop();
		else if( cmd == "Test" )
			cout << ( dream.empty()? "Not in a dream" : dream.top().c_str() ) << endl;
	}
}
