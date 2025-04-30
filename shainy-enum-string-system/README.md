# 💥 SHAINY ENUM STRING SYSTEM 🔥

Welcome to **EnumToString but make it street** edition.

This ain't your grandma's enum-to-string system.  
This is a *C++ trait-based chaotic neutral utility* that slaps 💯

---

## 🧠 what's goin on?

- We got **an enum** (yeah, the `Options` one)
- Then we got a **trait**, cuz C++ said we can
- If you forget to specialize the trait, we nuke the compiler with `static_assert`
- That's safety, baby. 🔐

---

## 📦 how it werk?

You write this:
```cpp
enum class Options {
  SHIT_GIT,
  SHIT_Update
};
```

Then you specialize:
```cpp
template <>
struct enumToString<Options> {
  static std::string to(Options opt) {
    switch (opt) {
      case Options::SHIT_GIT: return "Git";
      case Options::SHIT_Update: return "Update";
      default: return "Unknow";
    }
  }
};
```

Then you say:
```cpp

std::string result = typenameToString(Options::SHIT_GIT);
```

And it says:
```
Git
```

---

## 🛠 compile like a hacker

```bash
g++ -std=c++17 main.cpp -o shainy
./shainy
```

If it doesn't work... blame the compiler not me 🙃

---

## 🔥 feature ideas (aka TODO or not TODO)

- [ ] Add fromString (reverse uno card)
- [ ] Add colors? idk make it pretty
- [ ] Replace enum with emojis 🫠

---

made with static_assert & tears ❤️‍🔥

