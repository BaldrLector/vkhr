Real-Time Hair Renderer
=======================


<p align="center">
    <img src="https://eriksvjansson.net/images/vkhr/screenshot.png" alt="VKHR 1920x1080 Ponytail"/>
    <img width=33% src="https://eriksvjansson.net/images/vkhr/2018-12-09-smoothed-deep-shadows.png" alt="VKHR 1280x720 ADSM"/>
    <img width=33% src="https://eriksvjansson.net/images/vkhr/2018-12-09-smooth-deep-shadows-shaded.png" alt="VKRHR 1280x720 Shaded ADSM"/>
    <img width=33% src="https://eriksvjansson.net/images/vkhr/2018-12-23-bear-2.png" alt="VKHR 1280x720 Bear"/>
</p>

List of Features
----------------

Compiling and Running
---------------------

1. First, make sure you've changed your current directory to `vkhr`
2. Then do `git submodule update --init --recursive --depth 1`
    * **Description:** fetches submodule dependencies to `foreign`
3. Since we use [premake](https://premake.github.io/), you'll most likely need to fetch it as well:
    * **Tip:** there's pre-generated Visual Studio solutions in `build`
        * if you're happy with that, you can skip the steps below
    * **Unix-like:** just install `premake5` with your package manager
4. Now make sure you have the [glfw3](https://www.glfw.org/) external dependency solved
    * **Unix-like:** just install `glfw` with your package manager too
    * **Visual Studio:** pre-built version is already provided for you!
5. Finally, you'll also need [Embree](https://embree.github.io/) for the hair raytracing back-end:
    * **Unix-like:** just install `embree` using your package managers
    * **Visual Studio:** pre-built version is already provided for you!
6. Generate the `vkhr` project files by targeting your current setup
    * **Visual Studio:** `premake5 vs2017` or my alias `make solution`
        * then open the Visual Studio project in `build/vkhr.sln`
    * **GNU Makefiles:** `premake5 gmake` or just call `make all/run`.
7. Build as usual in your platform, and run with `bin/vkhr <scene>`.

Usage and Documents
-------------------

* `bin/vkhr`: loads the default `vkhr` scene in `share/scenes/curly.vkhr` with the standard window and renderer settings.
* `bin/vkhr share/scenes/curly.vkhr`: loads any `vkhr` scene file with the default settings. It is *always* the final argument.
* **Arguments:** `--width 1280`, `--height 720` , `--fullscreen no` , `--msaa off` , `--vsync on` , `--profile off`, `--ui on`.
* **Controls:** simply **click** and **drag** to rotate the camera, use **scrolling** to zoom, and use the **imgui** to modify everything else.

System Requirements
-------------------

Platforms *must* support Vulkan™.

Dependencies
------------

* `premake5` (pre-build)
* Any Vulkan™ 1.1 SDK
* `glfw3` (tested v3.2.1)
* `embree3` (uses v3.2.4)
* Any C++17 compiler!

All other dependencies are fetched using `git submodules`, and include the following libraries: `g-truc/glm`, `ocurnut/imgui`, `syoyo/tinyobjloader`, `nothings/stb`, `nlohmann/json`. The Vulkan C++ wrapper `vkpp` is being developed alongside `vkhr`.

Structure
---------

* `bin`: contains the built software and any other accompanying tools.
* `build`: stores intermediate object files and generated GNU Make files.
    * `obj`: has all of the generated object files given under compilation.
    * `Makefile`: automatically generated by executing `premake5 gmake`.
    * `*.make`: program specific make config for augmenting `Makefile`.
    * you'll also find the pre-generated Visual Studio '17 solution here.
* `docs`: any generated documentation for this project is over here.
* `foreign`: external headers and source for libraries and modules.
* `include`: only internal headers from this project should go here.
    * `vkhr`: internal headers for the Vulkan hair renderer project.
    * `vkpp`: headers for a minimal modern C++ Vulkan wrapper.
* `lib`: any generated libraries from the project reside here.
* `license.md`: please look through this very carefully.
* `premake5.lua`: configuration file for the build system.
* `readme.md`: this file contains information on the project.
* `share`: any extra data that needs to be bundled should go here.
    * `images`: any images on disk that should be used as textures.
    * `models`: the meshes/models/materials to be used in the project.
    * `shaders`: all of the uncompiled shaders should go over here.
    * `scenes`: any sort of scene files (e.g. in json) should go here.
    * `styles`: the hair styles compatible with the Cem Yuksel format.
* `src`: all source code for the project should be located below here.
    * `vkhr`: source code for the Vulkan hair renderer project itself.
    * `vkpp`: full implementation of an Vulkan C++ wrapper (separate).
    * `main.cc`: the primary entry point when generating the binaries.
* `utils`: any sort of helper scripts or similar should be over here.

Reporting Bugs
--------------

There are definitely no known bugs in this software at this time.

Still, if you find anything, feel free to open an issue and I'll fix it!

Acknowledgements
----------------

All hair styles are courtesy of Cem Yuksel's great [HAIR model files](http://www.cemyuksel.com/research/hairmodels/) repository.

The ponytail and bear hair geometry are from the [TressFX 3.1](https://github.com/GPUOpen-Effects/TressFX/tree/3.1.1) repository, and proper rights have been granted by AMD Inc.

The woman model was created by Murat Afshar (also for Cem Yuksel's repo).

Legal Notice
------------

Vulkan and the Vulkan logo are registered trademarks of Khronos Group Inc.

See: [foreign/glfw/COPYING.txt](foreign/glfw/COPYING.txt) plus [foreign/embree/LICENSE.txt](foreign/embree/LICENSE.txt) for licenses.
