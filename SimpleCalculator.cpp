#include<iostream>
using namespace std;

double addition(double num1, double num2) {
    return num1 + num2;
}

double subtraction(double num1, double num2) {
    return num1 - num2;
}

double multiplication(double num1, double num2) {
    return num1 * num2;
}

double division(double num1, double num2) {
    if (num2 == 0.0) return (double)-1;
    else {
        return num1/num2;
    }
}

int main() {

    while (true) {
        double num1, num2, result;
        char operation;
        cout<<"Enter first number: ";
        cin>>num1;
        cout<<"Enter second number: ";
        cin>>num2;
        cout<<"Enter operation (+, -, *, /, E->Exit): ";
        cin>>operation;
        switch(operation) {
            case '+':
                cout<<"Addition: "<<addition(num1, num2)<<endl;
                break;
            case '-':
                cout<<"Subtractiion: "<<subtraction(num1, num2)<<endl;
                break;
            case '*':
                cout<<"Multiplication: "<<multiplication(num1, num2)<<endl;
                break;
            case '/':
                result = division(num1, num2);
                if (result == -1) {
                    cout<<"Cannot divide by zero"<<endl;
                } else {
                    cout<<"Division: "<<result<<endl;
                }
                break;
            case 'E':
                return 0;
        }
    }

    return 0;
}
