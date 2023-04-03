#ifndef CALC_H
#define CALC_H

class calc
{
private:
    double a;
    double b;
    char op;

public:
    
    calc(double x, double y , char z);
    double geta() ;
    double getb() ;
    char getop() ;
    void seta(double n1) ;
    void setb(double n2) ;
    void setop(char o); 

    virtual void display();
   
    ~calc();
    virtual double result();
};

class scientific_calc:public calc{
    public:
    scientific_calc(double x, double y , char z);
    ~scientific_calc();
    double result();
    void display();
};

#endif
