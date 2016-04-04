#ifndef GLFW_SHELL_H
#define GLFW_SHELL_H

#include <GLFW/glfw3.h>
#include <glisy/gl.h>

/**
 * Initialize GLFW context with major and minor version.
 */

#define GL_CONTEXT_INIT(major, minor)                                          \
  if (!glfwInit()) return 1;                                                   \
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);                         \
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);               \
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);                           \
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);                           \

/**
 * Initialize window with width and height. Calls `cb` in render loop.
 */

#define GL_RENDER(window, width, height, cb) {                                 \
  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, 0, 0);   \
  if (!window) { glfwTerminate(); exit(1); }                                   \
  glfwMakeContextCurrent(window);                                              \
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);                                        \
  printf("OpenGL %s, GLSL %s\n",                                               \
         glGetString(GL_VERSION),                                              \
         glGetString(GL_SHADING_LANGUAGE_VERSION));                            \
  while (!glfwWindowShouldClose(window)) {                                     \
    int width, height;                                                         \
    glfwGetFramebufferSize(window, &width, &height);                           \
    glViewport(0, 0, width, height);                                           \
    glDepthMask(GL_TRUE);                                                      \
    glEnable(GL_DEPTH_TEST);                                                   \
    glEnable(GL_CULL_FACE);                                                    \
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                        \
    { cb }                                                                     \
    glfwSwapBuffers(window);                                                   \
    glfwPollEvents();                                                          \
  }                                                                            \
  glfwTerminate();                                                             \
}

#endif
