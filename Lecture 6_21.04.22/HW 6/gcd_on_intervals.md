## НОД на подотрезках

Реализуйте структуру данных для эффективного вычисления НОД нескольких подряд идущих элементов массива.
<br></br>
### Формат ввода

В первой строке вводится одно натуральное число _N_ (1 ≤ _N_ ≤ 100000) – количество чисел в массиве.

Во второй строке вводятся _N_ чисел от 0 до 100000 – элементы массива.

В третьей строке вводится одно натуральное число _K_ (1 ≤ _K_ ≤ 30000) — количество запросов на вычисление НОД.

В следующих _K_ строках вводится по два числа — номера левого и правого элементов отрезка массива (считается, что элементы массива нумеруются с единицы).<br></br>
### Формат вывода

Для каждого запроса выведите НОД всех чисел соответствующего участка массива. Числа выводите в одну строку через пробел.
<br></br>
#### Пример 1

<ins>Ввод:</ins><br>
5<br>
2 2 2 1 5<br>
2<br>
2 3<br>
2 5<br>

<ins>Вывод:</ins><br>
2 1
<br>
#### Пример 1

<ins>Ввод:</ins><br>
10<br>
18 16 20 2 53 57 39 97 21 59<br>
10<br>
3 10<br>
1 10<br>
3 4<br>
9 10<br>
8 10<br>
5 8<br>
6 7<br>
5 8<br>
1 10<br>
7 9<br>

<ins>Вывод:</ins><br>
1 1 2 1 1 1 3 1 1 1
<br>