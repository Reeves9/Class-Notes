#include <stdio.h>

#define max 10
int rear = -1 , front = 0 , count = 0;
int queue[max];

void enque()
{
  if (rear == max-1)
  {
    printf("the queue is full!\n");
  }
  else
  {
    int a;
    printf("enter the data to be inserted:\n");
    scanf("%d",&a);
    rear++;
    queue[rear] = a;
    count++;
  }
}

void deque()
{
  if (rear < front) 
  {
    printf("queue is empty\n");
  }
  else
  {
    printf("deleted data is %d\n",queue[front]);
    front++;
    rear--;
  }
}

void display()
{
  int i;
  for (i = front ; i = rear; i++)
  {
    printf("%d ",queue[i]);
  }
}

int main()
{
  int choice;
  do
  {
    if (count == 0)
    {
      rear = -1;
      front = 0;
    }
    printf("enter your choice:\n 1.enque \n 2.deque \n 3.display \n 4. exit \n");
    scanf("%d",&choice);
    switch (choice) 
    {
      case 1:
        enque();
        break;
      case 2:
        deque();
        break;
      case 3:
        display();
        break;
      case 4:
        break;
    }
  }while(choice <= 4);
  return 0;
}
