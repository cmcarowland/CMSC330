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

    TEST_F(EquationTest, Add) { 
        SetUp("( a + z ) , a = 3, z = 4.9;");
        double result = expression->evaluate();
        EXPECT_EQ(3 + 4.9, result) << "Failed!!"; 
    }
   
    TEST_F(EquationTest, Add2) { 
        SetUp("( a + 100 ) , a = 27;");
        double result = expression->evaluate();
        EXPECT_EQ(100 + 27, result) << "Failed!!"; 
    }
    
    TEST_F(EquationTest, Add3) { 
        SetUp("( 50 + b_aay ) , b_aay = 56;");
        double result = expression->evaluate();
        EXPECT_EQ(50 + 56, result) << "Failed!!"; 
    }
    
    TEST_F(EquationTest, Avg) { 
        SetUp("(100 & h), h = 90;");
        double result = expression->evaluate();
        EXPECT_EQ(95, result) << "Failed!!"; 
    }

    TEST_F(EquationTest, Avg2) { 
        SetUp("(q_z & 50), q_z = 150;");
        double result = expression->evaluate();
        EXPECT_EQ(100, result) << "Failed!!"; 
    }
   
    TEST_F(EquationTest, Avg3) { 
        SetUp("(z & a), a=1000,z=2000;");
        double result = expression->evaluate();
        EXPECT_EQ(1500, result) << "Failed!!"; 
    }
}