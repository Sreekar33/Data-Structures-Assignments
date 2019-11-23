#include"iostream"
using namespace std;
class heap{
	public:
	int a[100],n,h;
	void insert();
	void order();
	void delete_max();
	void find_max();
	void print();
	void shuffle(int a[],int i,int j,int k);
	void swap(int a[],int x,int y);	
    int power(int x,int y);
    int e_h(int x);
};
int heap::power(int x,int y)
{
    	int z=1;
    	for(int i=1;i<=y;i++){
    		z=z*x;}
    		return z;
}
int heap::e_h(int x)  
{
    	int k=0;
    	for(int i=0;i<=x;i++)
    	{k=k+power(2,i);}
    	return k;
}

void heap::swap(int a[],int x,int y){
    	int temp;
    	temp=a[x];
    	a[x]=a[y];
    	a[y]=temp;
	}

void heap::shuffle(int a[],int i, int j,int k)
{
		
		if(a[i]<a[j]&&a[j]>a[k])
		 swap(a,i,j);
		 else if(a[i]<a[k]&&a[j]<a[k])
		 swap(a,i,k);
}

void heap::insert()
{
	int i=0,k=0;
	cout<<"how many numbers?"<<endl;
	cin>>n;
	while(k==0){
	if((n>power(2,i)&&n<power(2,i+1))||n==power(2,i))
	  {
	     k=1;
		 h=i;
	  }
	  i++;}

	for(i=1;i<=n;i++){
	cout<<"enter the number"<<endl;
	cin>>a[i];
    }
}
void heap::order()
{
	int k;
	for(int j=h;j<=0;j--) {int i=0;
	for(k=(e_h(j-2)+1);k<=(e_h(j-1));k++){
	 shuffle(a,k,e_h(j-1)+2*i+1,e_h(j-1)+2*i+2);
	 i++;}
	 if(j<h)
	 {
	 	while(j<=h){
	 	for(k=e_h(j-2)+1;k<=e_h(j-1);k++){int i=0;
	 shuffle(a,k,e_h(j-1)+2*i+1,e_h(j-1)+2*i+2);
	 i++;}
	  j++;
		 }
	 }}
}
void heap::print()
{
	cout<<"the elements are "<<endl;
	for(int i=1;i<=n;i++)
	  cout<<"element:"<<a[i]<<endl;
}
main()
{
	heap m;
	  m.insert();
	  m.order();
	  m.print();
	  
}
