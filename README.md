# C Dilinde Nesne Yönelimli Benzetim (2023‑2024 Bahar Dönemi)

> Sakarya Üniversitesi Bilgisayar Mühendisliği – **Sistem Programlama / Gömülü** proje çalışması  
> **Geliştirici:** İbrahim Güldemir  
> **Repo:** <https://github.com/ibrhmgldmr3/C-Dilinde-Nesne-Y-nelimli-Benzetim>

---

## İçerik

- [Proje Hakkında](#proje-hakkında)
- [OOP Yaklaşımı](#oop-yaklaşımı)
- [Teknolojiler](#teknolojiler)
- [Kurulum](#kurulum)
- [Çalıştırma](#çalıştırma)
- [Örnek Kullanım](#örnek-kullanım)
- [Dizin Yapısı](#dizin-yapısı)
- [İletişim](#iletişim)

---

## Proje Hakkında

Bu depo, **salt C** dili kullanarak *nesne yönelimli programlama* (OOP) kavramlarını **struct + function pointer** tabanlı bir kütüphane ile taklit eder ve bunun üzerine basit bir **benzetim (simulation) motoru** kurar.  

Amaç, C’de:

- **Encapsulation** (veri + davranış bir arada),
- **Inheritance** (üst/alt “sınıf” katmanları),
- **Polymorphism** (virtual method benzeri),
- **Runtime type‐checking**

gibi kavramları göstermek ve bunların gömülü/sistem programlama projelerinde nasıl kullanılabileceğini uygulamalı biçimde sergilemektir.

---

## OOP Yaklaşımı

| Kavram | C’de Gerçekleniş Yöntemi |
| ------ | ----------------------- |
| **Sınıf (Class)** | `struct` + public header |
| **Constructor / Destructor** | `_new()` & `_delete()` fonksiyon şablonları |
| **Inheritance** | Alt struct ilk alanına *base struct*’ı gömerek *is‑a* ilişkisi |
| **Virtual Method** | Fonksiyon işaretçisi tablosu (pseudo‑vtable) |
| **Interface** | Sadece fonksiyon pointer şablonları içeren struct |

Proje, bu altyapının üzerine **örn. trafik ışığı simülasyonu / canlı hücre otomata / kaynak tahsisi** gibi küçük senaryolarla örnekler içerir.

---

## Teknolojiler

| Katman | Yığın / Araçlar |
| ------ | -------------- |
| **Dil / Derleyici** | ISO C17 – `gcc` / `clang` |
| **Build** | GNU Make (& opsiyonel **CMake**) |
| **Test** | **Unity** framework · `valgrind` bellek analizi |
| **CI** | GitHub Actions (Linux build & test) |
| **Dokümantasyon** | `doxygen` → HTML + PDF |

---

## Kurulum

### 1. Depoyu klonla

```bash
git clone https://github.com/ibrhmgldmr3/C-Dilinde-Nesne-Y-nelimli-Benzetim.git
cd C-Dilinde-Nesne-Y-nelimli-Benzetim
```

### 2. Derle

```bash
make          # varsayılan hedef → libooc.a + örnek binary
```

> Farklı derleyici / bayraklar için `Makefile` başındaki değişkenleri düzenle (`CC`, `CFLAGS`).

---

## Çalıştırma

```bash
./bin/simulation_demo           # Örnek senaryoyu başlatır
```

Parametreler:

```
--steps N          # Simülasyon adımı (vars. 100)
--verbose          # Ayrıntılı konsol çıktısı
```

---

## Örnek Kullanım

```c
#include "ooc/Animal.h"

int main(void) {
    Animal *cat = Animal_new("Mırmır", /*age=*/2);
    cat->speak(cat);                 // => "Miyav!"
    Animal_delete(cat);
    return 0;
}
```

```bash
gcc -Iinclude examples/cat_demo.c lib/libooc.a -o cat_demo
./cat_demo
```

---

## Dizin Yapısı

```text
C-Dilinde-Nesne-Y-nelimli-Benzetim/
├── include/               # OOP public header’lar
│   └── ooc/
├── src/                   # Kütüphane implementasyonu
│   └── core/
├── examples/              # Çalıştırılabilir demolar
├── tests/                 # Birim testleri (Unity)
├── docs/                  # Doxygen çıktıları
├── Makefile
└── README.md
```

---

## İletişim

| Kanal   | Bilgi |
| ------- | ----- |
| E‑posta | ibrahimguldemir123@gmail.com |
| LinkedIn| <https://www.linkedin.com/in/ibrhmgldmr/> |
| GitHub  | <https://github.com/ibrhmgldmr3> |

---

> **Katkılar / Sorunlar:** Issue veya Pull Request göndermekten çekinme!  
> Projeyi beğendiysen ⭐ vererek destek olabilirsin.
