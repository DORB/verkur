# TODO

* ADD function: Þurfum að implementa "INSERT INTO Programmers VALUES..."  SQL skipun
* DEL function: Þurfum að implementa "DELETE FROM Programmers VALUES..." SQL skipun
* LIST function: Þurfum að implementa "SELECT * FROM Programmers" SQL skipun
* FIND function: Þurfum að implementa "SELECT * FROM Programmers WHERE name LIKE = ..." SQL skipun
* SORT function: Þurfum að implementa "SELECT * FROM Programmers ORDER BY name" SQL skipun

## 5/12

* ~~Laga << overloadið fyrir Person og Computer þannig að það skrifist út á sama formi og þegar show() skipunin er notuð~~
* ~~Klasi fyrir database~~
* ~~Tékka á del function, alveg eins og add~~

## 7/12 - Það sem eftir er að gera

* ~~**Tengitafla** með færslum~~
* ~~Sýna tengda (list relate eða r) (consoleui.cpp)~~
	* Vantar show() fall fyrir vensl
* marry() fall og skipun (consoleui.cpp)
	* Viltu nota leit eða lista?
		* finna viðkomandi persónu
		* finna viðkomandi tölvu
			* **bamm** simple as dat
* ~~Breyta villutextum í cerr í stað cout~~ (consoleui.cpp)
* ~~Finna alvöru lista af tölvum~~
* ~~Finna alvöru lista af fólki til að tengja við tölvur~~
* Láta gagnagrunn verða til ef hann er ekki til staðar (CREATE TABLE kóðar fyrir Programmers, Computers og tengitöfluna) (database.cpp)
* Passa að .h skrár séu læsilegar, overloaduð föll saman osfrv.

Ef tími vinnst til væri geðveikt að
* implementa fuzzy search
* setja sort skipunina undir list skipunina
    * Sýna fyrst lista og fyrir neðan bjóða upp á að gera sort. Veit samt ekki aaalveg hvernig á að útfæra það nákvæmlega
