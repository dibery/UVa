#include<cctype>
#include<iostream>
#include<algorithm>
#include<list>
#include<map>
using namespace std;
map<string,int> ingredient, receipt;
bool cmp( string a, string b ) { return receipt[ a ] != receipt[ b ]? receipt[ a ] < receipt[ b ] : a < b; }

int main()
{
	int t, i, r, budget, cost, need, qnt;
	string binder, name, dish;

	for( cin >> t, cin.get(); t--; )
	{
		ingredient.clear(), receipt.clear();
		getline( cin, binder );
		cin >> i >> r >> budget;
		for( unsigned int n = 0; n < binder.size(); ++n )
			binder[ n ] = toupper( binder[ n ] );

		for( int n = 0; n < i; ++n )
		{
			cin >> name >> cost;
			ingredient[ name ] = cost;
		}
		cin.get();
		for( int n = 0; n < r; ++n, cin.get() )
		{
			getline( cin, dish );
			cin >> qnt;

			for( int n = 0; n < qnt; ++n )
			{
				cin >> name >> need;
				receipt[ dish ] += need * ingredient[ name ];
			}
		}

		list<string> out;
		for( map<string,int>::iterator it = receipt.begin(); it != receipt.end(); ++it )
			out.push_back( it->first );
		out.sort( cmp );
		cout << binder << endl;
		if( receipt[ out.front() ] > budget )
			cout << "Too expensive!\n";
		else
			for( list<string>::iterator it = out.begin(); it != out.end(); ++it )
				if( receipt[ *it ] <= budget )
					cout << *it << endl;
				else
					break;
		cout << endl;
	}
}
