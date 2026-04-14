#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "dtypes.h"

int
main(void)
{
  sqlite3 *db;
  sqlite3_stmt *stmt;

  int rc = sqlite3_open("./data/expense_tracker.db", &db);

  const char *command = "SELECT * from transactions";
  rc = sqlite3_prepare_v2(db, command, -1, &stmt, NULL);

  int num_col = sqlite3_column_count(stmt);

  dvar_t *row = (dvar_t *)malloc(sizeof(dvar_t) * num_col);

  printf("Number of Columns: %d\n", num_col);

  for(int i = 0; i < num_col; i++) {
    dtype_t type = GET_DTYPE(sqlite3_column_decltype(stmt, i));
    const char *name = sqlite3_column_name(stmt, i);
    row[i] = CREATE_DVAR(type, name, NULL);
    printf("|%d (%s)", i, row[i].name);
  }
  printf("|\n");
  while(sqlite3_step(stmt) == SQLITE_ROW) {
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
}
