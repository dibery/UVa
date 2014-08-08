#include<cstdio>
#include<cstdlib>

int main()
{
	char sol[ 10 ], op;
	int a, b, correct = 0;

	while( scanf( "%d%c%d=%s", &a, &op, &b, sol ) != EOF )
		if( *sol != '?' )
			if( op == '+' )
				correct += atoi( sol ) == a+b;
			else
				correct += atoi( sol ) == a-b;
	printf( "%d\n", correct );
}
