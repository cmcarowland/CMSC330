


class Avg: public SubExpression {
public:
    Avg(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return (left->evaluate() + right.front()->evaluate()) / 2.0;
    }
};