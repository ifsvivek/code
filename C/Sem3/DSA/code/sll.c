//DELETE AFTER//
void deleteafter()
{
    node *temp=start,*prev;
    int key;
    if(start==NULL)
    {
        printf("KEY NOT FOUND");
        return;
    }
    while(temp!=NULL&&temp->data!=key)
        temp=temp->next;
    if(temp==NULL)
    {
        printf("DELETION NOT POSSIBLE AS NO KEY FOUND");
        return;
    }
    temp->next=(temp->next)->next;
    printf("DELETED ELEMENT IS %d",(temp->next)->data);
    free(temp->next);
}
//CONCATENATING LISTS//
node *concat(node *start1,node *start2)
{
    node *temp;
    if(start1==NULL&&start2==NULL)
    {
        printf("CANCAT IS NOT POSSIBLE BECAUSE BOTH LIST ARE EMPTY");
        return;
    }
    if(start1==NULL)
        return start2;
    if(start2==NULL)
        return start1;
    temp=start1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=start2;
    return start1;
}
//DELETE KEY//
void deletekey()
{
    node *temp=start,*prev;
    int key;
    if(start==NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }
    printf("ENTER THE KEY");
    scanf("%d",&key);
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("KEY NOT FOUND");
        return;
    }
    if(temp==start)
    {
        deletebegin();
        return;
    }
    prev->next=temp->next;
    printf("DELETED KEY IS %d",temp->data);
    free(temp);
}
//REVERSE A LINKED LIST//
void reverse(node *start)
{
    if(start==NULL)
        printf("LIST IS EMPTY");
    while(start!=NULL)
    {
        temp=start;
        start=temp->next;
        temp->next=prev;
        prev=temp;
    }
    start=temp;
    free(temp);
}
//SORT//
void sort()
{
    int n=0,tdata,i,j;
    node *temp=start;
    if(start==NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    for(i=0;i<n-1;i++)
    {
        temp=start;
        for(j=0;j<n-1;j++)
        {
            if(temp->data>(temp->next)-data)
            {
                temp=temp->data;
                temp->data=(temp->next)->data;
                (temp->next)->data=tdata;
            }
            temp=temp->next;
        }
    }
    display();
}
//COUNTING NUMBER OF NODES//
void count(node *count)
{
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
}
int main() 
{
    int choice, value;
    while(1) 
    {
        printf("\n\n------ Singly Linked List Menu ------\n");
        printf("1. Create node\n");
        printf("2. Insert begin\n");
        printf("3. Insert at the End\n");
        printf("4. Delete from the Beginning\n");
        printf("5. Delete from the End\n");
        printf("6. Display the List\n");
        printf("7. Search\n");
        printf("8. Insert before key\n");
        printf("9. Insert after key\n");
        printf("10. Delete before key\n");
        printf("11. Delete after key\n");
        printf("12. Concatenating the list\n");
        printf("13. Delete key\n");
        printf("14. Reverse the linked list\n");
        printf("15. Sort the linked list\n");
        printf("16. Count\n");
        printf("17. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                createnode();
                break;
            case 2:
                insertbegin();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                display();
                break;
            case 7:
                search();
                break;
            case 8:
                insertbeforekey();
                break;
            case 9:
                insertafterkey();
                break;
            case 10:
                deletebeforekey();
                break;
            case 11:
                deleteafterkey();
                break;
            case 12:
                concat();
                break;
            case 13:
                deletekey();
                break;
            case 14:
                reverse();
                break;
            case 15:
                sort();
                break;
            case 16:
                count();
                break;
            case 17:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}