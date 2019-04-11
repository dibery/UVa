#include<cstdio>

int main()
{
	for( int prop, hunter, obj; scanf( "%d %d %d", &prop, &hunter, &obj ) == 3; )
		puts( obj - prop < hunter? "Hunters win!" : "Props win!" );
}
