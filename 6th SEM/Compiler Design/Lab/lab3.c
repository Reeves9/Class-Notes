#include <ctype.h>
#include <stdio.h>
int main() {
  char a[10];
  int flag, i = 1;
  printf("\n Enter an identifier:");
  scanf("%s", a);
  if (isalpha(a[0]) || a[0] == '_')
    flag = 1;
  else
    printf("\n Not a valid identifier");
  while (a[i] != '\0') {
    if (!isdigit(a[i]) && !isalpha(a[i]) && a[i] != '_') {
      flag = 0;
      break;
    }
    i++;
  }
  if (flag == 1)
    printf("\n Valid identifier");
  else
    printf("Not a valid identifier");
  return 0;
}