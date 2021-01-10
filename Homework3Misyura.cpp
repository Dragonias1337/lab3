#include <regex>
#include <conio.h>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

queue<string> inputs;
stack<string> operators;
queue<string> result;

void ShowPolishQueue()
{
    queue<string> buf = result;
    int size = buf.size();
    for (int i = 0; i < size; i++)
    {
        cout << buf.front() << " ";
        buf.pop();
    }
    cout << endl;
}

queue<string> ParseInputs(string _input)
{
    queue<string> result;
    result.push("a");
    int numberStart = -1;
    for (int i = 0; i < _input.length(); i++)
    {
        if (_input[i] == '(' ||
            _input[i] == ')' ||
            _input[i] == '+' ||
            _input[i] == '-' ||
            _input[i] == '/' ||
            _input[i] == '*')
        {
            if (numberStart >= 0)
            {
                result.push(_input.substr(numberStart, i - numberStart));
                numberStart = -1;
            }
            result.push(_input.substr(i, 1));
        }
        else
        {
            if (numberStart >= 0)
            {

            }
            else
            {
                numberStart = i;
            }

            if (i >= _input.length() - 1)
            {
                result.push(_input.substr(numberStart, i - numberStart + 1));
            }
        }
    }
    result.push("a");
    return result;
}

void f1()
{
    operators.push(inputs.front());
    inputs.pop();
}

void f2()
{
    result.push(operators.top());
    operators.pop();
}

void f3()
{
    operators.pop();
    inputs.pop();
}

void fnumber()
{
    result.push(inputs.front());
    inputs.pop();
}

queue<string> MakePolish(string _input)
{

    f1();

    while (!inputs.empty())
    {
        string s = inputs.front();
        switch (s[0])
        {
            case '(':
            {
                f1();
                break;
            }
            case ')':
            {
                switch (operators.top()[0])
                {
                    case 'a':
                    {
                        cout << "Error 5" << endl;
                        break;
                    }
                    case '(':
                    {
                        f3();
                        break;
                    }
                    default:
                    {
                        f2();
                        break;
                    }
                }
                break;
            }
            case '+':
            {
                if (operators.top()[0] == 'a' || operators.top()[0] == '(')
                {
                    f1();
                }
                else
                {
                    f2();
                }
                break;
            }
            case '-':
            {
                if (operators.top()[0] == 'a' || operators.top()[0] == '(')
                {
                    f1();
                }
                else
                {
                    f2();
                }
                break;
            }
            case '/':
            {
                if (operators.top()[0] == '*' || operators.top()[0] == '/')
                {
                    f2();
                }
                else
                {
                    f1();
                }
                break;
            }
            case '*':
            {
                if (operators.top()[0] == '*' || operators.top()[0] == '/')
                {
                    f2();
                }
                else
                {
                    f1();
                }
                break;
            }
            case 'a':
            {
                switch (operators.top()[0])
                {
                    case 'a':
                    {
                        return result;
                        break;
                    }
                    case '(':
                    {
                        cout << "Error 5" << endl;
                        break;
                    }
                    default:
                    {
                        f2();
                        break;
                    }
                }
                break;
            }
            default:
            {
                fnumber();
                break;
            }
        }

    }

    return result;
}

double CalcPolish()
{
    double output = 0;
    stack<double> args;

    while (!result.empty())
    {

        string s = result.front();


        if (s[0] == '+' ||
            s[0] == '-' ||
            s[0] == '/' ||
            s[0] == '*')
        {
            double right = args.top();
            args.pop();
            double left = args.top();
            args.pop();

            switch (s[0])
            {
                case '+':
                {
                    args.push(left + right);
                    break;
                }
                case '-':
                {
                    args.push(left - right);
                    break;
                }
                case '*':
                {
                    args.push(left * right);
                    break;
                }
                case '/':
                {
                    args.push(left / right);
                    break;
                }
            }
            result.pop();
        }
        else
        {
            args.push(stod(s));
            result.pop();
        }
    }

    return args.top();
}

bool CanParse(string _input)
{
    for (int i = 0; i < _input.length(); i++)
    {
        if (!(_input[i] >= 40 && _input[i] <= 57 && _input[i] != 44))
        {
            return false;
        }
    }
    return true;
}

bool CheckBrackets()
{
    int openBrakes = 0;
    queue<string> buf = inputs;
    while (!buf.empty())
    {
        if (buf.front()[0] == '(') openBrakes++;
        if (buf.front()[0] == ')') openBrakes--;
        if (openBrakes < 0) return false;

        buf.pop();
    }
    if (openBrakes == 0) return true;
    else return false;
}

bool CheckOperators()
{
    queue<string> buf = inputs;

    if (buf.size() >= 3)
    {
        string left = buf.front();
        buf.pop();
        string center = buf.front();
        buf.pop();
        string right = buf.front();
        buf.pop();

        if ((center[0] == '+' ||
             center[0] == '-' ||
             center[0] == '*' ||
             center[0] == '/'))
        {
            if (!(((left[0] >= 48 && left[0] <= 57) || left[0] == 41) &&
                  ((right[0] >= 48 && right[0] <= 57) || right[0] == 40)))
                return false;
        }


        while (!buf.empty())
        {
            left = center;
            center = right;
            right = buf.front();
            buf.pop();


            if ((center[0] == '+' ||
                 center[0] == '-' ||
                 center[0] == '*' ||
                 center[0] == '/'))
            {
                if (!(((left[0] >= 48 && left[0] <= 57) || left[0] == 41) &&
                      ((right[0] >= 48 && right[0] <= 57) || right[0] == 40)))
                    return false;
            }
        }
    }

    return true;
}


bool CheckInput(string _input)
{
    if (CanParse(_input))
    {
        inputs = ParseInputs(_input);

        if (CheckBrackets() && CheckOperators()) return true;
        else return false;
    }
    else return false;
}


string ResolveNegatives(string _input)
{
    size_t index = 0;
    string output = _input;

    while (true) {
        index = output.find("(-", index);
        if (index == std::string::npos) break;
        else
        {
            output.replace(index, 2, "(0-");
            index += 3;
        }
    }
    return output;
}

double Calc(string _input)
{
    string input = ResolveNegatives(_input);
    if (CheckInput(input))
    {
        queue<string> polish = MakePolish(input);
        return CalcPolish();
    }
    else
    {
        cout << "Incorrect expression." << endl;
        return 0;
    }
}

int main()
{
    string input;

    while (true)
    {
        cout << "Enter the expression: ";
        cin >> input;
        cout << Calc(input) << endl;
    }
    _getch();
}
