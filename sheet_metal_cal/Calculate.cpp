#include "Calculate.h"
Calculate::Calculate()
{



};
Calculate::~Calculate()
{
    //dtor
 delete p_lexer;
}
//----------------------------------------------------------------------
double Calculate::assign_expr()
{
  //Token t = p_lexer->get_current_token();
 // std::string text = p_lexer->get_token_text();

  double result = add_expr();



  return result;
}
//----------------------------------------------------------------------
double Calculate::add_expr()
{
  double result = mul_expr();

  for (;;) {
    switch (p_lexer->get_current_token()) {
    case Token::Plus:
      p_lexer->advance();
      result += mul_expr();
      break;
    case Token::Minus:
      p_lexer->advance();
      result -= mul_expr();
    default:
      return result;
    }
  }
}
//----------------------------------------------------------------------
double Calculate::mul_expr()
{
  double result = pow_expr();
  double x;

  for (;;) {
    switch (p_lexer->get_current_token()) {
    case Token::Mul:
      p_lexer->advance();
      result *= pow_expr();
      break;
    case Token::Div:
      p_lexer->advance();
      x = pow_expr();
      if (x == 0)
        throw Converter::Runtime_error{"attempt to divide by zero"};
      result /= x;
      break;
    case Token::Mod:
      p_lexer->advance();
      x = pow_expr();
      if (x == 0)
        throw Converter::Runtime_error{"attempt to divide by zero"};
      result = fmod(result, x);
      break;
    default:
      return result;
    }
  }
}
//----------------------------------------------------------------------
double Calculate::pow_expr()
{
  double result = unary_expr();

  if (p_lexer->get_current_token() == Token::Pow) {
    p_lexer->advance();
    double x = unary_expr();
    check_domain(result, x);
    return pow(result, x);
  }

  return result;
}
//----------------------------------------------------------------------
double Calculate::unary_expr()
{
  switch (p_lexer->get_current_token()) {
  case Token::Plus:
    p_lexer->advance();
    return +primary();
  case Token::Minus:
    p_lexer->advance();
    return -primary();
  default:
    return primary();
  }
}
//----------------------------------------------------------------------
double Calculate::primary()
{
  std::string text = p_lexer->get_token_text();
  double arg;
Converter cv;
cout<<static_cast<int>(p_lexer->get_current_token() )<<endl;
if (p_lexer->get_current_token() == Token::L)cout<<"trueval"<<endl;
  switch (p_lexer->get_current_token()) {
   /*
  case Token::Id:
    p_lexer->advance();
    return symbol_table[text];
    */
  case Token::Number:
    p_lexer->advance();
    return cv.to_number(text);
  case Token::Lp:
    p_lexer->advance();
    arg = add_expr();
    if (p_lexer->get_current_token() != Token::Rp)
      throw Converter::Syntax_error{"missing ) after subexpression"};
    p_lexer->advance();
    return arg;

  case Token::Sin:
    return sin(get_argument());
/*
  case Token::Cos:
    return cos(get_argument());

  case Token::Tan:
    arg = get_argument();
    if (cos(arg) == 0)
      throw Converter::Runtime_error{"invalid argument to tan: " + to_string(arg)};
    return tan(arg);

  case Token::Asin:
    return asin(get_argument());

  case Token::Acos:
    return acos(get_argument());
  case Token::Atan:
    return atan(get_argument());
  case Token::Log:
    arg = get_argument();
    if (arg < 1)
      throw Converter::Runtime_error{"invalid argument to log: " + to_string(arg)};
    return log(arg);
  case Token::Exp:
    return exp(get_argument());
  case Token::Log10:
    arg = get_argument();
    if (arg < 1)
      throw Converter::Runtime_error{"invalid argument to log10: " + to_string(arg)};
    return log10(arg);

  case Token::Sqrt:
    arg = get_argument();
    if (arg < 0)
      throw Converter::Runtime_error{"attempt to take square root of negative number"};
    return sqrt(arg);

  case Token::Int:
    arg = get_argument();
    if (arg < 0)
      return ceil(arg);
    else
      return floor(arg);
*/
  case Token::L:
  //cout<<"L funct"<<endl;
      return L();

  case Token::BA:
  //cout<<"BA funct"<<endl;
      return BA();
  default:
    throw Converter::Syntax_error{"invalid primary expression"};
  }
}
//----------------------------------------------------------------------
void Calculate::check_domain(double x, double y)
{
  // There is no error if x is nonnegative.
  if (x >= 0) return;

  // There is no error unless 0 < abs(y) < 1.
  double e = std::abs(y);
  if (e <= 0 || e >= 1) return;

  // We have an error.
  throw Converter::Runtime_error{"attempt to take root of a negative number"};
}
double Calculate::get_argument()
{
  p_lexer->advance();
  if (p_lexer->get_current_token() != Token::Lp)
    throw Converter::Syntax_error{"missing ( after function name"};
  p_lexer->advance();
  double arg = add_expr();
  if (p_lexer->get_current_token() != Token::Rp)
    throw Converter::Syntax_error{"missing ) after function argument"};
  p_lexer->advance();
  return arg;
}

double Calculate::BA()
{
  p_lexer->advance();
 if (p_lexer->get_current_token() != Token::Lp)
    throw Converter::Syntax_error{"missing ( after function name"};
  p_lexer->advance();
 std::string Rstr = p_lexer->get_token_text();
  p_lexer->advance();//,
 if (p_lexer->get_current_token() != Token::comma)
    throw Converter::Syntax_error{"missing , after first argument"};
  p_lexer->advance();
 if(p_lexer->get_current_token()!=Token::Number)
    throw Converter::Syntax_error{"second argument non numeric value"};
 std::string Anglestr = p_lexer->get_token_text();
 p_lexer->advance();
 if (p_lexer->get_current_token() != Token::Rp)
    throw Converter::Syntax_error{"missing ) after function argument"};

 double pi=3.1415926535897932384626433832795;
 double Angle=Converter::static_to_number(Anglestr),T=2,R=Converter::static_to_number(Rstr);
 double BA=Angle*(pi/180)*(R+(K*T));
 p_lexer->advance();
 return BA;
}//End BA
double Calculate::L()
{
    p_lexer->advance();
  if (p_lexer->get_current_token() != Token::Lp)
    throw Converter::Syntax_error{"missing ( after function name"};
  double A,R,L;
  assinval(L,R,A);
  double T=2;
  double tandeg=tan ( A/2 * 3.14 / 180.0 );
  double LL=L-(tandeg)*(R+T);
  p_lexer->advance();

  if (p_lexer->get_current_token() == Token::comma)
  {
  double R2=0,A2=0;
  assinval(R2,A2);
  tandeg=tan ( A2/2 * 3.14 / 180.0 );
  double LL2=(tandeg)*(R2+T);
  LL-=LL2;
  p_lexer->advance();
  };
  if (p_lexer->get_current_token() != Token::Rp)
    throw Converter::Syntax_error{"missing ) after function argument"};
  p_lexer->advance();
  return LL;
  //return  tan ( 45 * 3.14 / 180.0 );
  //return (tan(A/2.))*(R+T);
}
void Calculate:: assinval(double &L,double &R,double &A)
{

  p_lexer->advance();
  if(p_lexer->get_current_token()!=Token::Number)
    throw Converter::Syntax_error{"Lenth argument non numeric value"};
  std::string Lstr = p_lexer->get_token_text();

   L=Converter::static_to_number(Lstr);
  p_lexer->advance();
  if (p_lexer->get_current_token() == Token::comma)p_lexer->advance();
  if(p_lexer->get_current_token()!=Token::Number)
    throw Converter::Syntax_error{"Radius argument non numeric value"};
  std::string Rstr = p_lexer->get_token_text();
   R=Converter::static_to_number(Rstr);

  p_lexer->advance();
  if (p_lexer->get_current_token() == Token::comma)p_lexer->advance();
  if(p_lexer->get_current_token()!=Token::Number)
    throw Converter::Syntax_error{"Angle argument non numeric value"};
  std::string Astr = p_lexer->get_token_text();
   A=Converter::static_to_number(Astr);
}
void Calculate:: assinval(double &R,double &A)
{

  p_lexer->advance();
  if(p_lexer->get_current_token()!=Token::Number)
    throw Converter::Syntax_error{"Radius argument non numeric value"};
  std::string Rstr = p_lexer->get_token_text();
   R=Converter::static_to_number(Rstr);

  p_lexer->advance();
  if (p_lexer->get_current_token() == Token::comma)p_lexer->advance();
  if(p_lexer->get_current_token()!=Token::Number)
    throw Converter::Syntax_error{"Angle argument non numeric value"};
  std::string Astr = p_lexer->get_token_text();
   A=Converter::static_to_number(Astr);
}
void Calculate::setK()
{
  if(radiusv==0)
  {
       if(materialv==0)
       {
         K=0.33;

       }
       else if(materialv==1)
       {
        K=0.38;
       }
       else if(materialv==2)
       {
        K=0.4;

       }

  }
  else if(radiusv==1)
  {
       if(materialv==0)
       {
         K=0.4;

       }
       else if(materialv==1)
       {
        K=0.43;
       }
       else if(materialv==2)
       {
        K=0.45;
        cout<<K<<endl;
       }
  }
    else if(radiusv==2)
  {
       if(materialv==0)
       {
         K=0.5;

       }
       else if(materialv==1)
       {
        K=0.5;
       }
       else if(materialv==2)
       {
        K=0.5;
        cout<<K<<endl;
       }
  }
    else if(radiusv==3)
  {
       if(materialv==0)
       {
         K=0.42;

       }
       else if(materialv==1)
       {
        K=0.44;
       }
       else if(materialv==2)
       {
        K=0.46;
        cout<<K<<endl;
       }
  }
    else if(radiusv==4)
  {
       if(materialv==0)
       {
         K=0.46;

       }
       else if(materialv==1)
       {
        K=0.47;
       }
       else if(materialv==2)
       {
        K=0.48;
        cout<<K<<endl;
       }
  }
    else if(radiusv==5)
  {
       if(materialv==0)
       {
         K=0.5;

       }
       else if(materialv==1)
       {
        K=0.5;
       }
       else if(materialv==2)
       {
        K=0.5;
        cout<<K<<endl;
       }
  }
    else if(radiusv==6)
  {
       if(materialv==0)
       {
         K=0.38;

       }
       else if(materialv==1)
       {
        K=0.41;
       }
       else if(materialv==2)
       {
        K=0.44;
        cout<<K<<endl;
       }
  }
    else if(radiusv==7)
  {
       if(materialv==0)
       {
         K=0.44;

       }
       else if(materialv==1)
       {
        K=0.46;
       }
       else if(materialv==2)
       {
        K=0.47;
        cout<<K<<endl;
       }
  }
    else if(radiusv==8)
  {
       if(materialv==0)
       {
         K=0.5;

       }
       else if(materialv==1)
       {
        K=0.5;
       }
       else if(materialv==2)
       {
        K=0.5;
        cout<<K<<endl;
       }
  }
}
