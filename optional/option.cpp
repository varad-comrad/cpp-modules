#include <iostream>

using namespace std;

template <typename T>
class Option {
    private:
    enum class Variant {
        Some,
        None
    };
    T value;
    Variant variant;
    public:
    Option() : variant(Variant::None), value() {}
    
    Option(T value) : variant(Variant::Some), value(value) {}
    
    void print() {
        switch (variant) {
            case Variant::Some:
                cout << "Some(" << value << ")" << endl;
                break;
            case Variant::None:
                cout << "None" << endl;
                break;
        }
    }

    const static Option<T> None;
};

template <typename T>
const Option<T> Option<T>::None = Option<T>();


int main() {
    Option<int> some(5);
    some.print();
    Option<int> none = Option<int>::None;
    none.print();
    return 0;
}