#Exercise 13.21 
> 你認為TextQuery與QueryResult類別需要定義它們自己版本的拷貝控制成員嗎?如果是，為什麼呢?如果不是，為何不?實作你認為這些類別需要的任何拷貝控制運算。
    
- 因為兩個類別依靠shared_ptr進行資源共享，且當計數降為0會自動釋放記憶體，因此可以不定義拷貝控制成員