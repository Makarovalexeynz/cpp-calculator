#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"

bool ReadNumber(Number& result) {
    std::cin >> result;
    if (std::cin.fail()) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;    
    }
    else {
        return true;     
    }
}

bool RunCalculatorCycle() {
    Number save_var = 0; // сохраненное значение, значение над которым производят операции
    Number var = 0;  // значение после оператора
    Number memory = 0; // ячейка памяти для сохранения 
    bool open = true; // true в случае если ячейка памяти свободна
    bool last = false;  // для возврата всей функции, только в случае ввода q возвращает true
    
    if (ReadNumber(save_var)) {
        std::string op; // оператор
        while (std::cin >> op) { 
            if (op == "q") {
                return true;
            }
            else if (op == "=") {
                std::cout << save_var << std::endl;
            }
            else if (op == "+") {
                if (ReadNumber(var)) {
                    save_var += var;
                } 
                else break;
            }
            else if (op == "-") {
                if (ReadNumber(var)) {
                    save_var -= var;
                } 
                else break;    
            } 
            else if (op == "*") {
                if (ReadNumber(var)) {
                    save_var *= var;
                } 
                else break;
            } 
            else if (op == "/") {
                if (ReadNumber(var)) {
                    save_var /= var;
                } 
                else break;    
            } 
            else if (op == "**") {
                if (ReadNumber(var)) {
                    save_var = std::pow(save_var, var);
                } 
                else break;    
            } 
            else if (op == ":") {
                ReadNumber(save_var); 
            }
            else if (op =="c") {
                save_var=0; 
            }
            else if (op=="s") {
                memory=save_var;
                open=false;
            }
            else if (op=="l") {
                if (open) {
                    std::cerr << "Error: Memory is empty" << std::endl; 
                    break;
                } 
                else if (!open) {
                    save_var = memory;
                } 
            }
            else {
                std::cerr << "Error: Unknown token " << op <<std::endl; 
                break;
            }
        }
    }
    return last; 
}