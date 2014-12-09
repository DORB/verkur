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
	* ~~Vantar show() fall fyrir vensl **ÓKS**~~
* ~~marry() fall og skipun (consoleui.cpp) **BB**~~
	* ~~Viltu nota leit eða lista?~~
		* ~~finna viðkomandi persónu~~
		* ~~finna viðkomandi tölvu~~
			* ~~**bamm** simple as dat~~
* ~~Breyta villutextum í cerr í stað cout~~ (consoleui.cpp)
* ~~Finna alvöru lista af tölvum~~
* ~~Finna alvöru lista af fólki til að tengja við tölvur~~
* ~~Laga sort til að sýna líka Computers **BB**~~
* ~~Láta gagnagrunn verða til ef hann er ekki til staðar (CREATE TABLE kóðar fyrir Programmers, Computers og tengitöfluna) (database.cpp) **MN**~~
* ~~Passa að .h skrár séu læsilegar, overloaduð föll saman osfrv. **RÝK**~~
* ~~Setja færslurnar að neðan inn í töflurnar og tengja saman réttar færslur.~~

## 9/12 - Það sem eftir er

* ~~Klára **show()** fallið og fylgifiska þess.~~
* ~~Laga **sort()** til að sýna líka Computers **BB**~~
* ~~Láta gagnagrunn verða til ef hann er ekki til staðar (CREATE TABLE kóðar fyrir Programmers, Computers og tengitöfluna) (database.cpp) **MN**~~
* Setja færslurnar að neðan inn í töflurnar og tengja saman réttar færslur.
* ***BÖGGPRÓFA!!! REYNA AÐ GERA VILLUR KRAKKAR, BARA ALVEG BRJÁLAÐ STUÐ!!!***

**Ef tími vinnst til væri geðveikt að:**
* implementa fuzzy search
* setja **sort** skipunina undir list skipunina
    * Sýna fyrst lista og fyrir neðan bjóða upp á að gera sort. Veit samt ekki aaalveg hvernig á að útfæra það nákvæmlega
* Væri algjörlega brjálað að henda inn hvort það séu Relations inn í list() skipunina. Það er kannski doltið dýrt, en kannski ekki. Kannski fyrir næstu viku? Ka segiði? Iggibara stuð?
* Spuddning með í næstu viku að refactora SQL skipanirnar í repository.cpp, þetta er ekki beint fallegt eins og er.
* Sorrí
	* með
		* mig
			* langaði
				* bara að
					* sjá
						* hvað
							* gerist
								* híhí, margir punktar.


Tölvur:

| Name                   | Type            | Year  | Built | Manneskjan bakvið                 |
|------------------------|-----------------|-------|-------|-----------------------------------|
| PlayStation            | Electronic	   | 1994  | Yes   | Ken Kutaragi                      |
| Original Machintosh	 | Electronic	   | 1984  | Yes   | Steve Jobs                        |
| GameBoy                |                 | 1989  | Yes   | Gunpei Yokoi                      |
| Programma 101          |                 | 1964  |       | Pier Giorgio Perotto              |
| Differential Engine    |                 | ????  | ???   | Charles Babbage                   |
| Analytical Engine	 | Mechanical	   | 1937  |       | Charles Babbage                   |
| UNIVAC                 | Vacuum Tubes	   | 1951  |       | J. Presper Eckert og John Mauchly |
| ENIAC                  | Vacuum Tubes	   | 1946  |       | J. Presper Eckert og John Mauchly |
| TRADIC                 | Transistor	   | 1954  | Yes   | Jean Howard Felker                |
| ABC                    | Electronic	   | 1942  | Yes   | John Atanasoff og Clifford Berry  |
| Z1 computer            |                 | 1936  |       | Konrad Zuse                       |
| Harvard Mark I computer| Electronic	   | 1944  |       | Howard Aiken og Grace Hopper      |


| Fólk:	| Fæðist: | Drapst: | Þjóðerni: |
|-------------------|------|------|----------------------|
| Ken Kutaragi | 1950 |	  - 	| Japanskur |
| Steve Jobs | 1955 | 2011 | Bandarískur |
| Gunpei Yokoi | 1941 | 1997 | Japanskur |
| Pier Giorgio Perotto | 1930 | 2002 | ítalskur |
| Charles Babbage | 1791 | 1871 | Enskur |
| J. Presper Eckert | 1919 | 1995 | Bandarískur |
| John Mauchly | 1930 | 1980 | Bandarískur |
| Jean Howard Felker | 1920 | 1994 | Bandarískur ? |
| John Atanasoff | 1903 | 1995 | Bandarískur |
| Clifford Berry | 1930 | 1963 | Bandarískur ? |
| Konrad Zuse | 1910 | 1995 | Þýskur |
| Howard Aiken | 1900 | 1973 | Bandarískur |
| Grace Hopper | 1906 | 1992 | Bandarískur |



