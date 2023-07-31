#include "lib.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

Task *task_list = NULL;

int main(void) {
  system("clear");
  show_menu();
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

  switch (choice) {
  case 1:
    show_task();
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
  system("clear");
  Task *task_temp = task_list;

  if (task_list == NULL) {
    printf("You have no task\n\n");
    show_menu();
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
    task->task_id = id_generator();
    task_list = task;
    show_menu();
    return 0;
  }

  if (task_list->next == NULL) {
    task->task_id = task_list->task_id + 1;

    if (task->task_priority < task_list->task_priority) {
      task_temp = task_list;
      task_list = task;
      task_list->next = task_temp;

      show_menu();
      return 0;
    }

    task_list->next = task;

    show_menu();
    return 0;
  }

  // 5
  // 1,1,3
  while (task_temp != NULL) {
    // task->task_id = task_temp->task_id + 1;
    task->task_id = id_generator();

    if (task_temp->next == NULL) {
      task_temp->next = task;
      break;
    }

    if (task->task_priority < task_temp->next->task_priority) {
      task_temp_next = task_temp->next;
      task_temp->next = task;
      task_temp->next->next = task_temp_next;
      break;
    }

    task_temp = task_temp->next;
  }

  // Shift insertion
  // while (task_temp != NULL) {
  //   if (task_temp->next == NULL) {
  //     task_temp->next = task;
  //     break;
  //   }
  //
  //   task_temp = task_temp->next;
  // }

  show_menu();
  return 0;
}
/*
 * @return void
 * @desc delete task
 */
int del_task() {
  char *id = get_string("Enter id: ");

  return 0;
}

/*
 * @return void
 * @desc update task (Only priority)
 */
int update_task() { return 0; }
