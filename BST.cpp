#include"iostream"
using namespace std;
class node{
	public:
	int data;
	node *left;
	node *right;
   };
 class BST {
   public:
   int z;
   node *root=NULL;
   node *temp;
   node *temp1;
   node *temp2;
   node *temp3;
   void input();
   void insert(node *temp,int value);
   void search(node *temp2,int value);
   int del_search(node *temp,int value);
   void search1();
   void del(node *temp,int value);
};
void BST::input()
{
	int k;
	cout<<"enter a value to be inserted"<<endl;
	cin>>k;
    insert(root,k);	
}
void BST::search1()
{
	int k;
	cout<<"enter the value to search"<<endl;
	cin>>k;
	search(root,k);
}
void BST::insert(node *temp, int value)
{
	if(root==NULL)
	{
		root=new node;
		root->data=value;
		root->left=NULL;
		root->right=NULL;
		cout<<"root inserted"<<endl;
		}
    else if(temp->data<value){
      if(temp->right==NULL){
       	 	temp->right=new node;
    		(temp->right)->data=value;
	    	(temp->right)->left=NULL;
		    (temp->right)->right=NULL;
		    cout<<"inserted in right"<<endl;
        }
      else 
	   insert(temp->right,value); 
      }
    else if(temp->data>value){
    	if(temp->left==NULL){
       		temp->left=new node;
    		(temp->left)->data=value;
	    	(temp->left)->left=NULL;
		    (temp->left)->right=NULL;
		    cout<<"inserted in left"<<endl;
       }
    	  else
    	   insert(temp->left,value);
		}
    else if(temp->data==value)	
	     cout<<"this is already inserted"<<endl;

}
void BST::search(node *temp2,int value)
{
	temp1=temp2;
	if(temp1==NULL)
	{
		cout<<"no element matches your search"<<endl;
	
	}
	else if(temp1->data==value){
	 cout<<"we have your element"<<endl;
	}
	else if(temp1->data>value)
	  search(temp1->left,value);
	else if(temp1->data<value)
	 search(temp1->right,value);   
   
}
int BST::del_search(node *temp2,int value)
{	
    temp1=temp2;
	if(temp1==NULL)
		z=1;
	else if(temp1->data==value)
	    z=2;
	else if(temp1->data>value)
	  del_search(temp1->right,value);
	else if(temp1->data<value)
	 del_search(temp1->right,value);

return z;
}
void BST::del(node *temp,int value)
{
	int l=del_search(root,value);
	if(l==2){
	node *parent;
	node *temp4;
	int i;
	if(temp==NULL)
	  cout<<"no items in BST"<<endl;
	while(temp!=NULL)
	  {
	  	parent=temp;
		  if(temp->data>value)
	  	 {temp=temp->left;
	  	    }
	  	 else if(temp->data<value)
	  	   {temp=temp->right;
	  	      }
	  	  
	  	 if(temp->data==value)
	  	   {
			temp2=temp;
			temp=NULL;}
 	  }  
    if(temp2->left==NULL&&temp2->right==NULL)
      delete temp2;
    else if(temp2->left==NULL&&temp2->right!=NULL)
	    {parent->right=temp2->right;
	    delete temp2;}
	else if(temp2->left!=NULL&&temp2->right==NULL)
	  {
	  	parent->left=temp2->left;
	  	delete temp2;
		  }
	else if(temp2->left!=NULL&&temp2->right!=NULL)
	{
		temp3=temp2->right;
		  if(temp3->left==NULL)
		  {
		  	temp2=temp3;
		  }
		  while(temp3->left!=NULL)
		  {
		  	temp4=temp3;
			  temp3=temp3->left;
		  }
		  temp2->data=temp4->data;
		  delete temp4;
		  }      
}
else
cout<<"the element is not in the tree"<<endl;
}
main()
{

	BST l;
	int i=1;
	int ch=0;
while(ch<=3){
cout<<"select what you want to do"<<endl;
cout<<"1.insert in tree"<<endl;
cout<<"2.search"<<endl;
cout<<"3.delete"<<endl;
cout<<"4.exit"<<endl;
cout<<"enter your choice:";
cin>>ch;
  switch(ch){
	case 1:
	{while(i==1){
	l.input();
	cout<<"enter 1 to add more numbers"<<endl;
	cin>>i;
	}break;}
	case 2:
	{
	int j=1;
	while(j==1){
	l.search1();
	cout<<"enter 1 to search more numbers"<<endl;
	cin>>j;
    }break;}
    case 3:
	{
	int k=1;
    while(k==1){
    	cout<<"enter a element to delete"<<endl;
    	int n;
		cin>>n;
		l.del(l.root,n);
		cout<<"enter 1 to delete more numbers"<<endl;
		cin>>k;
	}break;}}
}

}
