#ifndef LEXER_H
#define LEXER_H
#include "Converter.h"
using namespace std;

class Lexer
{
public:
  explicit Lexer(std::istream& is);
  explicit Lexer(std::istream* ps);

  // A Lexer belongs to a parser and shouldn't be copied or moved.

  Lexer(const Lexer&) = delete;
  Lexer& operator=(const Lexer&) = delete;

  Lexer(Lexer&&) = delete;
  Lexer& operator=(Lexer&&) = delete;

  ~Lexer() { if (owns_input) delete p_input; }

  Token get_current_token() const { return current_token; }
  std::string get_token_text() const { return current_token_text; }

  void advance();		// Read the next token in the stream.

private:
  std::istream* p_input;		// The source stream (a stream of characters).
  bool owns_input;			// True if we can delete p_input, false if we can't.

  Token current_token;
  std::string current_token_text;

  void init();				// Code common to each constructor.

  Token get_token();			// The workhorse. Assembles characters from p_input into tokens.
  std::string token_buffer;		// The text of the token that get_token() just found.

  void exponent_part(char& c);		// A helper function for get_token() when it is looking for a number.
};

#endif // LEXER_H
