#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
template <typename T>
class DAS
{
private:
    T *ptr;
    int indx = -1; //it will track how many elements are present
    int len = 0;   //length of the array is 0
public:
    void create(int n)
    {
        if (n == 1)
            ptr = (T *)malloc(n * sizeof(T));
        else
            ptr = (T *)realloc(ptr, n * sizeof(T));
        //return n;
    }

    //insert at the end
    void insert(T val)
    {
        //cout << indx << " " << len << endl;
        if (indx + 1 < len)
        {
            ptr[indx + 1] = val;
            indx = indx + 1;
            //cout << indx << endl;
        }
        else
        {
            cout << "array size overflow: size increased" << endl;
            //len = int(len + 1 / (1 + (len + 1))); //using sigmoid function
            len = len + 1;
            create(len); //dynamic increase the array by length 1
            insert(val); // recursive call
        }
    }

    //push: insert at the begining
    void push(T val)
    {
        len = len + 1;
        indx = indx + 1;
        int i;
        create(len); //dynamic increase the array by length 1
        for (i = len - 1; i > 0; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[0] = val;
    }

    //delete from rear
    void rear_del()
    {
        if (len == 0)
            cout << "empty" << endl;
        else
        {
            len = len - 1;
            indx = indx - 1;
            int i;
            create(len); //dynamic increase the array by length 1
        }
    }

    void pop()
    {
        int i;
        if (len == 0)
            cout << "cant pop empty array" << endl;
        else
        {
            for (i = 0; i < indx; i++)
            {
                ptr[i] = ptr[i + 1];
            }
        }
        rear_del();
    }

    //print the array
    void print_data()
    {
        int i;
        for (i = 0; i <= indx; i++)
        {
            cout << ptr[i] << endl;
        }
    }
};

int main()
{
    DAS<int> obj1;
    int i;

    for (i = 1; i < 10; i++)
        obj1.insert(i);

    obj1.print_data();

    cout << "after push 100:" << endl;
    obj1.push(100);
    obj1.print_data();

    cout << "after delete from the end:" << endl;
    obj1.rear_del();
    obj1.print_data();

    cout << "after pop from front" << endl;
    obj1.pop();
    obj1.print_data();

    // obj1.insert(22);
    // obj1.print_data();
    return 0;
}