# villprog2-2017

A villamosmérnöki A programozás alapjai 2 (VIAUAA00) kettő tárgy gyakorlatanyagai

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
