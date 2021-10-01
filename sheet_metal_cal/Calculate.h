#ifndef CALCULATE_H
#define CALCULATE_H
#include <iostream>
#include <sstream>
#include <string.h>
#include "Lexer.h"
#include <FL/fl_ask.H>
class Calculate
{
    public:
        Calculate();
        virtual ~Calculate();
char * expressionToParse = "3+2*6";
//int res;
//char* char_type;
//std::string s;
bool isError=false;
//std::string text;
Lexer *p_lexer;
string resstr;
char*result;
//
  double assign_expr();
  double add_expr();
  double mul_expr();
  double pow_expr();
  double unary_expr();
  double primary();

  double BA();
  double L();
  void assinval(double &l,double &r,double &a);
    void assinval(double &r,double &a);
  void setK();
  double get_argument();
  // Check for root of a negative number.
  static void check_domain(double x, double y);
  void solve()
  {
     //expressionToParse = "3*(2.3+4)";
     std::istringstream ist{expressionToParse};
     p_lexer = new Lexer{ist};

         double res=assign_expr();
          Converter cv;
          resstr=cv.to_string(res);
          result=const_cast<char*>(resstr.c_str());



  }
  int radiusv,materialv;
  double K=0.4;
};

#endif // CALCULATE_H
