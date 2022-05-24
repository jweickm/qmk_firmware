# QMK Programming

TODOS

## Tap vs. Long-press keys

- change the logic of the function so that I can still use it in combination with custom keys:
  - return either true or false (look at the calling of the custom function for homerow mods for inspiration): `if(!custom_tap_processing_etc)` -> return false, else continue processing here
- this might shave off a few more bytes of the firmware size
- can also post this to getreuer to improve his "fancy key" section

## Keymap improvements

- add a hyper key to the nav layer for direct shortcuts
- change the location of the umlaut preregister to the left hand only, as "ly" is too commonly used.
- maybe change XS combo to `C(KC_DEL)`, as there is no such combo yet
- maybe change `WF_combo` to `Alt_Code` umlaut and `WP_combo` to wincompose umlaut
- `QW_combo` is still free (could be a hyper keys)
- capslock remake that deactivates capslock always when long-pressed (or double tapped, or deactivate when long-pressed and always active when double tapped)
