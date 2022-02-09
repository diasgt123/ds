
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* first = NULL;

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc((sizeof(struct node)));
    if(newNode == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}

void addElem(int data)
{
    struct node *newNode = createNode(data);

    if(first == NULL)
    {
        first = newNode;
    }
    else
    {
    	// List is maintained as a sorted list, so find index for insertion
        struct node *temp = first;
		while(temp->next && temp->next->data < data)    	
    	{
            temp = temp->next;
        }
        
        // inserting smallest element at first
		if(temp == first && data<first->data)
		{
			newNode->next = first;
			first = newNode;
		}
		//anywhere else
		else
        {
        	newNode->next = temp->next;
        	temp->next = newNode;
        }

    }
    
}

void display()
{
    if(first == NULL)
        printf("\nList Empty");
    else
    {
        struct node *temp = first;
        printf("Head");
        while(temp != NULL)
        {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
    }
    printf("\n\n");
}

void delete(int data)
{
    if(first == NULL)
    {
        printf("\nList Empty\n");
    }
    else
    {
        struct node *temp = first, *del = NULL;
        if(first->data == data)
        {
            del = first;
            first = first->next;
            free(del);
            printf("\nElement Deleted! \n");
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->next!=NULL && temp->next->data == data)
                {
                    del = temp->next;
                    temp->next = temp->next->next;
                    free(del); 
                    printf("\nElement Deleted! \n");
                    break;
                }
                temp = temp->next;
            }
        }
        if(del == NULL)
            printf("\nElement not found! \n");
    }
}

// Returns index of element if found
// (1 based indexing)
// else returns -1
void search(int data) {
    int index = 1;
    struct node *temp = first;
    while(temp && temp->data != data)
    {
    	index++;
    	temp = temp->next;
    }
    if(temp)
    	printf("\n %d found at position: %d \n", data, index);
	else
    	printf("\nElement not found!\n");
		
}

int main()
{
    int choice;
    do
    {
        int data;
        printf("1: Add elements (Maintains sorted List)\n");
        printf("2: Display Elements\n");
        printf("3: Delete Element\n");
        printf("4: Search for an Element\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                addElem(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter value that you want to delete: ");
                scanf("%d",&data);
                delete(data);
                break;
            case 4:
	            printf("Enter value that you want to search for: ");
                scanf("%d",&data);
                search(data);
                break;
            case 5:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 5);
    return 0;
}
