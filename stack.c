#include<stdio.h>
int top = -1;
void push(int stack[],int n){
  if(top == n-1){
    printf("Stack overflow!!\n");
  }
  else{
    int ele;
    printf("Enter element you want to push \n");
    scanf("%d",&ele);
    top++;
    stack[top] = ele;
    printf("Element %d has been pushed\n",ele);
  }
}

void pop(int stack[],int n){
  if(top == -1){
    printf("Stack Underflow!!\n");
  }
  else{
    printf("The element being popped is: %d \n",stack[top]);
    top --;
  }
}

void display(int stack[], int n){
  int i;
  printf("The stack status: \n");
  for(i = 0; i<n; i++){
    printf("%d\n",stack[n-i-1]);
  }
}

void peek(int stack[]){
  if(top>-1){
  printf("The top element is: %d\n",stack[top]);
  }
  else{
    printf("Stack empty!!\n");
  }
}

int main(){
  printf("Enter the size of your stack\n");
  int n;
  scanf("%d",&n);
  int stack[n],choice;
  while(1){
    printf("-----------Stack Operations-----------\n");
    printf("+----------1) PUSH-------------------+\n");
    printf("+----------2) POP--------------------+\n");
    printf("+----------3) DISPLAY----------------+\n");
    printf("+----------4) PEEK-------------------+\n");
    printf("+----------5) EXIT-------------------+\n");
    printf("-----------Enter your choice----------\n");
    scanf("%d",&choice);
    if(choice == 1){
      push(stack,n);
    }
    else if(choice == 2){
      pop(stack,n);
    }
    else if(choice == 3){
      display(stack,n);
    }
    else if(choice == 4){
      peek(stack);
    }
    else if(choice == 5){
      break;
    }
  }
}
