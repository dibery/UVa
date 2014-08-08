//�ϥ�Java���ҥͽЪ`�N�A�̥~�h�����O(class)�ݩR�W�� main �C
//�p�G�J��W�G�Q�������p�A�Ч��sĶ���լݬ�!! �U�sĶ���S�ʤ��P!!
//�w�]����B�H������B�T�w����O�Ψ����U�����Ϊ��C���ɡA�u�ݷt������O�_�q�L!!
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	scanf( "%d", &t );
	
	while( t-- )
	{
		int size, n;
		priority_queue<int> neg, pos, N, P;
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d", &n );
			if( n > 0 )
				pos.push( n ), P.push( n );
			else
				neg.push( -n ), N.push( -n );
		}
		int now = pos.top()+1, A = 0, B = 0;
		while( true )
		{
			while( !pos.empty() && pos.top() >= now )
				pos.pop();
			if( pos.empty() )
				break;
			++A;
			now = pos.top();
			pos.pop();
			
			while( !neg.empty() && neg.top() >= now )
				neg.pop();
			if( neg.empty() )
				break;
			++A;
			now = neg.top();
			neg.pop();
		}
		now = N.top()+1;
		while( true )
		{
			while( !N.empty() && N.top() >= now )
				N.pop();
			if( N.empty() )
				break;
			++B;
			now = N.top();
			N.pop();
			
			while( !P.empty() && P.top() >= now )
				P.pop();
			if( P.empty() )
				break;
			++B;
			now = P.top();
			P.pop();
		}
		printf( "%d\n", max( A, B ) );
	}
}