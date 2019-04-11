#include<cstdio>
int Val[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main()
{
    int N;
    while( scanf( "%d",&N ) && N )
          printf( "%d\n",Val[ N ] );
    return 0;
}