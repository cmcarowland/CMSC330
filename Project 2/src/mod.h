

class Mod: public SubExpression {
public:
    Mod(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return (int)left->evaluate() % (int)right.front()->evaluate();
    }
};