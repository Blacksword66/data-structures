#include<stdio.h>
int front = 0;
int rear = -1;
void enqueue(int queue[], int n){
  if(rear == n-1){
    printf("Queue Overflow!!\n");
  }
  else{
    int ele;
    printf("Enter the element you want to enter: \n");
    scanf("%d",&ele);
    rear++;
    queue[rear] = ele;
    printf("Element %d has been entered\n",ele);
  }
}

void dequeue(int queue[]){
  while(front<=rear){
    printf("Element %d has been removed\n", queue[front]);
    front ++;
  }
  front = 0;
  rear = -1;
  printf("Ready to take entries now!!\n");
}

void display(int queue[], int n){
  printf("The state of queue is: \n");
  int i;
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
    printf("+----------1) ENTER------------------+\n");
    printf("+----------2) DELETE-----------------+\n");
    printf("+----------3) DISPLAY----------------+\n");
    printf("+----------4) EXIT-------------------+\n");
    printf("-----------Enter your choice----------\n");
    scanf("%d",&choice);
    if(choice == 1){
      enqueue(queue,n);
    }
    else if(choice == 2){
      dequeue(queue);
    }
    else if(choice == 3){
      display(queue,n);
    }
    else if(choice == 4){
      break;
    }
  }
  return 0;
}
