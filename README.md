# villprog2-2017

A villamosmérnöki [A programozás alapjai 2 (VIAUAA00)](https://www.aut.bme.hu/Course/VIAUA116) kettő tárgy gyakorlatanyagai

# Eredmények

[KZH eredmények](http://avalon.aut.bme.hu/~judit/results/G11_prog2_kzh_2017.tsv)

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

## Az én környezetem

A gyakorlatokon a VIM szövegszerkesztőt használom.
A VIMhez létezik egy beépített tutorial, ami a `vimtutor` parancs beírásával
érhető el, valamint online megtalálható egy hasonló
[tutorial](http://openvim.com/), ami rövid leckéken keresztül mutatja be a VIM
alapjait.
Kódkiegészítéshez a
[YouCompleteMe](https://github.com/Valloric/YouCompleteMe)-t használom.
Debuggolásra több lehetőség áll rendelkezésre:

1. VIMen belül debuggolni, erről
   [itt](http://stackoverflow.com/questions/3536600/do-you-debug-c-code-in-vim-how)
   írnak,
1. külön debuggert használni, pl. gdb, illetve annak grafikus frontendjei.

A terminálom [Solarized palettát](http://ethanschoonover.com/solarized) és
[Adobe Source Code Pro](https://github.com/adobe-fonts/source-code-pro)
betűtípust használ, amik a legtöbb Linux disztribúción elérhetőek, illetve
csomagkezelővel telepíthetőek.

Több terminálablak kezeléséhez a [tmux](https://tmux.github.io/) nevű terminál
multiplexert használom.
