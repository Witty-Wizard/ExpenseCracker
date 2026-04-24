/*******************************************************************************
 * @file ec_db.c
 * @breif Source file for handing the database intnerface
 *******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "ec_db.h"

ec_db_t *
EC_DB_OPEN(const char *path)
{
  /* Allocate memory to database struct */
  ec_db_t *database = (ec_db_t *)malloc(sizeof(ec_db_t));

  /* check if malloc was successful */
  if(!database)
    return NULL;

  /* check if the database opened successfully */
  if(sqlite3_open(path, &database->db) != SQLITE_OK) {
    sqlite3_close(database->db);
    free(database);
    return NULL;
  }

  /* Declare result as NULL */
  database->table.result = NULL;

  /* return the database pointer */
  return database;
}

void
ec_db_get_table(ec_db_t *database)
{

  /* Check if database valid*/
  if(!database)
    return;

  /* Check if result exists */
  if(database->table.result) {
    sqlite3_free_table(database->table.result);
    database->table.result = NULL;
  }
  /* Get the Table */
  sqlite3_get_table(
    database->db,            /**< Pointer to the database handle */
    database->command,       /**< Pointer to the command string array */
    &database->table.result, /**< Pointer to the result array in table */
    &database->table.row,    /**< Pointer to the row in table */
    &database->table.col,    /**< Pointer to the col in table */
    &database->table.err     /**< Pointer to the error string array */
  );
}

char *
ec_table_get_cell(ec_db_t *database, int r, int c)
{
  /* Check for out of bound error */
  if(r < 0 || r > database->table.row || c < 0 || c >= database->table.col)
    return NULL;

  /* return the requested cell */
  return database->table.result[r * database->table.col + c];
}

void
EC_DB_CLOSE(ec_db_t *database)
{
  /* Check if database is valid */
  if(!database)
    return;
  /* Free the table result if it exists */
  if(database->table.result) {
    sqlite3_free_table(database->table.result);
    database->table.result = NULL;
  }
  /* Close the database connection */
  sqlite3_close(database->db);
  /* Free the database struct */
  free(database);
}

void
ec_db_free_table(ec_db_t *database)
{
  /* Check if database is valid */
  if(!database)
    return;
  /* Free the table result if it exists */
  if(database->table.result) {
    sqlite3_free_table(database->table.result);
    database->table.result = NULL;
  }
  /* Reset row and col counts */
  database->table.row = 0;
  database->table.col = 0;
  /* Reset the error pointer */
  database->table.err = NULL;
}

void
ec_db_print_table(ec_db_t *database)
{
  /* Check if database and result are valid */
  if(!database || !database->table.result)
    return;

  /* Print header row */
  for(int c = 0; c < database->table.col; c++)
    printf("%-15s", database->table.result[c]);
  printf("\n");

  /* Print data rows */
  for(int r = 1; r <= database->table.row; r++) {
    for(int c = 0; c < database->table.col; c++) {
      char *cell = ec_table_get_cell(database, r, c);
      printf("%-15s", cell ? cell : "NULL");
    }
    printf("\n");
  }
}

void
ec_db_get_account_ledger(ec_db_t *database, int account_id)
{
  if(!database)
    return;

  if(database->table.result) {
    sqlite3_free_table(database->table.result);
    database->table.result = NULL;
  }

  size_t sql_size = sizeof(EC_SQL_GET_ACCOUNT_LEDGER);
  EC_COMMAND sql = (EC_COMMAND)malloc(sql_size);
  if(!sql)
    return;

  snprintf((char *)sql, sql_size, EC_SQL_GET_ACCOUNT_LEDGER, account_id);

  sqlite3_get_table(
    database->db,
    sql,
    &database->table.result,
    &database->table.row,
    &database->table.col,
    &database->table.err
  );

  free((char *)sql);
}
