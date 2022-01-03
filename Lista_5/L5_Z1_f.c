// Plik jest stale otworzony, nie jest zamykany ani otwierany w czasie jego edycji. 
// Otworzyłem zwykły plik programem nano, znalazłem PID procesu odpowiedzialnego za uruchomienie nano i użyłem polecenia: 
// strace -e trace=open.write,read,close -p PID. 
// Następnie edytowałem plik w programie nano, a w okienku ze stracem obserwowałem, 
// że pojawiają się kolejne użycia funkcji read oraz write. 
// Ani razu nie pojawiło się użycie funkcji close lub open co oznacza, że plik jest ciągle otwarty w czasie jego edycji.