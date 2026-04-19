health bar component is based off UserWidget
the enemy class gets a reference to the widgetcomponent //UPROPERTY(visibleanywhere) UWidgetComponent*HealthBar;
implimented in the constructor creates default object and sets up attachment

create uuserwidget class called Health bar
it will have a variable progress bar* health bar, meta tag bind widget that will bind the child of that class
to the progress bar called health bar

change the wbp healthbar parent to that class
Here’s a **short, clean `.md` summary** you can drop straight into GitHub:

---

```md
# Health Bar System — Summary (UE5 C++ + UMG)

## Overview
Built a complete pipeline to display and control enemy health bars:

1. **Create UI (Widget Blueprint)**
   - Designed `WBP_HealthBar` with a ProgressBar
   - Positioned and styled for use above enemies

2. **Attach UI to Enemy (Widget Component)**
   - Added `UWidgetComponent` to enemy
   - Assigned `WBP_HealthBar`
   - Positioned above head
   - Set to **Screen Space** for consistent visibility

3. **Enable C++ Control (Custom Widget Class)**
   - Created `UHealthBar` (inherits `UUserWidget`)
   - Used `BindWidget` to link ProgressBar to C++
   - Reparented Blueprint to C++ class

4. **Update UI from Gameplay (Component Bridge)**
   - Created `UHealthBarComponent`
   - Accessed widget via `GetUserWidgetObject()`
   - Cached widget after casting (performance)
   - Exposed `SetHealthPercent(float)` function

## Final Flow

Enemy → HealthBarComponent → UHealthBar → ProgressBar

## Key Concepts
- UI is **driven by C++**, not Blueprint logic
- WidgetComponent connects UI to world actors
- `BindWidget` links Blueprint UI to C++
- Avoid repeated casting → cache pointers
- Percent values are **0–1 (normalized)**

## Next Step
- Replace test values with:
  - `Health / MaxHealth`
- Apply damage and update UI dynamically
- Later: migrate to GAS (AttributeSet + GameplayEffects)
```

---

If you want, I can also give you a **diagram-style version for README (with arrows/visual blocks)** or a **GAS-upgraded version of this pipeline**.
