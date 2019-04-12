#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class book
{
	public:
		book( string t, string a ) { author = a; title = t; borrowed = returned = false; }
		bool borrowed, returned;
		string author, title;
};
vector<book> all;
string in, command, req;

void shelve(), borrow(), back();
bool cmpa( book a, book b ){ return ( a.author < b.author ); }
bool cmpt( book a, book b ){ return ( a.title < b.title ); }

int main()
{
	while( getline( cin, in ) && in != "END" )
		all.push_back( book( in.substr( 0, in.find_last_of( "\"" ) + 1 ), 
					in.substr( in.find_last_of( "\"" ) + 1 ) ) );
	stable_sort( all.begin(), all.end(), cmpt );
	stable_sort( all.begin(), all.end(), cmpa );

	while( cin >> command )
		if( command == "BORROW" )
			cin.get(), borrow();
		else if( command == "RETURN" )
			cin.get(), back();
		else if( command == "SHELVE" )
			cin.get(), shelve();
}

void shelve()
{
	for( int i = 0, j; i < all.size(); ++i )
		if( all[ i ].returned == true )
		{
			for( j = i; j >= 0; --j )
				if( all[ j ].borrowed == false )
					break;
			if( j == -1 )
				printf( "Put %s first\n", all[ i ].title.c_str() );
			else
				printf( "Put %s after %s\n", all[ i ].title.c_str(), all[ j ].title.c_str() );
			all[ i ].borrowed = all[ i ].returned = false;
		}
	cout << "END\n";
}

void borrow()
{
	getline( cin, req );
	for( int i = 0; i < all.size(); i++ )
		if( all[ i ].title == req )
		{
			all[ i ].borrowed = true;
			return;
		}
}

void back()
{
	getline( cin, req );
	for( size_t i = 0; i < all.size(); i++ )
		if( all[ i ].title == req )
		{
			all[ i ].returned = true;
			return;
		}
}
