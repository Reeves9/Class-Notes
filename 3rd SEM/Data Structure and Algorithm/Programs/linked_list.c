#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
  int data;
  struct node *next;
}*head;

void createList(int n){
  struct node *newNode, *temp;
  int data, i;
  head = (struct node *)malloc(sizeof(struct node));
  if (head == NULL){
    printf("Unable to allocate memory\n");
    exit(0);
  }
  printf("Enter data of node 1:\n");
  scanf("%d",&data);
  head->data = data;
  head->next = NULL;
  temp = head;
  for (i = 2 ; i <= n ; i++){
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL){
      printf("Unable to allocate memory\n");
      break;
    }
    printf("Enter data of the node %d\n",i);
    scanf("%d",&data);
    newNode->data = data;
    newNode->next = NULL;
    temp->next = newNode;
    temp = temp->next;
  }
}
void traverse(){
  struct node *temp;
  if (head == NULL) {
    printf("list is empty\n");
    return;
  }
  temp = head;
  while (temp != NULL) {
    printf("data = %d \n",temp->data);
    temp = temp->next;
  }
}
void insertAtBegin(int data){
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL){
    printf("unable to allocate memory\n");
  }else{
   newNode->data = data;
   newNode->next = head;
   head = newNode;
   printf("data inserted successfully\n");
  }
}
void insertAtEnd(int data){
  struct node *newNode, *temp;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL){
    printf("unable to allocate memory\n");
  }else{
    newNode->data = data;
    newNode->next = NULL;
    temp = head;
    while(temp != NULL && temp->next != NULL){
      temp = temp->next;
      temp->next = newNode;
      printf("data inserted successfully\n");
    }
  }
}
void insertAtMiddle(int data , int position){
  int i;
  struct node *newNode , *temp;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL){
    printf("unable to allocate memory\n");
  }else{
    newNode->data = data;
    newNode->next = NULL;
    temp = head;
    for(i = 2 ; i <= position-1 ; i++){
      temp = temp->next;
      if(temp == NULL){
        break;
      }
      if (temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
        printf("data inserted successfully\n");
      }else{
        printf("unable to insert data\n");
      }
    }
  }
}
void deleteFirstNode(){
  struct node *toDelete;
  if (head == NULL){
    printf("list is empty\n");
  }else{
    toDelete = head;
    head = head->next;
    printf("data deleted = %d\n",toDelete->data);
    free(toDelete);
    printf("deleted successfully\n");
  }
}
void deleteLastNode(){
  struct node *toDelete , *secondLastNode;
  if(head == NULL){
    printf("list is empty\n");
  }else{
    toDelete = head;
    secondLastNode = head;
    while (toDelete->next != NULL){
      secondLastNode = toDelete;
      toDelete = toDelete->next;
    }
    if (toDelete == head){
      head = NULL;
    }else{
      secondLastNode->next = NULL;
      free(toDelete);
      printf("deleted successfully\n");
    }
  }
}
void deleteMiddleNode(int position){
  int i;
  struct node *toDelete , *prevNode;
  if (head == NULL){
    printf("list is empty\n");
  }else{
    toDelete = head;
    prevNode = head;
    for (i = 2 ; i < position ; i++){
      prevNode = toDelete;
      toDelete = toDelete->next;
      if(toDelete == NULL){
        break;
      } 
    }
    if(toDelete != NULL){
      if (toDelete == head){
        head = head->next;
      }
      prevNode->next = toDelete->next;
      toDelete->next = NULL;
      free(toDelete);
    }else{
      printf("invalid position\n");
    }
  }
}
int main(){
  int n,ch,position,data;
  bool Exit = 0;
  while(Exit == 0){
    printf("1.createList\n2.insertAtBegin\n3.insertAtMiddle\n4.insertAtEnd\n5.deleteFirstNode\n6.deleteLastNode\n7.deleteMiddleNode\n8.display\n9.exit\n");
    scanf("%d",&ch);
    switch (ch){
      case 1:
        printf("size of list\n");
        scanf("%d",&n);
        createList(n);
        break;
      case 2:
        printf("enter data to be inserted\n");
        scanf("%d",&data);
        insertAtBegin(data);
        break;
      case 3:
        printf("enter data to be inserted\n");
        scanf("%d",&data);
        printf("enter the position\n");
        scanf("%d",&position);
        insertAtMiddle(data,position);
        break;
      case 4:
        printf("enter data to be inserted\n");
        scanf("%d",&data);
        insertAtEnd(data);
        break;
      case 5:
        deleteFirstNode();
        break;
      case 6:
        deleteLastNode();
        break;
      case 7:
        printf("enter postition to be deleted\n");
        scanf("%d",&position);
        deleteMiddleNode(position);
        break;
      case 8:
        traverse();
        break;
      case 9:
        Exit = 1;
        break;
    }
  }
  return 0;
}
