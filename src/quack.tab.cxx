// A Bison parser, made by GNU Bison 3.4.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "quack.tab.hxx"


// Unqualified %code blocks.
#line 29 "quack.yxx"

    #include "lex.yy.h"
    #undef yylex
    #define yylex lexer.yylex  /* Within bison's parse() we should invoke lexer.yylex(), not the global yylex() */
    void dump(AST::ASTNode* n);


#line 53 "quack.tab.cxx"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 144 "quack.tab.cxx"


  /// Build a parser object.
  parser::parser (yy::Lexer& lexer_yyarg, AST::ASTNode** root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 145 "quack.yxx"
    { (yylhs.value.node) = new AST::Program(*(yystack_[1].value.classes), *(yystack_[0].value.block));
          *root = (yylhs.value.node); // Transmit tree back to driver
        }
#line 591 "quack.tab.cxx"
    break;

  case 3:
#line 151 "quack.yxx"
    { (yylhs.value.classes) = (yystack_[1].value.classes); (yylhs.value.classes)->append((yystack_[0].value.clazz)); }
#line 597 "quack.tab.cxx"
    break;

  case 4:
#line 152 "quack.yxx"
    {  (yylhs.value.classes) = new AST::Classes(); }
#line 603 "quack.tab.cxx"
    break;

  case 5:
#line 159 "quack.yxx"
    { (yylhs.value.clazz) = new AST::Class(*(yystack_[7].value.ident), *(new AST::Ident("Obj")), 
                        *(new AST::Method(*(yystack_[7].value.ident), *(yystack_[5].value.formals), *(new AST::Ident("Nothing")), *(yystack_[2].value.block))),
                        *(yystack_[1].value.methods)); }
#line 611 "quack.tab.cxx"
    break;

  case 6:
#line 163 "quack.yxx"
    { (yylhs.value.clazz) = new AST::Class(*(yystack_[9].value.ident), *(yystack_[4].value.ident), 
                            *(new AST::Method(*(yystack_[9].value.ident), *(yystack_[7].value.formals), *(new AST::Ident("Nothing")), *(yystack_[2].value.block))), *(yystack_[1].value.methods)); }
#line 618 "quack.tab.cxx"
    break;

  case 7:
#line 168 "quack.yxx"
    { (yylhs.value.methods) = (yystack_[1].value.methods); (yylhs.value.methods)->append((yystack_[0].value.method)); }
#line 624 "quack.tab.cxx"
    break;

  case 8:
#line 169 "quack.yxx"
    { (yylhs.value.methods) = new AST::Methods(); }
#line 630 "quack.tab.cxx"
    break;

  case 9:
#line 173 "quack.yxx"
    { (yylhs.value.method) = new AST::Method(*(yystack_[6].value.ident), *(yystack_[4].value.formals), *(yystack_[1].value.ident), *(yystack_[0].value.block)); }
#line 636 "quack.tab.cxx"
    break;

  case 10:
#line 175 "quack.yxx"
    { (yylhs.value.method) = new AST::Method(*(yystack_[4].value.ident), *(yystack_[2].value.formals), *(new AST::Ident("Nothing")), *(yystack_[0].value.block)); }
#line 642 "quack.tab.cxx"
    break;

  case 11:
#line 179 "quack.yxx"
    { (yylhs.value.formals) = (yystack_[0].value.formals); }
#line 648 "quack.tab.cxx"
    break;

  case 12:
#line 180 "quack.yxx"
    { (yylhs.value.formals) = new AST::Formals(); }
#line 654 "quack.tab.cxx"
    break;

  case 13:
#line 183 "quack.yxx"
    { (yylhs.value.formals) = (yystack_[2].value.formals); (yylhs.value.formals)->append((yystack_[0].value.formal)); }
#line 660 "quack.tab.cxx"
    break;

  case 14:
#line 184 "quack.yxx"
    { (yylhs.value.formals)->append((yystack_[0].value.formal)); }
#line 666 "quack.tab.cxx"
    break;

  case 15:
#line 186 "quack.yxx"
    { (yylhs.value.formal) = new AST::Formal(*(yystack_[2].value.ident), *(yystack_[0].value.ident)); }
#line 672 "quack.tab.cxx"
    break;

  case 16:
#line 195 "quack.yxx"
    { (yylhs.value.block) = (yystack_[1].value.block); (yylhs.value.block)->append((yystack_[0].value.statement)); }
#line 678 "quack.tab.cxx"
    break;

  case 17:
#line 196 "quack.yxx"
    { (yylhs.value.block) = new AST::Block(); }
#line 684 "quack.tab.cxx"
    break;

  case 18:
#line 199 "quack.yxx"
    {  (yylhs.value.block) = (yystack_[1].value.block); }
#line 690 "quack.tab.cxx"
    break;

  case 19:
#line 211 "quack.yxx"
    { (yylhs.value.statement) = new AST::If(*(yystack_[2].value.expr), *(yystack_[1].value.block), *(yystack_[0].value.block)); }
#line 696 "quack.tab.cxx"
    break;

  case 20:
#line 214 "quack.yxx"
    { (yylhs.value.block) = new AST::Block();
                  (yylhs.value.block)->append(new AST::If(*(yystack_[2].value.expr), *(yystack_[1].value.block), *(yystack_[0].value.block))); }
#line 703 "quack.tab.cxx"
    break;

  case 21:
#line 216 "quack.yxx"
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 709 "quack.tab.cxx"
    break;

  case 22:
#line 217 "quack.yxx"
    { (yylhs.value.block) = new AST::Block(); }
#line 715 "quack.tab.cxx"
    break;

  case 23:
#line 222 "quack.yxx"
    { (yylhs.value.statement) = new AST::While(*(yystack_[1].value.expr), *(yystack_[0].value.block)); }
#line 721 "quack.tab.cxx"
    break;

  case 24:
#line 231 "quack.yxx"
    { (yylhs.value.statement) = new AST::Assign(*(yystack_[3].value.l_expr), *(yystack_[1].value.expr)); }
#line 727 "quack.tab.cxx"
    break;

  case 25:
#line 233 "quack.yxx"
    { (yylhs.value.statement) = new AST::AssignDeclare(*(yystack_[5].value.l_expr), *(yystack_[1].value.expr), *(yystack_[3].value.ident)); }
#line 733 "quack.tab.cxx"
    break;

  case 26:
#line 235 "quack.yxx"
    { (yylhs.value.statement) = (yystack_[1].value.expr); }
#line 739 "quack.tab.cxx"
    break;

  case 27:
#line 246 "quack.yxx"
    { (yylhs.value.l_expr) =  new AST::Ident((yystack_[0].value.str));   }
#line 745 "quack.tab.cxx"
    break;

  case 28:
#line 247 "quack.yxx"
    { (yylhs.value.l_expr) = new AST::Dot(*(yystack_[2].value.expr), *(new AST::Ident((yystack_[0].value.str)))); }
#line 751 "quack.tab.cxx"
    break;

  case 29:
#line 262 "quack.yxx"
    { (yylhs.value.expr) = new AST::Load(*(yystack_[0].value.l_expr)); }
#line 757 "quack.tab.cxx"
    break;

  case 30:
#line 265 "quack.yxx"
    { (yylhs.value.expr) = new AST::StrConst((yystack_[0].value.str)); }
#line 763 "quack.tab.cxx"
    break;

  case 31:
#line 266 "quack.yxx"
    { (yylhs.value.expr) = new AST::IntConst((yystack_[0].value.num)); }
#line 769 "quack.tab.cxx"
    break;

  case 32:
#line 270 "quack.yxx"
    { (yylhs.value.expr) = (yystack_[1].value.expr); }
#line 775 "quack.tab.cxx"
    break;

  case 33:
#line 279 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop("TIMES", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 781 "quack.tab.cxx"
    break;

  case 34:
#line 280 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop("DIVIDE", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 787 "quack.tab.cxx"
    break;

  case 35:
#line 281 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop("PLUS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 793 "quack.tab.cxx"
    break;

  case 36:
#line 282 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop("MINUS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 799 "quack.tab.cxx"
    break;

  case 37:
#line 283 "quack.yxx"
    {
                              auto zero = new AST::IntConst(0);
                              (yylhs.value.expr) = AST::Call::binop("MINUS", *zero, *(yystack_[0].value.expr));
                            }
#line 808 "quack.tab.cxx"
    break;

  case 38:
#line 287 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop("EQUALS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 814 "quack.tab.cxx"
    break;

  case 39:
#line 288 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop("ATMOST", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 820 "quack.tab.cxx"
    break;

  case 40:
#line 289 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop("<", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 826 "quack.tab.cxx"
    break;

  case 41:
#line 290 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop("ATLEAST", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 832 "quack.tab.cxx"
    break;

  case 42:
#line 291 "quack.yxx"
    { (yylhs.value.expr) = AST::Call::binop(">", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 838 "quack.tab.cxx"
    break;

  case 43:
#line 294 "quack.yxx"
    { (yylhs.value.expr) = new AST::And(*(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 844 "quack.tab.cxx"
    break;

  case 44:
#line 295 "quack.yxx"
    { (yylhs.value.expr) = new AST::Or(*(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 850 "quack.tab.cxx"
    break;

  case 45:
#line 296 "quack.yxx"
    { (yylhs.value.expr) = new AST::Not(*(yystack_[0].value.expr)); }
#line 856 "quack.tab.cxx"
    break;

  case 46:
#line 315 "quack.yxx"
    { (yylhs.value.expr) = new AST::Call(*(yystack_[5].value.expr), *(yystack_[3].value.ident), *(yystack_[1].value.actuals)); }
#line 862 "quack.tab.cxx"
    break;

  case 47:
#line 317 "quack.yxx"
    { (yylhs.value.actuals) = new AST::Actuals(); }
#line 868 "quack.tab.cxx"
    break;

  case 48:
#line 318 "quack.yxx"
    { (yylhs.value.actuals) = (yystack_[0].value.actuals); }
#line 874 "quack.tab.cxx"
    break;

  case 49:
#line 321 "quack.yxx"
    { (yylhs.value.actuals) = (yystack_[2].value.actuals); (yylhs.value.actuals)->append((yystack_[0].value.expr)); }
#line 880 "quack.tab.cxx"
    break;

  case 50:
#line 322 "quack.yxx"
    { (yylhs.value.actuals) = new AST::Actuals(); (yylhs.value.actuals)->append((yystack_[0].value.expr)); }
#line 886 "quack.tab.cxx"
    break;

  case 51:
#line 327 "quack.yxx"
    { (yylhs.value.statement) = (yystack_[0].value.return_expr); }
#line 892 "quack.tab.cxx"
    break;

  case 52:
#line 330 "quack.yxx"
    { (yylhs.value.return_expr) = new AST::Return(*(yystack_[1].value.expr)); }
#line 898 "quack.tab.cxx"
    break;

  case 53:
#line 332 "quack.yxx"
    { (yylhs.value.return_expr) = new AST::Return(*(new AST::Ident("None"))); }
#line 904 "quack.tab.cxx"
    break;

  case 54:
#line 336 "quack.yxx"
    { (yylhs.value.statement) = (yystack_[0].value.typecase); }
#line 910 "quack.tab.cxx"
    break;

  case 55:
#line 339 "quack.yxx"
    { (yylhs.value.typecase) = new AST::Typecase(*(yystack_[3].value.expr), *(yystack_[1].value.type_alternatives)); }
#line 916 "quack.tab.cxx"
    break;

  case 56:
#line 342 "quack.yxx"
    { (yylhs.value.type_alternatives) = (yystack_[1].value.type_alternatives); (yylhs.value.type_alternatives)->append((yystack_[0].value.type_alternative)); }
#line 922 "quack.tab.cxx"
    break;

  case 57:
#line 343 "quack.yxx"
    { (yylhs.value.type_alternatives) = new AST::Type_Alternatives(); }
#line 928 "quack.tab.cxx"
    break;

  case 58:
#line 346 "quack.yxx"
    { (yylhs.value.type_alternative) = new AST::Type_Alternative(*(yystack_[3].value.ident), *(yystack_[1].value.ident), *(yystack_[0].value.block)); }
#line 934 "quack.tab.cxx"
    break;

  case 59:
#line 352 "quack.yxx"
    { (yylhs.value.expr) = new AST::Construct(*(yystack_[3].value.ident), *(yystack_[1].value.actuals)); }
#line 940 "quack.tab.cxx"
    break;

  case 60:
#line 354 "quack.yxx"
    { (yylhs.value.ident) = new AST::Ident((yystack_[0].value.str)); }
#line 946 "quack.tab.cxx"
    break;


#line 950 "quack.tab.cxx"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -54;

  const signed char parser::yytable_ninf_ = -61;

  const short
  parser::yypact_[] =
  {
     -54,    14,    16,   -54,    15,   -54,   200,   -54,     7,   338,
     338,    66,   338,   338,     8,   -54,   -54,   338,   338,   -54,
     -26,    38,   -54,   -54,    10,    15,   -54,   218,   218,   -54,
     137,   238,   294,    13,   258,    15,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,    24,   -54,
     338,    17,     9,   -54,    12,   -54,    20,   -54,   -54,   -54,
     -54,    11,   154,   326,   311,    68,   294,   294,   311,   326,
     -15,   -15,    13,    13,     8,    19,   277,    25,    22,    -2,
      15,    15,     6,   338,    18,   -54,   -10,   338,   -54,   338,
     -54,   338,    15,   -54,   -54,   -54,   -54,   218,   -54,   -54,
     -54,    32,   179,    37,   277,    40,   200,    20,    15,   -54,
     -54,   -54,     0,   -54,    18,   200,    15,   -54,   -54,   -54,
       2,    39,   -54,    15,    42,   -13,    15,   -54,    18,   -54
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,     0,    17,     1,     0,     3,     2,    60,     0,     0,
       0,     0,     0,     0,    27,    31,    30,     0,     0,    16,
      29,     0,    51,    54,     0,    12,    29,     0,     0,    53,
       0,     0,    45,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      47,     0,    11,    14,     0,    17,    22,    23,    52,    57,
      32,     0,     0,    41,    39,    38,    43,    44,    42,    40,
      35,    36,    33,    34,    28,     0,    50,     0,    48,     0,
       0,     0,     0,     0,     0,    19,     0,     0,    24,    47,
      59,     0,     0,    17,    13,    15,    18,     0,    21,    55,
      56,     0,     0,     0,    49,     0,     8,    22,     0,    25,
      46,    17,     0,    20,     0,     8,     0,     5,     7,    58,
       0,     0,     6,    12,     0,     0,     0,    10,     0,     9
  };

  const signed char
  parser::yypgoto_[] =
  {
     -54,   -54,   -54,   -54,   -46,   -54,   -50,   -54,    -5,   -53,
     -27,   -54,   -29,    -1,    98,    -9,   -54,   -54,   -54,   -54,
     -54,    -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     2,     5,   112,   118,    51,    52,    53,     6,
      56,    19,    85,    26,    21,    77,    78,    22,    23,    86,
     100,    24
  };

  const short
  parser::yytable_[] =
  {
       8,    57,    82,    92,   116,    20,   116,    35,     7,    36,
      46,    47,     9,    48,     3,    10,    11,    12,    55,     4,
     126,    54,    99,    13,    14,    15,    16,    83,    84,    93,
      17,    61,   117,     7,   122,    18,    25,   -60,    96,    50,
     106,    48,    74,    80,    75,    81,    87,    79,    89,    55,
      37,    38,    39,    40,    41,    90,    91,    98,   115,    42,
      43,    44,    45,    46,    47,   108,    48,   110,   123,   120,
     107,   111,   125,   124,    49,    94,    54,    95,   113,     0,
     103,    20,   101,    13,    14,    15,    16,   119,   105,     0,
      17,    44,    45,    46,    47,    18,    48,     0,   127,     0,
       0,   129,    29,     0,   114,    20,     0,    27,    28,    30,
      31,    32,   121,     0,    20,    33,    34,     0,     0,    54,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    76,    37,
      38,    39,    40,    41,     0,     0,     0,     0,    42,    43,
      44,    45,    46,    47,     0,    48,    37,    38,    39,    40,
      41,     0,     0,    58,     0,    42,    43,    44,    45,    46,
      47,    97,    48,     0,     0,   102,     0,    76,     0,   104,
      88,    37,    38,    39,    40,    41,     0,     0,     0,     0,
      42,    43,    44,    45,    46,    47,     9,    48,     0,    10,
      11,    12,     0,     0,     0,   109,     0,    13,    14,    15,
      16,     0,     0,     0,    17,     0,     0,     0,     0,    18,
      37,    38,    39,    40,    41,     0,     0,     0,     0,    42,
      43,    44,    45,    46,    47,     0,    48,     0,     0,    55,
      37,    38,    39,    40,    41,     0,     0,     0,     0,    42,
      43,    44,    45,    46,    47,     0,    48,     0,     0,    59,
      37,    38,    39,    40,    41,     0,     0,     0,     0,    42,
      43,    44,    45,    46,    47,     0,    48,     0,    60,    37,
      38,    39,    40,    41,     0,     0,     0,     0,    42,    43,
      44,    45,    46,    47,     0,    48,    37,    38,    39,     0,
       0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
      47,     0,    48,    37,   -61,    39,     0,     0,     0,     0,
       0,     0,   -61,    43,    44,    45,    46,    47,   -61,    48,
      39,     0,     0,     0,     0,     0,     0,     0,   -61,    44,
      45,    46,    47,     0,    48,    13,    14,    15,    16,     0,
       0,     0,    17,     0,     0,     0,     0,    18
  };

  const short
  parser::yycheck_[] =
  {
       4,    28,    55,     5,     4,     6,     4,    33,    18,    35,
      25,    26,     6,    28,     0,     9,    10,    11,    31,     3,
      33,    25,    32,    17,    18,    19,    20,     7,     8,    31,
      24,    35,    32,    18,    32,    29,    29,    29,    32,    29,
      93,    28,    18,    34,    48,    33,    35,    30,    29,    31,
      12,    13,    14,    15,    16,    30,    34,    84,   111,    21,
      22,    23,    24,    25,    26,    33,    28,    30,    29,   115,
      97,    31,    30,   123,    36,    80,    80,    81,   107,    -1,
      89,    82,    86,    17,    18,    19,    20,   114,    92,    -1,
      24,    23,    24,    25,    26,    29,    28,    -1,   125,    -1,
      -1,   128,    36,    -1,   108,   106,    -1,     9,    10,    11,
      12,    13,   116,    -1,   115,    17,    18,    -1,    -1,   123,
      -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    50,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    28,    12,    13,    14,    15,
      16,    -1,    -1,    36,    -1,    21,    22,    23,    24,    25,
      26,    83,    28,    -1,    -1,    87,    -1,    89,    -1,    91,
      36,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,     6,    28,    -1,     9,
      10,    11,    -1,    -1,    -1,    36,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    -1,    31,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    -1,    31,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    30,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    28,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    -1,    28,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    12,    28,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    -1,    28,    17,    18,    19,    20,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    38,    39,     0,     3,    40,    46,    18,    58,     6,
       9,    10,    11,    17,    18,    19,    20,    24,    29,    48,
      50,    51,    54,    55,    58,    29,    50,    51,    51,    36,
      51,    51,    51,    51,    51,    33,    35,    12,    13,    14,
      15,    16,    21,    22,    23,    24,    25,    26,    28,    36,
      29,    43,    44,    45,    58,    31,    47,    47,    36,    31,
      30,    58,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    18,    58,    51,    52,    53,    30,
      34,    33,    46,     7,     8,    49,    56,    35,    36,    29,
      30,    34,     5,    31,    45,    58,    32,    51,    47,    32,
      57,    58,    51,    52,    51,    58,    46,    47,    33,    36,
      30,    31,    41,    49,    58,    46,     4,    32,    42,    47,
      41,    58,    32,    29,    43,    30,    33,    47,    58,    47
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    46,    46,    47,    48,
      49,    49,    49,    48,    48,    48,    48,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    48,    54,    54,    48,    55,    56,    56,    57,    51,
      58
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     9,    11,     2,     0,     8,
       6,     1,     0,     3,     1,     3,     2,     0,     3,     4,
       4,     2,     0,     3,     4,     6,     2,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     2,     6,     0,     1,     3,
       1,     1,     3,     2,     1,     5,     2,     0,     4,     4,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "CLASS", "DEF", "EXTENDS", "IF", "ELIF",
  "ELSE", "WHILE", "RETURN", "TYPECASE", "ATLEAST", "ATMOST", "EQUALS",
  "AND", "OR", "NOT", "IDENT", "INT_LIT", "STRING_LIT", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "NEG", "'.'", "'('", "')'", "'{'", "'}'",
  "':'", "','", "'='", "';'", "$accept", "pgm", "classes", "clazz",
  "methods", "method", "formal_args", "formal_args_delim", "formal_arg",
  "statements", "statement_block", "statement", "opt_elif_parts", "l_expr",
  "expr", "actual_args", "actual_args_nonempty", "return_expr", "typecase",
  "type_alternatives", "type_alternative", "ident", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   144,   144,   151,   152,   158,   162,   168,   169,   172,
     174,   179,   180,   182,   184,   186,   195,   196,   199,   210,
     213,   216,   217,   221,   230,   232,   234,   246,   247,   262,
     265,   266,   270,   279,   280,   281,   282,   283,   287,   288,
     289,   290,   291,   294,   295,   296,   314,   317,   318,   321,
     322,   327,   329,   331,   336,   338,   341,   343,   345,   351,
     354
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,    25,    23,    34,    24,    28,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    36,
      22,    35,    21,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    27
    };
    const unsigned user_token_number_max_ = 276;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

} // yy
#line 1423 "quack.tab.cxx"

#line 356 "quack.yxx"


void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}
