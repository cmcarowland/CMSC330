

class Multiply: public SubExpression {
public:
    Multiply(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return left->evaluate() * right.front()->evaluate();
    }
};