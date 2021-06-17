
template <typename T>
struct Node
{
    T info;
    Node *next;
};

template <typename T>
class FwdList
{
private:
    Node<T>* head;
    size_t size;

public:
    FwdList();
    void insert(int pos, T elem);
    void remove(int pos);
    void push_front(T elem);
    void push_back(T elem);
    void pop_front();
    void pop_back();
    void traversal(void(*f)(Node<T> node));
    void print(Node<T> node);
    bool is_empty();
    size_t get_size();
};


