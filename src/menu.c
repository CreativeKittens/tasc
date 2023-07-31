#include "menu.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * @return choice
 * @desc show menu and return choice
 * */
int display_menu() {
  printf("Select menu by enter number below:\n");
  printf(" 1) %s\n", TASK_LIST_MESSAGE);
  printf(" 2) %s\n", ADD_TASK_MESSAGE);
  printf(" 3) %s\n", DELETE_TASK_MESSAGE);
  printf(" 4) %s\n", UPDATE_TASK_MESSAGE);
  printf(" 0) %s\n", "quit");

  int choice = get_number("\nEnter your choice: ");

  return choice;
}

/*
 * @return Task
 * @desc show prompt to add task
 *
 * TODO:
 * Use get_string for input
 *
 * */
Task *new_task() {
  system("clear");
  Task *new_task = (Task *)malloc(sizeof(Task));

  if (new_task == NULL) {
    printf("Failed to allocate memory");
    return NULL;
  }

  new_task->task = get_string("Enter your task: ");
  new_task->task_priority = get_number("Enter task priority: ");
  new_task->next = NULL;

  return new_task;
}

int display_update_taskg() { return 0; }
