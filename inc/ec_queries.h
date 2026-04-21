/*******************************************************************************
 * @file ec_queries.h
 * @breif Header file storing the standard queries
 *******************************************************************************/

#ifndef EC_QUERIES_H
#define EC_QUERIES_H

typedef const char* EC_COMMAND;

static EC_COMMAND EC_SQL_GET_TABLES = "SELECT name FROM sqlite_master WHERE type='table';";
static EC_COMMAND EC_SQL_GET_TRANSACTIONS = "SELECT * FROM transactions";

#endif
