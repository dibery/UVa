#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;  

int main()  
{  
	int test;  
	cin >> test;  

	while( test-- )
	{  
		int people, *time, total = 0, tmp;
		cin >> people;
		tmp = people;
		time = new int[ people ];

		for( int i = 0; i < people; ++i )  
			cin >> time[ i ];
		sort( time, time + people );

		while( people > 3 && time[ 0 ] + time[ people-2 ] > time[ 1 ] << 1 )  //sent B fist
		{
			total += time[ 1 ] + time[ 0 ] + time[ people-1 ] + time[ 1 ];  //BAEB
			people -= 2;
		}
		while( people > 2 )
		{
			total += time[ people-1 ] + time[ 0 ];  //DA
			--people;
		}
		if( people > 1 )
			total += time[ 1 ]; //B
		else
			total = time[ 0 ];
		cout << total << endl;

		people = tmp;

		while( people > 3 && time[ 0 ] + time[ people-2 ] > time[ 1 ] << 1 )    //sent B fist
		{
			printf( "%d %d\n%d\n%d %d\n%d\n", time[ 0 ], time[ 1 ], time[ 0 ], time[ people-2 ], time[ people-1 ], time[ 1 ] );
			people -= 2;
		}
		while( people > 2 )
		{
			cout << time[ people-1 ] << ' ' << time[ 0 ] << '\n' << time[ 0 ] << '\n';
			--people;
		}
		if( people > 1 )
			cout << time[ 0 ] << ' ' << time[ 1 ] << endl;
		else
			cout << time[ 0 ] << endl;

		delete[] time;
		if( test )
			cout << endl;
	}
	return 0;
}
