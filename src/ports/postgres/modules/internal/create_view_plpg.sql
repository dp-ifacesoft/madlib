CREATE OR REPLACE FUNCTION create_view(tab text, col text) RETURNS int AS
$$
DECLARE
myresult col%TYPE;
BEGIN
SELECT quote_ident(col) FROM quote_ident(tab) INTO myresult;
RETURN myresult;
END;
$$
LANGUAGE plpgsql
VOLATILE;
