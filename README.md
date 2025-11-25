# 🐵 MonkeyTyper

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-2.6.1-8CC445?style=for-the-badge&logo=sfml&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-3.28+-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=for-the-badge)

**Dynamiczna gra zręcznościowa w pisanie na klawiaturze**

[🎮 Wideo Demo](#-wideo-demonstracyjne) • [📥 Instalacja](#-instalacja) • [🎯 Rozgrywka](#-jak-grać) • [📚 Dokumentacja](#-struktura-projektu)

</div>

---

## 📝 O Projekcie

**MonkeyTyper** to dynamiczna gra typu *typing game* stworzona w C++20 z wykorzystaniem biblioteki SFML. Wyzwanie polega na wpisywaniu słów spadających z lewej strony ekranu, zanim dotrą do prawej krawędzi. Gra oferuje progresywną trudność, system zapisów i pełną personalizację!

### ✨ Główne Funkcje

- 🎮 **Dynamiczna rozgrywka** - Słowa poruszają się z różną prędkością
- 🏆 **System punktacji** - Zdobywaj punkty z mnożnikiem trudności
- 💾 **5 slotów zapisu** - Zapisuj i wczytuj postęp gry
- 🎨 **Personalizacja** - 3 czcionki, 3 kolory, 2 rozmiary słów
- 🎵 **Oprawa dźwiękowa** - Muzyka tła i efekty dźwiękowe
- 🌅 **Animowane tło** - Efekt parallax z ruchomymi chmurami
- ⚙️ **3 poziomy trudności** - EASY, NORMAL, HARD
- 📊 **Statystyki** - Śledzenie czasu, punktów i zgubionych słów

## 🎬 Wideo Demonstracyjne

<div align="center">

https://github.com/KieltRadek/MonkeyTyper/assets/s30383%20-%20Wideo.mp4

*Zobacz rozgrywkę w akcji! 🎥*

</div>

## 🛠️ Technologie

| Technologia | Wersja | Zastosowanie |
|------------|--------|--------------|
| **C++** | 20 | Główny język programowania |
| **SFML** | 2.6.1 | Grafika, okna, audio |
| **fmt** | 10.2.1 | Formatowanie komunikatów |
| **CMake** | 3.28+ | System budowania |

## 📋 Wymagania Systemowe

### Minimalne:
- **OS**: Windows 10/11, Linux (Ubuntu 20.04+), macOS 11+
- **Kompilator**: GCC 10+, Clang 10+, MSVC 2019+
- **CMake**: 3.28 lub nowszy
- **RAM**: 4 GB
- **Dysk**: 200 MB wolnego miejsca
- **Rozdzielczość**: 1920×1080 (wymagane)

## 📥 Instalacja

### 1️⃣ Klonowanie Repozytorium

```bash
git clone https://github.com/KieltRadek/MonkeyTyper.git
cd MonkeyTyper
```

### 2️⃣ Konfiguracja Ścieżki

⚠️ **WAŻNE**: Przed kompilacją zaktualizuj ścieżkę w pliku `main.cpp`:

```cpp
// main.cpp, linia 10:
auto MainPath = std::string("D:\\Studia\\MonkeyTyper\\");

// Zamień na swoją absolutną ścieżkę:
auto MainPath = std::string("C:\\Users\\TwojaNazwa\\MonkeyTyper\\");
```

### 3️⃣ Budowanie

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### 4️⃣ Uruchomienie

```bash
# Windows
.\Release\MonkeyTyper.exe

# Linux/macOS
./MonkeyTyper
```

## 🎮 Jak Grać

### 🎯 Cel Gry

Wpisuj spadające słowa przed tym, zanim dotrą do prawej krawędzi ekranu. Zgub 10 słów = koniec gry!

### 🎨 System Kolorów

Słowa zmieniają kolor w zależności od pozycji:

| Kolor | Pozycja X | Znaczenie |
|-------|-----------|-----------|
| ⚪ **Biały** | < 1200 | Bezpieczna strefa |
| 🟡 **Żółty** | 1200-1680 | Strefa ostrzeżenia |
| 🔴 **Czerwony** | > 1680 | Niebezpieczna strefa! |
| 🟢 **Zielony/Cyan/Magenta** | - | Litery, które wpisałeś |

### ⌨️ Sterowanie

| Klawisz | Akcja |
|---------|-------|
| `A-Z`, `a-z` | Wpisywanie liter |
| `Enter` | Potwierdzenie słowa |
| `Backspace` | Usunięcie ostatniej litery |
| `Escape` | Pauza (menu w grze) |

### 📊 Punktacja

```
Punkty = 100 × Mnożnik trudności
```

Mnożnik rośnie wraz z poziomem trudności i spadkiem czasu spawnu słów.

## 🎚️ Poziomy Trudności

| Poziom | Prędkość (px/frame) | Czas spawnu | Mnożnik początkowy | Przyrost trudności |
|--------|---------------------|-------------|--------------------|--------------------|
| 🟢 **EASY** | 0.05 | 3.11s | 0.3445 | 0.01s/słowo |
| 🟡 **NORMAL** | 0.09 | 2.27s | 0.6957 | 0.015s/słowo |
| 🔴 **HARD** | 0.13 | 1.13s | 1.1531 | 0.02s/słowo |

*Czas spawnu zmniejsza się progresywnie do minimalnie 0.3s*

## 📂 Struktura Projektu

```
MonkeyTyper/
├── 📄 main.cpp                   # Główna pętla gry, inicjalizacja
├── 🎮 Game.cpp / Game.h          # Logika rozgrywki, spawn, punktacja
├── 🖼️ mainMenu.cpp / mainMenu.h  # System menu i UI
├── 🌅 Background.cpp / Background.h  # Animowane tło parallax
├── 🔊 SoundManager.cpp / SoundManager.h  # Zarządzanie audio
├── ⚙️ GameMode.h                 # Enum poziomów trudności
├── 🔧 CMakeLists.txt             # Konfiguracja budowania
├── 📁 assets/
│   ├── 📝 Words.txt              # Baza 5000+ angielskich słów
│   ├── 🖼️ bg/                    # Tekstury tła (4 warstwy)
│   ├── 🎨 Buttons/               # Grafiki przycisków menu
│   ├── 🔤 Fonts/                 # Czcionki (BPdots, Coolvetica, Aller)
│   └── 🎵 Sounds/                # Muzyka i efekty dźwiękowe
└── 💾 Saves/
    ├── SavedGames.txt            # Lista aktywnych zapisów
    └── slot[1-5].txt             # Pliki stanów gry
```

## 🧩 Opis Komponentów

### 📄 `main.cpp` - Rdzeń Aplikacji

**Funkcjonalność:**
- Inicjalizacja okna SFML (1920×1080, 8x anti-aliasing)
- Główna pętla gry z obsługą eventów
- Zarządzanie stanami (menu/rozgrywka/pauza)
- Funkcja `wordsAssign()` - wczytuje słownik z `Words.txt`

**Kluczowe zmienne globalne:**
```cpp
bool gameStarted = false;   // Czy gra jest aktywna
bool gameStopped = false;   // Czy gra jest zapauzowana
bool gameIsLose = false;    // Czy gracz przegrał
```

### 🎮 `Game.cpp/h` - Logika Rozgrywki

**Główne metody:**

| Metoda | Opis |
|--------|------|
| `setGameMode(GameMode)` | Ustawia parametry trudności |
| `update()` | Spawuje słowa, aktualizuje pozycje, sprawdza kolizje |
| `handleWordInput(Event)` | Obsługuje wpisywanie i porównuje z słowami |
| `draw(RenderWindow&)` | Renderuje słowa z kolorowaniem i HUD |
| `saveGame(string)` | Serializuje stan do pliku |
| `loadGame(string)` | Deserializuje stan z pliku |
| `reset()` | Resetuje grę do stanu początkowego |

**Algorytm spawnu słów:**
1. Co `spawnTime` sekund (zmniejsza się progresywnie)
2. Losowe słowo z `wordList` o długości ≤ `ChosenSize`
3. Losowa pozycja Y (50-900)
4. Sprawdzenie kolizji z istniejącymi słowami
5. Dodanie do `wordsOnScreen`

### 🖼️ `mainMenu.cpp/h` - System Menu

**Struktura menu:**

```
Main Menu
├── Start
│   ├── New Game
│   │   ├── Easy
│   │   ├── Normal
│   │   ├── Hard
│   │   └── Play
│   └── Load Game
│       └── Slot 1-5
├── Options
│   ├── Font (BPdots/Coolvetica/Aller)
│   ├── Color (Green/Aqua/Purple)
│   └── Word Size (4/6 znaków)
├── Sound Toggle
└── Exit

Pause Menu (Escape)
├── Resume
├── Save (Slot 1-5)
├── Sound Toggle
├── Home
└── Exit
```

**System flag:**
Każdy przycisk ma flagę `xxxActive` kontrolującą możliwość interakcji. Funkcja `updateSlotColors()` koloruje sloty zapisu:
- 🟢 Zielony = wolny slot
- 🔴 Czerwony = zajęty slot

### 🌅 `Background.cpp/h` - Tło Parallax

**4 warstwy:**

| Warstwa | Plik | Ruch | Prędkość |
|---------|------|------|----------|
| 1 | bg1.png | Statyczna | - |
| 2 | bg2.png | Statyczna (księżyc) | - |
| 3 | bg3.png | Poziomy | 0.01 px/frame |
| 4 | bg4.png | Poziomy | 0.015 px/frame |

**Efekt:** Chmury poruszają się z różną prędkością, tworząc iluzję głębi. Po osiągnięciu x=0 resetują się na x=-1920.

### 🔊 `SoundManager.cpp/h` - Audio

**Zasoby dźwiękowe:**
- `Music.ogg` - Muzyka tła (zapętlona, volume 50)
- `MenuSound.wav` - Kliknięcie przycisku
- `LoseSound.wav` - Efekt przegranej

**Kluczowe metody:**
```cpp
playMusic()      // Uruchomienie muzyki tła
stopMusic()      // Toggle play/pause
playMenuSound()  // Efekt kliknięcia
playLoseSound()  // Przegrana (fade-out muzyki do volume 0)
```

### ⚙️ `GameMode.h` - Enum Trudności

```cpp
enum class GameMode {
    EASY,    // Wolne słowa, długi spawn time
    NORMAL,  // Średnia trudność
    HARD     // Szybkie słowa, krótki spawn time
};
```

## 💾 Format Pliku Zapisu

**Struktura `slotX.txt`:**

```
[linia 1]  lostWords          (int)    - Zgubione słowa
[linia 2]  points              (float)  - Punkty
[linia 3]  wordSpeed           (float)  - Prędkość słów
[linia 4]  spawnTime           (float)  - Czas spawnu
[linia 5]  multiplier          (float)  - Mnożnik punktów
[linia 6]  ChosenSize          (int)    - Rozmiar słów
[linia 7]  elapsedTime         (float)  - Czas gry
[linia 8]  spawnTimeMultiplier (float)  - Przyrost trudności
[linia 9]  wordsOnScreenSize   (int)    - Liczba słów

Dla każdego słowa (powtarzane wordsOnScreenSize razy):
[linia N]   wordLength (int)
[linia N+1] word (string)
[linia N+2] position.x (float)
[linia N+3] position.y (float)
```

**Przykład (slot1.txt):**
```
1
68.9
0.05
3.03
0.3445
4
24.1852
0.01
5
4
size
1660.84
106
4
aged
1322.06
116
```

**SavedGames.txt** - lista aktywnych slotów:
```
slot1.txt
slot3.txt
slot5.txt
```

## 🔨 Budowanie z CMake

**CMakeLists.txt** używa **FetchContent** do automatycznego pobierania zależności:

```cmake
# SFML 2.6.1
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 2.6.1
)

# fmt 10.2.1
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 10.2.1
)

FetchContent_MakeAvailable(SFML fmt)
```

**Linkowanie:**
```cmake
target_link_libraries(MonkeyTyper sfml-audio sfml-graphics fmt)
```

*Uwaga: `sfml-window` i `sfml-system` są dołączane automatycznie przez `sfml-graphics`*

## 🐛 Znane Problemy

- ⚠️ **Hardcoded ścieżka** - `MainPath` wymaga ręcznej konfiguracji
- 🌐 **Brak relatywnych ścieżek** - Utrudnia przenoszenie projektu
- 💾 **Brak walidacji zapisów** - Uszkodzone pliki mogą crashować grę
- 🗣️ **Single-language** - Tylko angielski słownik (5000+ słów)
- 📐 **Stała rozdzielczość** - UI zakodowane na 1920×1080
- 🔄 **Algorytm kolizji** - `do-while` może spowalniać przy >20 słowach

## 🚀 Przyszłe Rozszerzenia

- [ ] **Tryb wieloosobowy** - Rywalizacja online w czasie rzeczywistym
- [ ] **System achievementów** - Odznaki za osiągnięcia
- [ ] **Globalne rankingi** - Leaderboards z REST API
- [ ] **Więcej języków** - Słowniki: polski, niemiecki, francuski
- [ ] **Custom wordlisty** - Import własnych plików ze słowami
- [ ] **Power-upy** - Spowolnienie czasu, usunięcie słowa, bomba
- [ ] **Tryb survival** - Nieskończona gra z progresją
- [ ] **Mobile port** - Wersja na Android/iOS
- [ ] **Statystyki WPM** - Words Per Minute, accuracy %
- [ ] **Motywy graficzne** - Skins (cyberpunk, retro, nature)
- [ ] **Replay system** - Zapis i odtwarzanie rozgrywek
- [ ] **Tutorial** - Interaktywny samouczek dla nowych graczy

## 👤 Autor

<div align="center">

**Radosław Kiełt**

[![GitHub](https://img.shields.io/badge/GitHub-KieltRadek-181717?style=for-the-badge&logo=github)](https://github.com/KieltRadek)
[![Email](https://img.shields.io/badge/Email-s30383%40pjwstk.edu.pl-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:s30383@pjwstk.edu.pl)

*Polsko-Japońska Akademia Technik Komputerowych*

</div>

## 📄 Licencja

Projekt edukacyjny stworzony na potrzeby kursu programowania w C++.  
Można swobodnie używać w celach edukacyjnych i niekomercyjnych.

---

<div align="center">

**Dziękuję za zainteresowanie projektem!** ⭐

*Jeśli podoba Ci się gra, zostaw gwiazdkę na GitHubie!*

[![Stars](https://img.shields.io/github/stars/KieltRadek/MonkeyTyper?style=social)](https://github.com/KieltRadek/MonkeyTyper/stargazers)

**Ostatnia aktualizacja:** 25.11.2025 | **Wersja:** 1.0.0

</div>
