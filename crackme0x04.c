#include <stdio.h>
#include <string.h>
#include <signal.h>

#define MAX 0x78

void check(char *passwd)
{
  int i = 0;
  int t = 0;
  int s = 0;
  int len = 0;
  int tot = 0;

  len = strlen(passwd);
  while (i < len)
  {
    s = (int)passwd[0];
    sscanf(&s,"%d",&t);
    tot += t;
    if (tot == 0xf)
    {
      printf("Password OK!\n");
      exit(0);
    }
    passwd++;
    i++;
  }
  printf("Password Incorrect!\n");
  return;
}


void main(int argc, char *argv[])
{
  char passwd[MAX];
  printf("IOLI Crackme Level 0x04\n");
  printf("Password: ");
  scanf("%s", passwd);
  check(passwd);
  return;
}
