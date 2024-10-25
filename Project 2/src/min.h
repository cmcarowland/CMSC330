


class Min: public SubExpression {
public:
    Min(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return std::min(left->evaluate(), right.front()->evaluate());
    }
};