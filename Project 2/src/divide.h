class Divide: public SubExpression {
public:
    Divide(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return left->evaluate() / right.front()->evaluate();
    }
};