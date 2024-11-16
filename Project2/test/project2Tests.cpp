/**
 * Raymond Rowland
 * 10 NOV 24
 * Project 2
 * 
 * This code defines a set of unit tests for parsing and evaluating mathematical expressions
 * using the Google Test framework. It tests various operations such as addition, division,
 * minimum/maximum functions, average, and custom operators, as well as parsing literals and variables.
 * 
 * The `EquationTest` class is used as a fixture for setting up expression parsing and evaluation.
 * It includes tests for verifying the correctness of expressions with literals and variables.
 * The tests also cover complex scenarios like ternary and quaternary operations.
 * 
 * Additionally, the code includes exception handling tests to ensure that:
 * - `DoubleDefinedException` is raised when a variable is redefined.
 * - `InvalidOperatorException` is raised for unsupported operators.
 * - `UnefinedException` is raised when an undefined variable is encountered.
 */


#include "gtest/gtest.h"
#include "../src/expression.h"
#include "../src/subexpression.h"
#include "../src/symboltable.h"
#include "../src/parse.h"
#include "../src/exceptions.h"
#include "../src/variable.h"

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string LIGHT_BLUE = "\033[94m";
const string RESET = "\033[0m";

SymbolTable symbolTable;

namespace {
    class EquationTest : public testing::Test {
        protected:
        EquationTest() {}
        void SetUp(string equation) {
            symbolTable.clear();
            stringstream in(equation);
            in >> paren;
            expression = SubExpression::parse(in);
            in >> comma;
            parseAssignments(in);
        }
        
        char paren, comma;
        Expression* expression;
    };

    string result_header(string equation, double result) {
        stringstream ss;
        ss << LIGHT_BLUE << "[  RESULT  ]\t" << equation << " = " << result << RESET << endl;
        return ss.str();
    }

    TEST_F(EquationTest, InvertVars) { 
        string s = "(d ~), d=25;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(-25, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, InvertLiteral) { 
        string s = "((50 + q_z) ~), q_z = 150;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(-200, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, AddVars) { 
        string s = "( a + z ) , a = 3, z = 4.9;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(EquationTest, AddLiteral) { 
        string s = "( a + 100 ) , a = 27;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(100 + 27, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(EquationTest, SubVars) { 
        string s = "( a - z ) , a = 10, z = 2.9;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(10 - 2.9, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(EquationTest, SubLiteral) { 
        string s = "( a - 512 ) , a = 1024;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(1024 - 512, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(EquationTest, MulVars) { 
        string s = "( a * z ) , a = 10, z = 2.9;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(10 * 2.9, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
   
    TEST_F(EquationTest, MulLiteral) { 
        string s = "( a * 512 ) , a = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(4 * 512, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }
    
    TEST_F(EquationTest, DivVars) { 
        string s = "(c_ / h), c_=100, h = 2;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(50, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, DivLiteral) { 
        string s = "(q_z / 50), q_z = 150;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(3, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }
    
    TEST_F(EquationTest, RemVars) { 
        string s = "(c_ % h), c_=118, h = 8;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(6, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, RemLiteral) { 
        string s = "(q_z % 3), q_z = 20;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(2, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

     TEST_F(EquationTest, ExponentVars) { 
        string s = "(f ^ e), e=16, f=2;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(65536, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, ExponentLiteral) { 
        string s = "(2 ^ g_g), g_g = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(16, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, MinVars) { 
        string s = "(h < i), h=100, i=200;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(100, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, MinLiteral) { 
        string s = "(2 < j), j = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(2, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, MaxVars) { 
        string s = "(h > i), h=100, i=200;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(200, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, MaxLiteral) { 
        string s = "(2 > j), j = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(4, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, AvgVars) { 
        string s = "(100 & h), h = 90;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(95, result) << "Failed!!"; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, AvgLiteral) { 
        string s = "(q_z & 50), q_z = 150;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(100, result) << "Failed!! " << s;
        cout << result_header(s, result); 
    }
    
    TEST_F(EquationTest, TernaryVars) { 
        string s = "(m ? k l), k=34, l=926, m=0;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(926, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, TernaryLiteral) { 
        string s = "( n ? 0 -1 ), n = 1;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(0, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }
    
    TEST_F(EquationTest, TernaryExpressions) { 
        string s = "((5 - 4) ? (f * e) (f + e)), f = 2, e = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(8, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }
    
    TEST_F(EquationTest, TernaryExpressions0) { 
        string s = "((5 - 5) ? (f * e) (f + e)), f = 2, e = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(6, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, QuatnaryVarsLeft) { 
        string s = "(o # p q r), q=34, r=926, o=-1, p=123;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(123, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(EquationTest, QuatnaryVarsCenter) { 
        string s = "(o # p q r), q=34, r=926, o=0, p=123;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(34, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }
    
    TEST_F(EquationTest, QuatnaryVarsRight) { 
        string s = "(o # p q r), q=34, r=926, o=1, p=123;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(926, result) << "Failed!! " << s;
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, QuatnaryLiteralLeft) { 
        string s = "(n # -1 0 1), n = -1;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(-1, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, QuatnaryLiteralCenter) { 
        string s = "(0 # -1 n 1), n = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(4, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, QuatnaryLiteralRight) { 
        string s = "(n # -1 0 1), n = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(1, result) << "Failed!! " << s; 
        cout << result_header(s, result);
    }

    TEST_F(EquationTest, Cleared)
    {
        try {
            string s = "( a + b ) , a = 3, b = 4.9;";
            SetUp(s);
            double result = expression->evaluate();
            EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 
            cout << result_header(s, result);

            s = "(a # b c d), a = 0, b=-1,c=4,d=34;";
            SetUp(s);
            result = expression->evaluate();
            EXPECT_EQ(4, result) << "Failed!! " << s; 
            cout << result_header(s, result);
            cout << LIGHT_BLUE << "[  RESULT  ]\t" << GREEN << "Variables 'a' and 'b' were defined in repeating equations and they did not raise a double defined exception" << RESET << endl;
        } catch (const DoubleDefinedException& e) {
            EXPECT_STREQ( "a Was previously defined", e.what() );
        }
    }

    TEST(Exception, DoubleDefinedException )
    {
        symbolTable.clear();
        char comma, paren;

        EXPECT_THROW({
            try
            {
                string s = "( a + b ) , a = 3, a = 4.9;";
                stringstream in(s);
                in >> paren;
                Expression* expression = SubExpression::parse(in);
                in >> comma;
                parseAssignments(in);
                double result = expression->evaluate();
                EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 
            }
            catch( const DoubleDefinedException& e )
            {
                EXPECT_STREQ( "a Was previously defined", e.what() );
                cout << LIGHT_BLUE << "[  RESULT  ]\t" << RED << "Double defined exception was caught" << RESET << endl;
                throw;
            }
        }, DoubleDefinedException );
    }
   
    TEST(Exception, InvalidOperatorException )
    {
        symbolTable.clear();
        char comma, paren;

        EXPECT_THROW({
            try
            {
                string s = "( a $ b ) , a = 3, a = 4.9;";
                stringstream in(s);
                in >> paren;
                Expression* expression = SubExpression::parse(in);
                in >> comma;
                parseAssignments(in);
                double result = expression->evaluate();
                EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 
            }
            catch( const InvalidOperatorException& e )
            {
                EXPECT_STREQ( "$ is not supported yet", e.what() );
                cout << LIGHT_BLUE << "[  RESULT  ]\t" << RED << "InvalidOperationException was caught" << RESET << endl;
                throw;
            }
        }, InvalidOperatorException );
    }
 
    TEST(Exception, InvalidNameExceptionLeft )
    {
        char comma, paren;
        symbolTable.clear();

        string s = "( _a + b ) , _a = 3, b = 4.9;";
        stringstream in(s);

        EXPECT_THROW({
            try
            {
                in >> paren;
                Expression* expression = SubExpression::parse(in);
                in >> comma;        
                parseAssignments(in);
                double result = expression->evaluate();
                EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 
            }
            catch( const InvalidNameException& e )
            {
                EXPECT_STREQ( "Name cannot start with an underscore!", e.what() );
                cout << LIGHT_BLUE << "[  RESULT  ]\t" << RED << "InvalidNameException was caught" << RESET << endl;
                throw;
            }
        }, InvalidNameException );
    }

    TEST(Exception, InvalidNameExceptionRight )
    {
        char comma, paren;
        symbolTable.clear();

        string s = "( a + _b ) , a = 3, _b = 4.9;";
        stringstream in(s);

        EXPECT_THROW({
            try
            {
                in >> paren;
                Expression* expression = SubExpression::parse(in);
                in >> comma;        
                parseAssignments(in);
                double result = expression->evaluate();
                EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 
            }
            catch( const InvalidNameException& e )
            {
                EXPECT_STREQ( "Name cannot start with an underscore!", e.what() );
                cout << LIGHT_BLUE << "[  RESULT  ]\t" << RED << "InvalidNameException was caught" << RESET << endl;
                throw;
            }
        }, InvalidNameException );
    }
    
    TEST(Exception, InvalidNameExceptionBoth )
    {
        char comma, paren;
        symbolTable.clear();

        string s = "( _a + _b ) , _a = 3, _b = 4.9;";
        stringstream in(s);

        EXPECT_THROW({
            try
            {
                in >> paren;
                Expression* expression = SubExpression::parse(in);
                in >> comma;        
                parseAssignments(in);
                double result = expression->evaluate();
                EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 
            }
            catch( const InvalidNameException& e )
            {
                EXPECT_STREQ( "Name cannot start with an underscore!", e.what() );
                cout << LIGHT_BLUE << "[  RESULT  ]\t" << RED << "InvalidNameException was caught" << RESET << RESET << endl;
                throw;
            }
        }, InvalidNameException );
    }
}