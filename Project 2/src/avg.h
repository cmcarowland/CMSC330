


class Avg: public SubExpression {
public:
    Avg(Expression* left, Expression* right): SubExpression(left, right) {}
    
    double evaluate() {
       return (left->evaluate() + right->evaluate()) / 2.0;
    }
};