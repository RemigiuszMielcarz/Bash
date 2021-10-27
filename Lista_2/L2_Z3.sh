# Ćwiczenia z programem find:
# napisz skrypt znajdujący programem find wszystkie pliki o zadanym rozszerzeniu lub masce,
# które były modyfikowane w ciągu ostatnich N dni i tworzący z nich archiwum tar o zadanej nazwie.
# Mamy tu trzy parametry: maskę nazwy pliku, liczbę N i nazwę archiwum.
# Parametry są zadawane przez argumenty, to znaczy skrypt zawsze będzie wywołany z trzema parametrami.

maska=$1
N=$2
nazwatar=$3
echo "maska = $1"
echo "mtime = $2"
echo "nazwa archiwum -> $3"

x=$(find . -type f -name "$maska" -mtime -$N)
echo $x

tar -cjf $nazwatar $x

echo 

tar -xvf $nazwatar # Wypakowujemy zawartość z wyświetleniem plików

# -c – tworzy plik w formacie tar
# -j – włącza kompresję programem bzip2
# -f – określa nazwę pliku archiwum tar
