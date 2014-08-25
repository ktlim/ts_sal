
/*  A Bison parser, made from XDR.y
 by  GNU Bison version 1.25
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	yBOOL	258
#define	CONST	259
#define	DOUBLE	260
#define	FLOAT	261
#define	OPAQUE	262
#define	STRING	263
#define	STRUCT	264
#define	TYPEDEF	265
#define	UNSIGNED	266
#define	yVOID	267
#define	INT	268
#define	SHORT	269
#define	CONSTANT	270
#define	CHAR	271
#define	IDENTIFIER	272
#define	INTCONST	273
#define	LONG	274

#line 9 "XDR.y"
 /* C code section */

#define YYERROR_VERBOSE 1
#define YYDEBUG 1

#ifdef OS_VXWORKS
  #include <vxWorks.h>
  #include <sysLib.h>
  #include <vme.h>
  #include <stdioLib.h>
#else /* anything that isn't vxWorks */
  #include <stdlib.h>	/* For malloc */
  #include <stdio.h>
#endif /* OS_VXWORKS */

#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "XDR.h"

static char rcs_id[] =
  "$Id: XDR.y,v 1.8 1998/07/16 16:37:30 mwagner Exp $";

#ifndef IRIX
void __yy_memcpy (char *to, char *from, int count);
#endif

static int argcount=0;


#line 42 "XDR.y"
typedef union          yystacktype
                {
		  void			*ptrval;
                  int            	intval;
                  double         	floatval;
                  char           	*stringval;
                  char           	charval;
		} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		49
#define	YYFLAG		-32768
#define	YYNTBASE	28

#define YYTRANSLATE(x) ((unsigned)(x) <= 274 ? yytranslate[x] : 38)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    20,    22,
    21,    23,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    24,     2,    25,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    26,     2,    27,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     4,     6,     8,    12,    13,    19,    25,    28,
    33,    39,    44,    46,    49,    52,    55,    57,    59,    61,
    63,    66,    68,    72,    76,    79,    81
};

static const short yyrhs[] = {    28,
    29,     0,     0,    30,     0,    32,     0,    10,    33,    20,
     0,     0,     9,    17,    31,    35,    20,     0,     4,    17,
    21,    15,    20,     0,    34,    17,     0,    34,    17,    22,
    23,     0,    34,    17,    24,    18,    25,     0,     8,    17,
    22,    23,     0,    12,     0,    37,    19,     0,    37,    13,
     0,    37,    14,     0,     6,     0,     5,     0,     3,     0,
     7,     0,    37,    16,     0,    35,     0,    26,    36,    27,
     0,    36,    33,    20,     0,    33,    20,     0,    11,     0,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    72,    73,    75,    75,    77,    78,    80,    84,    86,   101,
   131,   167,   182,   184,   185,   186,   187,   188,   189,   190,
   193,   194,   196,   197,   198,   200,   200
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","yBOOL",
"CONST","DOUBLE","FLOAT","OPAQUE","STRING","STRUCT","TYPEDEF","UNSIGNED","yVOID",
"INT","SHORT","CONSTANT","CHAR","IDENTIFIER","INTCONST","LONG","';'","'='","'<'",
"'>'","'['","']'","'{'","'}'","specification","definition","type_def","@1","constant_def",
"decl","type","struct","declList","optUnsigned", NULL
};
#endif

static const short yyr1[] = {     0,
    28,    28,    29,    29,    30,    31,    30,    32,    33,    33,
    33,    33,    33,    34,    34,    34,    34,    34,    34,    34,
    34,    34,    35,    36,    36,    37,    37
};

static const short yyr2[] = {     0,
     2,     0,     1,     1,     3,     0,     5,     5,     2,     4,
     5,     4,     1,     2,     2,     2,     1,     1,     1,     1,
     2,     1,     3,     3,     2,     1,     0
};

static const short yydefact[] = {     2,
     0,     0,     0,    27,     1,     3,     4,     0,     6,    19,
    18,    17,    20,     0,    26,    13,    27,     0,     0,    22,
     0,     0,     0,     0,     0,    27,     5,     9,    15,    16,
    21,    14,     0,     0,     0,    25,    23,     0,     0,     0,
     8,     7,    12,    24,    10,     0,    11,     0,     0
};

static const short yydefgoto[] = {     1,
     5,     6,    23,     7,    18,    19,    20,    26,    21
};

static const short yypact[] = {-32768,
    16,   -16,   -11,     7,-32768,-32768,-32768,   -14,-32768,-32768,
-32768,-32768,-32768,    -6,-32768,-32768,     7,     2,     0,-32768,
    15,    12,     6,    14,    18,    -3,-32768,    13,-32768,-32768,
-32768,-32768,    19,    20,    21,-32768,-32768,    22,    23,    25,
-32768,-32768,-32768,-32768,-32768,    24,-32768,    41,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,     4,-32768,    27,-32768,-32768
};


#define	YYLAST		50


static const short yytable[] = {    10,
     8,    11,    12,    13,    14,     9,    22,    15,    16,    10,
    24,    11,    12,    13,    14,    48,    28,    15,    16,     2,
    25,    27,    17,    37,     3,     4,    33,    29,    30,    38,
    31,    17,    17,    32,    39,    35,    40,    36,    41,    42,
    49,    44,    46,    43,     0,    45,     0,     0,    47,    34
};

static const short yycheck[] = {     3,
    17,     5,     6,     7,     8,    17,    21,    11,    12,     3,
    17,     5,     6,     7,     8,     0,    17,    11,    12,     4,
    17,    20,    26,    27,     9,    10,    15,    13,    14,    26,
    16,    26,    26,    19,    22,    22,    24,    20,    20,    20,
     0,    20,    18,    23,    -1,    23,    -1,    -1,    25,    23
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/afs/cs/project/lri-7/bin/share/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 196 "/afs/cs/project/lri-7/bin/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 72 "XDR.y"
{ assert (rcs_id); /* Avoid a warning */ ;
    break;}
case 6:
#line 79 "XDR.y"
{ startStructFunction(yyvsp[0].stringval); argcount = 0; ;
    break;}
case 7:
#line 81 "XDR.y"
{   endStructFunction(yyvsp[-3].stringval, argcount); ;
    break;}
case 9:
#line 87 "XDR.y"
{
			  if ( 0 == strcmp (yyvsp[-1].stringval,"c") ) {
			      /* This is the ugly acception for the "char" type */
			      fprintf (T2Nfile,"  {\n    int num;\n    sscanf  (argv[count++], \"%%d\", &num);\n");
			      fprintf (T2Nfile,"    %s->%s = (char)num;\n  }\n", nddsObj, yyvsp[0].stringval);
			      fprintf (N2Tfile,"  sprintf (tmpStr, \"%%d\", %s->%-10s);",        nddsObj, yyvsp[0].stringval);
			  } else {
			      fprintf (T2Nfile,"  sscanf  (argv[count++], \"%%%s\", &%s->%-10s);\n", yyvsp[-1].stringval, nddsObj, yyvsp[0].stringval);
			      fprintf (N2Tfile,"  sprintf (tmpStr, \"%%%s\", %s->%-10s);",        yyvsp[-1].stringval, nddsObj, yyvsp[0].stringval);
			  }
			  fprintf (N2Tfile,"  newValue = Tcl_SetVar2 (interp, \"this\", \"%s\", tmpStr, TCL_LEAVE_ERR_MSG);\n",yyvsp[0].stringval);
			  argcount++;
			;
    break;}
case 10:
#line 102 "XDR.y"
{
			  /* Variable sized arrays */
			  /* FIX: does not handle chars the same way as other types. */
			  fprintf (N2Tfile,"  for (i=0; i<%s->%s.%s_len; i++) {\n", nddsObj, yyvsp[-2].stringval, yyvsp[-2].stringval);
			  /* Space required after %s to make a list: */
			  if ( 0 == strcmp (yyvsp[-3].stringval,"c") ) {
			      /* This is the ugly acception for the "char" type */
			      fprintf (N2Tfile,"    sprintf (tmpStr, \"%%d \", %s->%s.%s_val[i]);\n",nddsObj,yyvsp[-2].stringval, yyvsp[-2].stringval);
			  } else {
			      fprintf (N2Tfile,"    sprintf (tmpStr, \"%%%s \", %s->%s.%s_val[i]);\n",yyvsp[-3].stringval,nddsObj,yyvsp[-2].stringval, yyvsp[-2].stringval);
			  }
			  fprintf (N2Tfile,"    newValue = Tcl_SetVar2 (interp, \"this\", \"%s\", ", yyvsp[-2].stringval);
			  fprintf (N2Tfile,"tmpStr,TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG);\n");
			  fprintf (N2Tfile,"  }\n");


#if 0
			  fprintf (N2Tfile,"  for (i=0; i<%s->%s.%s_len; i++) {\n", nddsObj, yyvsp[-2].stringval, yyvsp[-2].stringval);
			  fprintf (N2Tfile,"    sprintf (tmpStr, \"%%%s\", %s->%s.%s_val[i]);\n",yyvsp[-3].stringval,nddsObj,yyvsp[-2].stringval,yyvsp[-2].stringval);
			  fprintf (N2Tfile,"    Tcl_DStringAppendElement (tclDStrPtr,tmpStr);\n");
			  fprintf (N2Tfile,"  }\n");
#endif
			  if ('c'==yyvsp[-3].stringval[0]) fprintf (N2Tfile,"    %s->%s.%s_val[i] = '\\0';\n", nddsObj, yyvsp[-2].stringval, yyvsp[-2].stringval);

			  fprintf (T2Nfile,"  for (i=0; i<%s->%s.%s_len; i++)\n", nddsObj, yyvsp[-2].stringval, yyvsp[-2].stringval);
			  fprintf (T2Nfile,"      sscanf(argv[count++],\"%%%s\",&(%s->%s.%s_val[i]));\n",yyvsp[-3].stringval,nddsObj,yyvsp[-2].stringval,yyvsp[-2].stringval);
			  if ('c'==yyvsp[-3].stringval[0]) fprintf (T2Nfile,"    %s->%s.%s_val[i] = '\\0';\n", nddsObj, yyvsp[-2].stringval, yyvsp[-2].stringval);
			  argcount++;
			;
    break;}
case 11:
#line 132 "XDR.y"
{
			  fprintf (N2Tfile,"  for (i=0; i<%d; i++) {\n", yyvsp[-1].intval);
			  /* Space required after %s to make a list: */
			  if ( 0 == strcmp (yyvsp[-4].stringval,"c") ) {
			      /* This is the ugly acception for the "char" type */
			      fprintf (N2Tfile,"    sprintf (tmpStr, \"%%d \", %s->%s[i]);\n",nddsObj,yyvsp[-3].stringval);
			  } else {
			      fprintf (N2Tfile,"    sprintf (tmpStr, \"%%%s \", %s->%s[i]);\n",yyvsp[-4].stringval,nddsObj,yyvsp[-3].stringval);
			  }
			  fprintf (N2Tfile,"    newValue = Tcl_SetVar2 (interp, \"this\", \"%s\", ", yyvsp[-3].stringval);
			  fprintf (N2Tfile,"tmpStr,TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG);\n");
			  fprintf (N2Tfile,"  }\n");
#if 0
			  fprintf (N2Tfile,"  for (i=0; i<%d; i++) {\n", yyvsp[-1].intval);
			  fprintf (N2Tfile,"    sprintf (tmpStr, \"%%%s\", %s->%s[i]);\n",yyvsp[-4].stringval,nddsObj,yyvsp[-3].stringval);
			  fprintf (N2Tfile,"    Tcl_DStringAppendElement (tclDStrPtr,tmpStr);\n");
			  fprintf (N2Tfile,"  }\n");
#endif


			  /* Finish off an array of characters (string) */
			  /* FIX: Is this really necessary?  -Kurt */
			  /*if ('c'==$1[0]) fprintf (N2Tfile,"    %s->%s[i] = '\\0';\n", nddsObj, $2);*/

			  /* fixed length  (char[x]) are special */
			  if ('c'==yyvsp[-4].stringval[0]) {
			      /* \0 provided by user: */
			      fprintf (T2Nfile,"  strcpy  (%s->%-10s , argv[count++]);\n",nddsObj,yyvsp[-3].stringval);
			      argcount ++;	/* Only one argument. */ 
			  } else {
			      fprintf (T2Nfile,"  for (i=0; i<%d; i++)\n", yyvsp[-1].intval);
			      fprintf (T2Nfile,"      sscanf(argv[count++],\"%%%s\",&(%s->%s[i]));\n",yyvsp[-4].stringval,nddsObj,yyvsp[-3].stringval);
			      argcount += yyvsp[-1].intval;
			  }
			;
    break;}
case 12:
#line 168 "XDR.y"
{
			  /* Strings become (char *) */

			  fprintf (N2Tfile,"  sprintf (tmpStr, \"%%s\", %s->%-10s);",nddsObj,yyvsp[-2].stringval);
			  fprintf (N2Tfile,"    newValue = Tcl_SetVar2 (interp, \"this\", \"%s\", ", yyvsp[-2].stringval);
			  fprintf (N2Tfile,"tmpStr,TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG);\n");
			  fprintf (T2Nfile,"  strcpy  (%s->%-10s , argv[count++]);\n",nddsObj,yyvsp[-2].stringval);
#if 0
			  fprintf (N2Tfile,"  sprintf (tmpStr, \"%%s\", %s->%-10s);",nddsObj,yyvsp[-2].stringval);
			  fprintf (N2Tfile,"  Tcl_DStringAppendElement (tclDStrPtr,tmpStr); \n");
			  fprintf (T2Nfile,"  strcpy  (%s->%-10s , argv[count++]);\n",nddsObj,yyvsp[-2].stringval);
#endif
			  argcount++;
			;
    break;}
case 14:
#line 184 "XDR.y"
{  yyval.stringval = ( yyvsp[-1].intval /*unsigned*/)?"ld":"ld"; ;
    break;}
case 15:
#line 185 "XDR.y"
{  yyval.stringval = ( yyvsp[-1].intval /*unsigned*/)? "u": "d"; ;
    break;}
case 16:
#line 186 "XDR.y"
{  yyval.stringval = ( yyvsp[-1].intval /*unsigned*/)?"hu":"hd"; ;
    break;}
case 17:
#line 187 "XDR.y"
{  yyval.stringval = "f"; ;
    break;}
case 18:
#line 188 "XDR.y"
{  yyval.stringval = "lf"; ;
    break;}
case 19:
#line 189 "XDR.y"
{  yyval.stringval = "d"; ;
    break;}
case 20:
#line 190 "XDR.y"
{  yyval.stringval = "c"; ;
    break;}
case 21:
#line 193 "XDR.y"
{  yyval.stringval = ( yyvsp[-1].intval /*unsigned*/)? "c": "c"; ;
    break;}
case 22:
#line 194 "XDR.y"
{  yyval.stringval = "?"; printf (" lookupStruct()->FIX:not implimented\n"); ;
    break;}
case 26:
#line 200 "XDR.y"
{ yyval.intval = TRUE;;
    break;}
case 27:
#line 200 "XDR.y"
{ yyval.intval = FALSE; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 498 "/afs/cs/project/lri-7/bin/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 201 "XDR.y"

/* C code section */