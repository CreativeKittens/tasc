#include "lib.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Task *task_list = NULL;

int main(void) {
  system("clear");
  show_menu();
  // char *s = get_string("hello: ");
  // char *a = get_string("hello: ");
  return 0;
}

/*
 * @return void
 * @desc show main menu
 */
int show_menu() {
  int choice = display_menu();

  if (choice > 4) {
    system("clear");
    printf("choice are invalid pick again\n\n");

    show_menu();
    return -1;
  }

  printf("\n");
  switch (choice) {
  case 1:
    display_task();
    break;
  case 2:
    add_task();
    break;
  case 3:
    del_task();
    break;
  case 4:
    update_task();
    break;
  default:
    printf("good bye\n");
    return -1;
  }

  return 0;
}

/*
 * @return void
 * @desc show task_list
 * */

int show_task() {
  Task *task_temp = task_list;

  if (task_list == NULL) {
    return -1;
  }

  while (task_temp != NULL) {
    // printf("[%d] %s (Priority: %i) %s ", task_temp->task_id, task_temp->task,
    //        task_temp->task_priority, task_temp->next == NULL ? "" : "->");
    printf("[%s] %s (Priority: %i) \n", task_temp->task_id, task_temp->task,
           task_temp->task_priority);
    task_temp = task_temp->next;
  }

  printf("\n");
  return 0;
}

int free_task() {
  Task *task_temp = task_list;

  if (task_list == NULL) {
    return -1;
  }

  while (task_temp != NULL) {
    task_temp = task_temp->next;
    free(task_list);
    task_list = task_temp;
  }

  return 0;
}

int display_task() {
  system("clear");

  if (show_task() == -1) {
    printf("You have no task\n\n");
  }
  free_task();

  show_menu();
  return 0;
}

/*
 * @return void
 * @desc show task_list
 * */
int add_task() {
  Task *task = new_task();
  Task *task_temp = task_list;
  Task *task_temp_next = NULL;

  if (task_list == NULL) {
    task_list = task;

    system("clear");
    printf("Success adding new task\n\n");

    show_menu();

    return 0;
  }

  if (task->task_priority < task_list->task_priority) {
    task_list = task;
    task_list->next = task_temp;

    system("clear");
    printf("Success adding new task\n\n");

    show_menu();

    return 0;
  }

  while (task_temp != NULL) {
    if (task_temp->next == NULL) {
      system("clear");
      printf("Success adding new task\n\n");
      task_temp->next = task;
      break;
    }

    if (task->task_priority < task_temp->next->task_priority) {
      task_temp_next = task_temp->next;
      task_temp->next = task;
      task_temp->next->next = task_temp_next;

      system("clear");
      printf("Success adding new task\n\n");
      break;
    }
    task_temp = task_temp->next;
  }

  show_menu();
  return 0;
}
/*
 * @return void
 * @desc delete task
 */
int del_task() {
  if (show_task() == -1) {
    printf("You have no task\n\n");

    return -1;
  }

  Task *task_temp = task_list;
  Task *task_temp_next = NULL;

  system("clear");
  show_task();

  char *id = get_string("Enter id: ");

  if (strcmp(id, task_temp->task_id) == 0) {
    task_temp = task_list->next;
    free(task_list);
    task_list = task_temp;

    system("clear");
    printf("Success deleting id %s\n\n", id);
    show_menu();

    return 0;
  }

  while (task_temp != NULL) {
    if (task_temp->next == NULL) {
      system("clear");
      printf("Id not found\n\n");
      break;
    }

    if (strcmp(id, task_temp->next->task_id) == 0) {
      task_temp_next = task_temp->next->next;
      free(task_temp->next);
      task_temp->next = task_temp_next;

      system("clear");
      printf("Success deleting id %s\n\n", id);

      break;
    }

    task_temp = task_temp->next;
  }

  show_menu();
  return 0;
}

/*
 * @return void
 * @desc update task (Only priority)
 */
int update_task() {
  if (show_task() == -1) {
    printf("You have no task\n\n");

    return -1;
  }

  Task *task_temp = task_list;

  system("clear");
  show_task();

  char *task_text = get_string("Update task: ");
  char *id = get_string("Enter id: ");

  while (task_temp != NULL) {
    if (task_temp == NULL) {
      system("clear");
      printf("Id not found\n\n");
      break;
    }

    if (strcmp(id, task_temp->task_id) == 0) {
      free(task_temp->task);
      task_temp->task = NULL;
      task_temp->task = task_text;

      system("clear");
      printf("Success updating task id %s\n\n", task_temp->task_id);
      break;
    }
    // printf("%s\n", id);
    // printf("%s\n", task_temp->task_id);
    // printf("%i\n", strcmp(id, task_temp->task_id));

    task_temp = task_temp->next;
  }

  show_menu();
  return 0;
}
