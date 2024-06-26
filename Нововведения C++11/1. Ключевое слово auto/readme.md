# Ключевое слово «auto»

Ключевое слово «auto» в C++11 позволяет компилятору автоматически выводить тип переменной на основе значения, с которым эта переменная была проинициализирована.

В старых версиях C++ требовалось явно указывать тип переменной при ее объявлении, например:

`int x = 10` // переменная x типа int, 10 - её значение 

В C++11 вместо явного указания типа можно использовать ключевое слово «auto», которое позволяет компилятору самостоятельно определить тип переменной на основе её значения, например:

`auto integer_value = 5;` // у integer_value - тип переменной int 


`auto floating_point_value = 4.0;` // у floating_point_value - тип double


`auto my_object = new my_class();` // у my_object - тип my_class


## «Auto» будет работать и с возвращаемыми значениями функций. 


Например, функция add, которая возвращает int. В этом случае можно использовать «auto», чтобы принять этот результат:

`int add(int first, int second) {`


   ` return first + second;`

   
`}`


`auto result = add(3, 4);`


## «Auto» удобно использовать, когда мы не знаем, какой тип будет иметь переменная.


Для примера рассмотрим функцию без определённого типа данных. 
Тип данных a и b, а также возращаемого значения будет определяться в зависимости от того, какие параметры мы туда передадим.

![Image alt](https://github.com/netology-code/cppl-homeworks/blob/main/common/5.PNG)


Если мы укажем целые числа, например, 3 и 5, то тип данных (T) будет int.

![Image alt](https://github.com/netology-code/cppl-homeworks/blob/main/common/8.PNG)

![Image alt](https://github.com/netology-code/cppl-homeworks/blob/main/common/7.PNG)


Если мы укажем числа с точкой, например, 3.0 и 5.3, то тип данных (T) будет duble.

![Image alt](https://github.com/netology-code/cppl-homeworks/blob/main/common/9.PNG)

![Image alt](https://github.com/netology-code/cppl-homeworks/blob/main/common/10.PNG)


## В C++11 нет возможности применения «auto» для типа отображаемых данных.


Вместо этого, вам необходимо указать конкретные типы параметров.

![Image alt](https://github.com/netology-code/cppl-homeworks/blob/main/common/63PNG.PNG)


Однако, уже в C++14 применение «auto» становится возможно.

## Чем полезно использование «auto»:

- Улучшает абстракцию: принуждает думать в терминах интерфейсов, а не реализаций. Мы поднимаемся на уровень выше, когда думаем не о самом объекте, а том, как его можно применить.
- Заставляет инициализировать переменные, что избавляет от ситуаций, когда в переменной лежит что-то не то.
- Безопасность и быстрота: нельзя опечататься в имени типа или случайно использовать другой, к которому есть неявное приведение.
- Стабильность: если тип функции изменится, то меньше случаев, когда код придется менять.
- Также «auto» сокращает код, часто помогает при работе с std.

## Рассмотрим удобство «auto» для сокращения кода: 

Есть прототип некоторой функции:

`std::map<std::string, std::vector<int>> some_func()` 

И каждый раз результат выполнения функции нужно будет сохранять в переменную типа:

`std::map<std::string, std::vector<int>>`

А можно написать короче:

`auto result = some_func()` 

## Итак, важные особенности использования «auto»:

- Переменная «auto» должна быть проинициализирована.
- Переменная «auto» не может быть членом класса. Компилятор должен иметь информацию о типе, чтобы выделить память для объекта класса и правильно выполнять доступ к его полям и методам. Поэтому требуется явное указание типа для членов класса, а использование «auto» не допускается.
- До С++14 переменная «auto» не может быть параметром функции.
