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
