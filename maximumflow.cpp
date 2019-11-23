#include"iostream"
using namespace std;

class network_flow{
	public:
	int V,E,s,t;	
	int a[50][50];
	int r[50][50];
	int parent[50];
	bool visited[50];
	bool bfs(int a[50][50],int s,int t,int p[50]);
	int max_flow(int a[50][50],int s,int t);
	void input();
};
void network_flow::input()
{
	cout<<"enter the number of vertices:";
	cin>>V;
	cout<<"enter the number of edges:";
	cin>>E;
	cout<<"enter the edge if it is from 1 to 2 and capacity 5 enter 1 2 5 :";
	for(int i=0;i<V;i++)
	{for(int j=0;j<V;j++)
	   a[i][j]=r[i][j]=0;}
	for(int i=0;i<E;i++)
	{
		int u,v,w;
		cin>>u;
		cin>>v;
		cin>>w;
		a[u][v]=w;
	}
	  cout<<"enter the source:";
	  cin>>s;
	  cout<<"enter the destination:";
	  cin>>t;	
}
bool network_flow::bfs(int a[50][50],int s,int t,int parent[50])
{
	int queue[50];
	int size=0;
	for(int i=0;i<V;i++)
	{visited[i]=false;}
	queue[0]=s;
	size++;
	parent[s]=-1;
	visited[s]=true;
	while(size!=0)
	{
		int u;
		u=queue[size];
		queue[size]=0;
		size--;
		for(int v=0;v<=V;v++)
		  {
		  	if(visited[v]==false&&a[u][v]>0)
		  	{
		  		size++;
		  		queue[size]=v;
		  		parent[v]=u;
		  		visited[v]=true;
			  }
		  }
	}
	if(visited[t]==true)
	return true;
	else
	return false;
}
int network_flow::max_flow(int a[50][50],int s,int t)
{
	int u,v;
	int max=0;
	//input();
	for(u=0;u<V;u++)
	  for(v=0;v<V;v++)
	  {
	  	r[u][v]=a[u][v];
	  }
	while(bfs(r,s,t,parent))
	{
		int min_flow=1000;
		v=t;
		u=parent[t];
		while(u!=s)
		{
			
			if(min_flow>r[u][v])
			min_flow=r[u][v];
			else
			min_flow=min_flow;
		    v=u;
			u=parent[v];
		}
		v=t;
		u=parent[t];
		while(u!=s)
		{
			r[u][v]=r[u][v]-min_flow;
			r[v][u]=r[v][u]+min_flow;
		    v=u;
			u=parent[v];
		}
        max=max+min_flow;
	}
return max;
}
main()
{
	network_flow t;
	t.input();
	int k=t.max_flow(t.a,t.s,t.t);
    cout<<"the maximum flow is :"<<k<<endl;
}
