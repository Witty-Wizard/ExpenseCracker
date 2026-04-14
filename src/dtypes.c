#include <stdio.h>
#include <string.h>
#include "dtypes.h"

dtype_t
GET_DTYPE(const char *s)
{
  if(strcmp(s, "INTEGER") == 0)
    return INTEGER;

  if(strcmp(s, "REAL") == 0)
    return REAL;

  if(strcmp(s, "TEXT") == 0)
    return TEXT;

  return UNDEF;
}

dvar_t
CREATE_DVAR(dtype_t type, const char *name, void *val)
{
  dvar_t _col = { 0 };
  if(!name)
    return _col;

  _col.type = type;
  _col.name = name;

  switch(_col.type) {
  case INTEGER:
    _col.value.i = val ? *(int *)val : 0;
    break;
  case TEXT:
    _col.value.s = val ? (const char *)val : "";
    break;
  case REAL:
    _col.value.d = val ? *(double *)val : 0.0;
    break;
  default:
    break;
  }
  return _col;
}
