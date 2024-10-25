class Max: public SubExpression {
public:
    Max(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return max(left->evaluate(), right.front()->evaluate());
    }
};