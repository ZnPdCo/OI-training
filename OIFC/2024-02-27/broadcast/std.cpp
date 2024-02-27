#pragma GCC optimize( 3, "inline", "Ofast" )
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// ifstream cin( "broadcast.in" );
// ofstream cout( "broadcast.out" );
const int MAXN = 1000010;
int x[ MAXN ], d[ MAXN ];

struct Tarjan
{
	int dfn[ 2 * MAXN ], low[ 2 * MAXN ], cnt, s[ 2 * MAXN ], in_stack[ 2 * MAXN ], tp;
	int col[ 2 * MAXN ], sc;
	int sz[ 2 * MAXN ];
	vector< int > g[ 2 * MAXN ];
	void add_edge( int u, int v )
	{
		g[ u ].emplace_back( v );
	}
	void tarjan( int x )
	{
		low[ x ] = dfn[ x ] = ++cnt;
		s[ ++tp ] = x;
		in_stack[ x ] = 1;
		for ( auto i : g[ x ] )
		{
			if ( !dfn[ i ] )
			{
				tarjan( i );
				low[ x ] = min( low[ x ], low[ i ] );
			}
			else if ( in_stack[ i ] )
			{
				low[ x ] = min( low[ x ], dfn[ i ] );
			}
		}
		if ( dfn[ x ] == low[ x ] )
		{
			sc++;
			while ( s[ tp ] != x )
			{
				col[ s[ tp ] ] = sc;
				sz[ sc ]++;
				in_stack[ s[ tp ] ] = 0;
				tp--;
			}
			col[ s[ tp ] ] = sc;
			sz[ sc ]++;
			in_stack[ s[ tp ] ] = 0;
			tp--;
		}
	}
	void solve( int n )
	{
		for ( int i = 1; i <= n; i++ )
		{
			if ( !col[ i ] )
			{
				tarjan( i );
			}
		}
	}
} G;
int id[ 2 * MAXN ];
int tot;
int trtot;
int lson[ 2 * MAXN ], rson[ 2 * MAXN ];
int build( int l, int r )
{
	int x = ++trtot;
	if ( l == r )
	{
		id[ x ] = l;
		return x;
	}
	id[ x ] = ++tot;
	int mid = ( l + r ) / 2;
	lson[ x ] = build( l, mid );
	rson[ x ] = build( mid + 1, r );
	G.add_edge( id[ x ], id[ lson[ x ] ] );
	G.add_edge( id[ x ], id[ rson[ x ] ] );
	return x;
}
void add( int x, int l, int r, int L, int R, int i )
{
	if ( L <= l and r <= R )
	{
		G.add_edge( i, id[ x ] );
		return;
	}
	int mid = ( l + r ) / 2;
	if ( L <= mid )
	{
		add( lson[ x ], l, mid, L, R, i );
	}
	if ( R > mid )
	{
		add( rson[ x ], mid + 1, r, L, R, i );
	}
}
bool haveo[ 2 * MAXN ];
vector< int > edges[ 2 * MAXN ];
int ind[ 2 * MAXN ];
class IO
{
	char ibuf[ 1 << 16 ], obuf[ 1 << 16 ], *ipl = ibuf, *ipr = ibuf, *op = obuf;
	
public:
	~IO()
	{
		write();
	}
	void read()
	{
		if ( ipl == ipr )
			ipr = ( ipl = ibuf ) + fread( ibuf, 1, 1 << 15, stdin );
	}
	void write()
	{
		fwrite( obuf, 1, op - obuf, stdout ), op = obuf;
	}
	char getchar()
	{
		return ( read(), ipl != ipr ) ? *ipl++ : EOF;
	}
	void putchar( char c )
	{
		*op++ = c;
		if ( op - obuf > ( 1 << 15 ) )
			write();
	}
	template < typename V > IO& operator>>( V& i )
	{
		int s = 1;
		char c = getchar();
		i = 0;
		for ( ; !isdigit( c ); c = getchar() )
			if ( c == '-' )
				s = -s;
		for ( ; isdigit( c ); c = getchar() )
			i = ( i << 1 ) + ( i << 3 ) + ( c ^ 48 );
		return i *= s, *this;
	}
	IO& operator<<( char c )
	{
		return putchar( c ), *this;
	}
	template < typename V > IO& operator<<( V i )
	{
		if ( !i )
			putchar( '0' );
		if ( i < 0 )
			putchar( '-' ), i = -i;
		char stk[ 100 ], *top = stk;
		for ( ; i; i /= 10 )
			*++top = i % 10 + '0';
		while ( top != stk )
			putchar( *top-- );
		return *this;
	}
} io;
int main()
{
	freopen("E:\\OI-training\\OIFC\\2024-02-27\\broadcast\\3.in", "r", stdin);
//	freopen( "broadcast.in", "r", stdin );
//	freopen( "broadcast.out", "w", stdout );
	int n;
	io >> n;
	tot = n;
	for ( int i = 1; i <= n; i++ )
	{
		io >> x[ i ] >> d[ i ];
	}
	build( 1, n );
	for ( int i = 1; i <= n; i++ )
	{
		int l = lower_bound( x + 1, x + n + 1, x[ i ] - d[ i ] ) - x;
		int r = upper_bound( x + 1, x + n + 1, x[ i ] + d[ i ] ) - x - 1;
		add( 1, 1, n, l, r, i );
	}
	G.solve( tot );
	
	for ( int i = 1; i <= n; i++ )
	{
		haveo[ G.col[ i ] ] = 1;
	}
	int ans2 = 0;
	for ( int i = 1; i <= G.cnt; i++ )
	{
		if ( haveo[ i ] )
		{
			ans2++;
		}
	}
	for ( int i = 1; i <= tot; i++ )
	{
		for ( auto j : G.g[ i ] )
		{
			if ( G.col[ i ] != G.col[ j ] )
			{
				if(G.col[i] == 0 || G.col[j] == 0) printf("F");
				edges[ G.col[ i ] ].emplace_back( G.col[ j ] );
//				cout << G.col[ i ] << ' ' << G.col[ j ] << endl;
				ind[ G.col[ j ] ]++;
			}
		}
	}
	queue< int > q;
	for ( int i = 1; i <= G.cnt; i++ )
	{
		if ( !ind[ i ] )
		{
			q.emplace( i );
		}
	}
	int ans1 = 0;
	while ( !q.empty() )
	{
		int x = q.front();
		q.pop();
		if ( !haveo[ x ] )
		{
			for ( auto i : edges[ x ] )
			{
				ind[ i ]--;
				if ( ind[ i ] == 0 )
				{
					q.emplace( i );
				}
			}
		}
		else
		{
			ans1++;
		}
	}
	cout << ans1 << endl << ans2 << endl;
}
