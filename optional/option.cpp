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
};


int main() {
    Option<int> some(5);
    some.print();
    Option<int> none;
    none.print();
    return 0;
}