#include<iostream>
#include<map>
using namespace std;

int main()
{
	for( int man, act, money, t = 0; cin >> man >> act && man + act; )
	{
		map<string,int> owe;
		string name, name2;

		for( int i = 0; i < man; ++i )
			cin >> name;
		for( int i = 0; i < act; ++i )
		{
			cin >> name >> name2 >> money;
			owe[ name ] += money;
			owe[ name2 ] -= money;
		}

		cout << "Case #" << ++t << endl;
		for( map<string,int>::iterator i = owe.begin(); next( i ) != owe.end(); ++i )
			if( i->second > 0 )
			{
				cout << next( i )->first << ' ' << i->first << ' ' << i->second << endl;
				next( i )->second += i->second;
			}
			else
			{
				cout << i->first << ' ' << next( i )->first << ' ' << -i->second << endl;
				next( i )->second += i->second;
			}
		cout << endl;
	}
}
