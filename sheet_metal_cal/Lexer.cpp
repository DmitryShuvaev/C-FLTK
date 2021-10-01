#include "Lexer.h"

Lexer::Lexer(std::istream& is)
  : p_input{&is}, owns_input{false}
{
  init();
}

Lexer::Lexer(std::istream* ps)
  : p_input{ps}, owns_input{false}
{
  init();
}

void Lexer::init()
{
  current_token = get_token();
  current_token_text = token_buffer;
}

void Lexer::advance()
{
  if (current_token != Token::Eofsym) {
    current_token = get_token();
    current_token_text = token_buffer;
  }
}

Token Lexer::get_token()
{
  std::istream& input = *p_input;		// Shorthand to make the notation convenient.

  token_buffer.clear();				// Clear the buffer for the new token.

  char c = input.get();				// A priming read on the stream.

  // Skip whitespace.
  while (isspace(c)) c = input.get();

  // If there are no characters, we're at the end of the stream.
  if (!input) return Token::Eofsym;

  // Look for an identifier or function name.
  if (isalpha(c)) {
    token_buffer = c;
    c = input.get();

    // Look for zero or more letters or digits. isalnum
    while (isalpha(c)) {
      token_buffer += c;
      c = input.get();
    }

    // The current character doesn' belong to our identifier.
    input.putback(c);

    // Check for a function name.
    if (token_buffer == "sin") return Token::Sin;
    if (token_buffer == "cos") return Token::Cos;


    if (token_buffer == "sqrt") return Token::Sqrt;
    if (token_buffer == "int") return Token::Int;
    if (token_buffer == "L")
    {
        //cout<<"val"<<endl;
        return Token::L;
    }
    if (token_buffer == "BA")
    {
        //cout<<"val"<<endl;
        return Token::BA;
    }
    // Whatever is not a function name must be an identifier.
    return Token::Id;
  }

  // Look for a number beginning with a digit.
  if (isdigit(c)) {
    token_buffer = c;
    c = input.get();

    // Look for other digits.
    while (isdigit(c)) {
      token_buffer += c;
      c = input.get();
    }

    // Look for an optional decimal point.
    // If there is one, it can be followed by zero or more digits.
    if (c == '.') {
      token_buffer += c;
      c = input.get();

      while (isdigit(c)) {
        token_buffer += c;
        c = input.get();
      }
    }

    // Look for an optional exponent part.
    exponent_part(c);

    input.putback(c);
    return Token::Number;
  }

  // Look for a number beginning with a decimal point.
  if (c == '.') {
    token_buffer = c;
    c = input.get();

    // A decimal point must be followed by a digit. Otherwise we have an error.
    if (!isdigit(c)) {
      throw Converter::Lexical_error{token_buffer += c};
    }
    while (isdigit(c)) {
      token_buffer += c;
      c = input.get();
    }

    // Check for the optional exponent part.
    exponent_part(c);

    input.putback(c);
    return Token::Number;
  }

  // Check for a single character token.
  token_buffer = c;
  switch (c) {
  // Note: fallthrough intentional.
  case '=':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case '^':
  case '(':
  case ')':
  case ',':
    return Token(c);
  }

  // Anything else is an error.
  throw Converter::Lexical_error{token_buffer};
}

void Lexer::exponent_part(char& c)
{
  std::istream& input = *p_input;

  if (c != 'e' || c != 'E')
    return;

  token_buffer += c;
  c = input.get();

  // Check for an optional sign.
  if (c == '+' || c == '-') {
    token_buffer += c;
    c = input.get();
  }

  // We must have a digit. Otherwise, we have an error.
  if (!isdigit(c))
    throw Converter::Lexical_error{token_buffer += c};
  while (isdigit(c)) {
    token_buffer += c;
    c = input.get();
  }
}

