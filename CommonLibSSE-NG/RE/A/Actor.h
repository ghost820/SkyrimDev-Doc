// ----------------------------------------------------------------------------------------------------
// Decapitate()
// ----------------------------------------------------------------------------------------------------
/*
    Cuts off the actor's head.
*/

RE::Actor* actor = ...;
/*
    Will fail if actor is not supported (for example: chicken).
    Will not fail if actor is already decapitated.
*/
bool success = actor->Decapitate();
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// GetEditorLocation2()
// ----------------------------------------------------------------------------------------------------
// TODO: Fourth argument.

RE::Actor* actor = ...;
RE::NiPoint3 pos;
RE::NiPoint3 rot;
RE::TESForm* worldOrCell;
if (actor->GetEditorLocation2(pos, rot, worldOrCell, nullptr)) {
    // pos should contain actor EDITOR position (base position from Creation Kit).
    // rot should contain actor EDITOR rotation (base rotation from Creation Kit).
    // worldOrCell should contain:
    //     * actor EDITOR world (base world from Creation Kit) if actor is placed in the exterior.
    //     * actor EDITOR cell (base cell from Creation Kit) if actor is placed in the interior.
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// HasKeywordHelper()
// ----------------------------------------------------------------------------------------------------
RE::Actor* actor = ...;
if (RE::BGSKeyword* keyword = RE::TESForm::LookupByID<RE::BGSKeyword>(0x000F5D16); keyword) {
    bool hasKeyword = actor->HasKeywordHelper(keyword);
}
// ----------------------------------------------------------------------------------------------------
