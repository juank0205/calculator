#include "input.h"
#include <cctype>
#include <cstdlib>
#include <iostream>

InputElement::InputElement() : valueType(-1), valueI(0), valueS("") {}

InputElement::InputElement(const std::string &valueS)
    : valueI(0), valueS(valueS) {
  if (valueS.length() == 1) {
    if (valueS[0] == '+' || valueS[0] == '-' || valueS[0] == '/' ||
        valueS[0] == '*' || valueS[0] == '=') {
      valueType = TYPE_OPERATOR;
      return;
    }
  }

  if (valueS[0] == '-') {
    if (isdigit(valueS[1])) {
      valueType = TYPE_NUMBER;
      valueI = atoi(valueS.c_str());
    } else {
      valueType = TYPE_OPERATOR;
    }
    return;
  }

  if (isdigit(valueS[0])) {
    valueType = TYPE_NUMBER;
    valueI = atoi(valueS.c_str());
  } else {
    valueType = TYPE_SYMBOL;
  }
}

Input::Input() {}
Input::~Input() {}

InputElement Input::readInput() {
  std::cout << "> ";
  std::cin >> m_userInput;

  InputElement input = InputElement(m_userInput);
  return input;
}
