#include <stdio.h>

void logger(char* message) {
  FILE* fp = fopen("log.txt", );
  fprintf(fp, "%s\n", message);
}

int job() {
  return 1;
}

int main(int argc, const char* aargv[]) {

  if(job() == 1)
    logger("success");
  else
    logger("fail");

  return 0;
}
