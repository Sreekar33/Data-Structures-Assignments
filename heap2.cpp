#include"iostream"
using namespace std;
class heap{
	public:
		int a[100];
		int i=0;
		void insert();
		void print();
		void delete_max();
		void find_max();
};
void heap::insert()
{
	int k,p,c;
	cout<<"enter the number to insert : ";
	cin>>k;
	i++;
	a[i]=k;
	c=i;
	p=i/2;
	while(p!=0)
	{
		if(a[p]<a[c])
		{
			int temp;
			temp=a[p];
			a[p]=a[c];
			a[c]=temp;
		}
		c=p;
		p=c/2;
	}
}
void heap::delete_max()
{
	int temp,p,c1,c2;
	temp=a[1];
	a[1]=a[i];
	a[i]=temp;
    a[i]=0;
    i=i-1;
   	p=1;
    c1=2*p;
    c2=2*p+1;
    while((a[p]<a[c1] || a[p]<a[c2])&&p<i/2)
    {
    	if(a[p]<a[c1]&&a[p]>a[c2])
    	{
			int temp1;
			temp1=a[p];
			a[p]=a[c1];
			a[c1]=temp1;
			p=c1;
   		}
   		else
   		{
			int temp2;
			temp2=a[p];
			a[p]=a[c2];
			a[c2]=temp2;
			p=c2;
		}
    c1=2*p;
    c2=2*p+1;
	}
}
void heap::print()
{
	for(int j=1;j<=i;j++)
	cout<<a[j]<<endl;
}
void heap::find_max()
{
	cout<<"the maximum element is : "<<a[1]<<endl;
}
main()
{
	heap t;
	int k=1;
	while(k==1)
	{
		t.insert();
		cout<<"enter 1 to add more numbers : ";
		cin>>k;
	}
	t.print();
	int m=1;
	while(m==1)
	{
	t.delete_max();
	cout<<"enter 1 if you want to delete more max :";
	cin>>m;
    }
    t.print();
    t.find_max();
}
