# Задача 3. Операции над углами

### Описание
Иногда бывает необходимо сохранить созданные лямбда-функции. Для этого есть тип [`std::function`](https://en.cppreference.com/w/cpp/utility/functional/function) .
В этой задаче вам дан массив углов. Нужно вывести их синус и косинус. Сделать это необходимо так, чтобы при необходимости произвести новые операции с углами, например, если захотим посчитать тангенсы, не изменять код вывода.

```C++
for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
                function(angle);
        std::cout << std::endl;
}
```

### Пример логической работы программы
```
[Входные данные]: 30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180 // перевод из градусов в радианы
[Выходные данные]:
0.523599: sin: 0.5 cos: 0.866025
1.0472: sin: 0.866025 cos: 0.5
1.5708: sin: 1 cos: 2.67949e-08
```

#### Подсказки

Не читайте этот раздел сразу. Попытайтесь сначала решить задачу самостоятельно :)

<details>

<summary>Что использовать для решений.</summary>
Нужно правильно понять, какая сигнатура будет у лямда-функций, и правильно их сохранить
