//Ques3
//19MA20039
//Rahul Saini

/*
Input specifications
Please use multiply symbol '*' wherever there is multiplication

For ex-
Correct - 3*x
Incorrect - 3x

Only works for one term 
No operations allowed 
*/

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;

class function{
public:
    virtual void diff() = 0;
    virtual void diff(string) = 0;
};

class pown:public function{
public:
    int n;
    pown(int n_){
        n = n_;
    }
};

class constn:public pown{
public:
    constn():pown(0) {}
    void diff(){printf("0");}

    void diff(string exp)
    {
        printf("0");
    }
};

class pow1:public pown{
public:
    pow1():pown(1) {}
    void diff(){printf("1");}
    void diff(string exp)
    {
        printf("1");
    }
};

class pow11:public pown{
public:
    pow11(int t):pown(t) {}
    void diff(){printf("%dx^(%d)",n,n-1);}
    void diff(string exp)
    {
        printf("%d(%s)^(%d)",n,exp.c_str(),n-1);
    }
};

class expo:public function{
public:
    void diff(){
        printf("e^(x)");
    }
    void diff(string exp)
    {
        printf("e^(%s)",exp.c_str());
    }
};

class log:public function{
public:
    void diff(){
        printf("1/x");
    }
    void diff(string exp)
    {
        printf("1/(%s)",exp.c_str());
    }
};

class bx:public function{
public:
    int n;
    bx(int n_){n = n_;}
    void diff(){
        printf("%d^(x)*log(%d)",n,n);
    }
    void diff(string exp)
    {
        printf("%d^(%s)*log(%d)",n,exp.c_str(),n);
    }
};

class inverse:public function{
public:
    inverse(){};
    string name;
    
};

class sininv:public inverse{
public:
    void diff(){ printf("1/((1-x^(2))^1/2)");}
    void diff(string exp)
    {
        printf("1/((1-(%s)^(2))^1/2)",exp.c_str());
    }
};

class cosinv:public inverse{
public:
    void diff(){ printf("-1/((1-x^(2))^1/2)");}
    void diff(string exp)
    {
        printf("-1/((1-(%s)^(2))^1/2)",exp.c_str());
    }
};

class taninv:public inverse{
public:
    void diff(){ printf("1/(1+x^(2))");}
    void diff(string exp)
    {
         printf("1/(1+(%s)^(2))",exp.c_str());
    }
};

class cotinv:public inverse{
public:
    void diff(){ printf("-1/(1+x^(2))");}
    void diff(string exp)
    {
        printf("-1/(1+(%s)^(2))",exp.c_str());
    }
};

class cosecinv:public inverse{
public:
    void diff(){ printf("-1/(|x|*((x^(2)-1)^1/2))");}
    void diff(string exp)
    {
        printf("-1/(|(%s)|*(((%s)^(2)-1)^1/2))",exp.c_str(),exp.c_str());
    }
};

class secinv:public inverse{
public:
    void diff(){ printf("1/(|x|*((x^(2)-1)^1/2))");}
    void diff(string exp)
    {
        printf("1/(|(%s)|*(((%s)^(2)-1)^1/2))",exp.c_str(),exp.c_str());
    }
};


class trigno:public function{
public:
    trigno(){};
    string name;
    trigno(string name_) {name = name_;}
};

class sin:public trigno{
public:

    void diff(){printf("cos(x)");}
    void diff(string exp)
    {
        printf("cos(%s)",exp.c_str());
    }
};

class cos:public trigno{
public:

    void diff(){printf("-sin(x)");}
    void diff(string exp)
    {   
        printf("-sin(%s)",exp.c_str());
    }
};

class tan:public trigno{
public:

    void diff(){printf("sec(x)^(2)");}
    void diff(string exp)
    {
        printf("sec(%s)^(2)",exp.c_str());
    }
};

class cosec:public trigno{
public:

    void diff(){printf("-cosec(x)*cot(x)");}
    void diff(string exp)
    {
        printf("-cosec(%s)*cot(%s)",exp.c_str(),exp.c_str());
    }
};

class sec:public trigno{
public:

    void diff(){printf("sec(x)*tan(x)");}
    void diff(string exp)
    {
        printf("sec(%s)*tan(%s)",exp.c_str(),exp.c_str());
    }
};

class cot:public trigno{
public:

    void diff(){printf("-(cosec(x)^(2))");}
    void diff(string exp)
    {
        printf("-(cosec(%s)^(2))",exp.c_str());
    }
};

class hyper:public function{
public:
    hyper(){};
};

class sinh:public hyper{
public:

    void diff(){printf("cosh(x)");}
    void diff(string exp)
    {
        printf("cosh(%s)",exp.c_str());
    }
};

class cosh:public hyper{
public:

    void diff(){printf("sinh(x)");}
    void diff(string exp)
    {
        printf("sinh(%s)",exp.c_str());
    }
};

class tanh:public hyper{
public:

    void diff(){printf("1-(tanh(x)^(2))");}
    void diff(string exp)
    {
        printf("1-(tanh(%s)^(2))",exp.c_str());
    }
};

class cosech:public hyper{
public:

    void diff(){printf("-cosech(x)*coth(x)");}
    void diff(string exp)
    {
        printf("-cosech(%s)*coth(%s)",exp.c_str(),exp.c_str());
    }
};

class sech:public hyper{
public:

    void diff(){printf("-sech(x)*tanh(x)");}
    void diff(string exp)
    {
        printf("-sech(%s)*tanh(%s)",exp.c_str(),exp.c_str());
    }
};

class coth:public hyper{
public:

    void diff(){printf("1-(coth(x)^(2))");}
    void diff(string exp)
    {
        printf("1-(coth(%s)^(2))",exp.c_str());
    }
};

void diff(string);

void chainrule(string expression,int u,function* f)
{
    // cout << "DEBUG" << endl;
    // cout << "|**" << expression << "**|" << endl;
    
    string exp;
    exp = "";
    for(int j =u;j<expression.length()-1;j++)
        exp += expression[j];
    // cout << "|**" << exp << "**|" << endl;
    cout << "(";
    f->diff(exp);
    cout << ")*";
    diff(exp);
}

void parse(string expression,int  i = 0)
{
    function *f;
    string exp;
    if(expression[i] == 's')
        {
            if(expression[i+1] == 'i')
            {
                if(expression[i+3] == '-') // sin-1
                {
                    int u = i+6;
                    f = new sininv();

                    if(expression[u] == 'x')
                    {  
                        f->diff();
                    }
                    else
                        chainrule(expression,u,f);
                    
                }
                else if(expression[i+3] == 'h') //sinh
                {
                    int u = i+5;
                    f = new sinh();
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
                else //sin(x)
                {
                    int u = i+4;
                    f = new sin();
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                    
                }
            }

            else
            {
                if(expression[i+3] == '-') // secin-1
                {
                    int u = i+8;
                    f = new secinv();
                    
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
                else if(expression[i+3] == 'h') //sech
                {
                    
                    int u = i+5;
                    f = new sech();
                    
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
                else //sec(x)
                {
                    int u = i+4;
                    f = new sec();
                    
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
            }
            
        }
        
        else if(expression[i] == 'c')
        {
            if(expression[i+2] == 's')
            {
                if(expression[i+3] == '-') // cos-1
                {
                    
                    int u = i+6;
                    f = new cosinv();
                    
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
                else if(expression[i+3] == 'h') //cosh
                {
                    f = new cosh();
                    int u = i+5;

                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
                else //cos(x)
                {
                    f = new cos();
                    
                    int u = i+4;
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
            }

            else if(expression[i+2] == 't')
            {
                if(expression[i+3] == '-') // cot-1
                {
                    f = new cotinv();
                    int u = i+6;
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
                else if(expression[i+3] == 'h') //coth
                {
                    f = new coth();
                    int u = i+5;
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
                else //cot(x)
                {
                    f = new cot();
                    int u = i+4;
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
            }

            else if(expression[i+2] == 'c') //csc
            {
                if(expression[i+3] == '-') // csc-1
                {
                    int u = i+6;
                    f = new cosecinv();
                    
                    if(expression[u] == 'x')
                    {
                        f->diff();
                    }

                    else
                        chainrule(expression,u,f);
                }
                else if(expression[i+3] == 'h') //csch
                {
                    

                    int u = i+5;
                    f = new cosech();

                    if(expression[u] == 'x')
                        f->diff();
                    else
                        chainrule(expression,u,f);
                }
                else //csc(x)
                {
                    
                    f = new cosec();
                    int u = i+4;
                    if(expression[u] == 'x')
                        f->diff();
                    else
                        chainrule(expression,u,f);
                }
            }
            
        }

        else if(expression[i] == 't')
        {
            if(expression[i+3] == '-') // tan-1
            {
                f = new taninv();
                int u = i+6;
                if(expression[u] == 'x')
                    f->diff();
                else
                    chainrule(expression,u,f);
            }
            else if(expression[i+3] == 'h') //tanh
            {
                
                f = new tanh();
                int u = i+5;
                if(expression[u] == 'x')
                    f->diff();
                else
                    chainrule(expression,u,f);
            }
            else //tan(x)
            {
                
                f = new tan();

                int u = i+4;
                if(expression[u] == 'x')
                    f->diff();
                else
                    chainrule(expression,u,f);
            }
        }

        
        else if(expression[i] >= '0' && expression[i] <= '9')
        {
            int n = 0;
            while(expression[i] >= '0' && expression[i] <= '9')
            {
                n *= 10;
                n += expression[i]-'0';
                i++;
            }
            
            f = new constn();

            if(expression[i] == '^')
            {
                f = new bx(n);

                int u = i+2;
                if(expression[u] == 'x')
                    f->diff();

                else
                    chainrule(expression,u,f);
            }
            else
                f->diff();
        }
        
        else if(expression[i] == 'x')
        {
            if(expression[i+1] == '^')
            {
                f = new pow11(0);
                i += 3;
                int  u = i;
                if(expression[i] >= '0' && expression[i] <= '9')
                {
                    int n = 0;
                    while(expression[i] >= '0' && expression[i] <= '9')
                    {
                        n *= 10;
                        n += expression[i]-'0';
                        i++;
                    }
                    // if(expression[i] == ')')
                    f = new pow11(n);


                }
                
            }
            else
            {
                f = new pow1();
                f->diff();
            }
        }

        else if(expression[i] == 'e')
        {
            f = new expo();

            int u = i+3;
            if(expression[u] == 'x')
                f->diff();
            else
                chainrule(expression,u,f);
        }

        else if(expression[i] == 'l')
        {
            f = new log();
            int u = i+4;
            if(expression[u] == 'x')
                f->diff();
            else
                chainrule(expression,u,f);
        }

        // if(expression[i+1] == '^') //Some function raised to constant power
        // {
        //     // f = new pow11(0);
        //     i += 3;
            
        //     if(expression[i] >= '0' && expression[i] <= '9')
        //     {
        //         int n = 0;
        //         while(expression[i] >= '0' && expression[i] <= '9')
        //         {
        //             n *= 10;
        //             n += expression[i]-'0';
        //             i++;
        //         }
        //         // if(expression[i] == ')')
        //         cout << "(" << n << "*(";
        //         f
        //         cout << ")^(" << n-1 << "))*";
        //         f->diff();

        //     }
            
        // }

    // return f;
}

void solve(string expression,string expression1,char op)
{
    // cout << "DEBUG OUTPUT" << endl;
    // cout << "Ex1 = " << expression << " with op = " << op << " Ex2 = " << expression1 << endl;
    
    if(op == '/')
    {
        printf("(");
        printf("((%s)*",expression1.c_str());
        diff(expression);
        printf(")");
        printf("-");
        printf("((%s)*",expression.c_str());
        diff(expression1);
        printf(")");
        printf("/");
        printf("((%s)^(2))",expression1.c_str());
    }

    else if(op == '*')
    {
        printf("(");
        printf("((%s)*",expression.c_str());
        diff(expression1);
        printf(")");
        printf("+");
        printf("((%s)*",expression1.c_str());
        diff(expression);
        printf(")");
    }

    else if(op == '+' || op == '-')
    {
        printf("(");
        diff(expression);
        printf("%c",op);
        diff(expression1);
        printf(")");
    }
    
}

void diff(string expression)
{

    int bracket = 0;
    bool udone = false;
    string u="",v="";
    char op = ' ';
    int i=0;

    while(i<expression.length())
    {
        if(expression[i] == '(')
        {
            bracket++;
            while(bracket != 0)
            {
                i++;
                if(expression[i] == '(') bracket++;
                else if(expression[i] == ')') bracket --;

                if(bracket)
                {
                    if(!udone)
                        u += expression[i];
                    else
                        v += expression[i];
                }
                
            }
            i++;

        }
        else
        {
            while(expression[i] != '/' && expression[i] != '*' && (expression[i] != '-' || expression[i+1] == '1') && expression[i] != '+' && i<expression.length())
            {
                if(!udone)
                    u += expression[i];
                else
                    v += expression[i];
                i++;
            }

            if(expression[i] == '/' || expression[i] == '*' || expression[i] == '-' || expression[i] == '+')
            {
                op = expression[i];
                udone = true;
            }
            
            i++;
            
        }
    }
    

    if(op == ' ')
    {
        parse(u);
    }
    else
        solve(u,v,op);
}

int main()
{

    string expression;

    ifstream input_file;
    
    input_file.open("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\OOSD Asign\\input3.txt");

    if(!input_file)
        cout << "Unable to open file" << endl;
    
    if(input_file.is_open()) cout << "File is open\n";

    while(getline(input_file,expression))
    {
        cout << "Expression = " << expression << endl;
        //Removing spaces from input
        string t;
        for(auto it:expression)
            if(it != ' ') t+= it;

        cout << "Derivative = " ;
        parse(t);
        cout << endl;
        cout << endl;
        // getline(input_file,expression);

    }
    input_file.close();

    // g++ -c main.cpp function.cpp
    // g++ -c main.o function.o
}