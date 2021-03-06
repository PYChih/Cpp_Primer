# Ch06_Functions
###### tags: `C++ exercise`
[TOC]
# 6.1 函式基礎
- [ ] 6.1: 參數和引數之間的差異為何?
    ```
    // 參數就是定義在函數定義後面括號裡的，會在函數內使用。
    // 引數就是呼叫函數的時候傳遞給函數的，引數要跟參數一樣多
    ```
- [ ] 6.2: 指出下列函式何者是錯的，並描述原因，以及你會如何進行更正
    ```
    // a
    int f() {
        string s;
        // ...
        return s;
    }
    // b
    f2(int i) { }
    // c
    int calc(int v1, int v1) /* ... */ }
    // d
    double square(double x) return x * x;
    ```
- [ ] 6.3: 撰寫並測試你自己版本的fact。
- [ ] 6.4: 編寫一個與使用者互動的函式，請求輸入一個數字並產生該數字的階乘。從main呼叫此函式。
- [ ] 6.5: 撰寫一個函式回傳其引數的絕對值(absolute value)。
## 6.1.1 區域物件
- [ ] 6.6: 解釋參數、區域變數，以及區域static變數之間的差異。各自給出一個函式為例，說明他們何時可能會有用處。
    ```
    // 參數: 參數是自動物件，參數是在函式主體的範疇中定義的，因此它們會在函式終結時被摧毀。
    // 區域變數: 定義在函數內的變數叫做區域變數，如果配有初始器就會初始化，否則就是預設初始化(這代表內建型別的未初始化區域變數有未定義的值。)
    // 區域static變數: 在函式裡為變數加上static宣告可以成為區域static變數，值就會一直存在直到程式結束被摧毀。
    ```
- [ ] 6.7: 撰寫一個會在它第一次被呼叫時回傳0，然後之後每次呼叫就依序產生對應數字的函式。
## 6.1.2 函式宣告
- [ ] 6.8: 撰寫一個名為Chapter6.h的標頭檔，其中含有$6.1中的習題所寫的函式之宣告
## 6.1.3 個別編譯
- [ ] 6.9: 寫出你自己版本的fact.cc和factMain.cc檔案。這些檔案應該引入你來自前一節習題的Chapter6.h。使用這些檔案來了解你的編譯器如何支援個別編譯。
# 6.2 引數傳遞

## 6.2.1 藉由值傳遞引數
- [ ] 6.10: 使用指標撰寫一個函式來將兩個int的值對調(swap)。呼叫此函式並印出對調後的值來測試之。
## 6.2.2 藉由參考傳遞引數
- [ ] 6.11: 撰寫並測試接受一個參考的你自己版本的reset。
    ```
    // reset是一個把傳入的參數設為0的函數
    ```
- [ ] 6.12: 改寫$6.2.1中練習6.10的程式，使用參考而非指標來對調兩個int的值。你認為哪個版本比較容易使用，原因何在?
- [ ] 6.13: 假設T是一個型別的名稱，請解釋宣告為void f(T) 和宣告為void f(T&)的函式之間的差異
    ```
    // 一個會傳入型別T的引數的一個拷貝，一個會傳入型別T的引數的參考
    ```
- [ ] 6.14: 給出例子說明何時一個參數應該是參考型別。也給出參數不應該是參考的一個例子。
    ```
    // 當我們想要回傳多於一個的參數的時候，可以傳入幾個參考的引數達到類似效果；
    ```
- [ ] 6.15: 解釋find_char的每個參數之型別背後的原因。特別是，為什麼s是對const的一個參考，但occurs卻是一個普通的參考? 為什麼這些參數是參考，但char參數c卻不是?如果我們讓s是一個普通的參考，可能會發生什麼事?如果讓occurs是對const的一個參考會怎樣呢?
    ```
    1. 為什麼s是對const的一個參考?因為我們不想動到s，反過來說，我們希望改動occurs
    2. 為什麼這些參數是參考但char參數c卻不是?因為string可大可小，我們希望避免拷貝string，char似乎沒差
    3. 如果我們讓s是一個普通的參考，可能會發生什麼事?平常沒事，不小心改到有事
    4. 如果讓occurs是對const的一個參考會怎樣呢? 對const的參考代表我們沒辦法從參考去改到本來的值，這個函式就錯了。
    ```
## 6.2.3 const參數與引數
- [ ] 6.16:下列函式，雖然是合法的，但其用處比預期低。請找出並解除這個函式所受的限制:
    ```
    bool is_empty(string& s) { return s.empty(); }
    ```
    - 因為s是普通的參考，可是函數的行為並不會改動到s，所以應該要改成對const string的參考。
    - 限制在於，沒辦法直接傳入"一個字面值"，因為字面值不給參考，而且const string也沒辦法傳入
- [ ] 6.17:寫一個函式來判斷一個string是否含有任何大寫字母。寫一個函式來將一個string全都變為小寫。你在這些函式中使用的參數有相同的型別嗎? 若是，為什麼呢?若非，為何沒有。`// 判斷不需要改動，改為小寫需要改動`
- [ ] 6.18: 為下列每個函式撰寫宣告。當你編寫這些宣告時，使用函式名稱來表明函式所做的事。
    ```
    // a
    // 一個名為compare的函式，它會回傳一個bool並有兩個參數，這兩個參數都是對名為matrix的類別的參考
    // b
    // 一個名為change_val的函式，它會回傳一vector<int>迭代器，並接受兩個參數: 其一是一個int，而另一個是某個vector<int>的迭代器
    ```
- [ ] 6.19: 給定下列宣告，判斷哪些呼叫是合法的，而哪些是非法的。對於那些非法的呼叫，請解釋不合法的原因
    ```
    double calc(double);
    int count(const string &, char);
    int sum(vector<int>::iterator, vector<int>::iterator, int);
    //a
    calc(23.4, 55.1);  // 非法，引數2個參數1個
    //b
    count("abcda", 'a');
    //c
    calc(66);
    //d
    sum(vec.begin(), vec.end(), 3.8);
    ```
- [ ] 6.20: 什麼時候參考參數應該是對const的參考呢? 如果我們在一個參數可以是對const的參考之時讓它是一個普通的參考，那會發生什麼事呢?
    ```
    // 沒有要改到函數的時候，就設成const參考，比較大的影響是參考沒辦法參考字面值，引數也無法傳入const，需要轉換的temp物件也無法傳入
    ```
## 6.2.4 陣列參數
- [ ] 6.21: 撰寫一個函式，接受一個int和對int的一個指標，並回傳所接受的int值和指標所指的值之中比較大的那一個。你應該為這個指標使用什麼型別呢?
- [ ] 6.22: 寫一個函式來對調兩個int指標
- [ ] 6.23: 為本節所呈現的那些print函式寫出你自己的版本。呼叫那些函式中的每一個來印出定義如下的i與j:
    ```
    int i = 0, j[2] = { 0, 1 };
    ```
- [ ] 6.24: 解釋下列函式的行為。如果程式碼中有問題，請解釋問題為何，以及你會如何修正它們。
    ```
    void print(const int ia[10]) {  // 好像是傳入大小為10的陣列，然後其實是傳入指向const int的指針?
        for (size_t i = 0; i != 10; ++i) {
        cout << ia[i] << endl;
        }
    }
    ```
## 6.2.5 main: 處理命令列選項
- [ ] 6.25: 撰寫接受兩個引數的一個main函式。串階所提供的引數，並印出所產生的string。
- [ ] 6.26: 寫一個程式接受在本節中呈現的那些選項。印出傳入main的引數之值
## 6.2.6 帶有不定參數的函式
- [ ] 6.27: 撰寫一個函式，接受一個`initializer_list<int>`並產生該串列中元素的總和
- [ ] 6.28: 在具有ErrCode參數的那第二個版本的error_msg中，for迴圈中的elem之型別為何?
    ```
    void error_msg(ErrCode e, initializer_list<string> il) {
        cout << e.msg() << ": ";
        for (const auto &elem : il)
            cout << elem << " ";
        cout<< endl;
    }
    ```
- [ ] 6.29: 當你在一個範圍for中使用一個initializer_list，你會使用一個參考作為迴圈的控制變數嗎? 若是，為什麼呢? 如果不是，為何不呢?
    ```
    // initializer_list中的元素永遠都是const，所以一般來說沒必要特別設成參考
    ```
# 6.3 回傳型別與return述句
## 6.3.1 沒有回傳值的函式
## 6.3.2 回傳一個值的函式
- [ ] 6.30: 編譯前面所呈現的str_subrange版本，看看你的編譯器會如何處理我們提過的那些錯誤。
    ```
    bool str_subrange(const string &str1, const string &str2) {
        // 同樣的大小: 回傳正常的相等性測試
        if (str1.size() == str2.size())
            return str1 == str2;  // ok: ==return bool
        auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
        for (decltype(size) i = 0; i != size; ++i){
            if (str1[i] != str2[i])
                return ; // 錯誤: 沒有回傳值
        }
        //錯誤2: 控制流程可能會流出函式而沒有return
    }
    ```
- [ ] 6.31: 何時回傳一個參考是有效的呢?那麼對const的參考呢?
    ```
    // 正常回傳參考，要記得不能回傳對局部變量的參考，所以如果這個參考是本來就已經存在的值，就會有效
    // 如果我們不需要變動它的值，總是回傳const參考
    ```
- [ ] 6.32: 指出下列的函式是否合法。若是，解釋為何如此；如果不是，更正所有的錯誤並解釋之。
    ```
    int &get(int *array, int index) {return array[index];}
    int main() {
        int ia[10];
        for (int i = 0; i != 10; ++i)
            get(ia, i) = i; 
    }
    ```
- [ ] 6.33: 寫一個遞迴函式印出一個vector的內容
- [ ] 6.34: 如果factorial中的停止條件是if (val !=0) 會發生什麼事?
- [ ] 6.35: 對factorial的呼叫中，為什麼我們傳入val - 1 而非`val--  // 操作與讀取變量值的操作共存於同一表達式?`
## 6.3.3 回傳對陣列的一個指標
- [ ] 6.36: 宣告一個會回傳一個參考的函式，該參考指涉有十個string的一個陣列，而且不使用尾端回傳、decltype或型別別名。
- [ ] 6.37: 為前一個練習中的函式撰寫三個額外的宣告。其中一個應該使用型別別名，一個使用尾端回傳，而第三個使用decltype。你喜歡哪個形式? 為什麼呢?
- [ ] 6.38: 修改arrPtr函式，改回傳對陣列的一個參考。
# 6.4 重載的函式
- [ ] 6.39: 解釋下列每組宣告中第二個宣告的效果。指出何者是非法的，如果有的話。
    ```
    // a: 兩個const都是頂層的，在拷貝的時候會被丟棄，所以這是非法的
    int calc(int, int);
    int calc(const int, const int); 
    // b: 回傳的型別不一樣，也不給重載
    int get();
    double get();
    // c: 可以
    int *rest(int *);
    double *rest(double *);
    ```
## 6.4.1 重載與範疇

# 6.5 特殊用途的功能
## 6.5.1 預設引數
- [ ] 6.40: 下列哪個宣告是錯的? 為什麼呢?
    ```
    // a
    int ff(int a, int b=0, int c=0);
    // b: 給了預設引數之後，後面的全都要給喔
    char *init(int ht=24, int wd, char bckgrnd);
    ```
- [ ] 6.41: 下列哪個呼叫是非法的呢? 為什麼呢? 如果有的話，哪個是合法的，但不太可能是程式設計師所期望的，為什麼呢?
    ```
    char *init(int ht, int wd=80, char bckgrnd = ' ');
    // a: 非法，ht要給值
    init();
    // b: ht給24, wd給80
    init(24, 10);
    // c: 合法，可是'*'會被轉成int然後給wd
    init(14, '*')
    ```
- [ ] 6.42: 賦予make_plural(6.3.2)的第二個參數一個's'的預設引數。印出字詞success和failure的單數與複數版本來測試你的程式。
    ```
    // 如果ctr大於1，就回傳word的複數版本
    string make_plural(size_t ctr, const string &word, const string &ending) {
        return (ctr > 1) ? word+ending : word;
    }
    ```
## 6.5.2 行內與constexpr函式
- [ ] 6.43: 你會將下列哪個宣告和定義放在一個標頭中? 或放在源碼檔中? 請解釋原因
    ```
    // a: inline，放標頭
    inline bool eq(const BigInt&, const BigInt&) {...}
    //b: 這個是函式宣告也，也是放標頭吧
    void putValues(int *arr, int size);
    ```
- [ ] 6.44: 將6.2.2的isShorter函式改寫為inline
    ```
    bool isShorter(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
    ```
- [ ] 6.45: 重新檢視你為前面的練習所寫的程式，判斷它們是否應該被定義為inline。如果是，就那麼做。若非，請解釋它們為何不應該是inline。
- [ ] 6.46: 有可能將isShorter定義為一個constexpr嗎? 若是，就那麼做。如果沒辦法，請解釋原因。
    ```
    // constexpr需要引數和回傳值都是字面值，string不是
    ```
## 6.5.3 用於除錯的輔助功能
- [ ] 6.47: 修改你在$6.3.2的練習中寫的那個以遞迴印出一個vector內容的程式，讓它能夠條件式地印出其執行相關的資訊。舉例來說，你可能會在每次呼叫印出vector的大小。編譯並執行該程式，先開啟除錯來執行，然後關閉除錯再次執行。
- [ ] 6.48: 解釋這個迴圈所做的事，以及這是否為assert的良好用法:
    ```
    // 從標準輸入讀取字串到s，只要s不是sought就繼續讀取，當終止輸入assert為假，跳出錯誤訊息
    string s;
    while (cin >> s && s != sought) { }  // 空的
    assert(cin);
    ```
# 6.6 函式匹配
### 習題章節6.6
- [ ] 6.49: 候選函式是什麼? 合用的函式是什麼?
    ```
    // 候選函式: 在範疇下與被呼叫相同名稱的函式
    // 合用的函式: 引數相同(包含預設引數)並且型態匹配或至少可轉換 
    ```
- [ ] 6.50: 給定前面的f宣告，為下列每個呼叫列出合用的函式。指出哪個函式是最佳匹配，哪個呼叫因為沒有匹配或歧異而是非法的。
    ```
    // a
    f(2.56, 42);  // 這個有歧異
    // b
    f(42)
    // c
    f(42, 0)
    // d
    f(2.56, 3.14)
    ```
- [ ] 6.51: 寫出f的四個版本。每個函式都應該印出一個足以區別的訊息。檢查你在前一個練習的答案。如果你的答案是錯的，就研讀這一節，直到你了解為何答案是錯的為止。
    ```
    // error: call of overloaded ‘f(double, int)’ is ambiguous
    ```
## 6.6.1 引數型別之轉換
- [ ] 6.52: 給定下列宣告
    ```
    void manip(int, int);
    double dobj;
    // 下列呼叫中每個轉換的排位為何?
    // a: 'a'跟'z'透過提升的匹配
    manip('a', 'z');
    // b: 透過算數匹配
    manip(55.4, dobj);
    ```
- [ ] 6.53: 說明下列宣告組合中第二個宣告的效果。如果有的話，指出哪個是非法的
    ```
    // a: 從對整數的參考變成對const int的參考
    int calc(int&, int&);
    int calc(const int&, const int&);
    // b: 
    int clac(char*, char*);
    int calc(const char*, const char*);
    //c: 這個非法喔
    int calc(char*, char*);
    int calc(char* const, char* const);
    ```
# 6.7 指向函式的指標
- [x] 6.54: 為一個函式撰寫宣告，它有兩個int參數，並回傳一個int，然後再宣告一個vector，其元素具有這種函式指標型別
- [x] 6.55: 寫出四個函式，為兩個int值進行加減乘和除。將這些函式的指標儲存到你為前一個練習所寫的vector
- [x] 6.56: 呼叫那個vector中的每個元素，並印出它們的結果
