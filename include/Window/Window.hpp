#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "Engine2D"

namespace Editor2D {
struct WindowBindings {
  int WINDOW_EXIT = GLFW_KEY_ESCAPE;
};

class Window {
public:
  GLFWwindow *WHandle;
  WindowBindings bindings;
  static Window &GetInstance() {
    static Window instance;
    return instance;
  }
  void WPollEvents() { glfwPollEvents(); }
  void WSwapBuffers() { glfwSwapBuffers(WHandle); }
  bool ExitStatus() { return glfwWindowShouldClose(WHandle); }
  void update() {
    glfwSetWindowShouldClose(
        WHandle, bool(glfwGetKey(WHandle, bindings.WINDOW_EXIT) == true));
  }

private:
  void createWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    WHandle = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME,
                               nullptr, nullptr);
    glfwMakeContextCurrent(WHandle);
  }
  Window() { createWindow(); }
  ~Window() {
    glfwDestroyWindow(WHandle);
    glfwTerminate();
  }
  Window(Window const &);
  void operator=(Window const &);
};
} // namespace Editor2D

#endif