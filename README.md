# MonkeyTyper

## Opis projektu
MonkeyTyper to gra w pisanie, zbudowana w języku C++ przy użyciu biblioteki SFML. Gra polega na pisaniu słów, które spadają z góry ekranu. Celem gry jest jak najszybsze wpisanie słów, aby uzyskać jak najwyższy wynik.

## Główne cechy
- **Gra w pisanie z opadającymi słowami**: Gracze muszą szybko wpisywać słowa, zanim dotrą do dolnej części ekranu.
- **Wielopoziomowy poziom trudności**: Gra oferuje trzy poziomy trudności: ŁATWY, NORMALNY i TRUDNY, co pozwala dostosować grę do umiejętności gracza.
- **System zapisywania/ładowania**: Dzięki pięciu slotom na zapisy można kontynuować grę w późniejszym czasie.
- **Opcje dostosowywania**: Gracze mogą dostosować kolory czcionek, rozmiary słów oraz tło.
- **Muzyka w tle i efekty dźwiękowe**: Gra oferuje przyjemną muzykę w tle oraz efekty dźwiękowe, które zwiększają wrażenia z gry.
- **Animowane tło parallaxowe**: Tło gry jest dynamiczne, co sprawia, że gra jest bardziej atrakcyjna wizualnie.

## Technologie
- **C++ 20**: Nowoczesny język programowania, który zapewnia wydajność i elastyczność.
- **SFML 2.6.1**: Biblioteka graficzna i dźwiękowa, która ułatwia tworzenie gier.
- **Biblioteka fmt**: Używana do efektywnego formatowania tekstu.
- **System budowania CMake**: Umożliwia łatwą kompilację projektu na różnych platformach.

## Wymagania systemowe
- System operacyjny: Windows, macOS, lub Linux.
- Procesor: Quad-core Intel lub AMD.
- Pamięć RAM: 8 GB lub więcej.
- Karta graficzna: Z obsługą OpenGL 3.0.
- Miejsce na dysku: 500 MB wolnego miejsca.

## Instrukcje instalacji
1. Klonuj repozytorium:
   ```bash
   git clone https://github.com/KieltRadek/MonkeyTyper.git
   ```
2. Zainstaluj zależności:
   Upewnij się, że masz zainstalowane SFML oraz bibliotekę fmt.
3. Zbuduj projekt:
   ```bash
   cd MonkeyTyper
   mkdir build
   cd build
   cmake ..
   make
   ```

## Sterowanie i mechanika gry
- Użyj klawiatury, aby pisać słowa.
- Wciśnij "Enter" po wpisaniu słowa, aby zaliczyć je do wyniku.
- Użyj klawiszy strzałek, aby nawigować w menu.

## Nawigacja w menu
- Główne menu zawiera opcje: Nowa Gra, Wczytaj Grę, Ustawienia, Wyjście.
- Ustawienia pozwalają na dostosowanie preferencji dotyczących dźwięku i grafiki.

## Wyjaśnienie systemu zapisywania/ładowania
- Gra pozwala na zapisanie stanu w pięciu różnych slotach. Aby załadować grę, wybierz slot z menu ładującego.

## Opcje dostosowywania
- Gracze mogą zmieniać kolory czcionek, rozmiar słów oraz tło, co pozwala na personalizację doświadczeń z gry.

## Struktura projektu
```
MonkeyTyper/
├── src/
│   ├── main.cpp           // punkt wejścia do aplikacji
│   ├── game.cpp           // logika gry
│   ├── graphics.cpp       // zarządzanie grafiką
│   ├── input.cpp          // obsługa wejścia
│   ├── settings.cpp       // zarządzanie ustawieniami
├── include/
│   ├── game.h             // nagłówek logiki gry
│   ├── graphics.h         // nagłówek zarządzania grafiką
│   ├── input.h            // nagłówek obsługi wejścia
└── CMakeLists.txt        // plik konfiguracyjny CMake
```

## Wyjaśnienie architektury kodu
- Kod jest podzielony na różne moduły, co ułatwia zarządzanie i rozwijanie projektu. Każdy moduł odpowiada za inną funkcjonalność, co pozwala na łatwiejsze testowanie i debugowanie.

## Format pliku dla slotów zapisu
- Sloty zapisu są przechowywane w formacie JSON, który umożliwia łatwe odczytywanie i zapisywanie danych.

## Instrukcje dotyczące budowy
1. Upewnij się, że masz zainstalowane wszystkie wymagane zależności.
2. Użyj polecenia cmake do generowania plików projektu.
3. Następnie skompiluj projekt za pomocą make.

## Sekcja zrzutów ekranu
- (Placeholder na zrzuty ekranu)

## Znane problemy
- Możliwe problemy z wydajnością na starszych komputerach.
- Potencjalne błędy związane z obsługą wejścia.

## Przyszłe ulepszenia
- Dodanie więcej poziomów trudności.
- Rozbudowa systemu zapisywania, aby umożliwić więcej slotów.

## Informacje o autorze
**Imię i nazwisko**: KieltRadek

## Licencja
Projekt jest licencjonowany na zasadach licencji MIT.