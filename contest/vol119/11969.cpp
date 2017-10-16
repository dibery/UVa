#include<bits/stdc++.h>
using namespace std;

struct student
{
	student()
	{
		scanf( "%[^\n] %d %d\n", name, &qnt, &id );
		for( double i = 0, sub, pnt; i < qnt; ++i )
		{
			scanf( "%lf %lf\n", &sub, &pnt );
			score[ sub ] = pnt;
			order.push_back( sub );
		}
	}
	double get( int n ) { return score[ n ]; }
	int qnt, id;
	char name[ 101 ];
	list<int> order;
	map<int,double> score;
};

int ID = 0;
struct cmp
{
	bool operator() ( student* a, student* b ) { return a->get( ID ) != b->get( ID )? a->get( ID ) > b->get( ID ) : a->id > b->id; }
};

struct subject
{
	subject()
	{
		gets( name );
		scanf( "%u%u\n", &id, &avail );
	}
	void show()
	{
		printf( "%s\n%llu\n", name, admis.size() );
		int rank = 0;
		for( auto i: admis )
			printf( "%d. %s\n", ++rank, i->name );
	}
	char name[ 201 ];
	unsigned id, avail;
	set<student*,cmp> admis;
};

int main()
{
	int P, G;
	subject* program;
	list<student*> graduate;
	map<int,subject*> lookup;

	scanf( "%d %d\n", &P, &G );
	program = new subject[ P ];
	for( int i = 0; i < G; ++i )
		graduate.push_back( new student );
	for( int i = 0; i < P; ++i )
		lookup[ program[ i ].id ] = program + i;

	while( !graduate.empty() )
	{
		auto stu = graduate.front();
		for( int i: stu->order )
		{
			auto school = lookup[ i ];
			ID = school->id;
			if( school->admis.size() < school->avail )
			{
				stu->order.pop_front();
				school->admis.insert( stu );
				break;
			}
			else if( school->avail && cmp()( stu, *school->admis.rbegin() ) )
			{
				stu->order.pop_front();
				school->admis.insert( stu );
				graduate.push_back( *school->admis.rbegin() );
				school->admis.erase( prev( school->admis.end() ) );
				break;
			}
		}
		graduate.pop_front();
	}

	for( int i = 0; i < P; ++i )
		program[ i ].show();
}
