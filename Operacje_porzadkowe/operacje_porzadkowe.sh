# Remigiusz Mielcarz 252887 30.11.2019r.

# Treść zadania nr. 6:

# Skrypt wykonujący operacje porządkowe na plikach ze zdjęciami i przygotowujący na ich podstawie archiwum)
# Napisz skrypt, który ze wskazanego katalogu:
# skopiuje wszystkie pliki ze zdjęciami w formacie JPEG/PNG
# zmieni skopiowanym plikom rozszerzenia na pisane małymi literami, 
# zastąpi występujące w nazwach plików spacje znakiem podkreślenia,
# zmieni rozmiar zdjęć do wskazanego argumentem podanym w wywołaniu skryptu 
# i w końcu utworzy archiwum z tak przygotowanych plików.

echo Podaj sciezke folderu wejsciowego
read sciezka
cd $sciezka
echo Podaj sciezke folderu wyjsciowego
read sciezka2

# Kopiowanie
for nazwa in *JPEG
do
cp $nazwa $sciezka2/$nazwa
done

for nazwa in *PNG
do
cp $nazwa $sciezka2/$nazwa
done

cd $sciezka2
echo podaj wartosc nowej szerokości pliku
read 1
echo podaj wartosc nowej wysokości pliku
read 2

# Zamiana spacji na _
for nazwa in *JPEG
do
echo $nazwa| tr " " "_" | xargs mv "$nazwa"
done

for nazwa in *PNG
do
echo $nazwa| tr " " "_" | xargs mv "$nazwa"
done

#Zmiana rozszerzenia oraz rozmiaru na wczesniej podany z klawiatury
for nazwa in *.JPEG
do
mogrify -resize $1x$2 $nazwa
mv $nazwa ${nazwa%.JPEG}.jpeg; 
done

for nazwa in *.PNG
do
mogrify -resize $1x$2 $nazwa
mv $nazwa ${nazwa%.PNG}.png;
done

#Utworzenie archiwum

tar -cvf  archiwum.tar.gz ./

# Sprawozdanie
# 1. Tworzymy folder wejściowy o nazwie Folder1
# 2. Tworzymy folder wyjściowy o nazwie Folder2
# 3. Wklejenie do Folder1 plików: z 1.PNG, z 2.PNG, z 3.JPEG, z 4.JPEG, z 5.JPEG (Mają spacje, rozszerzenia z dużej litery)
# 4. Uruchamiamy za pomocą sh skrypt6.sh
# 5. Pobieranie zdjec z katalogu do skryptu
# 6. Zamiana spacji w nazwach plików na podkreslenie.
# 7. Zmiana rozszerzenia
# 8. Zmiana wysokości i szerokości zdjęć
# 9. Utworzenie archiwum z tych zdjec

# Wnioski: Skrypt dziala poprawnie. Pobiera pliki ze wskazanego katalogu z rozszerzeniami napisanymi wielkimi literami, odpowiednio je modyfikuje (zamina spacji na podkreslenie), zmienianie rozszerzen na male litery. Przperaszam ale funkcja zmiana rozszerzenia nie działa, problem jest w read
