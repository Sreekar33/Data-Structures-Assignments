#include"iostream"
using namespace std;
class heap{
public:
	int a[100];
	void sort(int a[]);
	int n;
	void input();
	void print();
};
void heap::input()
{
	cout<<"enter the number of numbers :";
	cin>>n;
	cout<<"enter the numbers"<<endl;
	for(int i=0;i<n;i++)
	  cin>>a[i];
}
void heap::sort(int *a)
{
     int t;
     t=n-1;
     while(t>0)
     {
     	if(t<n-1){
     	for(int t=t;t<=n;t=2*t+2)
		 
		 {if(2*t+2>n-1)
		   t=n-1;
		 if(t%2==0)
     	{
     		for(int i=t;i>=t/2;i=i-2)
     		 {
     		 	if(a[t]>a[t-1]&&a[(t-1)/2]<a[t]){
     		 	int temp;
     		 	temp=a[t];
     		 	a[t]=a[(t-1)/2];
     		 	a[(t-1)/2]=temp;
			  }
			  else if(a[t]<a[t-1]&&a[(t-1)/2]<a[t-1])
			  {
                int temp;
     		 	temp=a[t-1];
     		 	a[t-1]=a[(t-1)/2];
     		 	a[(t-1)/2]=temp;
			  	
			  }
             }
	     }
	     else{
	     	if(a[(t-1)/2]<a[t])
	     	{
	     		cout<<"jdvn "<<a[t]<<" hgfhadsui "<<endl;
				 int temp;
	     		temp=a[t];
	     		a[t]=a[(t-1)/2];
	     		a[(t-1)/2]=temp;
			 }
      		for(int i=t-1;i>=t/2;i=i-2)
     		 {
     		 	if(a[t]>a[t-1]&&a[(t-1)/2]<a[t]){
     		 	int temp;
     		 	temp=a[t];
     		 	a[t]=a[(t-1)/2];
     		 	a[(t-1)/2]=temp;
			  }
			  else if(a[t]<a[t-1]&&a[(t-1)/2]<a[t-1])
			  {
                int temp;
     		 	temp=a[t-1];
     		 	a[t-1]=a[(t-1)/2];
     		 	a[(t-1)/2]=temp;
			  	
			  }
             }}

		 }}
  t=(t-1)/2;
}
}
void heap::print()
{
	for(int i=0;i<n;i++)
	cout<<" "<<a[i]<<" ";
}
main()
{
	heap t;
	t.input();
	t.sort(t.a);
	t.print();
}

