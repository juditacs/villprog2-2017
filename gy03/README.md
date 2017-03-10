## Fordítás és futtatás

    g++ gumimaci.cpp -o gumimaci -Wall
    ./gumimaci persons.txt companies.txt

## Nagyobb tesztadat generálása

10000-szer egymás után írjuk a `persons.txt` fájlt a `persons_large.txt`
fájlba.

    for i in `seq 1 10000`; do cat persons.txt >> persons_large.txt; done

Érdemes kivenni a kommentet a `findBadRoot` függvény hívása elől, újrafordítani
és kipróbálni a nagy fájllal:

    ./gumimaci persons_large.txt companies.txt


## Szorgalmi

1. Készítsd el a `clean` függvények iteratív változatát.
1. Ellenőrizd, hogy az adatbázis nem tartalmaz-e irányított kört.
