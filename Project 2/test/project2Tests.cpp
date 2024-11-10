#include "gtest/gtest.h"
#include "../src/expression.h"
#include "../src/subexpression.h"
#include "../src/symboltable.h"
#include "../src/parse.h"
#include "../src/exceptions.h"
#include "../src/variable.h"

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

    TEST_F(EquationTest, AddVars) { 
        string s = "( a + z ) , a = 3, z = 4.9;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 
    }
   
    TEST_F(EquationTest, AddLiteral) { 
        string s = "( a + 100 ) , a = 27;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(100 + 27, result) << "Failed!! " << s; 
    }
    
    TEST_F(EquationTest, AvgVars) { 
        SetUp("(100 & h), h = 90;");
        double result = expression->evaluate();
        EXPECT_EQ(95, result) << "Failed!!"; 
    }

    TEST_F(EquationTest, AvgLiteral) { 
        string s = "(q_z & 50), q_z = 150;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(100, result) << "Failed!! " << s; 
    }
    
    TEST_F(EquationTest, DivVars) { 
        string s = "(c_ / h), c_=100, h = 2;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(50, result) << "Failed!! " << s;
    }

    TEST_F(EquationTest, DivLiteral) { 
        string s = "(q_z / 50), q_z = 150;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(3, result) << "Failed!! " << s; 
    }
    
    TEST_F(EquationTest, InvertVars) { 
        string s = "(d ~), d=25;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(-25, result) << "Failed!! " << s;
    }

    TEST_F(EquationTest, InvertLiteral) { 
        string s = "((50 + q_z) ~), q_z = 150;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(-200, result) << "Failed!! " << s; 
    }
    
    TEST_F(EquationTest, ExponentVars) { 
        string s = "(f ^ e), e=16, f=2;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(65536, result) << "Failed!! " << s;
    }

    TEST_F(EquationTest, ExponentLiteral) { 
        string s = "(2 ^ g_g), g_g = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(16, result) << "Failed!! " << s; 
    }
   
    TEST_F(EquationTest, MinVars) { 
        string s = "(h < i), h=100, i=200;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(100, result) << "Failed!! " << s;
    }

    TEST_F(EquationTest, MinLiteral) { 
        string s = "(2 < j), j = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(2, result) << "Failed!! " << s; 
    }

    TEST_F(EquationTest, MaxVars) { 
        string s = "(h > i), h=100, i=200;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(200, result) << "Failed!! " << s;
    }

    TEST_F(EquationTest, MaxLiteral) { 
        string s = "(2 > j), j = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(4, result) << "Failed!! " << s; 
    }

    TEST_F(EquationTest, TernaryVars) { 
        string s = "(m ? k l), k=34, l=926, m=0;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(34, result) << "Failed!! " << s;
    }

    TEST_F(EquationTest, TernaryLiteral) { 
        string s = "( n ? 0 -1 ), n = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(-1, result) << "Failed!! " << s; 
    }

    TEST_F(EquationTest, QuatnaryVarsLeft) { 
        string s = "(o # p q r), q=34, r=926, o=-1, p=123;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(123, result) << "Failed!! " << s;
    }
    
    TEST_F(EquationTest, QuatnaryVarsCenter) { 
        string s = "(o # p q r), q=34, r=926, o=0, p=123;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(34, result) << "Failed!! " << s;
    }
    
    TEST_F(EquationTest, QuatnaryVarsRight) { 
        string s = "(o # p q r), q=34, r=926, o=1, p=123;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(926, result) << "Failed!! " << s;
    }

    TEST_F(EquationTest, QuatnaryLiteralLeft) { 
        string s = "(n # -1 0 1), n = -1;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(-1, result) << "Failed!! " << s; 
    }

    TEST_F(EquationTest, QuatnaryLiteralCenter) { 
        string s = "(0 # -1 n 1), n = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(4, result) << "Failed!! " << s; 
    }

    TEST_F(EquationTest, QuatnaryLiteralRight) { 
        string s = "(n # -1 0 1), n = 4;";
        SetUp(s);
        double result = expression->evaluate();
        EXPECT_EQ(1, result) << "Failed!! " << s; 
    }

    TEST_F(EquationTest, Cleared)
    {
        try {
            string s = "( a + b ) , a = 3, b = 4.9;";
            SetUp(s);
            double result = expression->evaluate();
            EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 

            s = "(a # b c d), a = 0, b=-1,c=4,d=34;";
            SetUp(s);
            result = expression->evaluate();
            EXPECT_EQ(4, result) << "Failed!! " << s; 
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
                throw;
            }
        }, InvalidOperatorException );
    }
 
    TEST(Exception, UnefinedException )
    {
        char comma, paren;
        symbolTable.clear();

        string s = "( a + b ) , a = 3, c = 4.9;";
        stringstream in(s);
        in >> paren;
        Expression* expression = SubExpression::parse(in);
        in >> comma;        

        EXPECT_THROW({
            try
            {
                parseAssignments(in);
                double result = expression->evaluate();
                EXPECT_EQ(3 + 4.9, result) << "Failed!! " << s; 
            }
            catch( const UnefinedException& e )
            {
                EXPECT_STREQ( "b was never defined for this equation", e.what() );
                throw;
            }
        }, UnefinedException );
    }
}