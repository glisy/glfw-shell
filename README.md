glfw-shell
==========

GLFW context creation and render loop helper

## Installation

```sh
$ clib install glisy/glfw-shell
```

## Usage

```c
#include <glfw-shell/glfw-shell.h>

int
main (void) {
  GLFWwindow *window;
  int width = 640;
  int height = 640;
  GLFW_SHELL_CONTEXT_INIT(3, 2);
  GLFW_SHELL_WINDOW_INIT(window, width, height);

  // initialize objects...

  GLFW_SHELL_RENDER(window, {
    // render here
  });
  return 0;
}
```

## License

MIT
