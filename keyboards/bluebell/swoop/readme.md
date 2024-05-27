# Swoop

![Swoop](https://i.imgur.com/mMlmEsdh.jpg)

*The Swoop is an open source split keyboard based on the Ferris/Sweep.*

* Keyboard Maintainer: [Jimmerricks](https://github.com/jimmerricks)
* Hardware Supported: *Swoop MX, Swoop LP + Pro-micro or equivalent*
* Hardware Availability: [*Swoop Repository*](https://github.com/jimmerricks/swoop)

Make example for this keyboard (after setting up your build environment):

    make bluebell/swoop:joaopedropio

Flashing example for this keyboard:

    make bluebell/swoop:joaopedropio:avrdude-split-right

To use RP2040 instead:

    qmk flash -c -kb bluebell/swoop -km joaopedropio -bl uf2-split-left -e CONVERT_TO=helios

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Entering the bootloader:

<!-- * **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard -->
* **Physical reset button**: Briefly press the small button on the inner side of the PCB - you may have pads you must short instead
<!-- * **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available -->
