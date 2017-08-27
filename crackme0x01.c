#include <stdio.h>

void main(int argc, char *argv[])
{
  int key = 0;
  printf("IOLI Crackme Level 0x01\n");
  printf("Password: ");
  scanf("%d",&key);
  if (key != 0x149a)
  {
    printf("Invalid Password!\n");
    return;
  }
  printf("Password OK :)\n");
  return;
}
