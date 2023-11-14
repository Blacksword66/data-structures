#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
  struct node *prev;
};
typedef struct node node;

node *createnode(int value){
  node *newNode = (node*)malloc(sizeof(node));
  newNode->data = value;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void insertAtHead(node** head, int value){
  node* toInsert = createnode(value);
  if(*head == NULL){
    *head = toInsert;
    return;
  }
  toInsert->next = *head;
  (*head)->prev = toInsert;
  *head = toInsert;
}

void insertAfter(node *head, int valueBefore, int value){
  node *nodeBefore = head;
  while(nodeBefore->data != valueBefore){
    nodeBefore = nodeBefore->next;
  }

  node *toInsert = createnode(value);
  toInsert->next = nodeBefore->next;
  toInsert->prev = nodeBefore;
  nodeBefore->next = toInsert;
  if(toInsert->next != NULL){
    toInsert->next->prev = toInsert;
  }
}

void insertBefore(node *head, int valueAfter, int value){
  node *nodeAfter = head;
  while(nodeAfter->data != valueAfter){
    nodeAfter = nodeAfter->next;
  }

  node *toInsert = createnode(value);
  toInsert->prev = nodeAfter->prev;
  toInsert->next = nodeAfter;
  nodeAfter->prev = toInsert;
  if(toInsert->prev != NULL){
    toInsert->prev->next = toInsert;
  }
}

void insertLast(node** head, int value){
  node* newNode = createnode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void removeLast(node *head){
  node *last = head;
  while(last->next != NULL){
    last = last->next;
  }
  last->prev->next = NULL;
}

void removeFirst(node **head){
  if(*head == NULL){
    printf("List is empty\n");
    return;
  }
  *head = (*head)->next;
  (*head)->prev = NULL;
}

void removeValue(int remove, node *head){
  node *searcher = head;
  while(searcher->data != remove){
    searcher = searcher->next;
  }
  searcher->prev->next = searcher->next;
  searcher->next->prev = searcher->prev;
}

void display(node *head){
  node *printer = head;
  while(printer != NULL){
    printf("%d\n",printer->data);
    printer = printer->next;
  }
}

void search(node* head, int search){
  int pos = 1;
  int found = 0;
  node *temp = head;
  while(temp->data != search && temp->next != NULL){
    temp = temp->next;
    pos++;
    if(temp->data == search){
      found = 1;
    }
  }
  if(found==1){
    printf("%d found at position %d",search, pos);
  }
  else{
    printf("%d not found",search);
  }
}

int main(){
  node *head = NULL;
  while(1){
    printf("-------Doubly Linked List Operatations-------\n");
    printf("+-------------1) Input at head--------------+\n");
    printf("+-------------2) Input at tail--------------+\n");
    printf("+-------------3) Input after node-----------+\n");
    printf("+-------------4) Input before node----------+\n");
    printf("+-------------5) Remove from head-----------+\n");
    printf("+-------------6) Remove last element--------+\n");
    printf("+-------------7) Remove specific------------+\n");
    printf("+-------------8) Search---------------------+\n");
    printf("+-------------9) Display--------------------+\n");
    printf("+------------10) Exit-----------------------+\n");
    printf("--------------Enter your choice--------------\n");
    int choice,tmp,exst;
    scanf("%d",&choice);
    switch(choice){
      case 1:
        scanf("%d", &tmp);
        insertAtHead(&head, tmp);
        break;
      case 2:
        scanf("%d", &tmp);
        insertLast(&head, tmp);
        break;
      case 3:
        printf("New value first, then the existing value");
        scanf("%d %d", &tmp, &exst);
        insertAfter(head, exst, tmp);
        break;
      case 4:
        printf("New value first, then the existing value");
        scanf("%d %d", &tmp, &exst);
        insertBefore(head, exst, tmp);
        break;
      case 5:
        removeFirst(&head);
        break;
      case 6:
        removeLast(head);
        break;
      case 7:
        scanf("%d",&tmp);
        removeValue(tmp, head);
        break;
      case 8:
        scanf("%d",&tmp);
        search(head, tmp);
        break;
      case 9:
        display(head);
        break;
    }
    if(choice>=10){
      break;
    }
  }
  return 0;
}
