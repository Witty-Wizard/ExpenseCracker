/*******************************************************************************
 * @file ec_queries.h
 * @breif Header file storing the standard queries
 *******************************************************************************/

#ifndef EC_QUERIES_H
#define EC_QUERIES_H

typedef const char *EC_COMMAND;

static EC_COMMAND EC_SQL_GET_TABLES =
  "SELECT name FROM sqlite_master WHERE type='table';";

static EC_COMMAND EC_SQL_GET_TRANSACTIONS =
  "SELECT "
  "  ROW_NUMBER() OVER (ORDER BY t.date, t.id) AS row_num, "
  "  t.date, "
  "  t.description, "
  "  a.name AS account, "
  "  c.name AS category, "
  "  t.debit, "
  "  t.credit, "
  "  SUM(t.credit - t.debit) OVER (ORDER BY t.date, t.id) AS running_balance "
  "FROM transactions t "
  "JOIN accounts a ON a.id = t.account_id "
  "JOIN categories c ON c.id = t.category_id "
  "ORDER BY t.date;";

static EC_COMMAND EC_SQL_GET_LEDGER =
  "select "
  "  t.id, t.date, t.description, "
  "  c.name as category, "
  "  t.debit, t.credit, "
  "  sum(t.credit - t.debit) over ("
  "    order by t.date, t.id"
  "  ) as running_balance "
  "from transactions t "
  "join categories c on c.id = t.category_id "
  "where t.account_id = ?;"; 
#endif
