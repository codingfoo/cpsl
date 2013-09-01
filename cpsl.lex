%{
#include <stdio.h>
#include <stdlib.h>
%}
%{
enum keyword {
ARRAY_KEYWORD,
BEGIN_KEYWORD,
CHR_KEYWORD,
CONST_KEYWORD,
DO_KEYWORD,
END_KEYWORD,
FOR_KEYWORD,
FORWARD_KEYWORD,
ORD_KEYWORD,
PRED_KEYWORD,
PROCEDURE_KEYWORD,
RETURN_KEYWORD,
STOP_KEYWORD,
SUCC_KEYWORD,
UNTIL_KEYWORD,
VAR_KEYWORD,
WHILE_KEYWORD,
DOWNTO_KEYWORD,
FUNCTION_KEYWORD,
READ_KEYWORD,
THEN_KEYWORD,
WRITE_KEYWORD
};
%}
digit [0-9]
letter [a-zA-Z]
%%
array|ARRAY {return(ARRAY_KEYWORD);}
begin|BEGIN {return(BEGIN_KEYWORD);}
chr|CHR {return(CHR_KEYWORD);}
const|CONST {return(CONST_KEYWORD);}

do|DO {return(DO_KEYWORD);}
end|END {return(END_KEYWORD);}
for|FOR {return(FOR_KEYWORD);}
forward|FORWARD {return(FORWARD_KEYWORD);}
ord|ORD {return(ORD_KEYWORD);}
pred|PRED {return(PRED_KEYWORD);}
procedure|PROCEDURE {return(PROCEDURE_KEYWORD);}
return|RETURN {return(RETURN_KEYWORD);}
stop|STOP {return(STOP_KEYWORD);}
succ|SUCC {return(SUCC_KEYWORD);}
until|UNTIL {return(UNTIL_KEYWORD);}
var|VAR {return(VAR_KEYWORD);}
while|WHILE {return(WHILE_KEYWORD);}
downto|DOWNTO {return(DOWNTO_KEYWORD);}
function|FUNCTION {return(FUNCTION_KEYWORD);}
read|READ {return(READ_KEYWORD);}
then|THEN {return(THEN_KEYWORD);}
write|WRITE {return(WRITE_KEYWORD);}

. {printf("ILLEGAL CHARACTER");}
%%
int main(int argc, char* argv[]) {
  yylex() ;
  return 0 ;
}


