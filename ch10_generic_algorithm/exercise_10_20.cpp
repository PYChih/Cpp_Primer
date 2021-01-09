// Exercise 10.20:
// The library defines an algorithm named count_if. Like find_if, this function takes
// a pair of iterators denoting an input range and a predicate that it applies to each
// element in the given range. count_if returns a count of how often the predicate is
// true. Use count_if to rewrite the portion of our program that counted how many words
// are greater than length 6.
//

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string make_plural(size_t ctr, const string &word,
                                const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}


void print_vector(const vector<string> &words)
{
    for (auto i : words){
        cout<<i<<" ";
    }
    cout<<endl;
}
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    cout<<"after you sort :"<<endl;
    print_vector(words);
    //stable_sort(words.begin(), words.end(), isShorter);
    //cout<<"after you stable sort :"<<endl;
    //print_vector(words);
    auto end_iter = std::unique(words.begin(), words.end());
    cout<<"after you unique :"<<endl;
    print_vector(words);
    words.erase(end_iter, words.end());
    cout<<"after you erase :"<<endl;
    print_vector(words);
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [sz](const string &a, const string &b)
                {return a.size() < b.size(); });
    cout<<"after you stable_sort :"<<endl;
    print_vector(words);
    //auto wc = find_if(words.begin(), words.end(),
    //                    [sz](const string &a)
    //                    { return a.size() >= sz; });
    auto wc = stable_partition(words.begin(), words.end(),
                        [sz](const string &a){ return a.size() >=sz;});
    auto count = wc - (words.begin());
    cout<< count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
    // here are count if version
    auto num_greater5 = count_if(words.begin(), words.end(),
                        [](string s){return s.size()>=6;});
    cout<<"how many words are greater than length 6 ?"<<endl;
    cout<< " ans :" << num_greater5<<endl;
    for_each(words.begin(), wc,
            [](const string &s){cout << s << " ";});
    cout << endl;
}


int main(){
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    cout<<"after you read the input :"<<endl;
    print_vector(words);
    biggies(words, 5);
    return 0;
}