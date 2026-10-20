<div align="center">

# ⚡ Monsgeek M1: Custom QMK Firmware

[![QMK Firmware](https://img.shields.io/badge/QMK-Firmware-444444.svg?style=for-the-badge&logo=qmk&logoColor=white)](https://qmk.fm/)
[![Built with C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Monsgeek M1](https://img.shields.io/badge/Monsgeek-M1-purple.svg?style=for-the-badge)](#)

<p align="center">
  <strong>My personal daily-driver QMK config for the Monsgeek M1 — custom firmware, RGB effects, and enough low-level control to make the stock configuration feel a little too quiet.</strong>
</p>

</div>

---

## 🚀 Why This Exists

I use this keyboard daily, and the stock firmware left enough room for customization to make a firmware project seem reasonable. This is how a small tweak becomes a new build target.

The result is a custom configuration focused on lighting behavior, key layers, macros, and the development workflow.

This repository contains my custom QMK firmware, complete with custom RGB effects, productivity-focused layers, hardcoded keymaps, macros, and a bunch of tweaks built around my development workflow. The stock firmware just wasn't cutting it.

And since QMK is written in C—and we all know C is the *absolute easiest, most forgiving* language ever created... *(hahahaha... crying in pain)*—I naturally thought, "Yeah, let's modify firmware that runs directly on the hardware."

Firmware changes have a different feedback loop from web development: a bad build can make the keyboard inconvenient to recover. Build carefully, keep a known-good recovery path, and flash only after checking the target.

Thankfully... it lived.

If you're interested in QMK development, custom keyboard firmware, hardware-level C programming, or just want to see what's possible with this board, you've come to the right place.

Feel free to:
- ✨ Steal my RGB effects
- ⌨️ Copy my keymaps and layers
- ⚡ Borrow my macros
- 🔧 Hack on the firmware and make it your own

If this repo gives you ideas for your own build, that's exactly why it's here.

<div align="center">

### ⭐ If you found this useful, consider giving the repo a star and happy hacking!

</div>

---

## ✨ Features I Coded From Scratch

### 🎨 Custom RGB Animations (`rgb_matrix_user.inc`)
To free up flash space on the WB32 microcontroller, I aggressively deleted the stock QMK animations and wrote **four completely custom reactive lighting effects**. They hook directly into the global hardware animation timer so they scale perfectly with your speed settings:

*   **🌌 Aurora Borealis:** A gorgeous, slow-rolling wave transitioning smoothly between deep greens, cyans, and purples.
*   **🪙 Liquid Mercury:** An ultra-clean, desaturated silver fluid flow effect for a minimal desktop vibe.
*   **🌸 Sakura Bloom:** A reactive typing effect that drops a pink-and-white ripple outward across the board from whatever key you press.
*   **🕳️ Event Horizon:** A dark, stealth-centered profile with sharp purple ripples expanding violently outward on keypress.

### ⚡ Git Macros (Leader Key Engine)
I mapped the right-side `Alt` key as a dedicated **Leader Key** with a tuned 1.5-second execution window. Instead of typing repetitive Git commands all day, I hardcoded structural sequences directly into the layout:

<div align="center">

| Sequence | Trigger Action | Exact String Injected |
| :--- | :--- | :--- |
| `Leader` + `G` + `A` | **Stage Files** | `git add .[ENTER]` |
| `Leader` + `G` + `C` | **Commit Code** | `git commit -m ""` *(Autofocuses cursor inside quotes)* |
| `Leader` + `G` + `P` | **Push Origin** | `git push[ENTER]` |

</div>

### 🛠️ Under-The-Hood Tweaks
*   **USB Endpoint Stability:** The WB32 MCU hates handling too many simultaneous endpoints. I completely disabled unused overhead like `Mousekeys` and `Console` in `rules.mk` to ensure **VIA compatibility** and heavy RGB processing never crash the board.
*   **Persistent Heatmaps:** Tuned `RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS` so your keys stay illuminated where you've been typing longer, rather than fading instantly.

---

## 💻 How to Compile & Flash

Ready to load this setup onto your own Monsgeek M1? Follow these steps to build it from source:

### 1️⃣ Set up the QMK Environment
Make sure you have your local environment initialized based on your OS:
*   **Windows:** Install [QMK MSYS](https://msys.qmk.fm/).
*   **macOS:** Run `brew install qmk/qmk/qmk`
*   **Linux:** Run `sudo apt install qmk`

Then open your terminal and run:
```bash
qmk setup