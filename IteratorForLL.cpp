#include<bits/stdc++.h>
using namespace std;

template<typename T> class myList;
template<typename T> class myList_iterator;

template<typename T>
class myList_node{
    friend class myList<T>;
    friend class myList_iterator<T>;

private :
    myList_node(const T& t, myList_node<T> *next) : elem(t), next(next){}
    ~myList_node(){delete next;}
    T elem;
    myList_node<T>*next;
};

template<typename  T>
class myList{
public:
    typedef myList_iterator<T> iterator;

public:
    myList() : head(NULL), tail(NULL){}
    ~myList(){delete head;}

    bool empty()const { return head==NULL;}
    void push_back(const T& elem);

    iterator begin(){ return myList_iterator<T>(head);}
    iterator end() { return myList_iterator<T>(NULL);}

private:
    myList_node<T> *head, *tail;
};
template<typename T>
void myList<T>::push_back(const T &elem) {
    myList_node<T> *newnode = new myList_node<T>(elem,NULL);

    if(head == NULL){
        head = newnode;
    }else{
        tail->next = newnode;
    }
    tail = newnode;
}

template<typename T>
class myList_iterator : public iterator<forward_iterator_tag,T>{
    friend class myList<T>;
public:
    T& operator*();
    const myList_iterator<T>& operator++();
    bool operator!=(const myList_iterator<T>& other) const;
private:
    myList_node<T> *pointee;
    myList_iterator(myList_node<T> *pointee) : pointee(pointee) {}
};

template<typename T>
T& myList_iterator<T>::operator*() {
    return pointee->elem;
}
template<typename T>
const myList_iterator<T>& myList_iterator<T>::operator++() {
    assert(pointee != NULL);
    pointee = pointee->next;
    return *this;
}
template<typename T>
bool myList_iterator<T>::operator!=(const myList_iterator<T>&other) const {
    return this->pointee != other.pointee;
}

int main(){

    myList<int>ll;
    ll.push_back(5);
    ll.push_back(66);
    ll.push_back(15);
    ll.push_back(2);
    ll.push_back(9);
    ll.push_back(5);
    ll.push_back(34);
    ll.push_back(10);

    int sum = 0;
    for(auto i = ll.begin(); i != ll.end(); ++i) {
        cout << *i << " ";
    }

    cout<<endl;
    for(auto i : ll){
        cout<<i<<" ";
    }
    /*cout<<endl<<sum<<endl;*/




}
