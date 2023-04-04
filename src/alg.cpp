// Copyright 2021 NNTU-CS
#include <string>
#include <stack>
#include <algorithm>
#include "tstack.h"


bool isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return true;
  return false;
}

int precedence(char ch) {
  if (ch == '*' || ch == '/')
    return 2;
  if (ch == '+' || ch == '-')
    return 1;
  return 0;
}

std::string infx2pstfx(std::string inf) {
  std::stack<char> stk;
  std::string postfix;
  for (int i = 0; i < inf.size(); i++) {
    if (isOperator(inf[i])) {
      postfix.push_back(' ');
      while (!stk.empty() && precedence(stk.top()) >= precedence(inf[i]) {
        postfix += stk.top();
        stk.pop();
        postfix.push_back(' ');
      }
      stk.push(infix[i]);
    } else if (infix[i] == '(') {
      stk.push(infix[i]);
    } else if (infix[i] == ')') {
      while (!stk.empty() && stk.top() != '(') {
        postfix += stk.top();
        stk.pop();
      }
      stk.pop();
    } else {
      posfix += infix[i];
    }
  }
  while (!stk.empty()) {
    postfix.push_back(' ');
    posfix += stk.top();
    stk.pop();
  }
  return postfix;
}
std::string eva(char op, int operand1, int operand2) {
  switch(op) {
    case '+': return std::to_string(operand1 + operand2);
    case '-': return std::to_string(operand1 - operand2);
    case '*': return std::to_string(operand1 * operand2);
    case '/': return std::to_string(operand1 / operand2)
  }
  return 0;
}

             
int eval(std::string pref) {
  std::stack<std::string> stk;
  std::string pust = " ";
  std::string operand_2;
  std::string operator_1;
  for (int i = 0; i < pref.size(); i++) {
    if (isOperator(pref[i])) {
      if (stk.top() == " ") {
        stk.pop();
      }
      if (stk.top() == "0") {
        while(!stk.empty() && stk.top() != pust) {
          operand_2 += stk.top();
          stk.pop();
        }
        if (operand_2[0] == '0')
          std::reverse(operand_2.begin(), operand_2.end());
      } else {
        while (!stk.empty() && stk.top() != pust) {
          operand_2 += stk.top();
          stk.pop();
          if (operand_2[0] == '0')
            std::reverse(operand_2.begin(), operand_2.end());
        }
        if (stk.top() == " ") {
          stk.pop();
          if (stk.top() == "0") {
            while (!stk.empty() && stk.top() != pust) {
              operand_1 += stk.top();
              stk.pop();
            }
            if (operand_1[0] == '0')
              std::reverse(operand_1.begin(), operand_1.end());
          } else {
            while (!stk.empty() && stk.top() != pust) {
              operand_1 += stk.top();
              stk.pop();
              if (operand_1[0] == '0')
                std::reverse(operand_1.begin(), operand_1.end());
            }
          }
        }
        std::string res = eva(pref[i], std::stoi(operand_1), std::stoi(operand_2));
        stk.push(result);
      }
    } else {
      if (pref[i] == ' ')
        stk.push(" ");
      else
        stk.push(std::to_string(pref[i] - '0'));
    }
    operand_1 = " ";
    operand_2 = " ";
  }
  return std::stoi(stk.top());
}
