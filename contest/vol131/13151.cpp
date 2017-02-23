#include<cstdio>
#include<cstring>

int main()
{
	for( int val, cmd, student; scanf( "%i %d", &val, &cmd ) && val; )
	{
		int score = 0;

		for( char act[ 5 ]; cmd-- && scanf( "%s %d", act, &student ); )
			if( !strcmp( act, "i" ) )
				if( student == val )
					++score;
				else
					val = student;
			else if( !strcmp( act, "++i" ) )
				if( student == ++val )
					++score;
				else
					val = student;
			else if( !strcmp( act, "i++" ) )
				if( student == val++ )
					++score;
				else
					val = student + 1;
			else if( !strcmp( act, "--i" ) )
				if( student == --val )
					++score;
				else
					val = student;
			else
				if( student == val-- )
					++score;
				else
					val = student - 1;

		printf( "%d\n", score );
	}
}
