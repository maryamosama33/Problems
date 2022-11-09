#include "problem_3.h"

//------------------------------------------------------------------------------
//function to takes a string and loads it and breaks it to tokens.
void StringSet::divide(string &s)
{
    string res="";
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i]!=' ')
        {
            if(isalpha(s[i]))
            {
                res+=(tolower(s[i]));
            }
        }
        else
        {
            if(isalpha(res[0]))
            {
                vec.push_back(res);
                res.clear();
            }
        }
    }
    if(isalpha(res[0]))
    {
        vec.push_back(res);
    }
    sort( vec.begin(), vec.end() );
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() ); //erase repeated words.
}
//------------------------------------------------------------------------------
//constructor that takes file and load it in vector.
StringSet::StringSet(fstream file)
{
    string word;
    while(file >> word)
    {
        string res="";
        for (int i = 0; i < word.length(); ++i)
        {
            if(isalpha(word[i]))
            {
                res+=tolower(word[i]);
            }
        }
        vec.push_back(res);
    }
    sort( vec.begin(), vec.end() );
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() ); //erase repeated words.
}
//-----------------------------------------------------------------------------------
//constructor that takes string.
StringSet ::StringSet(string s)
{
    divide(s);
}
//---------------------------------------------------------------------------------
//function to add string to the vector.
void StringSet :: Add(string add)
{
    divide(add);
}
//---------------------------------------------------------------------------------
//function to remove a string from the vector.
void StringSet :: Remove(string rem)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        if(vec[i]==rem)
        {
            vec.erase(vec.begin()+i);
        }
    }
}
//----------------------------------------------------------------------------------
//function to clear the entire vector.
void StringSet :: clear()
{
    vec.clear();
}
//---------------------------------------------------------------------------------
//function to return the number of strings in the vector.
int StringSet :: num_of_set()
{
    return vec.size();
}
//---------------------------------------------------------------------------------
//function to output all strings in the vector.
void StringSet :: print()
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << endl;
    }
}
//----------------------------------------------------------------------------------
//the union of two StringSet objects
StringSet StringSet :: operator+ (StringSet other)
{
    StringSet res;
    res.vec.insert(res.vec.begin(), vec.begin(), vec.end());
    res.vec.insert(res.vec.end(), other.vec.begin(), other.vec.end());
    return res;
}
//-----------------------------------------------------------------------------------
//the intersection of two StringSet objects.
StringSet StringSet :: operator* (StringSet other)
{
    StringSet res;
    sort(vec.begin(), vec.end());
    sort(other.vec.begin(), other.vec.end());
    set_intersection(vec.begin(),vec.end(),other.vec.begin(),other.vec.end(),back_inserter(res.vec));
    return res;
}
//-------------------------------------------------------------------------------------
//computes the similarity
double StringSet :: similarity(StringSet Q,StringSet D)
{
    StringSet res = Q.operator*(D);
    double result = res.num_of_set()/(sqrt(Q.num_of_set())*sqrt(D.num_of_set()));
    return result;
}
//--------------------------------------------------------------------------------------