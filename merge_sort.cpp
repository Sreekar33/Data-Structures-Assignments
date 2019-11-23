#include"iostream"
using namespace std;

void divide(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);

main()
{
   	

	cout<<"enter the number of elements"<<endl;
	int n,i;
	cin>>n;
    int a[n];
	cout<<"enter the elements"<<endl;
	for(i=0;i<n;i++)
	cin>>a[i];

   	divide(a,0,n-1);
    cout<<"the sorted order is:"<<endl;
   	for(int i=0;i<n;i++)
   	cout<<a[i]<<endl;
}
void divide(int a[],int low,int high)
{
   if(low<high){
	int mid;
	mid=(low+high)/2;
	divide(a,low,mid);
	divide(a,mid+1,high);
	merge(a,low,mid,high);}
}
void merge(int a[],int low,int mid,int high)
{
	int l,m,i,temp[200];
	l=low;
	m=mid+1;
	i=low;
	while( (l<=mid)&&(m<=high))
	{
		if(a[l]<=a[m]){
			temp[i]=a[l];
			l++;
			}
		else{
			temp[i]=a[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	 for(int k=m;k<=high;k++)
	 {
	 	temp[i]=a[k];
	 	i++;
	 }
	 else{
	 	for(int k=l;k<=mid;k++)
	 	{
	 		temp[i]=a[k];
	 		i++;
		 }
	 }
	for(int k=low;k<=high;k++)
    a[k]=temp[k];
}
