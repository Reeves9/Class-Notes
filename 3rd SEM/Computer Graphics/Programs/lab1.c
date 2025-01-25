#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

int main(){
  
  float x,y,x1,y1,x2,y2,dx,dy,step;
  int i,gd=DETECT,gm;
  
  initgraph(&gd,&gm,NULL);
  
  printf("enter first cordinate\n");
  scanf("%f%f",&x1,&y1);
  printf("enter second coordinate\n");
  scanf("%f%f",&x2,&y2);
  
  dx = abs(x2-x1);
  dy = abs(y2-y1);
  
  if(dx >= dy){
    step = dx;
  }
  else{
    step = dy;
  }
 
  dx = dx / step;
  dy = dy / step;

  x = x1;
  y = y1;

  i = 1;
  while (i <= step){
    putpixel(x,y,8);
    x = x + dx;
    y = y + dy;
    i++;
    delay(100);
  }
  closegraph();
  getchar();
  return 0;
}
