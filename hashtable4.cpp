/* name :Sreekar B
         CS14BTECH11033
*/
//implementing hash tables using quadratic probing
#include"iostream"
#include"string"                                 //for length of string
using namespace std;

class node{
  public:
	bool b;                                      //declaring a class
	string k;
	bool del;
};
class hash4{
  public:
  	 node a[100];                                  //declaration of functions and array
     void insert(string k);
	 void del(string k);
	 void search(string k);
	 int hash_func(string k);
};
void hash4::insert(string k)
{
	int i=0;
	int n;
	int h=hash_func(k);                           //getting value from hash function
	n=h;
	while(a[n].b==true)                           //searching for a blank space after that hash value
	{
		i++;
		n=h+(i*i);                                        //quadratic probing
		if(n>=100)
		n=n%100;                                     //if the size exceeds the maximum size of the array then it will go to starting
    }
	a[n].b=true;                                //inserting value
	a[n].k=k;
    
}
void hash4::search(string k)
{
	int i=0,f=0;
	int h=hash_func(k);                 //getting hash value
	int n=h;
	while(a[n].b==true)                           //running loop till we get the value
	{
		if(a[n].k==k && a[n].del==false)          //checking if that is the value and wheather it is not deleted
		{
			f=1;
			cout<<"found string"<<endl;
			break;
		}
		else
		{
			i++;
			n=h+(i*i);                                //quadratic probing
			if(n>=100)
			{
				n=n%100;                                     //if the size exceeds the maximum size of the array then it will go to starting
			}
		}
	}
	if(f==0)
	cout<<"no string"<<endl;
}
void hash4::del(string k)
{
	int i=0,f=0;
	int h=hash_func(k);                 //getting hash value
	int n=h;
	while(a[n].b==true)                         //running loop
	{
		if(a[n].k==k && a[n].del==false)              //finding the element
		{
			f=1;
			a[n].del=true;                           //setting del value true
			cout<<"string deleted"<<endl;
			break;
		}
		else
		{
			i++;                        //incrementing
			n=h+(i*i);                                //quadratic probing
			if(n>=100)
			{
				n=n%100;                                    //if the size exceeds the maximum size of the array then it will go to starting
			}
		}
	}
	if(f==0)
	cout<<"no string"<<endl;

}
int hash4::hash_func(string k)
{
	int h,l,a,sum=0;               //hash function by adding ascii values getting remainder when diveided by its size
	l=k.length();
	for(int i=0;i<l;i++)
	{
		a=k[i];
		sum=sum+a;
	}
	h=sum%100;
	return h;
}
main()
{
	hash4 t;
	int i=1;
	string k;
int ch=0;
while(ch<=3){
cout<<"select what you want to do"<<endl;      //running while loop to select the conditions
cout<<"1.insert"<<endl;
cout<<"2.search"<<endl;
cout<<"3.delete"<<endl;
cout<<"4.exit"<<endl;
cout<<"enter your choice:";
cin>>ch;
  switch(ch){
	case 1:
	{while(i==1){
	cout<<"enter the string :";
	cin>>k;
	t.insert(k);
	cout<<"enter 1 to insert more";
	cin>>i;
	}break;}
	case 2:
	{
	int j=1;
	while(j==1){
	cout<<"enter a string to search :";
	cin>>k;
	t.search(k);
	cout<<"enter 1 to search more :";
	cin>>j;
    }break;}
    case 3:
	{
	int n=1;
    while(n==1){
    	cout<<"enter a string to delete :";
    	cin>>k;
		t.del(k);
		cout<<"enter 1 to delete more :";
		cin>>n;
	}break;}}
}

}
/*
Sample input
 insert sreekar,srikanth, sunny
 search sunny
 delete sunny
 search sunny
 
 
sample output
 inserted,inserted,inserted
 found
 deleted
 no string
*/  
 
