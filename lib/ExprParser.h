#ifndef EXPRPARSER_H
#define EXPRPARSER_H

class ExpressionParser {
private:

  char * expressionToParse;

  int A;
  int B;
  int C;
  int D;

public:
    ExpressionParser()
    {
        A = 0;
        B = 0;
        C = 0;
        D = 0;
    }

    char peek()
    {
        return *expressionToParse;
    }

    char get()
    {
        return *expressionToParse++;
    }

    int expression();

    int number()
    {
        char g;
        int result;

        if (peek() == 'A'  |  peek() == 'B'  |  peek() == 'C' |  peek() == 'D')
        {
            result = 0;
        }else{
            g = get();
            result = g - '0';
        }


        while (peek() >= '0' && peek() <= '9' |  peek() == 'A'  |  peek() == 'B'  |  peek() == 'C' |  peek() == 'D' )
        {
            if (peek() == 'A')
            {
                get();
                result = 100000*result + A;
            }
            else if (peek() == 'B')
            {
                get();
                result = 100000*result + B;
            }
            else if (peek() == 'C')
            {
                get();
                result = 100000*result + C;
            }
            else if (peek() == 'D')
            {
                get();
                result = 100000*result + D;
            }else{
                g = get();
                result = 10*result + g - '0';
            }

        }
        return result;
    }

    int factor()
    {
        if (peek() >= '0' && peek() <= '9'  |  peek() == 'A'  |  peek() == 'B'  |  peek() == 'C' |  peek() == 'D'  )
        {
            return number();
        }
        else if (peek() == '(')
        {
            get(); // '('
            int result = expression();
            get(); // ')'
            return result;
        }
        else if (peek() == '-')
        {
            get();
            return -factor();
        }
        return 0; // error
    }

    int term()
    {
        int result = factor();
        while (peek() == '*' || peek() == '/' || peek() == '|' )
        {
            char g = get();
            if (g == '*')
                result *= factor();
            else if (g == '|')
                result =  result | factor();
    //		else if (g == 'A')
    //				result =  A;
            else
                result /= factor();
        }
        return result;
    }

    int expression(char * expr, int PA, int PB, int PC, int PD)
    {

        A = PA;
        B = PB;
        C = PC;
        D = PD;

        expressionToParse = expr;

        int result = term();
        while (peek() == '+' || peek() == '-'  || peek() == '>'  || peek() == '<' || peek() == '&')
        {
            char g = get();
            if (g == '+')
                result += term();
            else if (g == '>')
                result =  result >> term();
            else if (g == '<')
                result =  result << term();
            else if (g == '&')
                result =  result & term();
            else
                result -= term();
        }
        return result;
    }

};





#endif // EXPRPARSER_H
