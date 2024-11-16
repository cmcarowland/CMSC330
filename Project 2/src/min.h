/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * Class Min: Inherits from SubExpression.
 * 
 * This class computes the minimum value between a left expression and 
 * the first right expression. The evaluate method returns the smaller of 
 * the evaluated values using the std::min function.
 */



class Min: public SubExpression {
public:
    Min(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return std::min(left->evaluate(), right.front()->evaluate());
    }
};