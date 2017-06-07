Домашно 4
За това домашно ще трябва да имплементирате Двоично Наредено Дърво, като ще трябва да поддържате операциите добавяне, изтриване и търсене на елемент в него. То трябва да работи за произволен тип данни, за който има оператори за сравнение.

Имплементираното дърво ще трябва да използвате в следната програма:

Като параметър от командния ред на програмата се подава име на файл (двоичен), за който всеки запис се състои от три полета – цяло число key (32 бита), следвано от размера на данните в байтове (32 бита) и символен низ data (не терминиран). От вас се изисква при получаване на файла да построите идеално балансирано дърво съдържащо тези данни. След това трябва да поддържате следните четири заявки, получавани от стандартния вход (дървото не е задължително да остане идеално балансирано след изпълнението им):

аdd <key> <data> - добавя в дървото елемент с посочените данни (низът data е до края на реда).
remove <key> <data> - извежда на стандартния изход true/false в зависимост дали елемент с дадените данни е намерен и премахнат.
removeall <key> - премахва от дървото всички елементи с дадения key и извежда на стандартния изход броя на премахнатите елементи.
search <key> <data> - извежда на стандартния изход true/false в зависимост дали елемент с дадените данни е намерен.
Вашата програма трябва да приключи изпълнението си когато достигне до край на файл в стандартния вход (представян с ctrl+z или ctrl+d при четене от клавиатура).
