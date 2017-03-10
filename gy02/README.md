## argv_perfect

~~~
g++ argv_perfect_numbers.cpp -Wall -o perfect
./perfect 2
~~~

Kimenet:

~~~
6
28
~~~

## argv_prime

Az összes parancssori argumentumról megmondja, hogy prímszám-e.

~~~
g++ argv_prime.cpp -Wall -o prime
./prime 3 4 5 13 9
~~~

Kimenet:

~~~
3 prim
4 nem prim
5 prim
13 prim
9 nem prim
~~~

#### Érdekesség: első N prím kiírása

Számtartomány generálása pl. 1-től 5-ig:

~~~
seq 1 5
~~~


Ezeket megadhatjuk argumentumként a prímvizsgálónak:

~~~
./prime `seq 1 5 `
~~~

Kimenet:

~~~
1 nem prim
2 prim
3 prim
4 nem prim
5 prim
~~~

A `grep` programmal szűrhetünk olyan sorokra, amikben **nem** forul elő a "nem"
szó, tehát prímek:

~~~
./prime `seq 1 5` | grep -v nem
~~~

Kimenet:

~~~
2 prim
3 prim
5 prim
~~~

Csak a számokat megőrizve:

~~~
./prime `seq 1 5` | grep -v nem | cut -f1 -d" "
~~~

Kimenet:

~~~
2
3
5
~~~

## insertion_sort

Az argumentumként kapott számokat sorba rendezi.
Tetszőleges számú argumentumot kaphat.

~~~
g++ insertion_sort.cpp -o insertion_sort
./insertion_sort 2 0 13 5
~~~

#### Random számok megadása

Többféleképpen lehet random számokat generálni BASH-ban, de most használjuk
megint a `seq` parancsot.

~~~
seq 1 15 | shuf
~~~

A `shuf` parancs összekeveri a bemeneten kapott számokat, aminek az első 8
sorát vesszük a `head -8` parancs segítségével:

~~~
seq 1 15 | shuf | head -8
~~~

A kimenet random, egy lehetséges változat:

~~~
5
6
14
2
11
1
13
9
~~~

Ezt fel tudjuk ismét használni a rendező programunk argumentumaként:

~~~
./insertion_sort `seq 1 15 | shuf | head -8`
~~~

A kimenet pedig (ismét egy lehetséges változat a sok közül):

~~~
1 3 4 5 7 8 12 14
~~~


## test_reference_vs_value

~~~
g++ test_reference_vs_value.cpp -o tv
~~~

Az első argumentum alapján dönti el, hogy a referenciás vagy az érték szerinti
paraméterátadós függvény hívja-e.
Ezután a függvény rekurzívan hívja önmagát, amíg a stack meg nem telik.
Érték szerinti átadás esetén ez sokkal hamarabb bekövetkezik.

Referencia szerint (vigyázat, hosszú kimenet):

~~~
./tv R
~~~

Érték szerint (itt nincs nagy veszély):

~~~
./tv V
~~~

## osztalyzatok

~~~
g++ osztalyzatok.cpp -Wall -o osztalyzatok
./osztalyzatok
~~~

Kimenet:

~~~
Leggyakoribb pontszam: 1, 3x fordul elo
~~~

### Szorgalmi

Írd át úgy az osztályzatok programot, hogy a parancssori argumentumokból töltse
fel a zh eredményeket.
Például az alábbi eredmények esetén:

~~~
./osztalyzatok 12 13 34 34 12
~~~

a következő kimenetet várjuk:

~~~
Leggyakoribb pontszam: 12, 2x fordul elo
~~~
