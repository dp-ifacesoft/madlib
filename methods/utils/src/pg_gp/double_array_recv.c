#include "postgres.h"
#include "lib/stringinfo.h"
#include "utils/array.h"
#include "utils/fmgroids.h"

#ifndef NO_PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(double_array_recv);

Datum
double_array_recv(PG_FUNCTION_ARGS)
{
  bytea *d = PG_GETARG_BYTEA_P(0);
  Oid element_type = PG_GETARG_OID(1);
  StringInfoData si;
  Datum result;

  si.data = VARDATA(d);
  si.len = si.maxlen = VARSIZE(d) - VARHDRSZ;
  si.cursor = 0;

  result = OidReceiveFunctionCall(F_ARRAY_RECV,
                                  &si,
                                  element_type,
                                  -1);
  PG_RETURN_ARRAYTYPE_P(DatumGetArrayTypeP(result));
}
