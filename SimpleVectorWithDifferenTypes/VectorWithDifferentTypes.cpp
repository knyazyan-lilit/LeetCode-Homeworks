#include <iostream>

enum TypeName
{
    CHAR,
    INT,
    DOUBLE,
    FLOAT,
    STRING,
};

struct Type
{
    void *value;
    TypeName typ;
};

class Vector
{
private:
    int size;
    int capacity = 1;
    Type *buffer = new Type[capacity];

public:
    Vector()
    {
        size = 0;
        capacity = 1;
    }
    void push(Type elem)
    {
        if (size == capacity)
        {
            capacity *= 2;
            Type *temp = new Type[capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = buffer[i];
            }
            delete[] buffer;
            buffer = temp;
        }
        buffer[size].typ = elem.typ;
        buffer[size].value = elem.value;
        size++;
    }

    void pop()
    {
        size--;
    }

    void print()
    {
        std::cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            if (buffer[i].typ == INT)
            {
                std::cout << *(int *)(buffer[i].value) << ",";
            }
            else if (buffer[i].typ == CHAR)
            {
                std::cout << *(char *)(buffer[i].value) << ",";
            }
            else if (buffer[i].typ == DOUBLE)
            {
                std::cout << *(double *)(buffer[i].value) << ",";
            }
            else if (buffer[i].typ == FLOAT)
            {
                std::cout << *(float *)(buffer[i].value) << ",";
            }
            if (buffer[i].typ == STRING)
            {
                std::cout << *(string *)(buffer[i].value) << ",";
            }
        }
        cout << "]";
    }
};

int main()
{
    Vector obj;
    Type x;
    x.typ = INT;
    x.value = new int(21);
    obj.push(x);
    Type s;
    s.typ = STRING;
    s.value = new string("hi");
    obj.push(s);
    Type y;
    y.typ = INT;
    y.value = new int(1);
    obj.push(y);
    Type f;
    f.typ = DOUBLE;
    f.value = new double(15.23);
    obj.push(f);
    Type c;
    c.typ = CHAR;
    c.value = new char('a');
    obj.push(c);
    obj.print();
    obj.pop();
    obj.print();
    
    return 0;
}
