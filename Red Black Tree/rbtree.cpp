#include"iostream"
using namespace std;
enum col{red,black};
class node{
	public:
		int data;
		col color;
		node *parent;
		node *left;
		node *right;
};
class tree{
	public:
		node *root=NULL;
        node *nil;
		tree(){
        	nil=new node;
        	nil->color=black;
		}
		void insert(node *temp,int value);
		void search(node *temp,int value);
		void colour(node *x);
		void left_rotate(node *x);
		void right_rotate(node *x);
};
void tree::insert(node *temp,int value)
{
	if(root==NULL)
	{
		root =new node;
		root->color=red;
		root->data=value;
		root->left=nil;
		root->parent=nil;
		root->right=nil;
		colour(root);
		cout<<"root inserted"<<endl;
	}
	else if(temp->data>value)
	{
		if(temp->left==nil)
		{
			temp->left=new node;
			(temp->left)->data=value;
			(temp->left)->color=red;
			(temp->left)->parent=temp;
			(temp->left)->right=nil;
			(temp->left)->left=nil;
			colour(temp->left);
			cout<<"inserted in left"<<endl;
		}
		else
		{
			insert(temp->left,value); 
		}
	}
	else if(temp->data<value)
	{
		if(temp->right==nil)
		{
			temp->right=new node;
			(temp->right)->color=red;
			(temp->right)->data=value;
			(temp->right)->left=nil;
			(temp->right)->parent=temp;
			(temp->right)->right=nil;
			colour(temp->right);
			cout<<"inserted in right"<<endl;
		}
		else
		{
			insert(temp->right,value);
		}
	}
	else if(temp->data==value)
	cout<<"this value is already inserted"<<endl;
}
void tree::colour(node *x)
{   cout<<"painting....."<<endl;
  	while(x!=root&&x->parent->color==red)
   {
   	node *y,*gp;
   	gp=x->parent->parent;
   	if(x->parent==gp->left)
   	{
   		y=gp->right;
   		if(y->color==red)
   		{
   			x->parent->color=black;
   			y->color=black;
   			gp->color=red;
   			x=x->parent->parent;
		   }
		else if(y->color==black)
		{
			if(x->parent->right==x)
			{
				x=x->parent;
				left_rotate(x);
			}
			if(x->parent->left==x)
			{
			  	x->parent->color=black;
			  	right_rotate(x->parent->parent);
			}
		   }   
	   }
	 else if(x->parent==gp->right)
	 {
	 	y=gp->left;
   		if(y->color==red)
   		{
   			x->parent->color=black;
   			y->color=black;
   			gp->color=red;
   			x=x->parent->parent;
		   }
		else if(y->color==black)
		{
			if(x->parent->left==x)
			{
				x=x->parent;
				right_rotate(x);
			}
			if(x->parent->right==x)
			{
			  	x->parent->color=black;
			  	left_rotate(x->parent->parent);
			}
		   }   
	 	
	   }
}
  if(x==root)
  	x->color=black;
  
}
void tree::left_rotate(node *x)
{
	cout<<"rotating left....."<<endl;
	node *y;
	y=x->right;
	x->right=y->left;
	if(y->left!=nil)
	 {
	 	y->left->parent=x;
	 }
	 y->parent=x->parent;
	if(x->parent==nil)
	  root=y;
	  else if(x==x->parent->left)
	   x->parent->left=y;
	   else
	   x->parent->right=y;
	   y->left=x;
	   x->parent=y; 
}
void tree::right_rotate(node *x)
{
	cout<<"rotating right....."<<endl;
	node *y;
	y=x->left;
	x->left=y->right;
	if(y->right!=nil)
	{
		y->right->parent=x;
	}
	y->parent=x->parent;
	if(x->parent==nil)
	  root=y;
	  else if(x==x->parent->right)
	    x->parent->right=y;
	    else
	    x->parent->left=y;
	    y->right=x;
	    x->parent=y;
}
void tree::search(node *temp,int value)
{
	if(temp==NULL)
	{
		cout<<"no value matches your search";
	}
	else if(temp->data==value)
	{
		cout<<"the value is inserted"<<endl;
		if(temp->color==1)
		cout<<"its colour is: black"<<endl;
		else
		 cout<<"its colour is red"<<endl;
	}
	else if(temp->data<value)
	    search(temp->right,value);
	else if(temp->data>value)
	    search(temp->left,value);    
}
main()
{
	tree m;
	node *x;
    int k=1,l;
    while(k==1)
    {
    	cout<<"enter a value";
    	cin>>l;
    	m.insert(m.root,l);
    	cout<<"enter 1 to add more";
    	cin>>k;
	}
    int j=1;
    while(j==1)
    {
    	cout<<"enter a number to search: ";
    	cin>>l;
    	m.search(m.root,l);
    	cout<<"enter 1 to search more: ";
    	cin>>j;
	}
}
