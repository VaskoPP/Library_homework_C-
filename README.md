## Проект: Library System (Библиотечна система)

## Описание

Този проект представлява малка C++ библиотечна система, изградена от няколко взаимосвързани класа — **Author**, **Book**, **Member**, **Loan** и **Library**.

Целта е да се демонстрират ключови концепции от обектно-ориентираното програмиране:

- конструктори и списъци за инициализация  
- Rule of 5 / Rule of 3  
- капсулация и валидация на данни  
- статични членове  
- const-коректност  
- работа с `vector` и обекти  


## Структура на проекта

```
library/
├── Author.h
├── Author.cpp
├── Book.h
├── Book.cpp
├── Member.h
├── Member.cpp
├── Loan.h
├── Loan.cpp
├── Library.h
├── Library.cpp
├── main.cpp
└── README.md
```



## Компилация и изпълнение

Отворете терминал в директорията на проекта и компилирайте:

```bash
g++ -std=c++17 -Wall -Wextra Author.cpp Book.cpp Member.cpp Loan.cpp Library.cpp main.cpp -o library
./library
```

##  Примерен изход

```
<img width="504" height="132" alt="Screenshot 2025-12-01 at 21 37 23" src="https://github.com/user-attachments/assets/97026c0b-9945-4acc-9adc-b48a7afc3916" />

```


## Класове

### Клас Author

Представя автор на книга.


## Членове
- `string name`
- `int birthYear`


## Характеристики:
- конструктор по подразбиране  
- параметризиран конструктор с валидация  
- setter с проверки  
- `to_string()` метод  



### Клас Book
Представя книга.


## Членове:
- `string title`
- `Author author`
- `int year`
- `double price`
- `string isbn`
- `static int totalBooks`


## Характеристики:
- Rule of 5 (копиране и преместване са = default)
- валидации при year и price  
- `to_string()`  
- статистика на създадените книги  


### Клас Member
Представя регистриран читател.


## Членове:
- `string name`
- `string memberId`
- `int yearJoined`


## Функции:
- конструктор с валидация  
- `to_string()`  



### Клас Loan
Представя заем на книга.


## Членове:
- `string isbn`
- `string memberId`
- `string startDate`
- `string dueDate`
- `bool returned`


## Функции:
- валидация на датите  
- `markReturned()`  
- `isOverdue()`  
- `to_string()`  


## Клас Library:
Управлява цялата система.


## Членове:
- `vector<Book> books`
- `vector<Member> members`
- `vector<Loan> loans`


## Методи:
- добавяне на книги и читатели  
- заемане и връщане на книги  
- проверка за наличност  
- търсене по автор  
- системна информация (`to_string()`)  



## main.cpp

Файлът демонстрира работа с цялата система — добавяне на книги, заемане, връщане, търсене по автор и статистика.



## Автор
Име: Васил Петков  
Номер: 22502  
Курс:Обектно-ориентирано програмиране (C++)  
Дата: 2 декември 2025 



