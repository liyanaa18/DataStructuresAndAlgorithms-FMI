Дадени са ви две изречения. Напишете програма, която казва дали с думите от първото може да направите второто изречение, ако ви е позволено само да премахвате и да пренареждате думи.

Input Format

Първо се въвеждат броят тестове, за които ще направите проверката и за всеки тест:

На първия ред се въвеждат 2 числа - броят на думите съответно в първото и във второто изречение.

На втория ред се въвеждат думите от първото изречение разделени с интервал.

На третия ред се въвеждат думите от второто изречение разделени с интервал.

Бележка: За дума приемайте всеки въведен стринг(независимо дали елементите му са само латински букви)

Constraints

Броят на тестовете не надвишава 10
Размерът на изреченията не надвишава 30000
Размерът на думите не надвишава 10

Output Format

За всеки тест:

Ако от първото изречение може да се състави второте - трябва да се отпечата "Yes" на нов ред.

В противен случай - "No" на нов ред.

Sample Input 0

1
6 4
kyde sa kaisiite ? na masata
na masata sa kaisiite

Sample Output 0

Yes

Sample Input 1

1
5 3
tam tam na masata e
kaisii just ahead

Sample Output 1

No
