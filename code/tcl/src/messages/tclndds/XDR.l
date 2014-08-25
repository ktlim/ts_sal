%{  /* -*- c -*-  */

/*

   Kurt Schwehr - schwehr@artemis.arc.nasa.gov - 7/96 

   This is the flex input file.  It produces a lexical analyzer that
   returns tokens to the parser generated by bison from XDR.y.  The
   tokens returned to yyparse from here are defined by the "%token"
   statements in XDR.y.  Check the XDR RFC for more more information
   on the format for XDR data specifications in the .x files.

   COMPILING:
   flex -b -p -v -B -T -8 XDR.l
     [or]
   flex -B -8 XDR.l 
*/

static char rcs_id[] =
  "$Id: XDR.l,v 1.4 1998/07/16 16:37:29 mwagner Exp $";

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "XDR.tab.h"
#include "XDR.h"

#define YY_NO_UNPUT /* Stop getting a warning about it not getting used */
static void DB		(char *s);
static int tokenpos = 0;

static void
DB (char *s) {
    /*ECHO;*/
#ifndef NDEBUG
    /*printf ("%s ",s);*/
#endif
    tokenpos += yyleng;
    return;
}

/* NOT_IMPLEMINTED is a reminder that not all of the XDR specification
 * has been implimented in the parser.  If you get a not implimented
 * error, you need to add the handler for the keyword into the
 * parser (XDR.y).
 */
static void
NOT_IMPLIMENTED (char *s) {
  fprintf (stderr,"ERROR: keyword %s not implemented yet.\n", s);
  fprintf (stderr,"       Probably will be a fatal error.\n");
  exit(EXIT_FAILURE);
}

%}
%start          norm comment

    /* Handy regular expression substitutions. */
WS		([ \t])
LETTER		([a-zA-Z])
DIGIT		([0-9])
INTEGER		(("+"|"-")?{DIGIT}+)
SCALEFACTOR	("E"("+"|"-")?{DIGIT}+)
REAL		(("+"|"-")?{DIGIT}+"."{DIGIT}*{SCALEFACTOR}?)
WORD		({LETTER}({LETTER}|{DIGIT})*)

	/* Variable names/identifiers */
VARLETTER	([a-zA-Z_])
VARWORD		({VARLETTER}({VARLETTER}|{DIGIT})*)

%%

%{ /* Can place C code here */
%}

<norm>bool		{DB("BOOL");     return (yBOOL);}
<norm>char		{DB("CHAR");     return (CHAR);}
<norm>const		{DB("CONST");    return (CONST);}
<norm>double		{DB("DOUBLE");   return (DOUBLE);}
<norm>float		{DB("FLOAT");    return (FLOAT);}
<norm>string		{DB("STRING");   return (STRING);}
<norm>struct		{DB("STRUCT");   return (STRUCT);}
<norm>typedef		{DB("TYPEDEF");  return (TYPEDEF);}
<norm>unsigned		{DB("UNSIGNED"); return (UNSIGNED);}
<norm>void		{DB("VOID");     return (yVOID);}
<norm>opaque		{DB("OPAQUE");   return (OPAQUE);}

<norm>default		{DB("DEFAULT");  NOT_IMPLIMENTED ("DEFAULT");}
<norm>enum		{DB("ENUM");     NOT_IMPLIMENTED ("ENUM");}
<norm>hyper		{DB("HYPER");    NOT_IMPLIMENTED ("HYPER");}
<norm>switch		{DB("SWITCH");   NOT_IMPLIMENTED ("SWITCH");}
<norm>union		{DB("UNION");    NOT_IMPLIMENTED ("UNION");}
<norm>case		{DB("CASE");     NOT_IMPLIMENTED ("CASE");}

<norm>long		{DB("LONG");	return (LONG);}
<norm>int		{DB("INT");	return (INT);}
<norm>short		{DB("SHORT");	return (SHORT);}

<norm>"["		{DB("[");     return ((int)'[');}
<norm>"]"		{DB("]");     return ((int)']');}
<norm>"{"		{DB("{");     return ((int)'{');}
<norm>"}"		{DB("}");     return ((int)'}');}
<norm>"<"		{DB("<");     return ((int)'<');}
<norm>">"		{DB(">");     return ((int)'>');}
<norm>"("		{DB("(");     return ((int)'(');}
<norm>")"		{DB(")");     return ((int)')');}
<norm>"."		{DB(".");     return ((int)'.');}
<norm>","		{DB(",");     return ((int)',');}
<norm>";"		{DB(";");     return ((int)';');}
<norm>":"		{DB(":");     return ((int)':');}

<norm>{VARWORD}		{
                            yylval.stringval=
                                (char *) malloc((unsigned) yyleng+1);
                            strcpy(yylval.stringval,yytext);
                            return(IDENTIFIER);
                        }
<norm>{INTEGER}		{
  			  yylval.intval = 
			       (int) strtol(yytext,(char **) NULL,10);
			  DB("INTEGER");
			  /*NOT_IMPLIMENTED ("INTCONST");*/
			  return (INTCONST);
                        }
<norm>{REAL}		{
                          sscanf(yytext, "%lf",&yylval.floatval);
			  DB("REAL");
			  NOT_IMPLIMENTED ("FLOAT/REAL CONST");
			  return (FLOAT);
		        }

\n 		 	{ yylineno++;  tokenpos = 0;  DB("\n"); }
<norm>{WS}		{ /* NOP -> Suck up white space */ }

"/*"                    { BEGIN comment; }
<comment>(.)		{ ;              }  /* discard everything within a comment */
<comment>"*/"           { BEGIN norm;    }

<<EOF>>         	{ yyterminate(); }

%%  /* C code section */

/* lexinit - starts the Lexical Analyzer off in the right start condition */
void lexinit() {
    assert (rcs_id);	/* Avoid a gcc warning */
    yylineno = 0;
    BEGIN norm;
    return;
}

void yyerror (const char *s) { 
    printf ("\n");
    printf ("ERROR line %d: %s @ '%s'\n", yylineno, s, yytext);
    printf ("  Last token was %s\n", yytext);
    printf ("  Message: %s\n", s);
    return;
}