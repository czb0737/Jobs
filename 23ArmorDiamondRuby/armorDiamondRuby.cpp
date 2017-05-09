#include <iostream>
#include <queue>

using namespace std;

struct Item
{
    int max_stack_size;
    int value;
    int num;
    Item(int m, int v, int n) : max_stack_size(m), value(v), num(n) {}
};

struct Comp
{
    bool operator()(Item &it1, Item &it2)
    {
        int num1 = min(it1.num, it1.max_stack_size);
        int num2 = min(it2.num, it2.max_stack_size);
        return it1.value * num1 < it2.value * num2;
    }
};

int maxValue(Item armor, Item diamond, Item ruby, int n)
{
    priority_queue<Item, vector<Item>, Comp> pq;
    pq.push(armor), pq.push(diamond), pq.push(ruby);
    int result = 0;

    while (!pq.empty() && n--)
    {
        Item it = pq.top(); pq.pop();
        int num = min(it.num, it.max_stack_size);
        result += it.value * num;
        it.num -= num;
        if (it.num > 0) pq.push(it);
    }
    return result;
}

int main()
{
    Item armor(1, 25, 5);
    Item diamond(5, 10, 10);
    Item ruby(10, 6, 28);
    cout << maxValue(armor, diamond, ruby, 6) << endl;
}