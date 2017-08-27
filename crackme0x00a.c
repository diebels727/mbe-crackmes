#include <stdio.h>
#include <string.h>

#define MAX 0x17
#define GOOD_JOB "g00dJ0B!"

void main(void)
{
  char passwd[MAX];
  int fail = 0;
  printf("Enter password: ");
  scanf("%s",passwd);
  fail = strcmp(passwd,GOOD_JOB);
  if (!fail)
  {
    printf("Congrats!\n");
    goto GTFO;
  }
  printf("Wrong!\n");
GTFO:
  return;
}
