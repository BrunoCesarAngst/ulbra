#include <stdio.h>
int main() {
  int op;
  do {
    scanf("%d", &op);
    if ((op<1)||(op>3)) {
      printf("oi\n");
    }
  } while((op<1)||(op>3));
}
