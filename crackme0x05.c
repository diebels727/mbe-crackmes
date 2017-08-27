#include <stdio.h>
#include <string.h>

#define MAX 0x78

void parell(char *passwd)
{
  int t;
  sscanf(passwd,"%d",&t);
  if (((char)t & 0x01) == 0)
  {
    printf("Password OK!\n");
  }
  exit(0);
}

void check(char *passwd)
{
  int i, t, s, len, tot = 0;
  char passwd_orig = 0;

  passwd_orig = (int)passwd;
  printf("passwd ptr: %08x\n",passwd);

  len = strlen(passwd);
  while(1)
  {
    if (i >= len)
    {
      goto GTFO;
    }
    s = (int)passwd[i];
    sscanf(&s,"%d",&t);
    tot += t;
    if (tot == 0x10)
    {
      parell(passwd);
    }
    i++;
  }
GTFO:
  printf("Password Incorrect!\n");
  return;
}


void main(int argc, char *argv[])
{
  char passwd[MAX];
  printf("IOLI Crackme Level 0x05\n");
  printf("Password: ");
  scanf("%s", passwd);
  check(passwd);
  return;
}
