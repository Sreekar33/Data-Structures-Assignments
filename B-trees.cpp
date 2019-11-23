#include"iostream"
using namespace std;
class node{
	public:
	int k[6];
	int key_count;
	int leaf;
	node *c[6];
	node *parent;
};
class B_tree{
	public:
		node *root=NULL;
		node *temp;
		void insert(int value);
		void sort(int a[],int cc);
		void split(node *x);
		void del(int value);
};
void B_tree::insert(int value)
{
	temp=root;
	if(root==NULL)
	{
		root=new node;
		root->k[1]=value;
		root->c[1]=root->c[2]=root->c[3]=root->c[4]=root->c[5]=root->c[6]=NULL;
		root->parent=NULL;
		root->key_count=1;
		root->leaf=1;
		root!=NULL;
	}
	else{
		//cout<<"i am in else";
	   //deciding temp
	   while(temp->leaf==0)
	   {
	    //cout<<"value of temp->key_count"<<temp->key_count<<endl;
	    //cout<<"value of temp.keycount value"<<temp->k[temp->key_count]
		//cout<<"value of temp->k[1]=="<<temp->k[1]<<endl;

		 if(temp->k[1]>value)
	     {
	     	cout<<"temp c1";
			temp=temp->c[1];
	     	break;
		 }
	   else if(temp->k[temp->key_count]<value)
		 {
		 cout<<"temp c"<<temp->key_count+1<<"(calculated)";
			 temp=temp->c[temp->key_count+1];
	     }
		 else{
		 	for(int i=1;i<temp->key_count;i++)
		 	 {
		 	 	if(temp->k[i]<value && temp->k[i+1]>value)
		 	 	{
		 	 		cout<<"temp c"<<  i+1 <<"(calculated)";
					  temp=temp->c[i+1];
					  cout<<"temp->keycount="<<temp->key_count<<endl;
		 	 		break;
				}
			  }
		 }
	   }
	   //inserting into temp
	   if(temp->key_count<4)
	   {
	    
		 temp->k[temp->key_count+1]=value;
	     temp->key_count++;
	    //cout<<"i am in temp key count is"<<temp->key_count<<endl;
		 sort(temp->k,temp->key_count);
		// for(int i=1;i<=temp->key_count;i++)
		 //cout<<temp->k[i]<<endl;
	   }
	   else if(temp->key_count==4)
	   {cout<<"i am in temp->key_vount =4"<<endl;
	   	temp->k[5]=value;
	   	 sort(temp->k,temp->key_count+1);
		 //for(int i=1;i<=temp->key_count+1;i++)
		 //{cout<<temp->k[i]<<endl;}
         cout<<"have to split"<<endl;
	   	 //have to split
		 split(temp);
	   }
	}
}
void B_tree::split(node *x)
{node *y,*z;
	cout<<"split start";
	if(x==root)
	{cout<<"entered x parent";
		if(x->c[1]==NULL)
		{
		//	cout<<"declaring new nodes";
			root->c[1]=new node;
			root->c[2]=new node;
		//	cout<<"declaring nodes over";
			root->c[1]->k[1]=root->k[1];
			root->c[1]->k[2]=root->k[2];
			root->c[2]->k[1]=root->k[4];
			root->c[2]->k[2]=root->k[5];
			root->k[1]=root->k[3];
		//	cout<<"root k[1]=="<<root->k[1]<<endl;
		//	cout<<"root k[3]=="<<root->k[3]<<endl;
			root->k[2]=root->k[3]=root->k[4]=root->k[5]=0;
		//	cout<<"root k[3]=="<<root->k[3]<<endl;
			root->c[1]->c[1]=root->c[1]->c[2]=root->c[1]->c[3]=root->c[1]->c[4]=root->c[1]->c[5]=root->c[1]->c[6]=NULL;
			root->c[2]->c[1]=root->c[2]->c[2]=root->c[2]->c[3]=root->c[2]->c[4]=root->c[2]->c[5]=root->c[2]->c[6]=NULL;
			root->c[1]->parent=root;
			root->c[2]->parent=root;
			root->key_count=1;
			root->c[1]->key_count=2;
			root->c[2]->key_count=2;
			root->leaf=0;
			root->c[1]->leaf=1;
			root->c[2]->leaf=1;
		}
		else
		{
			node *temp1;
			node *temp2;
			temp1=new node;
			temp2=new node;
			temp1->c[1]=root->c[1];
			temp1->c[2]=root->c[2];
			temp1->c[3]=root->c[3];
			temp1->c[4]=temp1->c[5]=temp1->c[6]=NULL;
			temp1->k[1]=root->k[1];
			temp1->k[2]=root->k[2];
			temp1->key_count=2;
			temp1->leaf=0;
			temp2->c[1]=root->c[4];
			temp2->c[2]=root->c[5];
			temp2->c[3]=root->c[6];
			temp2->c[4]=temp2->c[5]=temp2->c[6]=NULL;
			temp2->k[1]=root->k[4];
			temp2->k[2]=root->k[5];
			temp2->key_count=2;
			temp2->leaf=0;
			root->c[1]=temp1;
			root->c[2]=temp2;
			root->c[3]=root->c[4]=root->c[5]=root->c[6]=NULL;
			root->k[1]=root->k[3];
			root->k[2]=root->k[3]=root->k[4]=root->k[5]=0;
			root->key_count=1;
			root->leaf=0;
			root->parent=NULL;
			temp1->parent=root;
			temp2->parent=root;

		}
    }
    else
    {
		 y=x->parent;
         //cout<<"parent key count is"<<y->key_count<<endl;
		 y->k[y->key_count+1]=x->k[3];
		 y->key_count=y->key_count+1;
		 y->c[y->key_count+1]=new node;
		 z=y->c[y->key_count+1];
		 z->k[1]=x->k[4];
		 z->k[2]=x->k[5];
		 z->leaf=1;
		 z->c[1]=x->c[4];
		 z->c[2]=x->c[5];
		 z->c[3]=x->c[6];
         z->c[4]=z->c[5]=z->c[6]=NULL;
         z->parent=y;
         z->key_count=2;
         x->key_count=2;
         x->leaf=1;
		 x->c[4]=x->c[5]=x->c[6]=NULL;
		 x->k[3]=x->k[4]=x->k[5]=0;
		 /*y->c[y->key_count]->k[(y->c[y->key_count])->key_count+1]=k[1];
		 y->c[y->key_count]->k[(y->c[y->key_count])->key_count+2]=k[2];
		 y->c[y->key_count]->leaf=1;
		 y->c[y->key_count]->parent=y;*/
	}
	cout<<"split end";
	if(x!=root)
	{
	if(y->key_count==5)
	{
		sort(y->k,5);
		split(y);
	}}
}
void B_tree::sort(int a[],int cc)
{
	int temp;
	for(int i=1;i<cc;i++)
	{
		temp=i;
		for(int j=i+1;j<cc+1;j++)
		{
			if(a[j]<a[temp])
			  temp=j;
		}
		if(temp!=i)
		{
			int temp1;
			temp1=a[i];
			a[i]=a[temp];
			a[temp]=temp1;
		}
	}
	 //for(int i=1;i<=cc;i++)
	 //{cout<<a[i]<<endl;}

}
void B_tree::del(int value)
{
	temp=root;
	int p=0,s=0;
	while(temp!=NULL)
	   {
		 if(temp->k[1]>value)
	     {
    		temp=temp->c[1];
	     	break;
		 }
       else if(temp->k[1]==value)
        {s=1;
		p=1;
		break;}
	   else if(temp->k[temp->key_count]==value)
	   {s=temp->key_count;
	   p=1;
	   break;}
	   else if(temp->k[temp->key_count]<value)
		 {
			 temp=temp->c[temp->key_count+1];
	     }
		 else{
		 	for(int i=1;i<temp->key_count;i++)
		 	 {
		 	 	if(temp->k[i]<value && temp->k[i+1]>value)
		 	 	{
					  temp=temp->c[i+1];
		 	 		break;
				}
				else if(temp->k[i]==value)
				{
					p=1;
					s=i;
					break;
				}
			  }
		 }
       }
    if(p==0)
    {
	cout<<"element is not there";
    }
    else
    {
    	if(temp->leaf==1 && temp->key_count>2)
    	{
    		for(int i=s;i<=temp->key_count-1;i++)
    		{
    			temp->k[i]=temp->k[i+1];
			}
			temp->k[temp->key_count]=0;
			temp->key_count=temp->key_count-1;
		}
		else if(temp->leaf==1&&temp->key_count==2)
		{
			if(temp==root)
			{
				//
			}
			else
			{ int ps;
				for(int i=1;i<=5;i++)
				   {
				   if(temp==temp->parent->c[i])
				   {
				   	ps=i;
				   	break;
				   }
			       }
			       int shiftc=0;
				   if(ps>1&&ps<5){
				   if(temp->parent->c[ps+1]->key_count>2)
				  	{
				  		shiftc=ps+1;
				  		break;
		            }
					else if(temp->parent->c[ps-1]->key_count>2)
					shiftc=ps-1;
					}
					else if(ps==5)
					{
						if(temp->parent->c[ps-1]->key_count>2)
						shiftc=ps-1;
					}
					else
					{
						if(temp->parent->c[ps+1]->key_count>2)
						shiftc=ps+1;
					}
					if(shiftc!=0)
					{
						temp->parent->k[shiftc+1]=temp->parent->c[shiftc]->k[1];
						for(int i=1;i<temp->parent->c[shiftc]->key_count;i++)
						{temp->parent->c[shiftc]->k[i]=temp->parent->c[shiftc]->k[i+1];}
						temp->parent->c[shiftc]->k[temp->parent->c[shiftc]->key_count]=0;
						temp->parent->c[shiftc]->key_count--;
						temp->k[2]=temp->parent->k[3];
						if(temp->k[1]>temp->k[2])
						{
							int t;
							t=temp->k[1];
						    temp->k[1]=temp->k[2];
						    temp->k[2]=t;
						}
						for(int i=3;i<=temp->parent->key_count;i++)
						{temp->parent->k[i]=temp->parent->k[i+1];}
						temp->parent->k[shiftc+1]=0;
					}
				  }  
				  if(shiftc==0)
				  {
			     for(int i=ps-1;i>0;i--)
				  {
				  	if(temp->parent->c[i]->key_count>2)
				  	{
				  		shiftc=i;
				  		break;
					}
					if(shiftc!=0)
					{
						temp->parent->k[temp->parent->key_count+1]=temp->parent->c[shiftc]->k[temp->parent->c[shiftc]->key_count];
						temp->parent->c[shiftc]->k[temp->parent->c[shiftc]->key_count]=0;
						temp->parent->c[shiftc]->key_count--;
						int t;
                 	   for(int i=1;i<temp->parent->key_count+1;i++)
	                   {
		                t=i;
                 		for(int j=i+1;j<temp->parent->key_count+2;j++)
		               {
			             if(temp->parent->k[j]<temp->parent->k[t])
			             t=j;
		               }
		                if(t!=i)
		               {
			           int t1;
			            t1=temp->parent->k[i];
			           temp->parent->k[i]=temp->parent->k[t];
			            temp->parent->k[t]=t1;
		               }
	                   }
                      temp->k[2]=temp->k[1];
                      temp->k[1]=temp->parent->k[ps-1];
                      temp->key_count++;
                      for(int i=ps-1;i<=temp->parent->key_count+1;i++)
                      {temp->parent->k[i]=temp->parent->k[i+1];}
                      temp->parent->k[temp->parent->key_count+1]=0;
					}
				  }  
				 }
				 
		    if(shiftc==0)
		    {
		    	//joining
		      int ttt;
				if(s==1)
		          ttt=temp->k[2];
		    	else 
				  ttt=temp->k[1];	
		    if(ps!=1)
			 {temp->parent->c[ps-1]->k[3]=temp->parent->k[ps-1];
				temp->parent->c[ps-1]->k[4]=ttt;
				temp->parent->k[ps]=0;
				temp->parent->key_count--;
				delete temp;}
			else
			{
				temp->parent->c[2]->k[3]=temp->parent->c[2]->k[1];
				temp->parent->c[2]->k[4]=temp->parent->c[2]->k[2];
				temp->parent->c[2]->k[1]=ttt;
				temp->parent->c[2]->k[2]=temp->parent->k[1];
			    for(int i=1;i<temp->parent->key_count;i++)
			    temp->parent->k[i]=temp->parent->k[i+1];
			    temp->parent->k[temp->parent->key_count]=0;
			    temp->parent->key_count--;
			    delete temp;
			}	
			}
			}
	   }
	   else if(temp->leaf!=1)
	   {
	   	//position of value is s and k[s] is value
		   node *temp1;
		   temp1=temp;
		   int r;
		   temp1=temp1->c[s+1];
		   if(temp1->leaf==1)
		   {
		   	 r=temp1->k[1];
		   	 temp1->k[1]=temp->k[s];
		   	 temp->k[s]=r;
		   	 del(value);
		   }
		   else
		   {
		   	while(temp1->leaf!=1)
		   	{
		   		temp1=temp1->c[1];
			}
   		   {
		   	 r=temp1->k[1];
		   	 temp1->k[1]=temp->k[s];
		   	 temp->k[s]=r;
		   	 del(value);
		   }
			
		   }   	  
	   }
    }
}
main()
{
	B_tree t;
	int k;
	int i=1;
	while(i==1)
	{
		cout<<"enter :";
		cin>>k;
		t.insert(k);
		cout<<"enter 1 to more";
		cin>>i;
	}
int j=1;
		while(j==1)
	{
		cout<<"enter :";
		cin>>k;
		t.del(k);
		cout<<"enter 1 to delete more";
		cin>>j;
	}

}
