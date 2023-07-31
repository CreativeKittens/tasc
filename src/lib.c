#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

bool get_bool(char *prompt) {
  char *b;
  printf("%s", prompt);
  scanf("%s", b);

  return b;
}

char *get_string(char *prompt) {
  char *s = malloc(50);
  if (s == NULL) {
    return NULL;
  }

  clear_input_buffer();
  printf("%s", prompt);
  scanf("%[^\n]", s);
  return s;
}

int get_number(char *prompt) {
  int n;
  printf("%s", prompt);
  scanf("%i", &n);

  return n;
}

char *id_generator() {
  char *id = malloc(20);

  time_t time_id;
  time(&time_id);

  sprintf(id, "%ld", time_id);

  return id;
}
