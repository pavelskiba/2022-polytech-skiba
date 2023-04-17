#include "logic.h"
#include <sstream>
#include <unordered_map>

namespace calc
{
    std::string Logic::process_math()
    {
        if (expression.empty())
        {
            return "";
        }

        // Map to store the values of variables
        std::unordered_map<char, double> variables;

        std::istringstream input_ss(expression);
        std::stringstream output_ss;

        double a;
        double b;
        char op;
        input_ss >> a >> op >> b;

        if (op == '=')
        {
            // Assign a value to a variable
            variables[a] = b;
            output_ss << a << op << b;
        }
        else
        {
            // Check if a or b are variables
            if (variables.count(a))
            {
                a = variables[a];
            }
            if (variables.count(b))
            {
                b = variables[b];
            }

            if (op == '+')
            {
                output_ss << a << op << b << "=" << a + b;
            }
            else if (op == '-')
            {
                output_ss << a << op << b << "=" << a - b;
            }
            else if (op == '*')
            {
                output_ss << a << op << b << "=" << a * b;
            }
            else if (op == '/')
            {
                if (b == 0)
                {
                    output_ss << "Error: division by zero";
                }
                else
                {
                    output_ss << a << op << b << "=" << a / b;
                }
            }
            else if (op == '%')
            {
                if (b == 0)
                {
                    output_ss << "Error: division by zero";
                }
                else
                {
                    output_ss << a << op << b << "=" << static_cast<int>(a) % static_cast<int>(b);
                }
            }
            else if (op == '^')
            {
                output_ss << a << op << b << "=" << pow(a, b);
            }
            else if (op == '!')
            {
                if (a < 0)
                {
                    output_ss << "Error: factorial of a negative number";
                }
                else
                {
                    int result = 1;
                    for (int i = 1; i <= a; ++i)
                    {
                        result *= i;
                    }
                    output_ss << a << op << "=" << result;
                }
            }
            else if (op == 'p')
            {
                output_ss << "pi=" << pi;
            }
            else if (op == 'e')
            {
                output_ss << "e=" << exp(1.0);
            }
            else if (op == 'c')
            {
                output_ss << "c=" << 299792458;
            }
            else if (op == 'G')
            {
                output_ss << "G=" << 6.67430e-11;
            }
            else
            {
                output_ss << "Error: unsupported operation or constant";
            }
        }
        return output_ss.str();
    }
}
