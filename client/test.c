#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
main()
{
  sqlite3 *db;
  sqlite3_stmt *stmt;
  char *errmsg=NULL;
  char sql[1000];
  remove("update.db");
  sqlite3_open("mydb",&db);
  strcpy(sql,"SELECT * FROM users WHERE Username=\'stefan\'");
  sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,NULL);
  while(sqlite3_step(stmt)==SQLITE_ROW)
  {
    int ref;
    ref = sqlite3_column_int(stmt,1);
    printf("Before %d\n",ref);
  }
  sqlite3_finalize(stmt);
  sqlite3_close(db);

}
