/*****************************************************************************
 * @file dtypes.h
 * @brief header file for dynamic typed variables
 *****************************************************************************/

#ifndef DTYPES_H
#define DTYPES_H

/*****************************************************************************
 * Header inclusions
 *****************************************************************************/

/*****************************************************************************
 * enum definitions
 *****************************************************************************/
typedef enum dtype_e
{
  INTEGER,
  REAL,
  TEXT,
  UNDEF
} dtype_t;

  /*****************************************************************************
   * Public Structure definition
   *****************************************************************************/
  typedef struct dvar_s
{
  dtype_t type;
  const char *name;
  union value_u
  {
    int i;
    double d;
    const char *s;
  } value;
} dvar_t;

/*****************************************************************************
 * Public function declaration
 *****************************************************************************/
/**
 * @brief function to take string and convert it to an enum
 */
dtype_t GET_DTYPE(const char *s);

/**
 * @brief Function to create a dynamic variable
 *
 * @param type Type of variable defined in the enum
 * @param *name Name of the Variable in a string literal
 * @param *val value of the variable
 */
dvar_t CREATE_DVAR(dtype_t type, const char *name, void *val);

#endif
