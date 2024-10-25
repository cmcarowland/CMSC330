class Quaternary: public SubExpression {
public:
    Quaternary(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
        double result = left->evaluate();
        if(result < 0)
            return right[0]->evaluate();
        else if(result == 0)
            return right[1]->evaluate();
        else
            return right[2]->evaluate();
    }
};