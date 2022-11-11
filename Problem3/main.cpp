//Name: Maryam Osama Mohamed
//ID: 20211090

#include "problem_3.h"

int main()
{
    //---------------------------------------------
    //Test case #1
    StringSet set("hello, MY name is maryam");
    set.Add("Apple");
    cout<<"Test case #1"<<endl;
    set.print();
    //---------------------------------------------
    //Test case #2
    StringSet set1("hello, i love CPP");
    set1.Remove("i");
    cout<<"Test case #2"<<endl;
    set1.print();
    //---------------------------------------------
    //Test case #3
    cout<<"Test case #3"<<endl;
    cout<<set1.num_of_set()<<endl;
    //---------------------------------------------
    //Test case #4
    cout<<"Test case #4"<<endl;
    StringSet set2 = set1 + set;
    set2.print();
    //---------------------------------------------
    //Test case #5
    cout<<"Test case #5"<<endl;
    StringSet set3 = set1 * set;
    set3.print();
    //---------------------------------------------
    //Test case #6
    cout<<"Test case #6"<<endl;
    cout<<StringSet().similarity(set,set1);
    //---------------------------------------------
}
