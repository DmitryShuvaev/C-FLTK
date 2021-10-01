#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
// The basic elements of our expressions.
enum class Token {
  Id, Number, Sin, Cos, Sqrt, Int, Assign='=', Plus='+', Minus='-',
  Mul='*', Div='/', Mod='%', Pow='^', Lp='(', Rp=')', BA=16,
  comma=',', L=20, Eofsym=-1
};//end of Token class

class Converter
{
    public:
        Converter();
        virtual ~Converter();

double to_number(const std::string& s)
{
  std::istringstream ist{s};
  ist.exceptions(std::ios_base::failbit);
  double x;
  ist >> x;
  return x;
}
static double static_to_number(const std::string& s)
{
  std::istringstream ist{s};
  ist.exceptions(std::ios_base::failbit);
  double x;
  ist >> x;
  return x;
}
std::string to_string(double x)
{
  std::ostringstream ost;
  ost << x;
  return ost.str();
}
//----------------------------------------------------------------------
template<int N>
  class Error {
  public:
    explicit Error(const std::string s) : message{s} { }

    std::string get_message() const { return message; }
    void put(std::ostream& os) const { os << message; }

  private:
    std::string message;
  };//end of Error class
//----------------------------------------------------------------------
  using Lexical_error = Error<1>;
  using Syntax_error = Error<2>;
  using Runtime_error = Error<3>;
//----------------------------------------------------------------------
template<int N>
  friend std::ostream& operator<<(std::ostream& os, const Error<N>& e)
  {
    e.put(os);
    return os;
  }
//----------------------------------------------------------------------


//----------------------------------------------------------------------

};//end of parser class
//----------------------------------------------------------------------

#endif // PARSER_H
