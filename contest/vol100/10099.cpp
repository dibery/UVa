//�ϥ�Java���ҥͽЪ`�N�A�̥~�h�����O(class)�ݩR�W�� main �C
//�p�G�J��W�G�Q�������p�A�Ч��sĶ���լݬ�!! �U�sĶ���S�ʤ��P!!
//�w�]����B�H������B�T�w����O�Ψ����U�����Ϊ��C���ɡA�u�ݷt������O�_�q�L!!
#include<cstdio>
#include<cstring>
#include<climits>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

		

void dfs( int pos, int goal, int size, int carry, int cap[], int adj[100][100], bool vis[100]/*, vector<int> *con*/ )
{
	if( pos == goal )
	{
		cap[ pos ] = max( cap[ pos ], carry );//printf("%d\n",cap);
		return;
	}//printf( "*%d\n", pos+1 );if(pos>=100||pos<0)return;
	if( carry <= cap[ pos ] )
		return;
	vis[ pos ] = true;
//	int s = con[ pos ].size();
	for( int i = 0; i < size; ++i )
		//if( !vis[ con[ pos ][ i ] ] )
		if( !vis[ i ] && adj[ i ][ pos ] )
			//dfs( con[ pos ][ i ], goal, size, min( carry, adj[ pos ][ con[ pos ][ i ] ] ), cap, con );
			dfs( i, goal, size, min( carry, adj[ pos ][ i ] ), cap, adj, vis );
	vis[ pos ] = false;
}

int main()
{
	int city, route, t = 0, from, to, all, cap;
	
	while( scanf( "%d %d", &city, &route ) && city + route )
	{
		int adj[ 100 ][ 100 ] = { 0 }, Cap[ 100 ] = { 0 };
		bool vis[ 100 ] = { false };
		priority_queue<int> tmp;
		//vector<int> connect[ city ];
		//memset( adj, 0, sizeof( adj ) );
		//memset( vis, false, sizeof( vis ) );
		while( route-- )
		{
			scanf( "%d %d %d", &from, &to, &cap );
			--from, --to;
			adj[ from ][ to ] = adj[ to ][ from ] = cap-1;
			//connect[ from ].push_back( to );
			//connect[ to ].push_back( from );
		}
		scanf( "%d %d %d", &from, &to, &all );
		//cap = 1;
		--from, --to;
		
		//dfs( from, to, city, INT_MAX, Cap/*, connect*/, adj, vis );
		//--cap;
		vis[ from ] = true;
		for( int i = 0; i < city; ++i )
			if( adj[ from ][ i ] )
				Cap[ i ] = adj[ from ][ i ], tmp.push( adj[ from ][ i ]*100 + i );
		while( !tmp.empty() )
		{
			int self = tmp.top() % 100;
			if( vis[ self ] )
			{
				tmp.pop();
				continue;
			}
			vis[ self ] = true;
			Cap[ self ] = tmp.top() / 100;
			//for( int i = 0; i < city; ++i )
			//printf("%d ",Cap[i]);puts("");
			for( int i = 0; i < city; ++i )
				if( !vis[ i ] && adj[ self ][ i ] )
					tmp.push( min( adj[ self ][ i ]*100, Cap[ self ]*100 ) + i );
		}
		//printf("%d\n",Cap[to]);
		printf( "Scenario #%d\nMinimum Number of Trips = %d\n\n", ++t, (all+Cap[to]-1)/Cap[to] );
	}
}