CREATE FUNCTION convert_to_bytea(independent_var REAL[])
RETURNS BYTEA
AS
$$
import numpy as np

return np.array(independent_var, dtype=np.float32).tobytes()
$$ LANGUAGE plpythonu;
