#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        this->length = l;
        this->breadth = b;
    }
    int area()
    {
        int a = length * breadth;
        return a;
    }
    int perimeter()
    {
        int a = 2 * (length + breadth);
        return a;
    }
};

int main()
{
    Rectangle rec(5, 10);
    int area = rec.area();
    int perimeter = rec.perimeter();
    cout << "The area is: " << area << endl;
    cout << "The perimeter is: " << perimeter << endl;
}