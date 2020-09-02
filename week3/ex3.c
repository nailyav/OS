#include <stdio.h>
#include <stdlib.h>


// indeces of nodes are counted starting from 1


struct node
{
    int data;
    struct node *next;
} *head;


void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));

    printf("Input data:\n");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    tmp = head;

    for(i=2; i<=n; i++)
    {
        fnNode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &data);

        fnNode->data = data;
        fnNode->next = NULL;

        tmp->next = fnNode;
        tmp = tmp->next;
    }
}

void print_list(){
    struct node *tmp;
    if (head == NULL){
        printf("List is empty");
    }
    else{
        tmp = head;
        while (tmp != NULL){
            printf("%d\n", tmp->data);
            tmp = tmp->next;
        }
    }
}

void insert_node(int data, int position) {
    struct node* newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node* previousNode = head;
    for (int i = 0; i < position - 2; i++) {
        previousNode = previousNode->next;
    }

    newNode->next = previousNode->next;
    previousNode->next = newNode;

}

void delete_node(int position)
{
    struct node* node1 = head;
    if(position == 1){
        head = node1->next;
        free(node1);
        return;
    }
    int i;
    for(i = 0; i < position - 2; i++)
    {
        node1 = node1->next;
    }
    struct node* node2 = node1->next;
    node1->next = node2->next;
    free(node2);
}


int main()
{
    int n, idx, val;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    createNodeList(n);

    printf("Enter the index of the node to be inserted:");
    scanf("%d", &idx);
    printf("Enter the value of the node:");
    scanf("%d", &val);
    insert_node(val, idx);
    printf("The list:");
    print_list();
    
    printf("Enter the index of the node to be deleted:");
    scanf("%d", &idx);
    delete_node(idx);
    printf("The list:");
    print_list();
    return 0;
}
