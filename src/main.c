/*******************************************************************************
 * @file main.c
 * @breif Application entry point
 *******************************************************************************/

/*******************************************************************************
 * Global header inclusion
 *******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************************************************
 * Library inclusion
 *******************************************************************************/
#include "sqlite3.h"

/*******************************************************************************
 * local header inclusion
 *******************************************************************************/
#include "ec_queries.h"
#include "ec_db.h"

int
main(void)
{
  ec_db_t *database = EC_DB_OPEN("./data/expense_tracker.db");
  EC_COMMAND command = EC_SQL_GET_TRANSACTIONS;

  database->command = command;

  ec_db_get_table(database);
  printf("Number of rows and colums: %d, %d\n",
         database->table.row,
         database->table.col);
 
  // print header
  for(int c = 0; c < database->table.col; c++)
    printf("%-15s", database->table.result[c]);
  printf("\n");

  // print data rows
  for(int r = 1; r <= database->table.row; r++) {
    for(int c = 0; c < database->table.col; c++) {
      char *cell = ec_table_get_cell(database, r, c);
      printf("%-15s", cell ? cell : "NULL");
    }
    printf("\n");
  }

  EC_DB_CLOSE(database);

  return 0;
}


