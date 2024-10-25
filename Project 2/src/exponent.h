
class Exponent: public SubExpression {
public:
    Exponent(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return pow(left->evaluate(), right.front()->evaluate());
    }
};