#include <iostream>

using namespace std;

class Rational
{
public:
    Rational(void);
    Rational(int wholeNumber);
    Rational(int num1, int num2);
    int getNumerator(void) const
    {
        return numerator;
    }

    int getDenominator(void) const
    {
        return denominator;
    }

    void setNumerator(int num1)
    {
        numerator = num1;
    }

    void setDenominator(int num2)
    {
        denominator = num2;
    }

private:
    friend int GCD(int x, int y);
    friend Rational reduce(int num1, int num2);
    friend Rational neg(const Rational &num1);
    int numerator;
    int denominator;
};

bool operator==(const Rational &num1, const Rational &num2);
bool operator<(const Rational &num1, const Rational &num2);
bool operator<=(const Rational &num1, const Rational &num2);
bool operator>(const Rational &num1, const Rational &num2);
bool operator>=(const Rational &num1, const Rational &num2);
Rational operator+(const Rational &num1, const Rational &num2);
Rational operator--(const Rational &num1);
Rational operator*(const Rational &num1, const Rational &num2);
Rational operator/(const Rational &num1, const Rational &num2);
istream &operator>>(istream &CIN, Rational &obj);
ostream &operator<<(ostream &COUT, Rational &obj);
int GCD(int x, int y);
Rational reduce(int num1, int num2);
Rational neg(const Rational &num1);

int main(int argc, char *argv[])
{
    Rational r1(-3, -2);
    Rational r2(-3, -4);

    r1 = neg(r1);
    r2 = neg(r2);

    cout << endl
         << "----------------------------TEST FOR CONSTRUCTOR (#1)----------------------------" << endl;
    Rational constructor1 = Rational();
    cout << "Rational() outputs " << constructor1 << endl;
    cout << "----------------------------TEST FOR CONSTRUCTOR (#1) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST FOR CONSTRUCTOR (#2)----------------------------" << endl;
    Rational constructor2 = Rational(5);
    cout << "Rational(whole number) outputs " << constructor2 << endl;
    cout << "----------------------------TEST FOR CONSTRUCTOR (#2) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST FOR CONSTRUCTOR (#3)----------------------------" << endl;
    Rational constructor3 = Rational(5, 6);
    cout << "Rational(num1, num2) outputs " << constructor3 << endl;
    cout << "----------------------------TEST FOR CONSTRUCTOR (#3) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 1 (==)----------------------------" << endl;
    cout << "Testing if " << r1 << " and " << r2 << " fractions are equal" << endl;

    if (r1 == r2)
    {
        cout << endl
             << "Result: Success" << endl;
        cout << r1 << " and " << r2 << " are equal" << endl;
    }

    else
    {
        cout << endl
             << "Result: Failure" << endl;
    }

    cout << "----------------------------TEST 1 (==) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 2 (<)----------------------------" << endl;
    cout << "Testing if " << r1 << " is less than " << r2 << endl;
    cout << "AND" << endl;
    cout << "Testing if " << r2 << " is less than " << r1 << endl;

    if (r1 < r2)
    {
        cout << "Result: Success" << endl;
        cout << "Fraction " << r1 << " is less than " << r2 << endl;
    }

    else if (r2 < r1)
    {
        cout << endl
             << "Result: Success" << endl;
        cout << "Fraction " << r2 << " is less than " << r1 << endl;
    }

    else
    {
        cout << endl
             << "Result: Failure" << endl;
    }
    cout << "----------------------------TEST 2 (<) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 3 (<=)----------------------------" << endl;
    cout << "Testing if " << r1 << " is less than or equal " << r2 << endl;
    cout << "AND" << endl;
    cout << "Testing if " << r2 << " is less than or equal " << r1 << endl;

    if ((r2 <= r1))
    {
        cout << endl
             << "Result: Success" << endl;
        cout << r2 << " is less than or equal to " << r1 << endl;
    }

    else if ((r1 <= r2))
    {
        cout << endl
             << "Result: Success" << endl;
        cout << r1 << " is less than or equal to " << r2 << endl;
    }

    else
    {
        cout << endl
             << "Result: Failure" << endl;
    }
    cout << "----------------------------TEST 3 (<=) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 4 (>)----------------------------" << endl;
    cout << "Testing if " << r1 << " is greater than " << r2 << endl;
    cout << "AND" << endl;
    cout << "Testing if " << r2 << " is greater than " << r1 << endl;

    if (r1 > r2)
    {
        cout << endl
             << "Result: Success" << endl;
        cout << "Fraction " << r1 << " is greater than " << r2 << endl;
    }

    else if (r2 > r1)
    {
        cout << endl
             << "Result: Success" << endl;
        cout << "Fraction " << r2 << " is greater than " << r1 << endl;
    }

    else
    {
        cout << endl
             << "Result: Failure" << endl;
    }
    cout << "----------------------------TEST 4 (>) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 5 (>=)----------------------------" << endl;
    cout << "Testing if " << r1 << " is greater than or equal " << r2 << endl;
    cout << "AND" << endl;
    cout << "Testing if " << r2 << " is greater than or equal " << r1 << endl;

    if ((r2 >= r1))
    {
        cout << endl
             << "Result: Success" << endl;
        cout << r2 << " is greater than or equal to " << r1 << endl;
    }

    else if ((r1 >= r2))
    {
        cout << endl
             << "Result: Success" << endl;
        cout << r1 << " is greater than or equal to " << r2 << endl;
    }

    else
    {
        cout << endl
             << "Result: Failure" << endl;
    }
    cout << "----------------------------TEST 5 (>=) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 6 (+)----------------------------" << endl;
    Rational temp = r1 + r2;
    cout << "Addition of " << r1 << " and " << r2 << " is " << temp << endl;
    cout << "----------------------------TEST 6 (+) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 7 (--)----------------------------" << endl;
    Rational temp1 = --r1;
    Rational temp2 = --r2;
    cout << "Decrementing " << r1 << ": " << endl;
    cout << "After Decrementing " << r1 << ": " << temp1 << endl;

    cout << "Decrementing " << r2 << ": " << endl;
    cout << "After Decrementing " << r2 << ": " << temp2 << endl;
    cout << "----------------------------TEST 7 (--) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 8 (*)----------------------------" << endl;
    Rational temp3 = r1 * r2;
    cout << "Multiplication of " << r1 << " and " << r2 << " is " << temp3 << endl;
    cout << "----------------------------TEST 8 (*) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 9 (/)----------------------------" << endl;
    Rational temp4 = r1 / r2;
    Rational temp5 = r2 / r1;

    cout << "Division of " << r1 << " and " << r2 << " is " << temp4 << endl;
    cout << "Division of " << r2 << " and " << r1 << " is " << temp5 << endl;
    cout << "----------------------------TEST 9 (/) end------------------------" << endl;

    cout << endl
         << "----------------------------TEST 10 (>> and <<)----------------------------" << endl;
    cout << "Input a fraction in form of num1/num2: " << endl;
    Rational temp6;
    cin >> temp6;
    if (temp6.getDenominator() != 0)
    {
        if(temp6.getDenominator() > 0)
        {
            Rational positive = neg(temp6);
            positive = reduce(temp6.getNumerator(), temp6.getDenominator());
            cout << "Outputting the input fraction: " << positive << endl;
        }
        else
        {
            temp6 = reduce(temp6.getNumerator(), temp6.getDenominator());
            cout << "Outputting the input fraction: " << temp6 << endl;
        }
        
    }
    cout << "----------------------------TEST 10 (>>  and <<) end------------------------" << endl;

    return 0;
}

Rational::Rational(void)
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int wholeNumber)
{
    numerator = wholeNumber;
    denominator = 1;
}

Rational::Rational(int num1, int num2)
{
    numerator = num1;
    denominator = num2;
}

int GCD(int x, int y)
{
    if (x == 0)
    {
        return y;
    }
    return GCD(y % x, x);
}

Rational reduce(int num1, int num2)
{
    int divisor;
    divisor = GCD(num1, num2);
    num1 = num1 / divisor;
    num2 = num2 / divisor;
    Rational temp(num1, num2);
    if(temp.getDenominator() < 0)
    {
        temp = neg(temp);
    }
    return temp;
}

Rational neg(const Rational &num1)
{
    if (num1.getDenominator() < 0)
    {
        int temp1 = num1.getNumerator();
        int temp2 = num1.getDenominator();
        int x = (-1) * temp1;
        int y = (-1) * temp2;
        Rational temp(x, y);
        return temp;
    }
    return num1;
}

bool operator==(const Rational &num1, const Rational &num2)
{
    return (num1.getNumerator() == num2.getNumerator() && num1.getDenominator() == num2.getDenominator());
}

bool operator<(const Rational &num1, const Rational &num2)
{
    if (num1.getNumerator() > num2.getNumerator())
    {
        return true;
    }

    else if (num1.getNumerator() == num2.getNumerator() && num1.getDenominator() > num2.getDenominator())
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool operator<=(const Rational &num1, const Rational &num2)
{
    if ((num1.getNumerator() > num2.getNumerator()) || (num1 == num2))
    {
        return true;
    }

    else if ((num1.getNumerator() == num2.getNumerator() && num1.getDenominator() > num2.getDenominator()) || (num1 == num2))
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool operator>(const Rational &num1, const Rational &num2)
{
    if (num1.getNumerator() < num2.getNumerator())
    {
        return true;
    }

    else if (num1.getNumerator() == num2.getNumerator() && num1.getDenominator() < num2.getDenominator())
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool operator>=(const Rational &num1, const Rational &num2)
{
    if ((num1.getNumerator() < num2.getNumerator()) || (num1 == num2))
    {
        return true;
    }

    else if ((num1.getNumerator() == num2.getNumerator() && num1.getDenominator() < num2.getDenominator()) || (num1 == num2))
    {
        return true;
    }

    else
    {
        return false;
    }
}

Rational operator+(const Rational &num1, const Rational &num2)
{
    int temp1 = num1.getNumerator() * num2.getDenominator();
    int temp2 = num1.getDenominator() * num2.getNumerator();
    int temp3 = num1.getDenominator() * num2.getDenominator();
    int numerator = temp1 + temp2;
    int denominator = temp3;

    Rational temp;
    reduce(numerator, denominator);
    return temp;
}

Rational operator--(const Rational &num1)
{
    int temp1 = num1.getNumerator() * 1;
    int temp2 = num1.getDenominator() * 1;
    int temp3 = num1.getDenominator() * 1;
    int numerator = temp1 - temp2;
    int denominator = temp3;

    Rational temp(numerator, denominator);
    return temp;
}

Rational operator*(const Rational &num1, const Rational &num2)
{
    int temp1 = num1.getNumerator() * num2.getNumerator();
    int temp2 = num1.getDenominator() * num2.getDenominator();
    int numerator = temp1;
    int denominator = temp2;

    Rational temp = reduce(numerator, denominator);
    return temp;
}

Rational operator/(const Rational &num1, const Rational &num2)
{
    int temp1 = num2.getNumerator();
    int temp2 = num2.getDenominator();
    int numerator = temp2;
    int denominator = temp1;

    Rational multiplier(numerator, denominator);
    Rational result = num1 * multiplier;
    return result;
}

istream &operator>>(istream &CIN, Rational &obj)
{
    char ignore;
    int x;
    int y;

    CIN >> x;
    obj.setNumerator(x);

    CIN >> ignore;

    CIN >> y;

    if (y == 0)
    {
        cout << "Undefined, cannot have 0 in denominator" << endl;
        cout << "----------------------------TEST 10 (>>  and <<) end------------------------" << endl;
        exit(1);
    }
    obj.setDenominator(y);

    return CIN;
}

ostream &operator<<(ostream &COUT, Rational &obj)
{
    COUT << obj.getNumerator() << "/" << obj.getDenominator();

    return COUT;
}