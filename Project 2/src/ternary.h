class Ternary: public SubExpression {
public:
    Ternary(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
        double result = left->evaluate();
        return result == 0 ? right[0]->evaluate() : right[1]->evaluate();
    }
};