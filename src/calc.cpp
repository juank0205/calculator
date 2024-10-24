#include "calc.h"
#include "input.h"

#include <iostream>
#include <string>

Calculator::Calculator() : m_index(0) {}
Calculator::~Calculator() {}

void Calculator::start() {
  do {
    InputElement input = m_input.readInput();
    if (input.valueS != "exit")
      checkInput(input);
    else
      m_isExit = true;
  } while (!m_isExit);
}

void Calculator::saveNumber(const InputElement &input) {
  if (m_index == 2) {
    m_index = 0;
    std::cout << "Expected operator..." << std::endl;
    return;
  }

  m_data[m_index] = input;
  m_index++;
}

void Calculator::saveSymbol(InputElement &input) {
  if (m_index == 2) {
    m_index = 0;
    std::cout << "Expected operator..." << std::endl;
    return;
  }

  if (m_variables.find(input.valueS) != m_variables.end())
    input.valueI = m_variables[input.valueS];

  m_data[m_index] = input;
  m_index++;
}

void Calculator::operate(const InputElement &input) {
  if (m_index != 2) {
    std::cout << "Expected 2 values, got " << m_index << std::endl;
    m_index = 0;
    return;
  }

  switch (input.valueS[0]) {
  case '+':
    std::cout << m_data[0].valueI + m_data[1].valueI << std::endl;
    break;
  case '-':
    std::cout << m_data[0].valueI - m_data[1].valueI << std::endl;
    break;
  case '*':
    std::cout << m_data[0].valueI * m_data[1].valueI << std::endl;
    break;
  case '/':
    std::cout << (float)m_data[0].valueI / (float)m_data[1].valueI << std::endl;
    break;
  case '=':
    saveVariable();
    break;
  default:
    std::cout << "What in the actual fuck" << std::endl;
  }

  m_index = 0;
}

void Calculator::checkInput(InputElement &input) {
  if (input.valueType == TYPE_SYMBOL) {
    saveSymbol(input);
  }

  if (input.valueType == TYPE_NUMBER) {
    saveNumber(input);
  }

  if (input.valueType == TYPE_OPERATOR) {
    operate(input);
  }
}

void Calculator::saveVariable() {
  if (m_data[0].valueType == TYPE_SYMBOL &&
      m_data[1].valueType == TYPE_SYMBOL) {

    if (m_variables.find(m_data[1].valueS) != m_variables.end()) {
      m_variables[m_data[0].valueS] = m_variables[m_data[1].valueS];
      std::cout << m_data[0].valueS << " = " << m_data[1].valueI << std::endl;
    }
    else {
      std::cout << "The symbol {" << m_data[1].valueS << "} does not exist" << std::endl;
    }

    return;
  }

  if (m_data[0].valueType == TYPE_SYMBOL &&
      m_data[1].valueType == TYPE_NUMBER) {
    m_variables[m_data[0].valueS] = m_data[1].valueI;
    std::cout << m_data[0].valueS << " = " << m_data[1].valueI << std::endl;
    return;
  }

  std::cout << "Invalid operation" << std::endl;
}
