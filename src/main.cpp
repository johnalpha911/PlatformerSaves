#include <Geode/Geode.hpp>
#include <hooks/PlayLayer.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    // Keybinds are declared in mod.json as a "keybind" setting since Geode v5.
    // The geode.custom-keybinds developer API was removed when keybinds moved
    // into Geode itself, so BindManager/registerBindable no longer exist.
    //
    // The listener is registered ONCE here, globally. It must not be registered
    // per-PlayLayer: listenForKeybindSettingPresses leaks its ListenerHandle by
    // design, so calling it in PlayLayer::init would stack up a new listener on
    // every level start and fire the save callback N times.
    setupSaveKeybindListener();
}
