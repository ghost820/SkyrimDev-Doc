// ----------------------------------------------------------------------------------------------------
// GetInventory()
// ----------------------------------------------------------------------------------------------------
if (RE::Actor* player = RE::PlayerCharacter::GetSingleton(); player) {
    RE::TESObjectREFR::InventoryItemMap inventory = player->GetInventory();
    for (const auto& [item, data] : inventory) {
        const auto& [count, entry] = data;
        if (count > 0) {
            logger::info("{}", entry->GetDisplayName());
        }
    }
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ProcessEvent()
// ----------------------------------------------------------------------------------------------------
/*
    Execute code on weapon swing.
*/

class AttackHook {
public:
    static void Hook() {
        _ProcessEvent = REL::Relocation<uintptr_t>(RE::VTABLE_PlayerCharacter[2]).write_vfunc(0x1, ProcessEvent);
    }

private:
    static RE::BSEventNotifyControl ProcessEvent(RE::BSTEventSink<RE::BSAnimationGraphEvent>* _this,
                                                 const RE::BSAnimationGraphEvent* a_event,
                                                 RE::BSTEventSource<RE::BSAnimationGraphEvent>* a_dispatcher) {
        if (a_event && a_event->holder) {
            if (auto a = const_cast<RE::Actor*>(a_event->holder->As<RE::Actor>())) {
                if (a_event->tag == "weaponSwing") {
                }
            }
        }
        return _ProcessEvent(_this, a_event, a_dispatcher);
    }

    static inline REL::Relocation<decltype(ProcessEvent)> _ProcessEvent;
};

/*
    Stagger when trying to sprint.
*/

class SprintHook {
public:
    static void Hook() {
        _ProcessEvent = REL::Relocation<uintptr_t>(RE::VTABLE_PlayerCharacter[2]).write_vfunc(0x1, ProcessEvent);
    }

private:
    static RE::BSEventNotifyControl ProcessEvent(RE::BSTEventSink<RE::BSAnimationGraphEvent>* _this,
                                                 const RE::BSAnimationGraphEvent* a_event,
                                                 RE::BSTEventSource<RE::BSAnimationGraphEvent>* a_dispatcher) {
        if (a_event && a_event->holder) {
            if (auto a = const_cast<RE::Actor*>(a_event->holder->As<RE::Actor>())) {
                if (a_event->tag == "FootSprintLeft" || a_event->tag == "FootSprintRight") {
                    a->SetGraphVariableFloat("staggerDirection", 3.1415926f);
                    a->SetGraphVariableFloat("staggerMagnitude", 0.5f);
                    a->NotifyAnimationGraph("staggerStart");
                }
            }
        }
        return _ProcessEvent(_this, a_event, a_dispatcher);
    }

    static inline REL::Relocation<decltype(ProcessEvent)> _ProcessEvent;
};
// ----------------------------------------------------------------------------------------------------
