//Ques1
//19MA20039
//Rahul Saini

/*
Input specifications
Please use multiply symbol '*' wherever there is multiplication

For ex-
Correct - 3*x
Incorrect - 3x
*/

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>

using namespace std;

//Change path here
string path = "C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\OOSD Asign\\";

class function{
public:
    virtual void diff() = 0;
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
};

class pow1:public pown{
public:
    pow1():pown(1) {}
    void diff(){printf("1");}
};

class pow11:public pown{
public:
    pow11(int t):pown(t) {}
    void diff(){printf("%dx^(%d)",n,n-1);}
};

class expo:public function{
public:
    void diff(){
        printf("e^(x)");
    }
};

class log:public function{
public:
    void diff(){
        printf("1/x");
    }
};

class bx:public function{
public:
    int n;
    bx(int n_){n = n_;}
    void diff(){
        printf("%d^(x)*log(%d)",n,n);
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
};

class cosinv:public inverse{
public:
    void diff(){ printf("-1/((1-x^(2))^1/2)");}
};

class taninv:public inverse{
public:
    void diff(){ printf("1/(1+x^(2))");}
};

class cotinv:public inverse{
public:
    void diff(){ printf("-1/(1+x^(2))");}
};

class cosecinv:public inverse{
public:
    void diff(){ printf("-1/(|x|*((x^(2)-1)^1/2))");}
};

class secinv:public inverse{
public:
    void diff(){ printf("1/(|x|*((x^(2)-1)^1/2))");}
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
};

class cos:public trigno{
public:

    void diff(){printf("-sin(x)");}
};

class tan:public trigno{
public:

    void diff(){printf("sec(x)^(2)");}
};

class cosec:public trigno{
public:

    void diff(){printf("-cosec(x)*cot(x)");}
};

class sec:public trigno{
public:

    void diff(){printf("sec(x)*tan(x)");}
};

class cot:public trigno{
public:

    void diff(){printf("-(cosec(x)^(2))");}
};

class hyper:public function{
public:
    hyper(){};
};

class sinh:public hyper{
public:

    void diff(){printf("cosh(x)");}
};

class cosh:public hyper{
public:

    void diff(){printf("sinh(x)");}
};

class tanh:public hyper{
public:

    void diff(){printf("1-(tanh(x)^(2))");}
};

class cosech:public hyper{
public:

    void diff(){printf("-cosech(x)*coth(x)");}
};

class sech:public hyper{
public:

    void diff(){printf("-sech(x)*tanh(x)");}
};

class coth:public hyper{
public:

    void diff(){printf("1-(coth(x)^(2))");}
};


void diff(string);

function* parse(string expression,int  i = 0)
{
    function *f;
    if(expression[i] == 's')
        {
            if(expression[i+1] == 'i')
            {
                if(expression[i+3] == '-') // sin-1
                {
                    f = new sininv();
                    i += 7;
                }
                else if(expression[i+3] == 'h') //sinh
                {
                    f = new sinh();
                    i += 6;
                }
                else //sin(x)
                {
                    f = new sin();
                    i += 5;
                }
            }

            else
            {
                if(expression[i+3] == '-') // secin-1
                {
                    f = new secinv();
                    i += 7;
                }
                else if(expression[i+3] == 'h') //sech
                {
                    f = new sech();
                    i += 6;
                }
                else //sec(x)
                {
                    f = new sec();
                    i += 5;
                }
            }
            
        }
        
        else if(expression[i] == 'c')
        {
            if(expression[i+2] == 's')
            {
                if(expression[i+3] == '-') // cos-1
                {
                    f = new cosinv();
                    i += 7;
                }
                else if(expression[i+3] == 'h') //cosh
                {
                    f = new cosh();
                    i += 6;
                }
                else //cos(x)
                {
                    f = new cos();
                    i += 5;
                }
            }

            else if(expression[i+2] == 't')
            {
                if(expression[i+3] == '-') // cot-1
                {
                    f = new cotinv();
                    i += 7;
                }
                else if(expression[i+3] == 'h') //coth
                {
                    f = new coth();
                    i += 6;
                }
                else //cots(x)
                {
                    f = new cot();
                    i += 5;
                }
            }

            else if(expression[i+2] == 'c') //csc
            {
                if(expression[i+3] == '-') // csc-1
                {
                    f = new cosecinv();
                    i += 7;
                }
                else if(expression[i+3] == 'h') //csch
                {
                    f = new cosech();
                    i += 6;
                }
                else //cscs(x)
                {
                    f = new cosec();
                    i += 5;
                }
            }
            
        }

        else if(expression[i] == 't')
        {
            if(expression[i+3] == '-') // tan-1
            {
                f = new taninv();
                i += 7;
            }
            else if(expression[i+3] == 'h') //tanh
            {
                f = new tanh();
                i += 6;
            }
            else //tan(x)
            {
                f = new tan();
                i += 5;
            }
        }

        
        else if(expression[i] >= '0' && expression[i] <= '9')
        {
            f = new constn();
            int  n =0;
            while(expression[i] >= '0' && expression[i] <= '9')
            {
                n*= 10;
                n += expression[i]-'0';
                i++;

            }

            if(expression[i] == '^')
            {
                f = new bx(n);
                i += 3;
            }
            else
                i--;

        }
        
        else if(expression[i] == 'x')
        {
            if(expression[i+1] == '^')
            {
                i += 3;
                int n = 0;
                while(expression[i] >= '0' && expression[i] <= '9')
                {
                    n *= 10;
                    n += expression[i]-'0';
                    i++;
                }
                f = new pow11(n);
            }
            else
                f = new pow1();
        }

        else if(expression[i] == 'e')
        {
            f = new expo();
            i += 4;
        }

        else if(expression[i] == 'l')
        {
            f = new log();
            i += 5;
        }

    return f;
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
        function *f = parse(u);
        f->diff();
    }
    else
        solve(u,v,op);
}

int main()
{

    string expression;

    ifstream input_file;
    
    input_file.open(path+"input1.txt");

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
        diff(t);
        cout << endl;
        cout << endl;
        // getline(input_file,expression);

    }
    input_file.close();
}