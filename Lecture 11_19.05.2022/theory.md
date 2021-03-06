 # Алгоритм Форда-Беллмана. Алгоритм Левита.
 
<ins>Для задач по типу сети:</ins>
(n — количество вершин, m — количество рёбер)
1. Поиск в ширину / BFS — О(n + m);
2. Алгоритм Дейкстры — O(n * log(n) + m);
3. Алгоритм Форда-Беллмана — O(n * m);

- Если какая-то задача решается с помощью 1, 2, то её можно решить и с помощью алгоритма 3;
- Не смотря на плохую асимптотику, алгоритм 3 используется — для задач с отрицательными весами рёбер, но надо исключить отрицательный цикл (= цикл отрицательного веса);
<br></br>

<ins>Имеем 3 вида задач:</ins>
1. Построение кратчайшего пути от одной вершины до одной;
2. Построение дерева кратчайших расстояний от одной до всех (решается с помощью 3 алгоритмов выше, с помощью этой задачи решается и задача 1);
3. От всех вершин до всех достижимых (алгоритм Флойда);
<br></br>

<ins>Общиая схема всех 3 алгоритмов:</ins>
1. Инициализация;
2. Выбор вершины;
3. Просмотр дуг выбранной вершины;
4. Улучшение дерева;
- Используем 3 множества:
  - T — Просмотренные и помеченные;
  - Q — Не просмотренные, но помеченные (их мы "трогаем"), пока ищем пути из просматриваемых;
  - S — Не просмотренные и не помеченные;
- Для алгоритма Дейскстры в качестве Q используется set/куча, в случае BFS и Форда-Беллмана — очередь/queue;
- Плохая асимптотика Форда-Беллмана обусловлена тем, что вершины могут по нескольку раз переходить из T в Q и обратно:
  - Мы можем строить "ложные" деревья кратчайших расстояний из какой-то вершины, а затем находить более эффективный путь до данной варшины и пересчитывать всё дерево;
  - Такой алгоритм конечен, так как мы избегаем отрицательного цикла, у нас гарантировано построение дерева кратчайших расстояний, и на каждом улучшении количество рёбер в пути у нас увеличивается;
  - В дереве кратчайших расстояний у нас не больше, чем (n - 1) ребро, это соотвествует n фазам (= n вершинам в ряд, по 1 на фазу), на каждой из них мы можем рассмотреть максимум m "потенциальных" рёбер; 
<br></br>

Примеры 2 реализаций Беллмана-Форда в:
- `bellman-ford-1.cpp` (не ориентированный граф, также "алгоритм Левита");
- `bellman-ford-2.cpp` (работает с ориентированным графом, рассматриваем рёбра именно в формате from->to).

