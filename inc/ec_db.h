/*******************************************************************************
 * @file ec_db.h
 * @breif Header file for handing the database intnerface
 *******************************************************************************/
#ifndef EC_DB_H
#define EC_DB_H

#include "sqlite3.h"

#include "ec_queries.h"

typedef char *EC_DB_RESULT;
typedef char *EC_DB_ERROR;

typedef struct ec_table_s
{
  EC_DB_RESULT *result;
  EC_DB_ERROR err;
  int row;
  int col;
} ec_table_t;

typedef struct ec_db_s
{
  sqlite3 *db;
  EC_COMMAND command;
  ec_table_t table;
} ec_db_t;

/**
 * @brief
 *
 * @param[IN
 */
ec_db_t *EC_DB_OPEN(const char *path);

/**
 * @brief
 *
 * @param[IN
 */
void ec_db_get_table(ec_db_t *database);

/**
 * @brief
 *
 * @param[IN
 */
char *ec_table_get_cell(ec_db_t *database, int r, int c);

/**
 * @brief
 *
 * @param[IN
 */
void EC_DB_CLOSE(ec_db_t *database);

/**
 * @brief
 *
 * @param[IN
 */
void ec_db_free_table(ec_db_t *database);

/**
 * @brief
 *
 * @param[IN
 */
void ec_db_print_table(ec_db_t *database);

#endif
