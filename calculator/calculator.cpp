#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"

bool ReadNumber(Number& result){
    std::cin>>result;
    if(std::cin.fail()){
        std::cerr<<"Error: Numeric operand expected"<<std::endl;
        return false;    
    }
    else{
        return true;     
    }
}

bool RunCalculatorCycle() {
    Number savevar; // сохраненное значение, значение над которым производят операции
    Number var;  // значение после оператора
    std::string op; // оператор
    Number memory; // ячейка памяти для сохранения 
    bool open=true; // true в случае если ячейка паняти свободна
    bool last = false;  // для возврата всей функции, только в случае ввода q возвращает true
    
    if (ReadNumber(savevar)){
        while(std::cin>>op){ 
            if (op=="q"){
                last=true; break;
            }
            else if (op=="=") {
                std::cout<<savevar<<std::endl;
            }
            else if (op=="+") {
                if(ReadNumber(var)) {
                    savevar += var;
                } 
                else break;
            }
            else if (op=="-") {
                if(ReadNumber(var)) {
                    savevar -= var;
                } 
                else break;    
            } 
            else if (op=="*") {
                if(ReadNumber(var)) {
                    savevar *= var;} 
                else break;
            } 
            else if (op=="/") {
                if(ReadNumber(var)) {
                    savevar /= var;
                } 
                else break;    
            } 
            else if (op=="**"){
                if(ReadNumber(var)) {
                    savevar= std::pow(savevar, var);
                } 
                else break;    
            } 
            else if (op ==":") {
                ReadNumber(savevar); 
            }
            else if (op =="c") {
                savevar=0; 
            }
            else if (op=="s") {
                memory=savevar;
                open=false;
            }
            else if (op=="l") {
                if(open){
                    std::cerr<<"Error: Memory is empty"<<std::endl; 
                    break;
                } 
                else if (!open){
                    savevar=memory;
                } 
            }
            else {
                std::cerr<<"Error: Unknown token "<<op<<std::endl; 
                break;
            }
        }
    }
    return last; 
}