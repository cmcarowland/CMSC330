


class Min: public SubExpression {
public:
    Min(Expression* left, Expression* right): SubExpression(left, right) {}
    
    double evaluate() {
       return std::min(left->evaluate(), right->evaluate());
    }
};