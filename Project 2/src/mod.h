

class Mod: public SubExpression {
public:
    Mod(Expression* left, Expression* right): SubExpression(left, right) {}
    
    double evaluate() {
       return (int)left->evaluate() % (int)right->evaluate();
    }
};