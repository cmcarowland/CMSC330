class Invert: public SubExpression {
public:
    Invert(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
        return -(left->evaluate());
    }
};