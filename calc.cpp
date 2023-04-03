#include <iostream>
#include <cmath>
#include "calc.h"
using namespace std;

calc::calc(double x, double y, char z)
{
    a = x;
    b = y;
    op = z;
}
double calc::geta() { return a; }
double calc::getb() { return b; }
char calc::getop() { return op; }
void calc::seta(double n1) { a = n1; }
void calc::setb(double n2) { b = n2; }
void calc::setop(char o) { op = o; }

void calc::display()
{
    cout << endl
         << "Basic Calculator ('m' to change mode) ('n' to quit)" << endl
         << "operations available : + - * / sqroot(r) sqr(s)" << endl;
}

calc::~calc() {}
double calc::result()
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case 'r':
        return sqrt(a);
    case 's':
        return a * a;

    }
    cout << "Operation not available in basic calc. Switch to scientific.";
    return 0;
}

scientific_calc::scientific_calc(double x, double y, char z) : calc(x, y, z){};
double scientific_calc::result()
{
    switch (getop())
    {
    case '+':
        return geta() + getb();
    case '-':
        return geta() - getb();
    case '*':
        return geta() * getb();
    case '/':
        return geta() / getb();
    case '^':
        return pow(geta(), getb());
    case 'q':
        return sin(geta());
    case 'w':
        return cos(geta());
    case 'e':
        return tan(geta());
    case 'r':
        return sqrt(geta());
    case 't':
        return asin(geta());
    case 'y':
        return acos(geta());
    case 'u':
        return atan(geta());
    case 's':
        return geta() * geta();

    }
    return 0;
}
scientific_calc::~scientific_calc() {}
void scientific_calc::display()
{
    cout << endl
         << "Scientific Calculator ('m' to change mode) ('n' to quit)" << endl
         << "operations available : + - * / sqroot(r) sqr(s)" << endl
         << "power(^) sine(q) cosine(w) tan(e) asin(t) acos(y) atan(u)" << endl;
}

int main()
{
    calc ins(4, 1, '+');
    scientific_calc inst(4, 5, '-');

    int flag = 1;
    char op = '+';
    double a, b;
    bool option = true;
    while (flag)
    {
        if (option)
        {
            ins.display();
        }
        else
        {
            inst.display();
        }
        cout << "Enter op followed by number(s)" << endl;

        cin >> op;
        if (op != 'm' && op != 'n' && op != '+' && op != '-' && op != '*' && op != '/' && op != 'q' && op != 'w' && op != 'e' && op != 'r' && op != 't' && op != 'y' && op != '^' && op != 's' && op != 'u')
        {
           
            cin.clear();
            continue;
        }
        if (op == 'm')
        {
            option = !option;
            continue;
        }
        if (op == 'n')
            return 0;

        
        cin >> a;
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        ins.seta(a);
        inst.seta(a);
        ins.setop(op);
        inst.setop(op);
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        {
            cin >> b;
            ins.setb(b);
            inst.setb(b);
        }
        if (option)
        {
            cout << ins.result() << endl;
        }
        else
        {
            cout << inst.result() << endl;
        }
        
    }
    return 0;
}
