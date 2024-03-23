// ----------------------------------------------------------------------------------------------------
// KnockExplosion()
// ----------------------------------------------------------------------------------------------------
/*
    Throws an actor.

    Here in positive Y direction. Play with x,y,z,magnitude parameters to achieve desired effect.
*/

RE::Actor* actor = ...;
if (RE::AIProcess* aiProcess = actor->GetActorRuntimeData().currentProcess; aiProcess) {
    RE::NiPoint3 actorPos = actor->GetPosition();
    actorPos.y += 100;
    float magnitude = 5;
    aiProcess->KnockExplosion(actor, actorPos, magnitude);
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// PlayIdle()
// ----------------------------------------------------------------------------------------------------
RE::Actor* actor = ...;
RE::Actor* secondActorIfPairedAnim = ...;
/*
    Creation Kit -> GAMEPLAY -> Animations -> Actors\Character\Behaviors\0_Master.hkx -> LOOSE -> Mouse Hover

    Paired animations start with pa_. For non-human actors select apropriate hkx path.
*/
RE::FormID idleAnimFormId = 0x000F465A;
if (RE::TESIdleForm* idleAnim = RE::TESForm::LookupByID<RE::TESIdleForm>(idleAnimFormId); idleAnim) {
    if (RE::AIProcess* aiProcess = actor->GetActorRuntimeData().currentProcess; aiProcess) {
        /*
            Can fail if for example:
                * Not supported animation chosen (dog animation for human actor).
                * Animation conditions not met (from Creation Kit Animations window).
        */
        bool success = aiProcess->PlayIdle(actor, idleAnim, secondActorIfPairedAnim);
    }
}
// ----------------------------------------------------------------------------------------------------
