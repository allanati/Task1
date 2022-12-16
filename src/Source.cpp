#include"Header.hpp";
#include<iostream>;
#include<string>;

namespace an
{
    void CheckSizeAndSwap(std::string* a, std::string* b)       //checks size of a and b, swaps values if a < b, adds '0's to b
    {
        if ((*a).length() < (*b).length())
        {
            std::swap(*a, *b);
        }
        if ((*a).length() > (*b).length())
        {
            while ((*b).length() < (*a).length())
            {
                *b = "0" + *b;
            }
        }
    }
    std::string Sum(std::string a, std::string b)
    {
        CheckSizeAndSwap(&a, &b);
        std::string SumString = "0" + a;               //adds '0' in front, for when sumstring has 1 more digit than a    
        for (int i = 0; i < SumString.length(); i++)
        {
            SumString[i] = '0';
        }

        bool flag = 0;
        int forNextDigit = 0;       // will be added to next digit in SumString, for example 9+3=12, help = (9+3)/10 = 1

        for (int i = 1; i < a.length() + 1; i++)
        {
            int c1 = int(a[a.length() - i]) - 48;       //get digit of a and b in int
            int c2 = int(b[b.length() - i]) - 48;

            int d = 0;      // d is value of digit in SumString

            if (c1 + c2 + forNextDigit > 9)
            {
                flag = 1;
                d = (c1 + c2) - 10 + forNextDigit;
                SumString[a.length() - i + 1] = char(d + 48);
               // std::cout << SumString[a.length() - i + 1] << std::endl;
                forNextDigit = (c1 + c2)/10;
            }

            if (flag == 0)
            {
                int c = c1 + c2;
                SumString[a.length() - i + 1] = char(c + 48) + forNextDigit;
                forNextDigit = 0;

            }

            flag = 0;
        }

        if (forNextDigit != 0)
        {
            SumString[0] = char(int(SumString[0]) + forNextDigit);
        }

        if (SumString[0] == '0')
        {
            SumString.erase(0, 1);
        }
        return SumString;
    }
   

    std::string Mult(std::string a, std::string b)
    {
        std::string MultString = a + b;

        for (int i = 0; i < a.length() + b.length(); i++)
        {
            MultString[i] = '0';
        }

        std::string Result = MultString;

        std::string EmptyString = MultString;

        for (int i = 0; i < a.length(); i++)
        {
            for (int j = 0; j < b.length(); j++)
            {
                int c1 = a[a.length() - i - 1] - 48;
                int c2 = b[b.length() - j - 1] - 48;

                int mult = c1 * c2;

                MultString[MultString.length() - j - i - 1] = char(mult % 10 + 48);
                MultString[MultString.length() - j - i - 2] = char(mult / 10 + 48);


                while (Result.length() > MultString.length())
                {
                    MultString = '0' + MultString;
                }

                Result = Sum(Result, MultString);

                MultString = EmptyString;
            }

        }
        if (Result[0] == '0')
        { 
            Result.erase(0, 1);
        } 
        return Result;
    }
}