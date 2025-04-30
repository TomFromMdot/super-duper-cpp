# 🕹️ Shainy Game Loop — State Pattern Playground

This project showcases a lightweight state-based game object system written in C++  
that leverages virtual inheritance and an enum-driven dispatcher. Perfect for late-night C++ madness.

---

## 🎯 What it does

- Defines a `States` enum for INIT, UPDATE, RENDER phases
- Introduces interfaces: `IState`, `InitState`, `UpdateState`, `RenderState`
- Lets you build your own `GameObject` subclasses (like `Player`) and implement only what they need
- Executes each state only when it's relevant (e.g. `INIT` only once)
- Runs a minimal game loop across all objects

---

## 🧠 How it works

You create a `GameObject` by inheriting the state interfaces you care about.  
Then you implement methods like `initState()`, `updateState()`, `renderState()`.

The game loop calls `useState(state)` and the object delegates to the proper function.

---

## 💡 Example output

```
💾 [INIT] Loading player into memory...
🧠 [UPDATE] Moving player forward...
🎨 [RENDER] Drawing player on screen...
...
```

---

## 🛠 Build it

```bash
g++ -std=c++20 main.cpp -o shainy_game
./shainy_game
```

---

## 📦 Features

- ✅ Clean interface separation (SOLID as heck)
- ✅ Minimal dependencies
- ✅ State logic runs only when needed (INIT once per object)
- ✅ Extendable with enemies, items, cutscenes, etc.

---

made with `virtual`, adhd, and a questionable sense of design 😅
