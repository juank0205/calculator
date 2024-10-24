#pragma once
#include "input.h"
#include <string>
#include <unordered_map>

class Calculator {
public:
  Calculator();
  ~Calculator();

  void start();
private:
  Input m_input;
  InputElement m_data[2];
  std::unordered_map<std::string, int> m_variables; 
  int m_index;
  bool m_isExit = false;

  void operate(const InputElement &input);
  void saveNumber(const InputElement &input);
  void saveSymbol(InputElement &input);
  void checkInput(InputElement &input);
  void saveVariable();
};
