#include<iostream>
#include<vector>
using namespace std;

unsigned int calc( vector<string>& prog, int begin, int end )
{
	unsigned int ans = 0;
	int start, i, j;

	if( begin >= end-1 )
		return 1;
	
	for( i = begin+1, start = 1; start && i < prog.size(); i += start != 0 )
		if( prog[ i ] == "IF" )
			start += 2;
		else if( prog[ i ] == "ELSE" || prog[ i ] == "END_IF" )
			--start;
	ans += calc( prog, begin+1, i-1 );

	for( j = begin+1, start = 2; start && j < prog.size(); j += start != 0 )
		if( prog[ j ] == "IF" )
			start += 2;
		else if( prog[ j ] == "ELSE" || prog[ j ] == "END_IF" )
			--start;
	ans += calc( prog, i+1, j-1 );
	
	return ans * calc( prog, j+1, end );
}

int main()
{
	int t;
	string in;
	cin >> t;

	while( t-- )
	{
		vector<string> prog;

		while( cin >> in && in != "ENDPROGRAM" )
			if( in != "S" )
				prog.push_back( in );
		cout << calc( prog, 0, prog.size()-1 ) << endl;
	}
}
