#pragma once
#include <string>

#define TYPE_OPERATOR 1
#define TYPE_NUMBER 2
#define TYPE_SYMBOL 3

struct InputElement {
  int valueI;
  std::string valueS;
  int valueType;

  InputElement();
  InputElement(const std::string &valueS);
};

class Input {
public:
  Input();
  ~Input();

  InputElement readInput();
private:
  std::string m_userInput;
};
