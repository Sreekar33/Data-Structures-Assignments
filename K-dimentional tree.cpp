/* Sreekar B
    CS14BTECH11033
    k dimensional binary search tree*/
#include"iostream"
using namespace std;
 
class node{
	public:                                         //declaring the node just same as BST but with an array of integers with size 2
		int a[2];
		node *left;
		node *right;
};
class kdbst{
	public:
		node *head=NULL;
		int k[2];                          //declaring the functions
		int aa[100][3];
		int size;
		int t;
		void insert(node *temp,int k[2],int t);
		void search();
		void input();
		void inorder(node *temp,int k[2]);
		void pinorder(node *temp);
};
void kdbst::input()
{
        int x,y;
		cout<<"enter the first value:";
		cin>>x;                                  //making separerate for input to insert
		cout<<"enter the second value:";
		cin>>y;
	    k[0]=x;
	    k[1]=y;
	    t=0;
		insert(head,k,t);              //passing into an insetr function
}
void kdbst::insert(node *temp,int k[2],int t)
{
	//cout<<"in insert";
	if(head==NULL)                  //inserting into that node is it is null
	{
	//	cout<<"in insert if";
		head=new node;
		head->a[0]=k[0];
		head->a[1]=k[1];
		head->left=NULL;
		head->right=NULL;
	}
	else
	{
		if(temp->a[t]>k[t])
			{
	//			cout<<"left ki";
				if(temp->left==NULL)
				{
					temp->left=new node;
					temp->left->a[0]=k[0];
					temp->left->a[1]=k[1];         //deciding whether to go left or right
					temp->left->left=NULL;
					temp->left->right=NULL;
				}
				else
				insert(temp->left,k,(t+1)%2);
			}
			else
			{
	//			cout<<"right ki"<<endl;
				if(temp->right==NULL)
				{
					temp->right=new node;
					temp->right->a[0]=k[0];
					temp->right->a[1]=k[1];
					temp->right->left=NULL;           //creating and inserting new node
					temp->right->right=NULL;
				}
				else
				insert(temp->right,k,(t+1)%2);
			}
		//cout<<t<<endl;	
		}
		//node temp;
		//temp!=NULL;
}
void kdbst::search()
{
     cout<<"enter the numbers to search";
     cin>>k[0];
     cin>>k[1];
     size=0;
     int mindisaa;
     inorder(head,k);                                 //going through inorder and comparing all values
     int mind=100000;
     for(int i=0;i<size;i++)
     {
     	if(aa[i][2]<mind)                         //finding minimum distance from that point
     	{
		 mindisaa=i;
     	 mind=aa[i][2];
        }
	 }                          
	 cout<<"the nearest neighbour is "<<aa[mindisaa][0]<<","<<aa[mindisaa][1]<<endl;           //printing nearest neighbour
}
void kdbst::inorder(node *temp,int k[2])
{
	if(!temp)return;
	inorder(temp->left,k);                                    //transversing through inorder
	int t;
	t=((temp->a[0]-k[0])*(temp->a[0]-k[0]))+((temp->a[1]-k[1])*(temp->a[1]-k[1]));       //calculating distance
	//cout<<temp->a[0]<<","<<temp->a[1]<<","<<t<<",;"<<size<<endl;
	aa[size][0]=temp->a[0];
	aa[size][1]=temp->a[1];                     //storing themin separate array
	aa[size][2]=t;
	size++;
	inorder(temp->right,k);       
}
void kdbst::pinorder(node *temp)
{
	if(!temp)return;
	pinorder(temp->left);                         //trasversing in inorder
	cout<<temp->a[0]<<","<<temp->a[1]<<endl;
	pinorder(temp->right);
}
main()
{
	kdbst t;
	int i=1;
	int ch=0;
while(ch<=3){
cout<<"select what you want to do"<<endl;
cout<<"1.insert in tree"<<endl;
cout<<"2.search minimum"<<endl;
cout<<"3.print inorder"<<endl;
cout<<"4.exit"<<endl;
cout<<"enter your choice:";
cin>>ch;
  switch(ch){
	case 1:
	{while(i==1){
	t.input();
	cout<<"enter 1 to add more numbers"<<endl;
	cin>>i;
	}break;}
	case 2:
	{
	int j=1;
	while(j==1){
	t.search();
	cout<<"enter 1 to search more numbers"<<endl;
	cin>>j;
    }break;}
    case 3:
	{
	//int k=1;
    //while(k==1){
    	t.pinorder(t.head);
	//	cout<<"enter 1 to delete more numbers"<<endl;
	//	cin>>k;
	}break;}}

}
/*
sample input
3,6
13,15
17,15
2,5
min search 2,6
2,5
*/
