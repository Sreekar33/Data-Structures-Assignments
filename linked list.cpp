#include"iostream"
using namespace std;
class node{
  public:	
	int data;
	node *next;
};
class linked_list{
	public:
	node *head=NULL;
	void insert(int num);
	void del(int num);
	void print();
};
void linked_list::insert(int num)
{
	if(head==NULL)
	{
		head=new node;
		head->data=num;
		head->next=NULL;
	}
	else
     {
     	node *temp;
     	node *temp1;
     	temp1=head;
     	while(temp1->next!=NULL)
     	{
     		temp1=temp1->next;
		 }
     	temp=new node;
     	temp->data=num;
     	temp->next=NULL;
        temp1->next=temp;
	 }
}
void linked_list::del(int num)
{
	node *temp;
	node *temp2;
	node *temp3;
	if(head->data==num)
	{
		temp2=head;
		head=temp2->next;
		delete temp2;
	}
	else{
	temp=head;
	temp3=head->next;
	
		while(temp3!=NULL)
		{
			if(temp3->data==num)
     		{
				if(temp3->next==NULL){
					temp->next=NULL;
					delete temp3;
				}
				else{
				    
				    temp->next=temp3->next;
				    temp3->next=NULL;
				delete temp3;
				}
				
			}
			temp=temp3;
			temp3=temp3->next;

		}
	}
}
void linked_list::print()
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<"value:"<<temp->data<<endl;
		temp=temp->next;
	}
	
}
main()
{
	linked_list m;
    int i=1,k,j=1;
    while(i==1)
    {
    	cout<<"enter the element to add";
    	cin>>k;
    	m.insert(k);
    	cout<<"enter 1 to add more"<<endl;
    	cin>>i;
	}
	m.print();
    while(j==1)
    {
    	cout<<"enter the element to delete";
    	cin>>k;
    	m.del(k);
    	cout<<"enter 1 to add more"<<endl;
    	cin>>j;
	}
	m.print();
	
}
