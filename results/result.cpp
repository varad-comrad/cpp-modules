#include <iostream>

using namespace std;

template <typename T, class E>
class Result{
private:
    enum class Variant{
        Ok,
        Err
    };
    T value;
    E error;
    Variant ty;

public:
    Result() : ty(Variant::Err), value() {}

    Result(T value) : ty(Variant::Ok), value(value) {}

    void print(){
        switch (variant){
        case Variant::Ok:
            cout << "Ok(" << value << ")" << endl;
            break;
        case Variant::Err:
            cout << "Err" << endl;
            break;
        }
    }
};


int main(){
    // Result<int> ok(5);
    // ok.print();
    // Result<int> err = Result<int>::Err;
    // err.print();
    return 0;
}