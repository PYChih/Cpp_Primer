# Ch03_Strings_Vectors_and_Arrays
###### tags: `C++ exercise`
[TOC]
# 3.1 命名空間的using宣告
- [ ] 3.1 以適當的using宣告改寫1.4.1和2.6.2的練習
# 3.2 程式庫的string型別
## 3.2.1 定義並初始化string
## 3.2.2 在string上進行的運算
- [ ] 3.2: 寫一個程式，一次讀取一行的標準輸入。修改你的程式，改成一次讀取一個字詞。
- [ ] 3.3: 解釋空白字元在string輸入運算子及getline函式中是如何被處理的
    - string輸入運算子讀取並捨棄所有的前導空白，然後它持續讀取字元，直到遇到下一個空白字元為止
    - getline: 讀取給定資料流，直到第一個newline，並包括這個newline，並將它所讀到的，但並不包括那個newline，儲存到它的string引數。
- [ ] 3.4: 寫一個程式來讀取兩個string，並回報這些string是否有相同的長度，若非如此，就回報哪個比較長
- [ ] 3.5: 寫一個程式從標準輸入讀取string，並將讀取到的串接起來放到一個大型的string中。將串接後的string印出。接著，更改程式，以一個空格分隔相鄰的輸入。

## 3.2.3 處理一個string中的字元
- [ ] 3.6: 使用一個範圍for來將一個string中的所有字元改為X。
- [ ] 3.7: 如果你將前面練習的迴圈控制變數定義為型別char，會發生什麼事？預測結果，然後修改你的程式，使用一個char看看你是否正確
- [ ] 3.8: 改變第一個練習中的程式，先使用一個while，接著再使用一個傳統的for迴圈。這三種做法中你比較喜歡哪一個？為什麼
- [ ] 3.9: 下列程式會做什麼事？它是有效的嗎？如果不是，為何呢？
    ```
    string s;
    cout << s[0] << endl;
    // (某些)編譯會過，但是s是空字串，這樣做沒意義
    ```
- [ ] 3.10: 寫出一個程式，讀取一串字元，包括標點符號，然後寫出所讀到的東西，但移除標點符號
- [ ] 3.11: 下列的範圍for合法嗎？如果是，c的型別是什麼呢?
    ```
    const string s = "Keep out!";
    for (auto &c : s) {/*...*/}
    //合法，c是對const string的參考
    ```
# 3.3 程式庫的vector類別
## 3.3.1 定義並初始化vector
- [ ] 3.12: 如果有的話，下列哪個vector定義是錯誤的? 對於合法的那些，請解釋那些定義做些什麼。不合法的那些，解釋為何不合法。
    ```
    a. vector<vector<int>> ivec; // 預設初始化
    b. vector<string> svec = ivec; // ivec是int喔
    c. vector<string> svec(10, "null");//10個叫null的string?
    ```
- [ ] 3.13: 下列每個vector中各有多少元素? 那些元素的值又是什麼?
    ```
    a. vector<int> v1;// 0個int...
    b. vector<int> v2(10); // 10個0
    c. vector<int> v3(10, 42);// 10個42
    d. vector<int> v4{10};// 一個10
    e. vector<int> v5{10, 42};// 兩個，10跟42
    f. vector<string> v6 {10};// 10個空字串
    g. vector<string> v7{10, "hi"};// 10個hi
    ```
## 3.3.2 新增元素到一個vector
- [ ] 3.14: 寫一個程式從cin讀取一序列的int，並將那些值儲存在一個vector中。
- [ ] 3.15: 重複前一個程式，但這次改讀取string
## 3.3.3 其他的vector運算
- [ ] 3.16: 寫出一個程式印出練習3.13中那些vector的大小與內容。檢查你對於那個練習的解答是否正確。若非如此，重新研讀3.3.1值到你了解為何出錯為止
- [ ] 3.17: 從cin讀取一序列字詞，並將那些值儲存為一個vector。在你讀完了所有的字詞之後，就處理那個vector並將每個字詞變為大寫。印出變換後的元素，一行八個字。
- [ ] 3.18: 下列的程式合法嗎? 若非，你會如何修正之?
    ```
    vector<int> ivec;
    ivec[0] = 42;
    ```
- [ ] 3.19: 列出定義一個vector的三種方法，並賦予它十個元素，每個都有值42。指出要這麼做是否有偏好的方式以及原因。
- [ ] 3.20: 將一組整數讀到一個vector中。印出每對相鄰元素的和。更改你的程式，改印出第一與最後一個元素的和，後面接著第二個和倒數第二個的和，依此類推。
# 3.4 迭代器簡介
## 3.4.1 使用迭代器
- [ ] 3.21: 使用迭代器重新做一遍3.3.3的第一個練習
- [ ] 3.22: 假設我們有一個名為text的`vector<string>`，存放了來自一個文字檔案的資料，這個vector中的每個元素要不是一個句子，就是一個空的string，表示段落。如果我們想要從text印出第一段的內容，我們就得寫一個迴圈，迭代text直到我們遇到空的元素為止。修改會印出text第一個段落的迴圈，改為將text中對應到第一個段落的元素全都變為大寫。更改text後印出其內容
- [ ] 3.23: 寫一個程式來建立帶有十個int元素的一個vector。使用一個迭代器將每個元素的指定為目前值的兩倍。印出這個vector來測試你的程式。
## 3.4.2 迭代器的算術運算
- [ ] 3.24: 使用迭代器重做3.3.3的最後一個練習
- [ ] 3.25: 使用迭代器來取代下標，改寫3.3.3的成績叢集程式。
- [ ] 3.26: 在前面的二元搜尋程式中，為什麼我們寫的是mid = beg + (end - beg) / 2; 而非min = (beg + end) / 2

## 3.5.1 定義並初始化內建的陣列
- [ ] 3.27: 假設txt_size是一個函式，他不接受引數(arguments)，並回傳一個int值，下列哪些定義是非法的？解釋原因。
    ```
    unsigned buf_size = 1024;
    a. int ia[buf_size]; // buf_size不是常數運算式
    b. int ia[4*7-14];//常數運算式，給過
    c. int ia[txt_size()];//不是常數運算式
    d. char st[11] = "fundamental";//這個有12個字喔因為是"
    ```
- [ ] 3.28: 下列陣列中的值是什麼?
    - 定義在局部和全局的差別:
    - string本來就接受無參數初始化，所以每個都空字串
    - 全局的array初始化全都是0
    - 局部的array初始化是未定義
    ```
    string sa[10]; // 10 個空字串
    int ia[10];// 10個0
    int main(){
        string sa2[10]; // 10個空字串
        int ia2[10]; // 10個0
    }
    ```
- [ ] 3.29: 列出使用陣列而非vector的一些缺點。
    - 一定要一開始就知道有多少元素
    - 陣列沒辦法直接拷貝(就是用等於另一個陣列給值)
## 3.5.2 存取一個陣列的元素
- [ ] 3.30: 辨識出下列程式碼中的索引錯誤:
    ```
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 1; ix<=array_size; ++ix)
        ia[ix] = ix;
    ```
- [ ] 3.31: 寫一個程式來定義由十個int構成的陣列。賦予每個元素與其在陣列中所在位置相同的值
- [ ] 3.32: 將你在前面定義的陣列拷貝到另一個陣列。使用vector改寫你的程式。
- [ ] 3.33: 如果我們沒有初始化前面程式中的scores陣列，會發生什麼事？
    - 陣列在局部變量的時候，值是未定義，就有可能是任意值，直接++會發生不是預期結果
## 3.5.3 指標與陣列
- [ ] 3.34: 如果p1和p2指向同一個陣列中的元素，下列的程式碼會做什麼呢? 有p1或p2的值會讓這段程式碼變得不合法嗎?
    ```
    p1 += p2 - p1;  // 把p1移動到p2的位子，如果p2是end，那就不能解參考// 如果p1和p2的類型不同則會報錯
    ```
- [ ] 3.35: 使用指標寫一個程式來將一個陣列中的元素設為零。
- [ ] 3.36: 寫一個程式來比較兩個陣列的相等性。寫一個類似的程式來比較兩個vector。
## 3.5.4 C-Style的字元字串
- [ ] 3.37: 下列程式會做什麼事呢?
    ```
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp){
    cout << *cp << endl;
    ++cp;
    }
    // 沒null
    ```
- [ ] 3.38: 在本節中，我們注意到試著將兩個指標相加不只是非法的，也沒有意義。為何將兩個指標相加沒有意義? `// 指標裡面放位子，加兩個位子就沒意義阿= =`
- [ ] 3.39: 撰寫一個程式來比較兩個string。現在撰寫一個程式來比較兩個C-style字元字串的值。
- [ ] 3.40: 寫一個程式來定義從字串字面值初始化的兩個字元陣列。現在定義第三個陣列來存放那兩個陣列串接的結果。使用strcpy和strcat來將那兩個陣列拷貝到第三個中。
## 3.5.5 與舊有程式碼的介面
- [ ] 3.41: 寫出一個程式從一個int陣列初始化一個vector
- [ ] 3.42: 寫出一個程式來將由int所構成的一個vector拷貝到一個int陣列。
# 3.6 多維陣列
- [ ] 3.43: 寫出三種不同版本的程式來印出ia的元素。一個版本使用範圍for來管理迭代動作(a)，一個使用下標(b)，一個使用指標(c)。並且禁止使用auto和decltype. 
    ```
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11}
            }
    ```
- [ ] 3.44: 改寫前面的練習，使用一個型別別名作為迴圈控制變數的型別 
- [ ] 3.45: 再次改寫程式，使用auto。