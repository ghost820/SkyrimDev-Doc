// ----------------------------------------------------------------------------------------------------
// HandleHits()
// ----------------------------------------------------------------------------------------------------
/*
    Projectile (e.g. fireball) bounces off the target and flies back to the caster.
*/

class ProjHook {
public:
    static void Hook() {
        _HandleHits = REL::Relocation<uintptr_t>(RE::VTABLE_MissileProjectile[0]).write_vfunc(0xBE, HandleHits);
    }

private:
    static bool HandleHits(RE::Projectile* proj, RE::hkpCollidable*) {
        proj->GetProjectileRuntimeData().linearVelocity *= -1;
        // TODO: There was no collision?
        return false;
    }

    static inline REL::Relocation<decltype(HandleHits)> _HandleHits;
};
// ----------------------------------------------------------------------------------------------------
