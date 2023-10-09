#include<stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node* next;
};

typedef struct node node_ll; //to make the code look cleaner and to type less

void display(node_ll *head){
  node_ll *temp = head;
  while(temp != NULL){
    printf("%d \n", temp->value);
    temp = temp->next;
  }
}

void insertAtHead(node_ll **head, int value){
  node_ll *newNode = malloc(sizeof(node_ll));
  newNode->value = value;
  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(node_ll **head, int value){
  node_ll *newNode = malloc(sizeof(node_ll));
  newNode->value = value;
  node_ll *last = *head;
  if(*head == NULL){
    *head = newNode;
    return;
  }

  while(last->next != NULL){
    last = last->next;
  }
  last->next = newNode;
}

void insertAfterNode(node_ll *head, int valueBefore, int newValue){
  node_ll *temp = head;
  while(temp != NULL){
    if(temp->value == valueBefore){
      break;
    }
    temp = temp->next;
  }
  if(temp == NULL && temp->value != valueBefore){
    printf("Value asked was not found,so inserting at the end\n");
    insertAtEnd(&head, newValue);
  }
  node_ll *newNode = malloc(sizeof(node_ll));
  newNode->value = newValue;
  newNode->next = temp->next;
  temp->next = newNode;
}

void findValue(node_ll *head, int key){
  node_ll *finder = head;
  while(finder != NULL){
    if(finder->value == key){
      printf("Value %d found in list\n",key);
      return;
    }
    finder = finder->next;
  }
  printf("Value not found\n");
}

int main(){
  
  node_ll *head = NULL;
  int size, i, tmp, exst;
  printf("Enter the size of your linked list\n");
  scanf("%d",&size);
  printf("Enter the elements: \n");
  for(i = 0; i<size; i++){
    int temp;
    scanf("%d",&temp);
    insertAtEnd(&head, temp);
  }
  printf("Here is your linked list\n");
  display(head);
  while(1){
    printf("-------Linked List Operatations-------\n");
    printf("+----------1) Input at head----------+\n");
    printf("+----------2) Input at tail----------+\n");
    printf("+----------3) Input after node-------+\n");
    printf("+----------4) Search-----------------+\n");
    printf("+----------5) Display----------------+\n");
    printf("+----------6) Exit-------------------+\n");
    printf("-----------Enter your choice----------\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
      case 1:
        scanf("%d", &tmp);
        insertAtHead(&head, tmp);
        break;
      case 2:
        scanf("%d", &tmp);
        insertAtEnd(&head, tmp);
        break;
      case 3:
        printf("New value first, then the existing value");
        scanf("%d %d", &tmp, &exst);
        insertAfterNode(head, exst, tmp);
        break;
      case 4:
        scanf("%d", &tmp);
        findValue(head, tmp);
        break;
      case 5:
        display(head);
        break;
    }
    if(choice >= 6){
      break;
    }
  }
  return 0;
}
