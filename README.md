# villprog2-2017

A villamosmérnöki [A programozás alapjai 2 (VIAUAA00)](https://www.aut.bme.hu/Course/VIAUA116) kettő tárgy gyakorlatanyagai


# Hogyan tudom futtatni az órai kódokat?

Az órai példák Linux rendszeren futottak, de a forráskódoknak más platformokon
is működniük kell.
A felhasznált egyéb parancsok (grep, head, seq) megtalálhatók minden sztenderd
Linux disztribúcióban.

[Parancssori argumentumok megadása Visual Studio
alatt](http://stackoverflow.com/questions/3697299/passing-command-line-arguments-in-visual-studio-2010).

Mappánként található egy rövid leírás az órán használt parancsokról.

A példák sokszor használnak csővezetékeket vagy angolul pipe-okat.
Erről egy rövid leírás található
[itt](http://ryanstutorials.net/linuxtutorial/piping.php).

## Fordítás egy forrásfájl esetén

    g++ mysource.cpp -Wall -o myprogram

A paraméterek jelentése:

|  Param | sdf |
| ----- | ----- |
| `g++` | fordítóprogram neve |
| `mysource.cpp` | forrásfájl neve, ezt kell megváltoztatni a saját fájlodra |
| `-Wall` | warningok kiírása |
| `-o myprogram` | lefordított állomány neve, tetszőleges |

Több forrásfájl esetén mindegyiket meg kell adni a `gcc`-nek.
