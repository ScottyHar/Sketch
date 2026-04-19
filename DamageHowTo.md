## Damage + Health Bar System

Implemented a full damage pipeline:

Weapon hit → ApplyDamage → Enemy.TakeDamage → Health reduced → UI updated

Key points:
- Uses Unreal’s built-in damage system
- Health managed via AttributeComponent
- Values clamped (0 → MaxHealth)
- UI updated via normalized percent (Health / MaxHealth)
- Clean separation: Weapon → Enemy → Attributes → UI

Result:
Real-time combat feedback with responsive health bars
