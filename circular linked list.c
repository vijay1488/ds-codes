    #include<stdio.h>  
    #include<stdlib.h>  
    struct node   
    {  
        int data;  
        struct node *next;   
    };  
    struct node *head=NULL;  
      
    struct node *insert_begin (struct node *);   
    struct node *insert_end (struct node *);  
    struct node *insert_pos(struct node *);  
    struct node *del_head(struct node *);  
    struct node *del_tail(struct node *);   
	struct node *del_ele(struct node *);
	struct node *del_pos(struct node *);
	struct node *length(struct node *);
    void display(struct node *);  
    void search(struct node *);  
    void main ()  
    {  
        int choice;
		 printf("1.Insert begin\n2.Insert end\n3.insert position\n4.Delete head\n5.Delete tail\n6.del_ele\n7.del position\n8.Searching\n9.dislay\n10.length\n11.Exit\n");   
        do
        {   
            printf("Enter your choice::");         
            scanf("%d",&choice);  
            switch(choice)  
            {  
                case 1:  
                		head=insert_begin(head);      
               			break;  
                case 2:  
              		  head=insert_end(head);         
              		  break;
				case 3:
						head=insert_pos(head);
						break;  
                case 4:  
                		head=del_head(head);       
                		break;  
                case 5:  
                		head=del_tail(head);        
                		break;
				case 6:
						head=del_ele(head);
						break; 
				case 7:
						head=del_pos(head);
						break; 
                case 8:  
                		search(head);         
               			break;  
                case 9:  
                		display(head);        
                		break;  
                case 10:
                		head=length(head);
                		break;
                case 11:  
                		exit(1);  
                		break;  
                default:  
                		printf("Please enter valid choice..\n");  
            }  
        } while(choice!=11);
}
    struct node *insert_begin(struct node *head)  
    {  
        struct node *temp1,*temp=head;     
        temp1= (struct node *)malloc(sizeof(struct node));   
            printf("Enter the node data\n");  
            scanf("%d",&temp1->data);    
            if(head == NULL)  
            {  
                head = temp1;  
                temp1 -> next = head;  
            }  
            else   
            {      
                while(temp->next != head)  
                {
                    temp = temp->next;  
                }
                temp1->next = head;   
                temp -> next = temp1;   
                head = temp1;  
            }  
        return head;
	}
    struct node *insert_end(struct node *head)  
    {  
        struct node *temp1,*temp=head;    
        temp1 = (struct node *)malloc(sizeof(struct node)); 
            printf("Enter Data?\n");  
            scanf("%d",&temp1->data);    
            if(head == NULL)  
            {  
                head = temp1;  
                temp1 -> next = head;    
            }  
            else  
            {   
                while(temp -> next != head)  
                {  
                    temp = temp -> next;  
                }  
                temp -> next = temp1;   
                temp1 -> next = head;  
            }     
      return head;
    }  
    struct node *insert_pos(struct node *head)
    {
    	struct node *temp1,*p,*temp=head;
    	int pos,i=1;
    	printf("enter position to insert node\n");
    	scanf("%d",&pos);
    	temp1=(struct node *)malloc(sizeof(struct node));
    	printf("enter node data\n");
    	scanf("%d",&temp1->data);
    	if(pos==1)
    	{
    		while(temp->next!=head)
    		{
    			temp=temp->next;
			}
			temp->next=temp1;
			temp1->next=head;
			head=temp1;
		}
		else
		{
    	while(i<pos && temp->next!=head)
    	{
    		p=temp;
    		temp=temp->next;
    		i++;
		}
		if(temp->next!=head)
		{
		p->next=temp1;
		temp1->next=temp;
	}
	else
	{
		temp->next=temp1;
		temp1->next=head;
	}
    }
    return head;
	}
    struct node *del_head(struct node *head)  
    {  
        struct node *temp=head;    
        if(head->next == head)  
        {  
            head = NULL;  
            free(head);   
        }  
        else  
        {     
            while( temp-> next != head) 
			{
				temp = temp -> next;
			}    
            temp->next = head->next;  
            free(head);  
            head = temp->next;  
        } 
		return head; 
    }  
    struct node *del_tail(struct node *head)  
    {  
        struct node *temp1, *temp=head;  
        if (head ->next == head)  
        {  
            head = NULL;  
            free(head);
        }  
        else   
        {
            while(temp ->next != head)  
            {  
                temp1=temp;  
                temp = temp->next;  
            }  
            temp1->next = temp -> next;  
            free(temp); 
        } 
		return head; 
    }  
    struct node *del_ele(struct node *head)
    {
    	struct node *temp=head,*p;
		int ele,flag=0;
		printf("enter element to delete\n");
		scanf("%d",&ele);
		if(head==NULL)
		{
			printf("list is empty\n");
		}
		else if(head->data==ele)
		{
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=head->next;
			free(head);	
			head=temp->next;
		}
		else
		{
		while(temp->next!=head)
		{
			if(temp->data==ele)
			{
				flag=1;
				break;	
			}
			p=temp;
			temp=temp->next;
		}
		if(flag==1)
		{
			p->next=temp->next;
		}
		else
		{
			printf("no element to match\n");
		}
	}
	return head;
	}
	struct node *del_pos(struct node *head)
	{
		struct node *p,*temp=head;
    	int pos,i=1;
    	printf("enter position to delete node\n");
    	scanf("%d",&pos);
    	if(pos==1)
    	{
    		while(temp->next!=head)
    		{
    			temp=temp->next;
			}
			temp->next=head->next;
			free(head);
			head=temp->next;
		}
		else
		{
    	while(i<pos && temp->next!=head)
    	{
    		p=temp;
    		temp=temp->next;
    		i++;
		}
		if(temp->next!=head)
		{
		p->next=temp->next;
	}
	else
	{
		p->next=head;
		temp->next=NULL;
	}
    }
    return head;	
	}
    void search(struct node *head)  
    {  
        struct node *temp=head;  
        int i=0,flag=1,ele;     
            printf("Enter item which you want to search\n");   
            scanf("%d",&ele); 
			if(head==NULL)
			{
				printf("list is empty\n");
			 } 
            else if(head ->data == ele)  
            {  
            printf("item found at location %d",i+1);  
            flag=0;  
            }  
            else   
            {  
            while (temp->next != head)  
            {  
                if(temp->data == ele)  
                {  
                    printf("item found at location %d\n ",i+1);  
                    flag=0;  
                    break;  
                }   
                else  
                {  
                    flag=1;  
                }  
                i++;  
                temp = temp -> next;  
            }  
            }  
            if(flag != 0)  
            {  
                printf("Item not found\n");  
            }  
        }             
    void display(struct node *head)  
    {  
        struct node *temp=head;   
        if(head == NULL)  
        {  
            printf("nothing to print\n");  
        }     
        else  
        { 
            while(temp -> next != head)  
            {  
              
                printf("%d\n", temp -> data);  
                temp = temp -> next;  
            }  
			printf("%d\n",temp->data); 
        }        
    }
    struct node *length(struct node *head)
    {
    	struct node *temp=head;
    	int count=1;
    	while(temp->next!=head)
    	{
    		count++;
    		temp=temp->next;
		}
		printf("no.of nodes are %d\n",count);
		return head;
	}
