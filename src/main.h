typedef struct Task {
  char *task;
  char *task_id;
  // int task_id;
  int task_priority;
  struct Task *next;
} Task;

int show_menu();
int display_task();

int show_task();
int add_task();
int del_task();
int update_task();
