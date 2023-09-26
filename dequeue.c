#include<stdio.h>
int front = 0;
int rear = -1;

void insertRear(int queue[], int n){
  if(rear == n-1){
    printf("Can't insert from the rear!\n");
  }
  else{
    int ele;
    printf("Enter the element you want to insert\n");
    scanf("%d", &ele);
    rear++;
    queue[rear] = ele;
    printf("Element %d has been inserted from the rear\n",ele);
  }
}

void insertFront(int queue[], int n){
  if(front == 0){
    printf("Can't insert from the front!\n");
  }
  else{
    int ele;
    printf("Enter the element you want to insert\n");
    scanf("%d",&ele);
    front --;
    queue[front] = ele;
    printf("Element %d has been inserted from the front\n",ele);
  }
}

void deleteRear(int queue[], int n){
  if(front == rear &&(rear == n-1)){
    printf("Can't delete from the rear!\n");
  }
  else{
    printf("Element %d has been deleted from the queue\n",queue[rear]);
    rear --;
  }
}

void deleteFront(int queue[], int n){
  if(front == rear || front == n-1){
    printf("Can't delete from the front!\n");
  }
  else{
    printf("Element %d has been deleted from the queue\n",queue[front]);
    front ++;
  }
}

void display(int queue[], int n){
  int i;
  printf("Queue: \n");
  for(i = 0; i<n; i++){
    printf("%d\n",queue[i]);
  }
}

int main(){
  int n;
  printf("Enter the size of your queue\n");
  scanf("%d",&n);
  int queue[n],choice; 
  while(1){
    printf("-----------Queue Operations-----------\n");
    printf("+----------1) ENTER R----------------+\n");
    printf("+----------2) ENTER F----------------+\n");
    printf("+----------3) DELETE F---------------+\n");
    printf("+----------4) DELETE R---------------+\n");
    printf("+----------5) DISPLAY----------------+\n");
    printf("+----------6) EXIT-------------------+\n");
    printf("-----------Enter your choice----------\n");
    scanf("%d",&choice);
    if(choice == 1){
      insertRear(queue,n);
    }
    else if(choice == 2){
      insertFront(queue, n);
    }
    else if(choice == 3){
      deleteFront(queue,n);
    }
    else if(choice == 4){
      deleteRear(queue, n);
    }
    else if(choice == 5){
      display(queue, n);
    }
    else if(choice == 6){
      break;
    }
  }
  return 0;
}
