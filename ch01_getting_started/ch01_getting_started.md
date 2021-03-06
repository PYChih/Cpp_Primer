# ch01_Getting_Started
###### tags: `C++Primer`
[TOC]
# 1.1 撰寫一個簡單的C++程式
## 1.1.1 編譯並執行我們的程式
### 程式原始碼檔案命名慣例
### 從命令列執行編譯器
```
g++ -o prog1 prog1.cc
```
```
g++ prog1.cc -o prog1
```
==在UNIX系統上，我們以下列命令取得狀態==:
```$echo $?```
### 習題章節1.1.1
- 練習1.1: 查閱你編譯器的說明文件，找出它所使用的檔案命名慣例。編譯並執行前面的main程式
    ```g++ --help```
    ```g++ -o prog1 prog1.cc```
- 練習1.2: 把程式改成回傳值-1。回傳值-1經常被用來表示程式執行失敗。重新編譯並再執行你的程式，看看你的系統如何處理來自main的這種錯誤失敗指示器。
```echo $?```返回255
## 1.2 初步認識輸入/輸出
- C\+\+語言並沒有定義用來進行輸入或輸出的任何述句。取而代之，C\+\+包含了一個擴充性的標準程式庫來提供IO機能。iostream程式庫
### 標準輸入與輸出物件
- 四個IO物件:
    - 型別為istream名稱是cin的物件
    - 型別為ostream名稱是cout的物件
    - 其他ostream物件: cerr和clog
### 用到IO程式庫的一個程式
```
#include <iostream> // 用到某個程式庫機能的每個程式都必須引入(include)它關聯的標頭
int main()
{
    std::cout << "Enter two numbers: "<< std::endl;
    int v1==0, v2==0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1+v2 << std::endl;
    return 0;
}
```
### 寫入資料流
- main主體第一個述句執行了一個運算式
- 這個運算式使用輸出運算子``<<``
- ``<<``運算子接受兩個運算元: 左手邊的運算元必須是一個ostream物件，右手邊的運算元則是要印出的一個值。此運算子會把給定的值印在給定的ostream上。
- 輸出運算子的結果是其左手邊的運算元(所以cout<<"Hello"; 的輸出是cout: 一個ostream物件)
- ``"hello"``是一個字串字面值
- endl是一個特殊值，叫做一個manipulator(操作符)。寫入endl有結束目前文字行並且==排清關聯裝置緩衝區的效果==。
### 使用來自標準程式庫的名稱
- 使用std::cout而不是cout。
- std::這個前綴指出名稱cout和endl定義在名為std的命名空間中。
- 標準程式庫定義的所有名稱都在std命名空間中
- ``::``是範疇運算子
### 讀取自一個資料流
### 完成此程式
### 習題章節1.2
- 練習1.3: 寫一個程式在標準輸出印出Hello, World。
- 練習1.4: 我們的程式用到加法運算子+來相加兩個數字。寫一個程式，使用乘法運算子``*``印出乘積
- 練習1.5: 我們將輸出寫為一個大型述句。改寫這個程式，使用分開的述句來印出個個運算元。
- 練習1.6: 解釋下列程式片段是否合法。
    ```
    std::cout << "The sum of " << v1;
              << " and " << v2;
              << " is " << v1 + v2 << std::endl;
    ```
    如果這個程式是合法的，它會做什麼? 如果不合法，那是為什麼呢?你會如何修正它?
## 1.3 關於註解
### C++中的註解種類
- ``//單行註解``
- 成對註解:
    ```
    /*
    *成對註解
    *書上風格
    *以一個星號作為註解每一行的開頭
    */
    ```
### 成對註解不能內嵌
```
//因此建議在我們想要忽略的片段
//的每一行開頭插入單行註解
```
### 習題章節1.3
- 練習1.7: 編譯錯誤地內嵌了註解的一個程式
- 練習1.8: 指出下列輸出述句何者是合法的(如果有的話):
    ```
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */;
    std::cout << /* "*/" /* "/*" */;
    ```
     預測了會發生什麼事之後，編譯含有上述各個述句的一個程式來驗證你的答案。更正你所遇到的任何錯誤
# 1.4 流程控制
## 1.4.1 while述句
### 習題章節1.4.1
- 練習1.9: 寫一個程式用while將50到100的數字加總。
- 練習1.10 : 除了會加1到其運算元的++運算子，另外還有一個會減1的遞減運算子(--)。使用遞減運算子寫一個while，印出從十遞減到零的數字
- 練習1.11: 寫個程式提示使用者輸入兩個整數。印出由這兩個整數所指定的範圍內每一個數字
## 1.4.2 for述句
```
# include <iostream>
int main()
{
    int sum = 0;
    // 加總從1到10的值，包括兩端
    for (int val = 1; val <=10; ++val)
        sum += val ; //等同於sum = sum + val
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
    return 0;
}
```
- 每個for述句都有兩個部分: 一個標頭及一個主體。
- 標頭控制主體執行的次數。
- 標頭本身由三個部分構成:
    - 一個init-statement、
    - 一個codition
    - 以及一個expression
- 變數val只存在於for之內，你無法在此迴圈結束後使用val
- 整個執行流程:
    1. 創建val並將之初始化為1。
    2. 測試val是否小於或等於10。如果測試通過，就執行for主體。如果測試失敗，就退出迴圈，繼續執行接在for主體後的第一個述句。
    3. 遞增val
    4. 重複第2步的測試
- 重訪編譯
    1. 常見語法錯誤
        - main的參數列少了)
        - endl候用了冒號而非分號
        - 字串少了引號包圍
        - 缺少第二個輸出運算子
        - return少了分號
    2. 型別錯誤
        - 傳入一個字串值給int
    3. 宣告錯誤
        - 忘記使用std::
        - 拼錯識別字的名稱
### 習題章節1.4.2
- 練習1.12: 下列for迴圈會做什麼呢? sum的最終值是什麼呢?
    ```
    int sum = 0;
    for (int i = -100; i<=100; ++i)
        sum +=1;
    ```
- 練習1.13: 使用for迴圈改寫$ 1.4.1的頭兩個練習
- 練習1.14: 對照比較使用for的迴圈與使用while的迴圈。他們各有什麼優缺點呢?
- 練習1.15: 寫一個程式，其中含有後面補充說明***重訪編譯***中所討論的常見錯誤。讓自己熟悉編譯器產生的那些訊息。
## 1.4.3 讀取未知數量的輸入
```
int value = 0;
while (std::cin >> value)
```
- 當我們使用一個istream作為條件，效果就等於測試該資料流的狀態。
- 若該資料流是有效的，也就是說，該資料流尚未遭遇錯誤，那麼測試就成功通過。
- 一個istream會在碰到end-of-file(EOF)或遇到無效輸入時變得無效。
- 處於無效狀態的istream會導致條件產出false。
- 在UNIX系統上，通常以``ctrl+d``代表檔案結尾。
### 習題章節1.4.3
- 練習1.16: 寫出你自己的程式，從cin讀取一組整數並印出他們的總和
## 1.4.4 if述句
- 關鍵概念
    - 對於格式化C或C++程式的正確之道為何，有無限的爭議產生。我們認為，並不存在單一種正確的風格，但維持前後一致有其價值。
    - 我們通常會讓用來界定函式的大括號字自一行。
    - 我們也會將複合的IO運算式縮排，以對齊運算子。
### 習題章節1.4.4
- 練習1.17: 如果輸入的值全都相同，那麼本節中的程式會發生什麼事呢？如果沒有重複的數字呢？
- 練習1.18: 編譯並執行本節的程式，賦予它相同的值作為輸入。給它不重複的數字，然後再次執行它。
- 練習1.19: 修改你為$ 1.4.1的練習所寫的那個會印出一個範圍的數字的程式，讓它能夠處理第一個數字小於第二個的輸入。

# 1.5 類別簡介
- C++的設計所專注的一個重點正是如何讓定義出來的類別型別運作起來跟內建型別一樣自然。
- 要使用一個類別，我們得知道三件事情：
    - 它的名稱為何?
    - 它定義於何處?
    - 它支援什麼運算?
- 對我們的書店問題而言，我們會假設類別的名稱為Sales_item，以及它已經定義於名為Sales_item.h的標頭檔中。
- 要使用程式庫的機能，我們必須引入關聯的標頭。
- 我們也透過標頭來取用為我們自己的應用所定義的類別。
- 我們所寫的標頭檔通常會有後綴.h
```
#include <iostream>
#include "Sales_item.h"
```
- 內建函式庫用<>，自訂的用""
## 1.5.1 Sales_item類別
```
Sales_item item;
```
- item是型別為Sales_item的一個物件。
- 除了能夠定義Sales_item型別的變數，我們還能:
    - 呼叫名為isbn的函式從一個Sales_item物件擷取ISBN
    - 使用輸入``>>``與輸出``<<``運算子來讀取或寫入型別為Sales_item的物件
    - 使用指定運算子``=``來將一個Sales_item物件指定給另一個。
    - 使用加法運算子來相加兩個Sales_item物件。
    - 使用複合指定運算子來將一個Sales_item物件加到另一個。

- 關鍵概念: 類別定義行為
    Sales_item類別的作者定義了此類別之物件能夠進行的所有動作。

### 讀取或寫入Sales_items
```
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item book;
    std::cin >> book;
    std::cout << book << std::endl;
    return 0;
}
```
### 相加Sales_item
### 使用檔案重導
- 假設我們已經編譯了一個叫做addItems的可執行檔
    ```
    $ addItems <infile >outfile
    ```
- 會從名為infile的檔案讀取交易紀錄，並將其輸出寫到目前目錄中一個名叫outfile的檔案。
- 讀是<，然後cout是<<
### 習題章節1.5.1
- 練習1.20: [這裡](http://www.informit.com/title/0321714113) 含有Sales_item.h，位在第一章的程式碼目錄中。將那個檔案複製到你的工作目錄。用它來撰寫一個程式，讀取一組書籍販售紀錄，再將每筆交易紀錄寫到標準輸出。
- 練習1.21:寫一個程式，讀取兩個具有相同ISBN的Sales_item物件，並產生它們的總和。
- 練習1.22: 寫一個程式讀取具有相同ISBN的數筆交易紀錄。寫出所讀取的所有交易紀錄之總和。
## 1.5.2 成員函式初探
### 什麼是成員函式?
### 習題章節1.5.2
- 練習1.23: 寫一個程式，讀取數筆交易紀錄，並計數每個ISBN出現幾次。
- 練習1.24: 給予前一個程式代表多個ISBN的多筆交易紀錄來測試它。每個ISBN的交易紀錄應該歸為同一組。
## 1.6 Bookstore程式
### 習題章節4.6
- 練習1.25: 使用網站上的Sales_item.h標頭，編譯並執行本節中的書店程式。